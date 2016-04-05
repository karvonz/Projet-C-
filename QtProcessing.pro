TEMPLATE = app
TARGET = QtProcessing

#    win32{
        QMAKE_CXXFLAGS= -O2 \
            -msse -msse2 -mtune=native -pipe -fomit-frame-pointer \
            -fprefetch-loop-arrays -I./ffmpeg-2010-01-19/include/ -I./ffmpeg-2010-01-19
        LIBS += -lavdevice -lavformat -lavcodec -lavutil -lswscale -lm -L./ffmpeg-2010-01-19/lib -lws2_32
#    } else {
#       QMAKE_CXXFLAGS= -O2 \
#           -m32 -msse -msse2 -mtune=native -pipe -fomit-frame-pointer \
#           -fprefetch-loop-arrays
#       LIBS += -lavdevice -lavformat -lavcodec -lavutil -lswscale -lm -m32 -lbz2
# }

QT += core \
    gui \
    opengl \
    network

LIBS += -lopengl32

HEADERS += src/playerinterface.h \
    src/openglwidget.h \
    src/Image/FImage.h \
    src/Image/CVideo.h
SOURCES += src/playerinterface.cpp \
    src/openglwidget.cpp \
    src/main.cpp \
    src/Image/FImage.cpp \
    src/Image/CVideo.cpp
RESOURCES +=

FORMS +=
