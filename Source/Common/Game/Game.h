#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../Screen Manager/Screen.h"
#include "../../Windows/Windows Game/BrickManager.h"
#include "Ball.h"

class GameObject;
class OpenGLTexture;

class Game : public Screen
{
public:
  Game();
  ~Game();

  //Game lifecycle methods
  void update(double delta);
  void paint();
  void reset();

  void nextStage();//loads the next level
  
  //Game Over method, call this when to end the game
  void gameOver();

  //Screen name, must be implemented, it's a pure
  //virtual method in the Screen class
  const char* getName();
  
  //Screen event method, inherited from the screen class
  void screenWillAppear();

  //GameObject Methods
  void addGameObject(GameObject* gameObject);
  GameObject* getGameObjectByType(const char* type);

  OpenGLTexture * getBallTexture();
  OpenGLTexture * getBrickTexture();
  OpenGLTexture * getHealthTexture();

  void setBallTexture (OpenGLTexture* aBallTexture );
  void setBrickTexture(OpenGLTexture* aBrickTexture);
  void setHealthTexture(OpenGLTexture* aHealthTexture);


private:
  Ball *m_Ball;
  
  OpenGLTexture * m_BallTexture;
  OpenGLTexture * m_BrickTexture;
   OpenGLTexture * m_HealthTexture;

  //Mouse Events
  void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);

  //Key Events
  void keyUpEvent(int keyCode);

  //Vector to hold the GameObjects
  std::vector<GameObject*> m_GameObjects;

  //Manages brick stuff
  BrickManager brickManager;

  //Counts the bricks in a level
  int brickCounter;

  //Counts the current level
  unsigned levelCounter;

  //Timer variable to delay reseting the game has ended
  double m_GameOverTimer;

  //Counts the number of ballLives the player has
  int ballLives;


};

#endif