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

local os = require('os')
local path = require('path')
local string = require('string')

local flags = {}
local linker = {}

local function include(include)
  for i, include in pairs(include) do
    table.insert(flags, string.format('-I%s', include))
  end
end

local function lib(link)
  for i, link in pairs(link) do
    table.insert(linker, string.format('-l%s', link))
  end
end

local function libpath(path)
  for i, path in pairs(path) do
    table.insert(linker, string.format('-L%s', path))
  end
end

local function module(name)
  local source = path.find(string.format('%s/%s.cpp', name, name))
  local lib = source:gsub('.-([^/]*)[.]cpp', function(all)
    return 'lib'..all..'.dylib'
  end)

  os.execute('mkdir -p lib')
  
  local cmd = {}
  table.insert(cmd, 'clang++')
  table.insert(cmd, '-O0 -g -Wno-ignored-attributes -Wno-deprecated-register -std=c++11')
  for i, flag in pairs(flags) do
    table.insert(cmd, flag)
  end
  table.insert(cmd, '-I./src')
  table.insert(cmd, source)
  table.insert(cmd, '-dynamiclib')
  for i, linker in pairs(linker) do
    table.insert(cmd, linker)
  end
  table.insert(cmd, string.format('-olib/%s', lib))

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
