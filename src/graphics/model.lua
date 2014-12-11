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

local Model = {}; Model.__index = Model

function Model.new(args)
  local args = args or {}
  local self = {
    material = args.material,
    mesh = args.mesh,
    program = args.program,
  }
  return setmetatable(self, Model)
end

function Model:clone()
  return Model.new{
    material = self.material:clone(),
    mesh = self.mesh,
    program = self.program,
  }
end

return Model.new
