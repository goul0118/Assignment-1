#include "Brick.h"

#include "../../Common/Constants/Constants.h"
#include "../../Common/Screen Manager/ScreenManager.h"
#include "../../Common/OpenGL/OpenGL.h"
#include "../../Common/Game/Game.h"

Brick::Brick()
{
    m_StartPositionX = 100;
    m_StartPositionY = 100;

    m_PositionX = m_StartPositionX;
    m_PositionY = m_StartPositionY;

  //Get the screen width and height
  float screenWidth = ScreenManager::getInstance()->getScreenWidth();
  float screenHeight = ScreenManager::getInstance()->getScreenHeight();

  //Reset the paddle's width and height
  setWidth(screenWidth * GAME_BRICK_WIDTH_PERCENTAGE);
  setHeight(screenHeight * GAME_BRICK_HEIGHT_PERCENTAGE);

  m_Texture = NULL;

}

Brick::~Brick()
{

}

void Brick::update(double delta)
{
    Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
    m_Texture = game->getBrickTexture();

}

void Brick::paint()
{
    OpenGLTexture * myTexture;
    Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
    myTexture = game->getBrickTexture();

     OpenGLRenderer::getInstance()->drawTexture ( 
                                                    myTexture,
                                                    getX(),getY(),
                                                    getWidth(),
                                                    getHeight(),
                                                    0.0F
                                                   );
}

void Brick::reset()
{


}

const char* Brick::getType()
{
  return GAME_BRICK_TYPE;
}

