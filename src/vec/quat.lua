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
local math = require('math')

local Quat = {}; Quat.__index = Quat
local QuatType = ffi.typeof('vec_Quat')
local Vec3 = require('vec.vec3')

Quat.new = QuatType

function Quat.identity() 
  return Quat.new(1, 0, 0, 0)
end

function Quat.fromAxisAngle(axis, angle)
  return Quat.new{
    w = math.cos(angle/2),
    x = math.sin(angle/2)*axis.x,
    y = math.sin(angle/2)*axis.y,
    z = math.sin(angle/2)*axis.z,
  }
end

function Quat.fromVectors(a, b)
  local cross = a:cross(b)

  local ret = Quat.new{
    w = math.sqrt(a:len2() * b:len2()) + a:dot(b),
    x = cross.x,
    y = cross.y,
    z = cross.z,
  }

  return ret:unit()
end

function Quat.lookAt(xaxis, yaxis, zaxis)
  assert(false)
end

function Quat:len(other)
  return math.sqrt(self:len2())
end

function Quat:len2(other)
  return self:dot(self)
end

function Quat:unit()
  local norm = self:len()
  return Quat.new(self.w/norm, self.x/norm, self.y/norm, self.z/norm)
end

function Quat:dot(other)
  return self.w*other.w + self.x*other.x + self.y*other.y + self.z*other.z
end

function Quat:slerp(other, alpha) 
  local cos = self:dot(other)
  local rkt = Quat.new()

  if cos < 0 then
      cos = -cos;
      rkt = Quat.new(-other.w, -other.x, -other.y, -other.z)
  else
      rkt = other
  end

  if math.abs(cos) < (1-1e-03) then
      local sin = math.sqrt(1-cos*cos)
      local angle = math.atan2(sin, cos)
      local invsin = 1/sin
      local coeff0 = math.sin((1-alpha) * angle) * invsin
      local coeff1 = math.sin(alpha * angle) * invsin
      return self*coeff0 + rkt*coeff1
  else
      return (self*(1-alpha) + rkt*alpha):unit();
  end
end

local function mulquat(self, q)
  local out = Quat.new()
  out.w = self.w*q.w - self.x*q.x - self.y*q.y - self.z*q.z
  out.x = self.w*q.x + self.x*q.w + self.y*q.z - self.z*q.y
  out.y = self.w*q.y + self.y*q.w + self.z*q.x - self.x*q.z
  out.z = self.w*q.z + self.z*q.w + self.x*q.y - self.y*q.x
  return out
end

local function mulvec3(self, v)
  local qv = Vec3(self.x, self.y, self.z)
  local uv = qv:cross(v)
  local uuv = qv:cross(uv)
  return v+((uv*self.w)+uuv)*2
end

function Quat:__add(other)
  return Quat.new(self.w+other.w, self.x+other.x, self.y+other.y, self.z+other.z)
end

function Quat:__mul(other)
  if type(other) == 'number' then
    return Quat.new(self.w*other, self.x*other, self.y*other, self.z*other)
  elseif other.new == Quat.new then
    return mulquat(self, other)
  elseif other.new == Vec3 then
    return mulvec3(self, other)
  else
    assert(false, 'invalid multiplicand')
  end
end

function Quat:__tostring()
  return string.format('%f, %f, %f, %f', self.w, self.x, self.y, self.z)
end

function Quat:__eq(other)
  return self.x == other.x and self.y == other.y and self.z == other.z and self.w == other.w
end

ffi.metatype(QuatType, Quat)
return Quat
