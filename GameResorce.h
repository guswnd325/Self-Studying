#include "cocos2d.h"
#define _height 480
#define _width 270
using namespace cocos2d;
using namespace std;

Point Player_position;

class WinSize
{
    // Get WinSize Width
int width()
{
return _width;
}
 // Get WinSize Height
int height()
{
return _height
}

}

class SpriteInit : WinSize
{
    // Sprite Add
Sprite * add(string _filename, bool _visible, float _scale)
{
Sprite * _newSprite = Sprite::create(_filename);
_newSprite->setVisible(_visible); 
_newSprite->setScale(_scale);
return _newSprite
}

void Position()
{
    
}

}


class Player : SpriteInit
{
Sprite * _Player = add("Char.png", true, 1.0);

// Jump Acc
void Jump()
{

}

// Check Collision
bool Collision()
{

}

}

class Block : SpriteInit
{
Sprite * _Block = add("Platform.png", true, 1.0);



}

class Monster : SpriteInit
{ 

}

class Item : SpriteInit
{

}
