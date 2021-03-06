SUBDIRS = shaders baseline

AM_CPPFLAGS = -I.. @XML2_CFLAGS@ @GL_CFLAGS@ @GDK_PIXBUF_CFLAGS@

if APPLE
    GL_SOURCES = CGLContext.cpp PBO.cpp AppleDisplay.cpp
    GL_INCLUDES = CGLContext.h PBO.h AppleDisplay.h
else
if ENABLE_RPI
    GL_SOURCES = EGLContext.cpp BCMDisplay.cpp
    GL_INCLUDES = EGLContext.h BCMDisplay.h
else
if ENABLE_EGL
    GL_SOURCES = EGLContext.cpp X11Display.cpp
    GL_INCLUDES = EGLContext.h X11Display.h
else
    GL_SOURCES = GLXContext.cpp PBO.cpp X11Display.cpp
    GL_INCLUDES = GLXContext.h PBO.h X11Display.h
endif
endif
endif

ALL_H = Bitmap.h Filter.h GLContext.h GLContextAttribs.h GLContextManager.h \
        Pixel32.h Pixel24.h Pixel16.h Pixel8.h Pixeldefs.h PixelFormat.h \
        Filtercolorize.h Filterfill.h Filterfillrect.h Filterflip.h FilterflipX.h \
        Filterfliprgb.h Filterflipuv.h Filtergrayscale.h Filter3x3.h \
        FilterConvol.h FilterHighpass.h \
        Filterfliprgba.h FilterFastDownscale.h \
        FilterGauss.h FilterBandpass.h FilterBlur.h FilterMask.h \
        OGLHelper.h OGLShader.h GL/gl.h GL/glext.h GL/glx.h \
        VertexArray.h GPUNullFilter.h GPUChromaKeyFilter.h Display.h \
        GPUBrightnessFilter.h GPUBlurFilter.h GPUShadowFilter.h GraphicsTest.h\
        GPUFilter.h GPUBandpassFilter.h GPUHueSatFilter.h GPUInvertFilter.h \
        FilterIntensity.h FilterNormalize.h FilterFloodfill.h FilterDilation.h \
        FilterErosion.h FilterGetAlpha.h FBO.h GLTexture.h TexInfo.h TextureMover.h \
        MCTexture.h FBOInfo.h MCFBO.h Color.h \
        ContribDefs.h TwoPassScale.h FilterResizeBilinear.h FilterThreshold.h \
        FilterResizeGaussian.h FilterUnmultiplyAlpha.h ShaderRegistry.h \
        ImagingProjection.h GLBufferCache.h GLConfig.h BmpTextureMover.h \
        GPURGB2YUVFilter.h GLShaderParam.h StandardShader.h SubVertexArray.h \
        VertexData.h BitmapLoader.h MCShaderParam.h CachedImage.h ImageCache.h \
        WrapMode.h $(GL_INCLUDES)
ALL_CPP = Bitmap.cpp Filter.cpp Pixel32.cpp Filtergrayscale.cpp PixelFormat.cpp \
        GLContextManager.cpp \
        Filtercolorize.cpp Filterflip.cpp FilterflipX.cpp Filterfliprgb.cpp \
        Filterflipuv.cpp Filter3x3.cpp FilterHighpass.cpp \
        Filterfliprgba.cpp FilterFastDownscale.cpp \
        FilterGauss.cpp FilterBandpass.cpp FilterBlur.cpp FilterMask.cpp \
        OGLHelper.cpp OGLShader.cpp GPUNullFilter.cpp GPUChromaKeyFilter.cpp \
        Display.cpp \
        GPUHueSatFilter.cpp GPUInvertFilter.cpp VertexArray.cpp GLContextAttribs.cpp \
        GPUBrightnessFilter.cpp GPUBlurFilter.cpp GPUShadowFilter.cpp GraphicsTest.cpp \
        GPUFilter.cpp GPUBandpassFilter.cpp FilterIntensity.cpp GLContext.cpp \
        FilterNormalize.cpp FilterDilation.cpp FilterErosion.cpp \
        FilterGetAlpha.cpp FBO.cpp GLTexture.cpp TexInfo.cpp TextureMover.cpp \
        MCTexture.cpp FBOInfo.cpp MCFBO.cpp Color.cpp \
        FilterResizeBilinear.cpp FilterResizeGaussian.cpp FilterThreshold.cpp \
        FilterUnmultiplyAlpha.cpp ShaderRegistry.cpp \
        ImagingProjection.cpp GLBufferCache.cpp GLConfig.cpp BmpTextureMover.cpp \
        GPURGB2YUVFilter.cpp GLShaderParam.cpp StandardShader.cpp SubVertexArray.cpp \
        VertexData.cpp BitmapLoader.cpp MCShaderParam.cpp CachedImage.cpp ImageCache.cpp \
        WrapMode.cpp $(GL_SOURCES)

if APPLE
    PLATFORM_LDF = -F/System/Library/PrivateFrameworks \
            -framework MultitouchSupport -framework Cocoa -framework CoreAudio \
            -framework AudioUnit -framework ForceFeedback -framework CoreVideo \
            -framework IOKit
    PLATFORM_LIBS =
else
if ENABLE_RPI
    PLATFORM_LDF =
    PLATFORM_LIBS = -lXxf86vm -lX11 -lbcm_host -lGLESv2 -lEGL
else
if ENABLE_EGL
    PLATFORM_LDF =
    PLATFORM_LIBS = -lXxf86vm -lX11 -lGLESv2 -lEGL
else
    PLATFORM_LDF =
    PLATFORM_LIBS = -lXxf86vm -lX11
endif
endif
endif

TESTS = testgraphics testgpu

EXTRA_DIST = $(wildcard baseline/*.png)

noinst_LTLIBRARIES = libgraphics.la
test_PROGRAMS = testgraphics  testgpu benchmarkgraphics
libgraphics_la_SOURCES = $(ALL_CPP) $(ALL_H)
testgraphics_SOURCES = testgraphics.cpp $(ALL_H)
testgraphics_LDADD = libgraphics.la ../base/libbase.la \
        @XML2_LIBS@ @BOOST_THREAD_LIBS@ @PTHREAD_LIBS@ $(PLATFORM_LIBS) @GDK_PIXBUF_LIBS@

benchmarkgraphics_SOURCES = benchmarkgraphics.cpp $(ALL_H)
benchmarkgraphics_LDADD = libgraphics.la ../base/libbase.la \
        @XML2_LIBS@ @BOOST_THREAD_LIBS@ @PTHREAD_LIBS@ @GDK_PIXBUF_LIBS@

testgpu_SOURCES = testgpu.cpp $(ALL_H)
testgpu_LDADD = libgraphics.la ../base/libbase.la -ldl \
        @XML2_LIBS@ @BOOST_THREAD_LIBS@ @PTHREAD_LIBS@ $(PLATFORM_LIBS) \
        @GL_LIBS@ @SDL_LIBS@ \
        @GDK_PIXBUF_LIBS@
testgpu_LDFLAGS = $(PLATFORM_LDF)
testdir = $(pkgpyexecdir)/bintest
