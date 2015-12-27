//
//  GameScene.h
//  nyangame
//
//  Created by Sho Nakatani on 2015/12/24.
//
//

#ifndef __nyangame__GameScene__
#define __nyangame__GameScene__

#include <map>
#include <list>
#include "cocos2d.h"
#include "PazzleConfig.h"

static const char * const BgImgName = "background.png";
static const float BgImgHeight = 768.0;

static const int MaxBlockX = 8;
static const int MaxBlockY = 8;

class GameScene : public cocos2d::CCLayer {
protected:
  enum kTag {
    kTagBackGround = 1,
    kTagBaseBlock = 10000,  // コマのタグ = kTagBaseBlock + x-index * 100 + y-index
  };
  enum kZOrder {
    kZOrderBackground,
    kZorderBlock,
  };

  cocos2d::CCSprite* m_background;
  void showBackground();

  float m_blockSize;
  std::map<kBlock, std::list<int> > m_blockTags;  // 1つの色のコマが隣接してるかを探すのに使う

  void initVariables();
  void showBlocks();
  cocos2d::CCPoint getPosition(int posIndexX, int posIndexY);
  kTag getTag(int posIndexX, int posIndexY);

public:
  virtual bool init();
  static cocos2d::CCScene* scene();
  CREATE_FUNC(GameScene);
};

#endif /* defined(__nyangame__GameScene__) */
