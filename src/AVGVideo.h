//
// $Id$
// 

#ifndef _AVGVideo_H_
#define _AVGVideo_H_

#include "AVGNode.h"
#include "IAVGVideo.h"
#include "AVGRect.h"

#include <string>

class PLBmp;
class IAVGVideoDecoder;

//8d8abfe4-a725-4908-96a6-53c575f1f574
#define AVGVIDEO_CID \
{ 0x8d8abfe4, 0xa725, 0x4908, { 0x96, 0xa6, 0x53, 0xc5, 0x75, 0xf1, 0xf5, 0x74 } }

#define AVGVIDEO_CONTRACTID "@c-base.org/avgvideo;1"

class AVGVideo : public AVGNode, IAVGVideo
{
    public:
        NS_DECL_ISUPPORTS
        NS_DECL_IAVGVIDEO

        static AVGVideo * create();

        AVGVideo ();
        virtual ~AVGVideo ();
        
        NS_IMETHOD GetType(PRInt32 *_retval);

        virtual void init (const std::string& id, const std::string& filename, 
           bool bLoop, bool bOverlay, 
           IAVGDisplayEngine * pEngine, AVGContainer * pParent, AVGPlayer * pPlayer);
        virtual void prepareRender (int time, const AVGDRect& parent);
        virtual void render (const AVGDRect& Rect);
        bool obscures (const AVGDRect& Rect, int z);
        virtual std::string getTypeStr ();
        virtual std::string dump (int indent = 0);

    protected:        
        virtual AVGDPoint getPreferredMediaSize();
    
    private:
        void initVideoSupport();

        void open (int* pWidth, int* pHeight);
        void close();
        typedef enum VideoState {Unloaded, Paused, Playing};
        void changeState(VideoState NewState);
        void renderToBmp();
        void renderToBackbuffer();
        void seek(int DestFrame);
        void advancePlayback();
       
        std::string m_Filename;
        int m_Width;
        int m_Height;
        bool m_bLoop;

        PLBmp * m_pBmp;
        bool m_bFrameAvailable;

        VideoState m_State;
        int m_CurFrame;
        AVGDPoint m_PreferredSize;
        bool m_bEOF;

        IAVGVideoDecoder * m_pDecoder;

        static bool m_bInitialized;
};

#endif 

