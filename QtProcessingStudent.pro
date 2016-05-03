TEMPLATE = app
TARGET = QtProcessing

QMAKE_CXXFLAGS= -O2 \
       -march=native -mtune=native -pipe -fomit-frame-pointer \
       -fprefetch-loop-arrays -I/opt/local/include

LIBS += -lz -lm -L/opt/local/lib -lopencv_contrib -lopencv_core \
        -lopencv_features2d -lopencv_flann -lopencv_highgui \
        -lopencv_imgproc -lopencv_legacy -lopencv_ml  \
        -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres \
        -lopencv_ts -lopencv_video -lopencv_videostab -I/opt/local/lib

QT       += core gui opengl network

HEADERS += src/playerinterface.h \
    src/openglwidget.h \
    src/Image/FImage.h \
    src/Image/CVideo.h \
    src/bibliotheque.h \
    src/filter.h \
    src/greyfilter.h \
    src/filtercanal.h \
    src/filtersubsampling.h \
    src/filtercomplexsubsampling.h \
    src/filterupsample.h \
    src/filteradaptcolor.h \
    src/filtercomplexupsample.h \
    src/filtercomplexupsamplecubic.h \
    src/filtermotionblur.h \
    src/filterconv2.h \
    src/filterconv3.h
SOURCES += src/playerinterface.cpp \
    src/openglwidget.cpp \
    src/main.cpp \
    src/Image/FImage.cpp \
    src/Image/CVideo.cpp \
    src/bibliotheque.cpp \
    src/filter.cpp \
    src/greyfilter.cpp \
    src/filtercanal.cpp \
    src/filtersubsampling.cpp \
    src/filtercomplexsubsampling.cpp \
    src/filterupsample.cpp \
    src/filteradaptcolor.cpp \
    src/filtercomplexupsample.cpp \
    src/filtercomplexupsamplecubic.cpp \
    src/filtermotionblur.cpp \
    src/filterconv2.cpp \
    src/filterconv3.cpp
RESOURCES +=
FORMS +=
