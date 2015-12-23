//
//  GameScene.h
//  nyangame
//
//  Created by Sho Nakatani on 2015/12/24.
//
//

#ifndef __nyangame__GameScene__
#define __nyangame__GameScene__

#include "cocos2d.h"

static const char * const BgImgName = "background.png";
static const float BgImgHeight = 768.0;

class GameScene : public cocos2d::CCLayer {
protected:
  enum kTag {
    kTagBackGround = 1,
  };
  enum kZOrder {
    kZOrderBackground,
  };

  cocos2d::CCSprite* m_background;
  void showBackground();

public:
  virtual bool init();
  static cocos2d::CCScene* scene();
  CREATE_FUNC(GameScene);
};

#endif /* defined(__nyangame__GameScene__) */
