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
local path = require('path')

ffi.cdef(path.open('blob/blob.h'):read('*all'))

local blob = path.load('blob')

-- Libary for managing and sharing large binary objects in Lua between multiple
-- Lua interpreters within the same process. All BLOBs are owned via the blob
-- interface.

local function new(kind, len)
  local len = ffi.sizeof(kind, len)
  local kind = tostring(kind):gsub('ctype<(.+) %[%?%]>','%1*')
  local kind = ffi.typeof(kind)
  return ffi.gc(ffi.cast(kind, blob.blob_Ref_new(len)), blob.blob_Ref_del)
end

local function id(ref)
  return blob.blob_Ref_id(ref)
end

local function find(kind, id)
  local kind = tostring(kind):gsub('ctype<(.*) %[%?%]>','%1*')
  local kind = ffi.typeof(kind)
  return ffi.gc(ffi.cast(kind, blob.blob_Ref_find(id)), blob.blob_Ref_del)
end

return {
  new = new,
  find = find,
  id = id,
}


