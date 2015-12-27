//
//  BlockSprite.h
//  nyangame
//
//  Created by Sho Nakatani on 2015/12/24.
//
//

#ifndef __nyangame__BlockSprite__
#define __nyangame__BlockSprite__

#include "cocos2d.h"
#include "PazzleConfig.h"

class BlockSprite : public cocos2d::CCSprite {
protected:
  const char * getBlockImageFileName(kBlock blockType);

public:
  CC_SYNTHESIZE_READONLY(kBlock, m_blockType, BlockType);

  BlockSprite();
  virtual ~BlockSprite();
  virtual bool initWithBlockType(kBlock blockType);
  static BlockSprite* createWithBlockType(kBlock blockType);
};

#endif /* defined(__nyangame__BlockSprite__) */
