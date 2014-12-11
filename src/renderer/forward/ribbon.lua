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

local ffi = require('ffi')
local gl = require('gl')
local graphics = require('graphics')
local asset = require('asset')
local struct = require('graphics.struct')

local program, buffer

-- Define the vertex format for OpenGL, and bind it to a new draw buffer
local function createDrawBuffer()
  local buffer = graphics.StreamDrawBuffer()
  gl.glBindVertexArray(buffer.vertexArrayId)
  gl.glBindBuffer(gl.GL_ARRAY_BUFFER, buffer.id)
  struct.defAttribute('graphics_RibbonVertex', 0, 'position')
  struct.defAttribute('graphics_RibbonVertex', 1, 'direction')
  struct.defAttribute('graphics_RibbonVertex', 2, 'index')
  gl.glBindVertexArray(0)
  return buffer
end

-- Render a ribbons to the screen using the streaming draw buffer
local function render(g, ribbon)
  if not ribbon:visible() then return end

  local camera = g.camera
  local texture = ribbon.texture

  program = program or asset.open('shader/forward/Ribbon.prog')
  buffer = buffer or createDrawBuffer()

  g:glUseProgram(program.id)
  g:glEnable(gl.GL_BLEND, gl.GL_DEPTH_TEST)
  g:glDepthMask(gl.GL_FALSE)
  g:glBlendFunc(gl.GL_SRC_ALPHA, gl.GL_ONE)
  g:commit()
  
  gl.glUniform1i(program.tex, 0)
  gl.glActiveTexture(gl.GL_TEXTURE0)
  gl.glBindTexture(gl.GL_TEXTURE_2D, texture.id)

  -- Pass matrices to the vertex shader
  local worldViewMatrix = camera.viewMatrix * g.worldMatrix 
  gl.glUniformMatrix4fv(program.worldViewMatrix, 1, 0, worldViewMatrix:data())
  gl.glUniformMatrix4fv(program.projectionMatrix, 1, 0, camera.projectionMatrix:data())

  gl.glUniform1f(program.width, ribbon.width)
  gl.glUniform1f(program.minWidth, ribbon.minWidth)
  gl.glUniform1i(program.count, math.min(ribbon.tail, ribbon.quota))
  gl.glUniform1i(program.tail, ribbon.tail)

  local normalMatrix = worldViewMatrix:inverse():transpose() 
  local temp = ffi.new('GLfloat[9]', {
    normalMatrix.d00, normalMatrix.d01, normalMatrix.d02, 
    normalMatrix.d04, normalMatrix.d05, normalMatrix.d06, 
    normalMatrix.d08, normalMatrix.d09, normalMatrix.d10, 
  })
  gl.glUniformMatrix3fv(program.normalMatrix, 1, 0, temp)

  -- Render the ribbon
  buffer:draw(gl.GL_TRIANGLES, ribbon.vertex)

end

return {
  render = render,
}
