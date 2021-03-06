-- Copyright (c) 2016 Matt Fichman
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
-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
-- IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
-- FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
-- AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
-- LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
-- FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
-- IN THE SOFTWARE.

local ffi = require('ffi')

local Vec3 = require('vec.vec3')
local Quat = require('vec.quat')

local Transform = {}; Transform.__index = Transform
local TransformType = ffi.typeof('vec_Transform')
  
function Transform.new(origin, rotation, scale)
  return TransformType{
    origin = origin or Vec3(), 
    rotation = rotation or Quat.identity(),
    scale = scale or 1,
  }
end

local function multransform(self, other)
  return Transform.new(
    self.rotation * other.origin + self.origin,
    self.rotation * other.rotation,
    self.scale * other.scale
  )
end

local function mulvec3(self, other)
  return (self.rotation * other) + self.origin
end

function Transform:__mul(other)
  if other.new == Transform.new then
    return multransform(self, other)
  elseif other.new == Vec3 then
    return mulvec3(self, other)
  else
    error('invalid multiplicand')
  end
end

ffi.metatype(TransformType, Transform)
return Transform.new
