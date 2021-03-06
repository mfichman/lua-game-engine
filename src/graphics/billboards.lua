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

local vec = require('vec')
local gl = require('gl')
local geom = require('geom')

local Buffer = require('graphics.buffer')
local Billboard = require('graphics.billboard')

local Billboards = {}; Billboards.__index = Billboards

-- Creates a new set of billboards. Each billboard is a quad that faces in the
-- direction of its normal vector. All billboards use the same texture, blend
-- modes, etc. so that they can all be drawn in the same batch.
function Billboards.new(args)
  assert(args.texture, 'no texture set for billboards')
  local self = {
    width = args.width or 1,
    height = args.height or 1,
    texture = args.texture,
    clearMode = args.clearMode or 'manual',
    blendMode = args.blendMore or 'additive',
    tint = args.tint or vec.Color(1, 1, 1, 1),
    billboard = geom.Buffer('graphics_Billboard')
  }
  return setmetatable(self, Billboards)
end

function Billboards:visible()
  return self.texture and self.billboard.count > 0
end

return Billboards.new
