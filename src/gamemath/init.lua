-- ========================================================================== --
--                                                                            --
-- Copyright (c) 2014 Matt Fichman <matt.fichman@gmail.com>                   --
--                                                                            --
-- This file is part of Quadrant.  It is subject to the license terms in the  --
-- LICENSE.md file found in the top-level directory of this software package  --
-- and at http://github.com/mfichman/quadrant/blob/master/LICENSE.md.         --
-- No person may use, copy, modify, publish, distribute, sublicense and/or    --
-- sell any part of Quadrant except according to the terms contained in the   --
-- LICENSE.md file.                                                           --
--                                                                            --
-- ========================================================================== --

local vec = require('vec')

-- Clamps a value to the range defined by [min max]
local function clamp(val, min, max)
  return math.min(math.max(val, min), max)
end

-- Given a line and a plane, compute the intersection.  The line is defined
-- by a point on the line (l0) and the vector in the direction of the line
-- (ln).  The plane is defined by a point on the plane (p0) and the plane's
-- normal (pn).
--
-- http://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection#Algebraic_form
local function rayPlaneIntersect(ray, p0, pn)
  local l0 = ray.origin
  local ln = ray.direction
  local d = (p0-l0):dot(pn) / ln:dot(pn)
  return ln * d + l0
end

-- Convert device coordinates (i.e., [-1 1] x [-1 1]) to world coordinates.
local function deviceToWorld(camera, device)
  local device = vec.Vec4(device.x, device.y, device.z, 1)

  -- World coordinates; do perspective divide
  local world = camera.viewProjectionMatrix:inverse() * device  
  return world/world.w
end

-- Convert screen coordinates (i.e., [0, width] x [0 height]) to world coordinates.
local function screenToWorld(camera, screen)
  local device = vec.Vec3()
  device.x = clamp(2*screen.x/camera.viewport.width-1, -1, 1)
  device.y = clamp(1-2*screen.y/camera.viewport.height, -1, 1)
  device.z = 0
  return deviceToWorld(camera, device)
end

-- Returns a world-space picking ray that passes from a point in world space
-- through the camera. Returns {origin = ?, vector = ?}.
local function pickRay(camera, screen)
  -- Find a ray from the mouse to the camera in world space, and then intersect
  -- the ray with the z = 0 plane. Point the thruster in that direction.
  local cameraWorld = camera.viewMatrix:inverse() * vec.Vec4(0, 0, 0, 1)
  local ray = {}
  ray.origin = screenToWorld(camera, screen)
  ray.direction = (ray.origin-cameraWorld):unit()
  ray.direction = vec.Vec3(ray.direction.x, ray.direction.y, ray.direction.z)
  return ray
end

-- Returns a function that scales the domain [begin, rend) to [0, 1)
local function domain(f, min, max)
  return function(t)
    local t = clamp(t, min, max)
    local t = (t-min)/(max-min)
    return f(t)
  end
end

-- Returns a function for a cubic polynomial with coefficients a, b, c, d
local function cubic(a, b, c, d) 
  return function(t)
    return a*math.pow(t, 3) + b*math.pow(t, 2) + c*t + d
  end
end

-- Returns a function that outputs a hermite curve for a parameterized input
-- with domain in [0, 1)
local function hermite(p0, p1, m0, m1)
  local a = 2*p0 + m0 - 2*p1 + m1
  local b = -3*p0 - 2*m0 + 3*p1 - m1
  local c = m0
  local d = p0
  return cubic(a, b, c, d)
end

-- Mix a and b using factor alpha
local function mix(min, max, alpha)
  return min * (1-alpha) + max * alpha
end

return {
  clamp = clamp,
  rayPlaneIntersect = rayPlaneIntersect,
  screenToWorld = screenToWorld,
  deviceToWorld = deviceToWorld,
  pickRay = pickRay,
  hermite = hermite,
  domain = domain,
  cubic = cubic,
  mix = mix,
}
