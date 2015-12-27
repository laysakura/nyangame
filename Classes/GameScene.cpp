//
//  GameScene.cpp
//  nyangame
//
//  Created by Sho Nakatani on 2015/12/24.
//
//

#include "GameScene.h"
#include "BlockSprite.h"

using namespace cocos2d;

CCScene* GameScene::scene() {
  CCScene* scene = CCScene::create();
  GameScene* layer = GameScene::create();
  scene->addChild(layer);
  return scene;
}

bool GameScene::init() {
  if (!CCLayer::init()) { return false; }

  initVariables();

  showBackground();

  showBlocks();

  return true;
}

void GameScene::showBackground() {
  CCSize winSize = CCDirector::sharedDirector()->getWinSize();

  m_background = CCSprite::create(BgImgName);
  m_background->setPosition(ccp(winSize.width / 2, winSize.height / 2));
  addChild(m_background, kZOrderBackground, kTagBackGround);
}

void GameScene::initVariables() {
  srand((unsigned)time(NULL));

  BlockSprite* pBlock = BlockSprite::createWithBlockType(kBlockRed);
  m_blockSize= pBlock->getContentSize().height;
}

CCPoint GameScene::getPosition(int posIndexX, int posIndexY) {
  float offsetX = m_background->getContentSize().width * 0.168;
  float offsetY = m_background->getContentSize().height * 0.029;
  return CCPoint(
    (posIndexX + 0.5) * m_blockSize + offsetX,
    (posIndexY + 0.5) * m_blockSize + offsetY
  );
}

GameScene::kTag GameScene::getTag(int posIndexX, int posIndexY) {
  return (kTag)(kTagBaseBlock + posIndexX * 100 + posIndexY);
}

void GameScene::showBlocks() {
  for (int x = 0; x < MaxBlockX; x++) {
    for (int y = 0; y < MaxBlockX; y++) {
      auto blockType = static_cast<kBlock>(rand() % kBlockCount);

      int tag = getTag(x, y);
      m_blockTags[blockType].push_back(tag);

      BlockSprite* pBlock = BlockSprite::createWithBlockType(blockType);
      pBlock->setPosition(getPosition(x, y));
      m_background->addChild(pBlock, kZorderBlock, tag);
    }
  }
}