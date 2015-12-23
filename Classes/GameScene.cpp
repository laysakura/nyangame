//
//  GameScene.cpp
//  nyangame
//
//  Created by Sho Nakatani on 2015/12/24.
//
//

#include "GameScene.h"

using namespace cocos2d;

CCScene* GameScene::scene() {
  CCScene* scene = CCScene::create();
  GameScene* layer = GameScene::create();
  scene->addChild(layer);
  return scene;
}

bool GameScene::init() {
  return CCLayer::init();
}