/*
 * CVideo.h
 *
 *  Created on: 19 janv. 2009
 *      Author: legal
 */

#ifndef CVIDEO_H_
#define CVIDEO_H_

extern "C" {
	#include <libavcodec/avcodec.h>
	#include <libavformat/avformat.h>
	#include "libswscale/swscale.h"
}

#include "FImage.h"
#include <QThread>
#include <QMutex>
using namespace std;


class CVideo : public QThread {
private:
	bool fileOpen;
	bool fileFinish;


	AVFormatContext *pFormatCtx;
	AVFrame *pFrame;
	AVFrame *pFrameRGB;

	AVCodecContext *pCodecCtx;
	AVCodec *pCodec;
	AVPacket packet;

    int videoStream;
	int frameFinished;
	int numBytes;
	uint8_t *buffer;

	int videoH;
	int videoW;

	int frameCnt;

	bool framePrefetch;

public:
	QMutex mutex;

    CVideo(const char *filename);
	virtual ~CVideo();
	void run();
	int  frameNumber();
	bool isFinished();
	bool close();
    bool open(const char *filename);
	bool isOpen();
    bool decodeNextFrame();
	void jumpFrame(int count);
    //void copyToFastImage();

    int getVideoWidth();
    int getVideoHeight();

        FastImage* getNextVideoFrame();
        void getNextVideoFrame( FastImage* buffer );
};

#endif /* CVIDEO_H_ */
