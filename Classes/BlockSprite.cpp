//
//  BlockSprite.cpp
//  nyangame
//
//  Created by Sho Nakatani on 2015/12/24.
//
//

#include "BlockSprite.h"

BlockSprite::BlockSprite() {
}

BlockSprite::~BlockSprite() {
}

BlockSprite* BlockSprite::createWithBlockType(kBlock blockType) {
  BlockSprite *pRet = new BlockSprite();
  if (pRet->initWithBlockType(blockType)) {
    pRet->autorelease();
    return pRet;
  }
  else {
    CC_SAFE_DELETE(pRet);
    return NULL;
  }
}

bool BlockSprite::initWithBlockType(kBlock blockType) {
  auto ret = CCSprite::initWithFile(getBlockImageFileName(blockType));
  CCAssert(ret, "Failed to initWithFile()");

  m_blockType = blockType;
  return true;
}

const char * BlockSprite::getBlockImageFileName(kBlock blockType) {
  switch (blockType) {
    case kBlockRed:
      return "red.png";
    case kBlockBlue:
      return "blue.png";
    case kBlockYellow:
      return "yellow.png";
    case kBlockGreen:
      return "green.png";
    case kBlockGray:
      return "gray.png";
    default:
      CCAssert(false, "invalid blockType");
      return "";
  }
}