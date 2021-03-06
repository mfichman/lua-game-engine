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

local config = require('config')
local vec = require('vec')

local Context = require('graphics.context')

local viewport = vec.Vec2(config.display.width, config.display.height)
local context = Context(viewport.width, viewport.height)

-- Render a graphics node with the given transform. Recursively render any
-- attached children as well.
local function render(node, camera, worldTransform)
  assert(camera.new == require('graphics.camera'))
  context:submit(node, camera, worldTransform)
end

-- Finish rendering the scene.
local function finish()
  context:finish()
end


return {
  Billboard = require('graphics.billboard'),
  Billboards = require('graphics.billboards'),
  Buffer = require('graphics.buffer'),
  Camera = require('graphics.camera'),
  Context = require('graphics.context'),
  DepthRenderTarget = require('graphics.depthrendertarget'),
  Font = require('graphics.font'),
  FrameBuffer = require('graphics.framebuffer'),
  HemiLight = require('graphics.hemilight'),
  Instance = require('graphics.instance'),
  Instances = require('graphics.instances'),
  Line = require('graphics.line'),
  Material = require('graphics.material'),
  Mesh = require('graphics.mesh'),
  Model = require('graphics.model'),
  Particle = require('graphics.particle'),
  Particles = require('graphics.particles'),
  PointLight = require('graphics.pointlight'),
  Program = require('graphics.program'),
  Quad = require('graphics.quad'),
  RenderTarget = require('graphics.rendertarget'),
  Ribbon = require('graphics.ribbon'),
  RibbonVertex = require('graphics.ribbonvertex'),
  Shader = require('graphics.shader'),
  SpotLight = require('graphics.spotlight'),
  StreamDrawBuffer = require('graphics.streamdrawbuffer'),
  Text = require('graphics.text'),
  Texture = require('graphics.texture'),
  Transform = require('graphics.transform'),
  context = context,
  render = render,
  finish = finish,
  viewport = viewport,
}
