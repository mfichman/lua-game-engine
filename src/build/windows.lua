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

local os = require('os')
local path = require('path')
local string = require('string')

local flags = {}
local linker = {}

local function include(include)
  for i, include in pairs(include) do
    table.insert(flags, string.format('/I%s', include))
  end
end

local function lib(link)
  for i, link in pairs(link) do
    table.insert(linker, string.format('%s.lib', link))
  end
end

local function libpath(path)
  for i, path in pairs(path) do
    table.insert(linker, string.format('/LIBPATH:%s', path))
  end
end

local function module(name)
  local source = path.find(string.format('%s/%s.cpp', name, name))
  local lib = source:gsub('.-([^/]*)[.]cpp', function(all)
    return all..'.dll'
  end)

  os.execute('mkdir lib')
  os.execute('mkdir bld')

  local cmd = {}
  table.insert(cmd, 'cl')
  table.insert(cmd, '/nologo /MD /EHsc /Zi /Gm /FS /O2')
  for i, flag in pairs(flags) do
    table.insert(cmd, flag)
  end
  table.insert(cmd, string.format('/Fo:bld/%s.obj', name))
  table.insert(cmd, string.format('/Fd:bld/vs.pdb', name))
  table.insert(cmd, '/I./src')
  table.insert(cmd, source)
  table.insert(cmd, '/link')
  for i, linker in pairs(linker) do
    table.insert(cmd, linker)
  end
  table.insert(cmd, '/dll')
  table.insert(cmd, string.format('/out:lib/%s', lib))

  local cmd = table.concat(cmd, ' ')
  print(cmd)
  os.execute(cmd)
end


return {
  libpath = libpath,
  lib = lib,
  include = include,
  module = module,
}
