/*****************************************************************************
 * Simple, Fast Renderer (SFR)                                               *
 * CS249b                                                                    *
 * Matt Fichman                                                              *
 * February, 2011                                                            *
 *****************************************************************************/

#pragma include "shader/Camera.vert"

uniform sampler2D diffuseBuffer;
uniform sampler2D specularBuffer;
uniform sampler2D normalBuffer;
uniform sampler2D emissiveBuffer;
uniform sampler2D depthBuffer;

uniform sampler2DShadow shadowMap;
uniform float shadowMapSize;

uniform mat4 lightMatrix; // From _view space_ (!!) to light space

in vec4 position;

struct LightingInfo {
    vec3 view; // View space coordinates of pixel
    float depth; // Coord in range [0, 1]
    vec3 Kd; // Diffuse color sampled from G-buffers
    vec3 Ks; // Specular color sampled from G-buffers
    vec3 Ke; // Emissive color sampled from G-buffers
    float alpha; // Specular lighting exponent sampled from G-buffers
    vec3 N; // Normal vector
};

LightingInfo lightingInfo() {
    // Reconstruct lighting info from the G-buffers that was generated in the first 
    // rendering pass
    LightingInfo info;
   
    // Perform the viewport transform on the clip position. 

    // Normalize the coordinates
    vec2 normalized = position.xy/position.w;

    // Viewport (x, y) coordinates of pixel, range: [0, 1]
    vec2 viewport = (normalized.xy + 1.)/2.;

    // Sample the depth and reconstruct the fragment view coordinates. 
    // Make sure the depth is unpacked into clip coordinates.
    info.depth = texture(depthBuffer, viewport).r;

    // Reconstructed clip space coordinates of pixel, range: [-1, 1]
    vec3 clip = vec3(normalized, 2. * info.depth - 1.);

    // Transform the clip coordinates back into view space for lighting calculations
    vec4 view = projectionInvMatrix * vec4(clip, 1.);
    info.view = view.xyz/view.w;

    // Sample the materials using the viewport position
    vec4 temp = texture(specularBuffer, viewport);
    info.Kd = texture(diffuseBuffer, viewport).rgb;
    info.Ke = texture(emissiveBuffer, viewport).rgb;
    info.Ks = temp.rgb;

    float alphaPackFactor = 1024;
    info.alpha = temp.a*alphaPackFactor;

    // Sample the normal vector for the pixel
    info.N = normalize(texture(normalBuffer, viewport).xyz * 2. - 1.);

    return info;
}

float shadowPoissonPcf(in LightingInfo li) {
    // PCF shadow lookup using poisson disk distribution for samples. Assumes 
    // that the shadow map size is 2048x2048.  Input: Coordinates in light clip 
    // space (including perspective divide by w).  Output: A value from 1-0, 
    // where 1 is fully lit and 0 is in full shadow.

    if (shadowMapSize == 0) {
        return 1.;
    }

    // Transform the view coordinates to light space and renormalize
    vec4 shadowCoord = lightMatrix * vec4(li.view, 1);

    if(shadowCoord.x>1||shadowCoord.x<0||shadowCoord.y>1||shadowCoord.y<0) {
        return 1;
    }

    float shadow = textureProj(shadowMap, shadowCoord);
    if (shadow <= 0) {
        float dist = shadowCoord.z/shadowCoord.w;
        float maxDist = .7;
        return clamp(sqrt(max(dist-maxDist, 0)/maxDist), 0, 1);
    } else {
        return 1;
    }
}

