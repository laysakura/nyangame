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

class GameScene : public cocos2d::CCLayer {
public:
  virtual bool init();
  static cocos2d::CCScene* scene();
  CREATE_FUNC(GameScene);
};

#endif /* defined(__nyangame__GameScene__) */
