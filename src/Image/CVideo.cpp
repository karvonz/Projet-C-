/*
 * CVideo.cpp
 *
 *  Created on: 19 janv. 2009
 *      Author: legal
 */

#include "CVideo.h"

CVideo::CVideo(const char *filename) {
        fileOpen   = false;
        fileFinish = false;
        frameCnt = 0;
        bool isOK = open( filename );
        if( !isOK ){
                cout << "Erreur a l'ouverture du fichier video..." << endl;
                exit(0);
        }
}


CVideo::~CVideo() {
}


int  CVideo::frameNumber() {
    return 0;
}


bool CVideo::isFinished() {
    return fileFinish;
}


bool CVideo::close() {
    return 0;
}


bool CVideo::open(const char *filename) {

        // Register all formats and codecs
        av_register_all();

        // Open video file
        if (av_open_input_file(&pFormatCtx, filename, NULL, 0, NULL) != 0)
                return false;

        // Retrieve stream information
        if (av_find_stream_info(pFormatCtx) < 0)
                return false; // Couldn't find stream information

        // Dump information about file onto standard error
        dump_format(pFormatCtx, 0, filename, false);

        // Find the first video stream
        videoStream = -1;
        for (int i = 0; i < (int)pFormatCtx->nb_streams; i++)
                if (pFormatCtx->streams[i]->codec->codec_type == CODEC_TYPE_VIDEO) {
                        videoStream = i;
                        break;
                }
        if (videoStream == -1)
                return false; // Didn't find a video stream

        // Get a pointer to the codec context for the video stream
        pCodecCtx = pFormatCtx->streams[videoStream]->codec;

        // Find the decoder for the video stream
        pCodec = avcodec_find_decoder(pCodecCtx->codec_id);
        if (pCodec == NULL)
                return false; // Codec not found

        // Open codec
        if (avcodec_open(pCodecCtx, pCodec) < 0)
                return false; // Could not open codec

        // Allocate an AVFrame structure
        pFrame    = avcodec_alloc_frame();
        pFrameRGB = avcodec_alloc_frame();
        if (pFrameRGB == NULL)
                return false;

        // Determine required buffer size and allocate buffer
        numBytes = avpicture_get_size(PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height);
        buffer = new uint8_t[numBytes];

        // Assign appropriate parts of buffer to image planes in pFrameRGB
        avpicture_fill((AVPicture *) pFrameRGB, buffer, PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height);

        #ifdef WORDS_BIGENDIAN
                        printf("=> Le stockage des données est fait en WORDS_BIGENDIAN\n");
        #else
                        printf("=> Le stockage des données est fait en WORDS_LITTLEENDIAN\n");
        #endif

        //////////////////////////////////////////////////////////////////////////////

        videoH = pCodecCtx->height;
        videoW = pCodecCtx->width;

        fileFinish = false;

        //
        // ON FORCE L'EXECUTION EN MODE SEQUENTIEL POUR CAUSE DE PROBLEME
        // DE SYNCHRONISATION DANS LES STRUCTURES EN COURS D'INIT.
        //
        run();

        return true;
}


bool CVideo::isOpen() {
        return true;
}


void CVideo::run() {
    cout << "=> Thread execution begin..." << endl;
    mutex.lock();
    while( !decodeNextFrame() ){
        if( isFinished() == true ){
            printf("=> OUPS FILE FINISHED...\n");
            mutex.unlock();
                return;
        }
    }
    mutex.unlock();
    cout << "=> Thread execution stop...\n" << endl;
}


bool CVideo::decodeNextFrame() {
        bool isOK = (av_read_frame(pFormatCtx, &packet) >= 0);

        if (packet.stream_index != videoStream) {
            return false;
        }

        if( isOK == false ){
                printf("=> Frame extration wrong => file finished...\n");
                fileFinish = true;
                return false;
        }

        avcodec_decode_video(pCodecCtx, pFrame, &frameFinished, packet.data, packet.size);

        // LA VIDEO EST ELLE TERMINEE ?
        if (frameFinished) {
            av_free_packet(&packet);
            frameCnt += 1;
        }else{
            return false;
        }
        return true;
}


void CVideo::jumpFrame(int count) {
    while( count-- )
        decodeNextFrame();
}

static int sws_flags = SWS_BICUBIC;

int CVideo::getVideoWidth(){
    return videoW;
}

int CVideo::getVideoHeight(){
    return videoH;
}

FastImage* CVideo::getNextVideoFrame(){
    FastImage* img = new FastImage(videoH, videoW);
    getNextVideoFrame( img );
    return img;
}

void CVideo::getNextVideoFrame( FastImage* buffer ){
    mutex.lock();

    // SYNCRONISATION DU MOTEUR D'EXTRACTION...
    mutex.unlock();

    if( isFinished() == true ){
        cout << "(EE) The video file reading is finish..." << endl;
        return;
    }


    if( frameFinished == false ){
        cout << "(II) The frame was not OK for decompression..." << endl;
        return;
    }

    buffer->resize(pCodecCtx->height, pCodecCtx->width);

    struct SwsContext *toRGB_convert_ctx = NULL;
    toRGB_convert_ctx = sws_getCachedContext(toRGB_convert_ctx,
                        pCodecCtx->width, pCodecCtx->height,
                        pCodecCtx->pix_fmt, pCodecCtx->width,
                        pCodecCtx->height, PIX_FMT_RGB32, sws_flags,
                        NULL, NULL, NULL);

        if (toRGB_convert_ctx == NULL) {
            printf("Cannot initialize the toRGB conversion context\n");
            return ;
        }


        // CONVERSION DE L'IMAGE AU FORMAT RGB CAR C'EST COMME CELA QUE L'ON
        // VA LA MANIPULER PAR LA SUITE...
        sws_scale(toRGB_convert_ctx, (const uint8_t**)pFrame->data, pFrame->linesize, 0,
                        pCodecCtx->height, pFrameRGB->data, pFrameRGB->linesize);


    sws_freeContext(toRGB_convert_ctx);

    buffer->FastImageFill( pFrameRGB );
    start();
}
