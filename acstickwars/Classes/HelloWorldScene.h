#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CCParallaxNodeExtras.h"
USING_NS_CC;

class HelloWorld : public Layer
{

  private:
    CCSpriteBatchNode *_batchNode;
    CCSprite *_ship;

    CCParallaxNodeExtras *_backgroundNode;
    CCSprite *_spacedust1;
    CCSprite *_spacedust2;
    CCSprite *_planetsunrise;
    CCSprite *_galaxy;
    CCSprite *_spacialanomaly;
    CCSprite *_spacialanomaly2;

    // scheduled Update
    void update(float dt);

  public:
    static Scene *createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(Ref *pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
