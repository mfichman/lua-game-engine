typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef __signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef void GLvoid;
typedef double GLdouble;
typedef double GLclampd;
typedef long GLintptr;
typedef long GLsizeiptr;
typedef char GLchar;
typedef unsigned short GLhalf;
typedef int64_t GLint64;
typedef uint64_t GLuint64;
typedef struct __GLsync *GLsync;
typedef int GLfixed;
typedef unsigned short GLhalfARB;
typedef char GLcharARB;
typedef void *GLhandleARB;
typedef long GLintptrARB;
typedef long GLsizeiptrARB;
typedef int64_t GLint64EXT;
typedef uint64_t GLuint64EXT;
void  glCullFace (GLenum mode);
void  glFrontFace (GLenum mode);
void  glHint (GLenum target, GLenum mode);
void  glLineWidth (GLfloat width);
void  glPointSize (GLfloat size);
void  glPolygonMode (GLenum face, GLenum mode);
void  glScissor (GLint x, GLint y, GLsizei width, GLsizei height);
void  glTexParameterf (GLenum target, GLenum pname, GLfloat param);
void  glTexParameterfv (GLenum target, GLenum pname, GLfloat *params);
void  glTexParameteri (GLenum target, GLenum pname, GLint param);
void  glTexParameteriv (GLenum target, GLenum pname, GLint *params);
void  glTexImage1D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid *pixels);
void  glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid *pixels);
void  glDrawBuffer (GLenum mode);
void  glClear (GLbitfield mask);
void  glClearColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void  glClearStencil (GLint s);
void  glClearDepth (GLclampd depth);
void  glStencilMask (GLuint mask);
void  glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void  glDepthMask (GLboolean flag);
void  glDisable (GLenum cap);
void  glEnable (GLenum cap);
void  glFinish (void);
void  glFlush (void);
void  glBlendFunc (GLenum sfactor, GLenum dfactor);
void  glLogicOp (GLenum opcode);
void  glStencilFunc (GLenum func, GLint ref, GLuint mask);
void  glStencilOp (GLenum fail, GLenum zfail, GLenum zpass);
void  glDepthFunc (GLenum func);
void  glPixelStoref (GLenum pname, GLfloat param);
void  glPixelStorei (GLenum pname, GLint param);
void  glReadBuffer (GLenum mode);
void  glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
void  glGetBooleanv (GLenum pname, GLboolean *params);
void  glGetDoublev (GLenum pname, GLdouble *params);
GLenum  glGetError (void);
void  glGetFloatv (GLenum pname, GLfloat *params);
void  glGetIntegerv (GLenum pname, GLint *params);
GLubyte *  glGetString (GLenum name);
void  glGetTexImage (GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
void  glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params);
void  glGetTexParameteriv (GLenum target, GLenum pname, GLint *params);
void  glGetTexLevelParameterfv (GLenum target, GLint level, GLenum pname, GLfloat *params);
void  glGetTexLevelParameteriv (GLenum target, GLint level, GLenum pname, GLint *params);
GLboolean  glIsEnabled (GLenum cap);
void  glDepthRange (GLclampd near, GLclampd far);
void  glViewport (GLint x, GLint y, GLsizei width, GLsizei height);
void  glDrawArrays (GLenum mode, GLint first, GLsizei count);
void  glDrawElements (GLenum mode, GLsizei count, GLenum type, GLvoid *indices);
void  glPolygonOffset (GLfloat factor, GLfloat units);
void  glCopyTexImage1D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void  glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void  glCopyTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void  glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void  glTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid *pixels);
void  glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
void  glBindTexture (GLenum target, GLuint texture);
void  glDeleteTextures (GLsizei n, GLuint *textures);
void  glGenTextures (GLsizei n, GLuint *textures);
GLboolean  glIsTexture (GLuint texture);
void  glBlendColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void  glBlendEquation (GLenum mode);
void  glDrawRangeElements (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid *indices);
void  glTexImage3D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid *pixels);
void  glTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid *pixels);
void  glCopyTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void  glActiveTexture (GLenum texture);
void  glSampleCoverage (GLclampf value, GLboolean invert);
void  glCompressedTexImage3D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid *data);
void  glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid *data);
void  glCompressedTexImage1D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid *data);
void  glCompressedTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid *data);
void  glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid *data);
void  glCompressedTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid *data);
void  glGetCompressedTexImage (GLenum target, GLint level, GLvoid *img);
void  glBlendFuncSeparate (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void  glMultiDrawArrays (GLenum mode, GLint *first, GLsizei *count, GLsizei drawcount);
void  glMultiDrawElements (GLenum mode, GLsizei *count, GLenum type, GLvoid* *indices, GLsizei drawcount);
void  glPointParameterf (GLenum pname, GLfloat param);
void  glPointParameterfv (GLenum pname, GLfloat *params);
void  glPointParameteri (GLenum pname, GLint param);
void  glPointParameteriv (GLenum pname, GLint *params);
void  glGenQueries (GLsizei n, GLuint *ids);
void  glDeleteQueries (GLsizei n, GLuint *ids);
GLboolean  glIsQuery (GLuint id);
void  glBeginQuery (GLenum target, GLuint id);
void  glEndQuery (GLenum target);
void  glGetQueryiv (GLenum target, GLenum pname, GLint *params);
void  glGetQueryObjectiv (GLuint id, GLenum pname, GLint *params);
void  glGetQueryObjectuiv (GLuint id, GLenum pname, GLuint *params);
void  glBindBuffer (GLenum target, GLuint buffer);
void  glDeleteBuffers (GLsizei n, GLuint *buffers);
void  glGenBuffers (GLsizei n, GLuint *buffers);
GLboolean  glIsBuffer (GLuint buffer);
void  glBufferData (GLenum target, GLsizeiptr size, GLvoid *data, GLenum usage);
void  glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data);
void  glGetBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data);
GLvoid*  glMapBuffer (GLenum target, GLenum access);
GLboolean  glUnmapBuffer (GLenum target);
void  glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params);
void  glGetBufferPointerv (GLenum target, GLenum pname, GLvoid* *params);
void  glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha);
void  glDrawBuffers (GLsizei n, GLenum *bufs);
void  glStencilOpSeparate (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
void  glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask);
void  glStencilMaskSeparate (GLenum face, GLuint mask);
void  glAttachShader (GLuint program, GLuint shader);
void  glBindAttribLocation (GLuint program, GLuint index, GLchar *name);
void  glCompileShader (GLuint shader);
GLuint  glCreateProgram (void);
GLuint  glCreateShader (GLenum type);
void  glDeleteProgram (GLuint program);
void  glDeleteShader (GLuint shader);
void  glDetachShader (GLuint program, GLuint shader);
void  glDisableVertexAttribArray (GLuint index);
void  glEnableVertexAttribArray (GLuint index);
void  glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
void  glGetActiveUniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
void  glGetAttachedShaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
GLint  glGetAttribLocation (GLuint program, GLchar *name);
void  glGetProgramiv (GLuint program, GLenum pname, GLint *params);
void  glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
void  glGetShaderiv (GLuint shader, GLenum pname, GLint *params);
void  glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
void  glGetShaderSource (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
GLint  glGetUniformLocation (GLuint program, GLchar *name);
void  glGetUniformfv (GLuint program, GLint location, GLfloat *params);
void  glGetUniformiv (GLuint program, GLint location, GLint *params);
void  glGetVertexAttribdv (GLuint index, GLenum pname, GLdouble *params);
void  glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params);
void  glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params);
void  glGetVertexAttribPointerv (GLuint index, GLenum pname, GLvoid* *pointer);
GLboolean  glIsProgram (GLuint program);
GLboolean  glIsShader (GLuint shader);
void  glLinkProgram (GLuint program);
void  glShaderSource (GLuint shader, GLsizei count, GLchar* *string, GLint *length);
void  glUseProgram (GLuint program);
void  glUniform1f (GLint location, GLfloat v0);
void  glUniform2f (GLint location, GLfloat v0, GLfloat v1);
void  glUniform3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void  glUniform4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void  glUniform1i (GLint location, GLint v0);
void  glUniform2i (GLint location, GLint v0, GLint v1);
void  glUniform3i (GLint location, GLint v0, GLint v1, GLint v2);
void  glUniform4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void  glUniform1fv (GLint location, GLsizei count, GLfloat *value);
void  glUniform2fv (GLint location, GLsizei count, GLfloat *value);
void  glUniform3fv (GLint location, GLsizei count, GLfloat *value);
void  glUniform4fv (GLint location, GLsizei count, GLfloat *value);
void  glUniform1iv (GLint location, GLsizei count, GLint *value);
void  glUniform2iv (GLint location, GLsizei count, GLint *value);
void  glUniform3iv (GLint location, GLsizei count, GLint *value);
void  glUniform4iv (GLint location, GLsizei count, GLint *value);
void  glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glValidateProgram (GLuint program);
void  glVertexAttrib1d (GLuint index, GLdouble x);
void  glVertexAttrib1dv (GLuint index, GLdouble *v);
void  glVertexAttrib1f (GLuint index, GLfloat x);
void  glVertexAttrib1fv (GLuint index, GLfloat *v);
void  glVertexAttrib1s (GLuint index, GLshort x);
void  glVertexAttrib1sv (GLuint index, GLshort *v);
void  glVertexAttrib2d (GLuint index, GLdouble x, GLdouble y);
void  glVertexAttrib2dv (GLuint index, GLdouble *v);
void  glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y);
void  glVertexAttrib2fv (GLuint index, GLfloat *v);
void  glVertexAttrib2s (GLuint index, GLshort x, GLshort y);
void  glVertexAttrib2sv (GLuint index, GLshort *v);
void  glVertexAttrib3d (GLuint index, GLdouble x, GLdouble y, GLdouble z);
void  glVertexAttrib3dv (GLuint index, GLdouble *v);
void  glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z);
void  glVertexAttrib3fv (GLuint index, GLfloat *v);
void  glVertexAttrib3s (GLuint index, GLshort x, GLshort y, GLshort z);
void  glVertexAttrib3sv (GLuint index, GLshort *v);
void  glVertexAttrib4Nbv (GLuint index, GLbyte *v);
void  glVertexAttrib4Niv (GLuint index, GLint *v);
void  glVertexAttrib4Nsv (GLuint index, GLshort *v);
void  glVertexAttrib4Nub (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
void  glVertexAttrib4Nubv (GLuint index, GLubyte *v);
void  glVertexAttrib4Nuiv (GLuint index, GLuint *v);
void  glVertexAttrib4Nusv (GLuint index, GLushort *v);
void  glVertexAttrib4bv (GLuint index, GLbyte *v);
void  glVertexAttrib4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void  glVertexAttrib4dv (GLuint index, GLdouble *v);
void  glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void  glVertexAttrib4fv (GLuint index, GLfloat *v);
void  glVertexAttrib4iv (GLuint index, GLint *v);
void  glVertexAttrib4s (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
void  glVertexAttrib4sv (GLuint index, GLshort *v);
void  glVertexAttrib4ubv (GLuint index, GLubyte *v);
void  glVertexAttrib4uiv (GLuint index, GLuint *v);
void  glVertexAttrib4usv (GLuint index, GLushort *v);
void  glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid *pointer);
void  glUniformMatrix2x3fv (GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glUniformMatrix3x2fv (GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glUniformMatrix2x4fv (GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glUniformMatrix4x2fv (GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glUniformMatrix3x4fv (GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glUniformMatrix4x3fv (GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glColorMaski (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
void  glGetBooleani_v (GLenum target, GLuint index, GLboolean *data);
void  glGetIntegeri_v (GLenum target, GLuint index, GLint *data);
void  glEnablei (GLenum target, GLuint index);
void  glDisablei (GLenum target, GLuint index);
GLboolean  glIsEnabledi (GLenum target, GLuint index);
void  glBeginTransformFeedback (GLenum primitiveMode);
void  glEndTransformFeedback (void);
void  glBindBufferRange (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
void  glBindBufferBase (GLenum target, GLuint index, GLuint buffer);
void  glTransformFeedbackVaryings (GLuint program, GLsizei count, GLchar* *varyings, GLenum bufferMode);
void  glGetTransformFeedbackVarying (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
void  glClampColor (GLenum target, GLenum clamp);
void  glBeginConditionalRender (GLuint id, GLenum mode);
void  glEndConditionalRender (void);
void  glVertexAttribIPointer (GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid *pointer);
void  glGetVertexAttribIiv (GLuint index, GLenum pname, GLint *params);
void  glGetVertexAttribIuiv (GLuint index, GLenum pname, GLuint *params);
void  glVertexAttribI1i (GLuint index, GLint x);
void  glVertexAttribI2i (GLuint index, GLint x, GLint y);
void  glVertexAttribI3i (GLuint index, GLint x, GLint y, GLint z);
void  glVertexAttribI4i (GLuint index, GLint x, GLint y, GLint z, GLint w);
void  glVertexAttribI1ui (GLuint index, GLuint x);
void  glVertexAttribI2ui (GLuint index, GLuint x, GLuint y);
void  glVertexAttribI3ui (GLuint index, GLuint x, GLuint y, GLuint z);
void  glVertexAttribI4ui (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
void  glVertexAttribI1iv (GLuint index, GLint *v);
void  glVertexAttribI2iv (GLuint index, GLint *v);
void  glVertexAttribI3iv (GLuint index, GLint *v);
void  glVertexAttribI4iv (GLuint index, GLint *v);
void  glVertexAttribI1uiv (GLuint index, GLuint *v);
void  glVertexAttribI2uiv (GLuint index, GLuint *v);
void  glVertexAttribI3uiv (GLuint index, GLuint *v);
void  glVertexAttribI4uiv (GLuint index, GLuint *v);
void  glVertexAttribI4bv (GLuint index, GLbyte *v);
void  glVertexAttribI4sv (GLuint index, GLshort *v);
void  glVertexAttribI4ubv (GLuint index, GLubyte *v);
void  glVertexAttribI4usv (GLuint index, GLushort *v);
void  glGetUniformuiv (GLuint program, GLint location, GLuint *params);
void  glBindFragDataLocation (GLuint program, GLuint color, GLchar *name);
GLint  glGetFragDataLocation (GLuint program, GLchar *name);
void  glUniform1ui (GLint location, GLuint v0);
void  glUniform2ui (GLint location, GLuint v0, GLuint v1);
void  glUniform3ui (GLint location, GLuint v0, GLuint v1, GLuint v2);
void  glUniform4ui (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void  glUniform1uiv (GLint location, GLsizei count, GLuint *value);
void  glUniform2uiv (GLint location, GLsizei count, GLuint *value);
void  glUniform3uiv (GLint location, GLsizei count, GLuint *value);
void  glUniform4uiv (GLint location, GLsizei count, GLuint *value);
void  glTexParameterIiv (GLenum target, GLenum pname, GLint *params);
void  glTexParameterIuiv (GLenum target, GLenum pname, GLuint *params);
void  glGetTexParameterIiv (GLenum target, GLenum pname, GLint *params);
void  glGetTexParameterIuiv (GLenum target, GLenum pname, GLuint *params);
void  glClearBufferiv (GLenum buffer, GLint drawbuffer, GLint *value);
void  glClearBufferuiv (GLenum buffer, GLint drawbuffer, GLuint *value);
void  glClearBufferfv (GLenum buffer, GLint drawbuffer, GLfloat *value);
void  glClearBufferfi (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLubyte *  glGetStringi (GLenum name, GLuint index);
void  glDrawArraysInstanced (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
void  glDrawElementsInstanced (GLenum mode, GLsizei count, GLenum type, GLvoid *indices, GLsizei instancecount);
void  glTexBuffer (GLenum target, GLenum internalformat, GLuint buffer);
void  glPrimitiveRestartIndex (GLuint index);
void  glGetInteger64i_v (GLenum target, GLuint index, GLint64 *data);
void  glGetBufferParameteri64v (GLenum target, GLenum pname, GLint64 *params);
void  glFramebufferTexture (GLenum target, GLenum attachment, GLuint texture, GLint level);
void  glVertexAttribDivisor (GLuint index, GLuint divisor);
void  glMinSampleShading (GLfloat value);
void  glBlendEquationi (GLuint buf, GLenum mode);
void  glBlendEquationSeparatei (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void  glBlendFunci (GLuint buf, GLenum src, GLenum dst);
void  glBlendFuncSeparatei (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GLboolean  glIsRenderbuffer (GLuint renderbuffer);
void  glBindRenderbuffer (GLenum target, GLuint renderbuffer);
void  glDeleteRenderbuffers (GLsizei n, GLuint *renderbuffers);
void  glGenRenderbuffers (GLsizei n, GLuint *renderbuffers);
void  glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void  glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint *params);
GLboolean  glIsFramebuffer (GLuint framebuffer);
void  glBindFramebuffer (GLenum target, GLuint framebuffer);
void  glDeleteFramebuffers (GLsizei n, GLuint *framebuffers);
void  glGenFramebuffers (GLsizei n, GLuint *framebuffers);
GLenum  glCheckFramebufferStatus (GLenum target);
void  glFramebufferTexture1D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void  glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void  glFramebufferTexture3D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
void  glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void  glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint *params);
void  glGenerateMipmap (GLenum target);
void  glBlitFramebuffer (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
void  glRenderbufferStorageMultisample (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
void  glFramebufferTextureLayer (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLvoid*  glMapBufferRange (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
void  glFlushMappedBufferRange (GLenum target, GLintptr offset, GLsizeiptr length);
void  glBindVertexArray (GLuint array);
void  glDeleteVertexArrays (GLsizei n, GLuint *arrays);
void  glGenVertexArrays (GLsizei n, GLuint *arrays);
GLboolean  glIsVertexArray (GLuint array);
void  glGetUniformIndices (GLuint program, GLsizei uniformCount, GLchar* *uniformNames, GLuint *uniformIndices);
void  glGetActiveUniformsiv (GLuint program, GLsizei uniformCount, GLuint *uniformIndices, GLenum pname, GLint *params);
void  glGetActiveUniformName (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
GLuint  glGetUniformBlockIndex (GLuint program, GLchar *uniformBlockName);
void  glGetActiveUniformBlockiv (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
void  glGetActiveUniformBlockName (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
void  glUniformBlockBinding (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
void  glCopyBufferSubData (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
void  glDrawElementsBaseVertex (GLenum mode, GLsizei count, GLenum type, GLvoid *indices, GLint basevertex);
void  glDrawRangeElementsBaseVertex (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid *indices, GLint basevertex);
void  glDrawElementsInstancedBaseVertex (GLenum mode, GLsizei count, GLenum type, GLvoid *indices, GLsizei instancecount, GLint basevertex);
void  glMultiDrawElementsBaseVertex (GLenum mode, GLsizei *count, GLenum type, GLvoid* *indices, GLsizei drawcount, GLint *basevertex);
void  glProvokingVertex (GLenum mode);
GLsync  glFenceSync (GLenum condition, GLbitfield flags);
GLboolean  glIsSync (GLsync sync);
void  glDeleteSync (GLsync sync);
GLenum  glClientWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout);
void  glWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout);
void  glGetInteger64v (GLenum pname, GLint64 *params);
void  glGetSynciv (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
void  glTexImage2DMultisample (GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void  glTexImage3DMultisample (GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
void  glGetMultisamplefv (GLenum pname, GLuint index, GLfloat *val);
void  glSampleMaski (GLuint index, GLbitfield mask);
void  glBindFragDataLocationIndexed (GLuint program, GLuint colorNumber, GLuint index, GLchar *name);
GLint  glGetFragDataIndex (GLuint program, GLchar *name);
void  glGenSamplers (GLsizei count, GLuint *samplers);
void  glDeleteSamplers (GLsizei count, GLuint *samplers);
GLboolean  glIsSampler (GLuint sampler);
void  glBindSampler (GLuint unit, GLuint sampler);
void  glSamplerParameteri (GLuint sampler, GLenum pname, GLint param);
void  glSamplerParameteriv (GLuint sampler, GLenum pname, GLint *param);
void  glSamplerParameterf (GLuint sampler, GLenum pname, GLfloat param);
void  glSamplerParameterfv (GLuint sampler, GLenum pname, GLfloat *param);
void  glSamplerParameterIiv (GLuint sampler, GLenum pname, GLint *param);
void  glSamplerParameterIuiv (GLuint sampler, GLenum pname, GLuint *param);
void  glGetSamplerParameteriv (GLuint sampler, GLenum pname, GLint *params);
void  glGetSamplerParameterIiv (GLuint sampler, GLenum pname, GLint *params);
void  glGetSamplerParameterfv (GLuint sampler, GLenum pname, GLfloat *params);
void  glGetSamplerParameterIuiv (GLuint sampler, GLenum pname, GLuint *params);
void  glQueryCounter (GLuint id, GLenum target);
void  glGetQueryObjecti64v (GLuint id, GLenum pname, GLint64 *params);
void  glGetQueryObjectui64v (GLuint id, GLenum pname, GLuint64 *params);
void  glVertexAttribP1ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
void  glVertexAttribP1uiv (GLuint index, GLenum type, GLboolean normalized, GLuint *value);
void  glVertexAttribP2ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
void  glVertexAttribP2uiv (GLuint index, GLenum type, GLboolean normalized, GLuint *value);
void  glVertexAttribP3ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
void  glVertexAttribP3uiv (GLuint index, GLenum type, GLboolean normalized, GLuint *value);
void  glVertexAttribP4ui (GLuint index, GLenum type, GLboolean normalized, GLuint value);
void  glVertexAttribP4uiv (GLuint index, GLenum type, GLboolean normalized, GLuint *value);
void  glDrawArraysIndirect (GLenum mode, GLvoid *indirect);
void  glDrawElementsIndirect (GLenum mode, GLenum type, GLvoid *indirect);
void  glUniform1d (GLint location, GLdouble x);
void  glUniform2d (GLint location, GLdouble x, GLdouble y);
void  glUniform3d (GLint location, GLdouble x, GLdouble y, GLdouble z);
void  glUniform4d (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void  glUniform1dv (GLint location, GLsizei count, GLdouble *value);
void  glUniform2dv (GLint location, GLsizei count, GLdouble *value);
void  glUniform3dv (GLint location, GLsizei count, GLdouble *value);
void  glUniform4dv (GLint location, GLsizei count, GLdouble *value);
void  glUniformMatrix2dv (GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glUniformMatrix3dv (GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glUniformMatrix4dv (GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glUniformMatrix2x3dv (GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glUniformMatrix2x4dv (GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glUniformMatrix3x2dv (GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glUniformMatrix3x4dv (GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glUniformMatrix4x2dv (GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glUniformMatrix4x3dv (GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glGetUniformdv (GLuint program, GLint location, GLdouble *params);
GLint  glGetSubroutineUniformLocation (GLuint program, GLenum shadertype, GLchar *name);
GLuint  glGetSubroutineIndex (GLuint program, GLenum shadertype, GLchar *name);
void  glGetActiveSubroutineUniformiv (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
void  glGetActiveSubroutineUniformName (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
void  glGetActiveSubroutineName (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
void  glUniformSubroutinesuiv (GLenum shadertype, GLsizei count, GLuint *indices);
void  glGetUniformSubroutineuiv (GLenum shadertype, GLint location, GLuint *params);
void  glGetProgramStageiv (GLuint program, GLenum shadertype, GLenum pname, GLint *values);
void  glPatchParameteri (GLenum pname, GLint value);
void  glPatchParameterfv (GLenum pname, GLfloat *values);
void  glBindTransformFeedback (GLenum target, GLuint id);
void  glDeleteTransformFeedbacks (GLsizei n, GLuint *ids);
void  glGenTransformFeedbacks (GLsizei n, GLuint *ids);
GLboolean  glIsTransformFeedback (GLuint id);
void  glPauseTransformFeedback (void);
void  glResumeTransformFeedback (void);
void  glDrawTransformFeedback (GLenum mode, GLuint id);
void  glDrawTransformFeedbackStream (GLenum mode, GLuint id, GLuint stream);
void  glBeginQueryIndexed (GLenum target, GLuint index, GLuint id);
void  glEndQueryIndexed (GLenum target, GLuint index);
void  glGetQueryIndexediv (GLenum target, GLuint index, GLenum pname, GLint *params);
void  glReleaseShaderCompiler (void);
void  glShaderBinary (GLsizei count, GLuint *shaders, GLenum binaryformat, GLvoid *binary, GLsizei length);
void  glGetShaderPrecisionFormat (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
void  glDepthRangef (GLclampf n, GLclampf f);
void  glClearDepthf (GLclampf d);
void  glGetProgramBinary (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, GLvoid *binary);
void  glProgramBinary (GLuint program, GLenum binaryFormat, GLvoid *binary, GLsizei length);
void  glProgramParameteri (GLuint program, GLenum pname, GLint value);
void  glUseProgramStages (GLuint pipeline, GLbitfield stages, GLuint program);
void  glActiveShaderProgram (GLuint pipeline, GLuint program);
GLuint  glCreateShaderProgramv (GLenum type, GLsizei count, GLchar* *strings);
void  glBindProgramPipeline (GLuint pipeline);
void  glDeleteProgramPipelines (GLsizei n, GLuint *pipelines);
void  glGenProgramPipelines (GLsizei n, GLuint *pipelines);
GLboolean  glIsProgramPipeline (GLuint pipeline);
void  glGetProgramPipelineiv (GLuint pipeline, GLenum pname, GLint *params);
void  glProgramUniform1i (GLuint program, GLint location, GLint v0);
void  glProgramUniform1iv (GLuint program, GLint location, GLsizei count, GLint *value);
void  glProgramUniform1f (GLuint program, GLint location, GLfloat v0);
void  glProgramUniform1fv (GLuint program, GLint location, GLsizei count, GLfloat *value);
void  glProgramUniform1d (GLuint program, GLint location, GLdouble v0);
void  glProgramUniform1dv (GLuint program, GLint location, GLsizei count, GLdouble *value);
void  glProgramUniform1ui (GLuint program, GLint location, GLuint v0);
void  glProgramUniform1uiv (GLuint program, GLint location, GLsizei count, GLuint *value);
void  glProgramUniform2i (GLuint program, GLint location, GLint v0, GLint v1);
void  glProgramUniform2iv (GLuint program, GLint location, GLsizei count, GLint *value);
void  glProgramUniform2f (GLuint program, GLint location, GLfloat v0, GLfloat v1);
void  glProgramUniform2fv (GLuint program, GLint location, GLsizei count, GLfloat *value);
void  glProgramUniform2d (GLuint program, GLint location, GLdouble v0, GLdouble v1);
void  glProgramUniform2dv (GLuint program, GLint location, GLsizei count, GLdouble *value);
void  glProgramUniform2ui (GLuint program, GLint location, GLuint v0, GLuint v1);
void  glProgramUniform2uiv (GLuint program, GLint location, GLsizei count, GLuint *value);
void  glProgramUniform3i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
void  glProgramUniform3iv (GLuint program, GLint location, GLsizei count, GLint *value);
void  glProgramUniform3f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void  glProgramUniform3fv (GLuint program, GLint location, GLsizei count, GLfloat *value);
void  glProgramUniform3d (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
void  glProgramUniform3dv (GLuint program, GLint location, GLsizei count, GLdouble *value);
void  glProgramUniform3ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
void  glProgramUniform3uiv (GLuint program, GLint location, GLsizei count, GLuint *value);
void  glProgramUniform4i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void  glProgramUniform4iv (GLuint program, GLint location, GLsizei count, GLint *value);
void  glProgramUniform4f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void  glProgramUniform4fv (GLuint program, GLint location, GLsizei count, GLfloat *value);
void  glProgramUniform4d (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
void  glProgramUniform4dv (GLuint program, GLint location, GLsizei count, GLdouble *value);
void  glProgramUniform4ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void  glProgramUniform4uiv (GLuint program, GLint location, GLsizei count, GLuint *value);
void  glProgramUniformMatrix2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glProgramUniformMatrix3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glProgramUniformMatrix4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glProgramUniformMatrix2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glProgramUniformMatrix3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glProgramUniformMatrix4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glProgramUniformMatrix2x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glProgramUniformMatrix3x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glProgramUniformMatrix2x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glProgramUniformMatrix4x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glProgramUniformMatrix3x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glProgramUniformMatrix4x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat *value);
void  glProgramUniformMatrix2x3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glProgramUniformMatrix3x2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glProgramUniformMatrix2x4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glProgramUniformMatrix4x2dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glProgramUniformMatrix3x4dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glProgramUniformMatrix4x3dv (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble *value);
void  glValidateProgramPipeline (GLuint pipeline);
void  glGetProgramPipelineInfoLog (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
void  glVertexAttribL1d (GLuint index, GLdouble x);
void  glVertexAttribL2d (GLuint index, GLdouble x, GLdouble y);
void  glVertexAttribL3d (GLuint index, GLdouble x, GLdouble y, GLdouble z);
void  glVertexAttribL4d (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void  glVertexAttribL1dv (GLuint index, GLdouble *v);
void  glVertexAttribL2dv (GLuint index, GLdouble *v);
void  glVertexAttribL3dv (GLuint index, GLdouble *v);
void  glVertexAttribL4dv (GLuint index, GLdouble *v);
void  glVertexAttribLPointer (GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid *pointer);
void  glGetVertexAttribLdv (GLuint index, GLenum pname, GLdouble *params);
void  glViewportArrayv (GLuint first, GLsizei count, GLfloat *v);
void  glViewportIndexedf (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
void  glViewportIndexedfv (GLuint index, GLfloat *v);
void  glScissorArrayv (GLuint first, GLsizei count, GLint *v);
void  glScissorIndexed (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
void  glScissorIndexedv (GLuint index, GLint *v);
void  glDepthRangeArrayv (GLuint first, GLsizei count, GLclampd *v);
void  glDepthRangeIndexed (GLuint index, GLclampd n, GLclampd f);
void  glGetFloati_v (GLenum target, GLuint index, GLfloat *data);
void  glGetDoublei_v (GLenum target, GLuint index, GLdouble *data);
