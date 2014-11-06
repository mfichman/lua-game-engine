-- Copyright (c) 2014 Matt Fichman
--
-- Permission is hereby granted, free of charge, to any person obtaining a copy
-- of this software and associated documentation files (the "Software"), to
-- deal in the Software without restriction, including without limitation the
-- rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
-- sell copies of the Software, and to permit persons to whom the Software is
-- furnished to do so, subject to the following conditions:
-- 
-- The above copyright notice and this permission notice shall be included in
-- all copies or substantial portions of the Software.
-- 
-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, APEXPRESS OR
-- IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
-- FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
-- AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
-- LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
-- FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
-- IN THE SOFTWARE.

-- Renders material info for triangle meshes into the G-buffer.

local ffi = require('ffi')
local gl = require('gl')
local graphics = require('graphics')
local assets = require('graphics.assets')
local program = assets.assetIs(graphics.Program, 'shaders/model')


-- Render a mesh, using the current bindings for the material and texture
local function mesh(g, mesh)
  assert(model.mesh, "model has no mesh!")
  assert(model.mesh.indexBuffer, "mesh has no index buffer!")
  assert(g.camera, "no camera!")

  mesh:sync()
  
  -- Calculate the normal matrix and pass it to the vertex shader
  local camera = g.camera
  local normalMatrix = camera:viewTransform() * g.worldTransform
  normalMatrix = normalMatrix.inverse()
  normalMatrix = normalMatrix.transpose()

  local temp = ffi.new('GLfloat[9]', {
    normalMatrix.data[0], normalMatrix.data[1], normalMatrix.data[2], 
    normalMatrix.data[4], normalMatrix.data[5], normalMatrix.data[6], 
    normalMatrix.data[8], normalMatrix.data[9], normalMatrix.data[10], 
  })

  local transform = camera:transform() * g.worldTransform

  -- Pass the model matrix to the vertex shader
  gl.glUniformMatrix3fv(program.normalMatrix.data, 1, 0, temp)
  gl.glUniformMatrix4fv(program.transform.data, 1, 0, transform.data) 

  local buffer = mesh.indexBuffer
  gl.glBindVertexArray(mesh.id)
  gl.glDrawElements(gl.GL_TRIANGLES, buffer.elementCount, gl.GL_UNSIGNED_INT, 0)
  gl.glBindVertexArray(0)
end

-- Pass the texture data to the shader
local function texture(g, texture)
  if texture then
    gl.glBindTexture(gl.GL_TEXTURE_2D, texture.id) 
  end
end

-- Pass the material data to the shader
local function material(g, material)
  gl.glUniform3fv(program.ambient, 1, material.ambientColor.data)
  gl.glUniform3fv(program.diffuse, 1, material.diffuseColor.data)
  gl.glUniform3fv(program.specular, 1, material.specularColor.data)
  gl.glUniform3fv(program.emissive, 1, material.emissiveColor.data)
  gl.glUniform1f(program.shininess, material.shininess)

  gl.glActiveTexture(gl.GL_TEXTURE0)
  texture(g, material.diffuseMap)
  gl.glActiveTexture(gl.GL_TEXTURE1)
  texture(g, material.specularMap)
  gl.glActiveTexture(gl.GL_TEXTURE2)
  texture(g, material.normalMap)
  gl.glActiveTexture(gl.GL_TEXTURE3)
  texture(g, material.emissiveMap)
end

-- Render a model (a mesh with an attached texture and material)
local function render(g, model)
  assert(g, "graphics context is nil!")
  assert(model.material, "model has no material!")
  if model.material.opacity < 1 then
    return
  end

  g.rendererIs(render) -- Notify that a new renderer is starting
  g.glUseProgram(program.id) -- Use cached program ID if already set
  g.glEnable(gl.GL_CULL_FACE)
  g.glEnable(gl.GL_DEPTH_TEST)

  material(g, model.material)
  mesh(g, model.mesh)

end

return {
  render = render
}
