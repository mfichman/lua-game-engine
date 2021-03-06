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
local gl = require('gl')

local FrameBuffer = {}; FrameBuffer.__index = FrameBuffer

local MAXDRAWBUFFER = 8

-- Manages an offscreen frame buffer
function FrameBuffer.new() 
  local self = {
    drawBuffer = {},
    drawBufferAttachment = ffi.new('GLint[?]', MAXDRAWBUFFER),
    drawBufferAttachmentCount = 0,
    handle = gl.Handle(gl.glGenFramebuffers, gl.glDeleteFramebuffers),
    id = 0,
  }
  self.id = self.handle[0]
  return setmetatable(self, FrameBuffer)
end

function FrameBuffer:drawBufferEnq(target) 
  assert((#self.drawBuffer+1) < MAXDRAWBUFFER)
  local attachment = gl.GL_COLOR_ATTACHMENT0 + #self.drawBuffer
  table.insert(self.drawBuffer, target)
  self.drawBufferAttachment[self.drawBufferAttachmentCount] = attachment
  self.drawBufferAttachmentCount = self.drawBufferAttachmentCount + 1

  gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, self.id)
  gl.glFramebufferTexture2D(gl.GL_FRAMEBUFFER, attachment, target.target, target.id, 0)
  gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, 0)
end

function FrameBuffer:depthBufferIs(target)
  assert(not self.depthBuffer, 'depth buffer already attached')
  self.depthBuffer = target

  gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, self.id)
  gl.glFramebufferTexture2D(gl.GL_FRAMEBUFFER, gl.GL_DEPTH_ATTACHMENT, target.target, target.id, 0)
  gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, 0)
end

function FrameBuffer:stencilBufferIs(target)
  assert(not self.stencilBuffer, 'stencil buffer already attached')
  self.stencilBuffer = target

  gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, self.id)
  gl.glFramebufferTexture2D(gl.GL_FRAMEBUFFER, gl.GL_STENCIL_ATTACHMENT, target.target,  target.id, 0)
  gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, 0) 
end

function FrameBuffer:check() 
  self:enable()
  local status = gl.glCheckFramebufferStatus(gl.GL_FRAMEBUFFER)
  if status == gl.GL_FRAMEBUFFER_COMPLETE then
    -- OK
  elseif status == gl.GL_FRAMEBUFFER_UNDEFINED then
    error('undefined')
  elseif status == gl.GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE then
    error('incomplete multisample')
  elseif status == gl.GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT then
    error('incomplete attachment')
  elseif status == gl.GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER then
    error('incomplete read buffer')
  elseif status == gl.GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT then
    error('incomplete missing attachment')
  elseif status == gl.GL_FRAMEBUFFER_UNSUPPORTED then
    error('incomplete unsupported')
  else
    error('unknown')
  end
  gl.glDrawBuffers(self.drawBufferAttachmentCount, self.drawBufferAttachment)
  self:disable()
end

function FrameBuffer:enable()
  gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, self.id) 
end

function FrameBuffer:disable()
  gl.glBindFramebuffer(gl.GL_FRAMEBUFFER, 0)
end

return FrameBuffer.new
