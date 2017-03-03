#ifndef Cocos2DxFirstIosSample_CCParallaxNodeExtras_h
#define Cocos2DxFirstIosSample_CCParallaxNodeExtras_h

#include "cocos2d.h"

USING_NS_CC;

class CCParallaxNodeExtras : public ParallaxNode
{

  public:
    // Need to provide a constructor
    static CCParallaxNodeExtras *create();
    void updatePosition();
};

#endif