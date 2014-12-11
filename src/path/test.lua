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

local path = require('path')
assert(path.find('mesh/quad.obj') == './mesh/quad.obj')
assert(path.open('mesh/quad.obj'))
assert(path.join('foo/', 'mesh/quad.obj') == 'foo/mesh/quad.obj')
assert(path.join('foo', 'mesh/quad.obj') == 'foo/mesh/quad.obj')
