#include <vector>

#include "Game.h"
#include "GameObject.h"
#include "Paddle.h"
#include "Ball.h"
#include "../../Windows/Windows Game/Brick.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "..//Utils/Utils.h"
#include "../Screen Manager/ScreenManager.h"

Game::Game()
{
	m_HealthTexture = new OpenGLTexture("Health");
    m_BallTexture = new OpenGLTexture("Ball"); // Gives a texture to the ball.
    m_BrickTexture = new OpenGLTexture("Brick"); // Gives a texture to the brick.
    m_backgroundTexture = new OpenGLTexture("Background"); // Gives a texture to the background.

    ballLives = 3;
    brickCounter = 100;
    levelCounter = 0;

    //Creates and new ball/paddle.
    addGameObject(new Paddle());
    
    m_Ball = new Ball();
    m_Ball->setBrickCounter(&brickCounter);
    m_Ball->setballLives(&ballLives);

    addGameObject(m_Ball);

    nextStage();

    reset();

}

Game::~Game()
{
    if (m_backgroundTexture != NULL)
    {
        delete m_backgroundTexture;
        m_backgroundTexture = NULL;
    }

    //Delete all the GameObject's in the vector
    for(int i = 0; i < m_GameObjects.size(); i++)
    {
       delete m_GameObjects[i];
       m_GameObjects[i] = NULL;
       //delete m_GameObjects.at(i);
       //m_GameObjects.at(i) = NULL;
    
    }
  //Clears the pointers from the vector.
  m_GameObjects.clear();
}

void Game::nextStage()
{
  brickCounter = 0;

  ballLives++;

  m_Ball->setSpeed(m_Ball->getSpeed()+100);

  //BRICK HACK, NEED TO FIX LATER
  brickManager.createLevel(levelCounter);

  std::vector < Brick* > buffer;

  buffer = brickManager.getBrickList();

  Brick *newBrick = NULL;
  
  for (int i = 0; i < buffer.size(); i++)
  {
      newBrick = new Brick();
      newBrick->setX(buffer[i]->getX());
      newBrick->setY(buffer[i]->getY());
      
      addGameObject(newBrick);

      brickCounter++;

      newBrick = NULL;

  }

  levelCounter++;

}

void Game::update(double aDelta)
{
    if (ballLives <= 0)
    {
        //This is the lose condition
        int i = 0;
        gameOver();
    }

   if (brickCounter <= 0)
   {
       nextStage();
   }

   if (brickManager.isGameComplete() == true)
   {
       //This is win condition
       int i = 0;
       gameOver();
   }

  //If the GameOver Timer is greater that zero, countdown
  if(m_GameOverTimer > 0.0)
  {
    m_GameOverTimer -= aDelta;
    if(m_GameOverTimer < 0.0)
    {
      m_GameOverTimer = 0.0;
      reset();
    }
    return;
  }

  //Get the ball GameObject, we'll use this for collision detection
  Ball* ball = (Ball*)getGameObjectByType(GAME_BALL_TYPE);

  //Cycle through all the game objects update them and check their collision detection
  for(int i = 0; i < m_GameObjects.size(); i++)
  {
    //Make sure the GameObject is active
    if(m_GameObjects.at(i)->getIsActive() == true)
    {
      //Update the GameObject
      m_GameObjects.at(i)->update(aDelta);
      
      //Check collision detection against the ball
      if(m_GameObjects.at(i) != ball)
      {
        ball->checkCollision(m_GameObjects.at(i));
      }
    }
  }
}

void Game::paint()
{
    Screen::paint();
  //Cycle through and draw all the game objects
  for(int i = 0; i < m_GameObjects.size(); i++)
  {
    if(m_GameObjects.at(i)->getIsActive() == true)
    {
      m_GameObjects.at(i)->paint();
    }
    else
    {

    }
  }
  
  //Draw the outer white walls
  OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorWhite());
  OpenGLRenderer::getInstance()->setLineWidth(4.0f);
  OpenGLRenderer::getInstance()->drawLine(1.0f, 0.0f, 1.0f, getHeight());
  OpenGLRenderer::getInstance()->drawLine(0.0f, 1.0f, getWidth(), 1.0f);
  OpenGLRenderer::getInstance()->drawLine(getWidth() - 1, 0.0f, getWidth() - 1, getHeight());
  OpenGLRenderer::getInstance()->setLineWidth(1.0f);

  for (int i = 0; i < ballLives; i++)
  {OpenGLRenderer::getInstance()->drawTexture ( 
                                                    m_HealthTexture,
													30 + (50*i), ScreenManager::getInstance()->getScreenHeight()-50,
                                                    30,
                                                    30
                                                 );
  }



}

void Game::reset()
{
  //Cycle through and reset all the game objects
  for(int i = 0; i < m_GameObjects.size(); i++)
  {
    m_GameObjects.at(i)->reset();
  }
  
  //Reset the game over timer to zero
  m_GameOverTimer = 0.0;
}

void Game::gameOver()
{
	m_GameOverTimer = GAME_OVER_TIMER;
}

const char* Game::getName()
{
	return GAME_SCREEN_NAME;
}

void Game::screenWillAppear()
{
	OpenGLRenderer::getInstance()->setBackgroundColor(OpenGLColorCornflowerBlue());
}

void Game::addGameObject(GameObject* aGameObject)
{
  if(aGameObject != NULL)
  {
	m_GameObjects.push_back(aGameObject);
  }
}

GameObject* Game::getGameObjectByType(const char* aType)
{
  //Cycle through a find the game object (if it exists)
  for(unsigned int i = 0; i < m_GameObjects.size(); i++)
  {
    if(strcmp(m_GameObjects.at(i)->getType(), aType) == 0)
    {
      return m_GameObjects.at(i);
    }
  }
  return NULL;
}

void Game::mouseMovementEvent(float aDeltaX, float aDeltaY, float aPositionX, float aPositionY)
{
  //Set the paddle to the x position of the mouse
  Paddle* paddle = (Paddle*)getGameObjectByType(GAME_PADDLE_TYPE);

  //Safety check, paddle could be NULL
  if(paddle != NULL)
  {
    paddle->setX(aPositionX - (paddle->getWidth() / 2.0f));
  }

}

void Game::keyUpEvent(int aKeyCode)
{

}

OpenGLTexture * Game::getBallTexture ()
{
    return m_BallTexture;
}
OpenGLTexture * Game::getBrickTexture()
{
    return m_BrickTexture;
}

void Game::setBallTexture (OpenGLTexture* aBallTexture )
{
    m_BallTexture = aBallTexture;
}

void Game::setBrickTexture(OpenGLTexture* aBrickTexture)
{
    m_BrickTexture = aBrickTexture;
}