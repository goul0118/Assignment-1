//
//  Ball.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-01-09.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef BALL_H
#define BALL_H

#include "GameObject.h"
#include "Paddle.h"
#include "../../Windows/Windows Game/Brick.h"
#include "../../Common/OpenGL/OpenGLTextureLoader.h"


//Ball class, inherits from the GameObject class, handles 
//collision detection internally.
class Ball : public GameObject
{
public:
  Ball();
  ~Ball();
  
  //Implementing the pure virtual lifecycle methods from GameObject
  void update(double delta);
  void paint();
  
  //Overriding the virtual reset method from GameObject
  void reset();
  
  //Implementing the pure virtual type method from GameObject
  const char* getType();
  
  //Check collision method, checks if the gameObject 
  //parameter is colliding with this class
  void checkCollision(GameObject* gameObject);
  
  //Set and get radius methods
  void setRadius(float radius);
  float getRadius();
  
  //Set and get speed methods
  void setSpeed(float speed);
  float getSpeed();
  
  //Setter direction methods
  void setDirection(float directionX, float directionY);
  void setDirectionX(float directionX);
  void setDirectionY(float directionY);
  
  //Getter direction methods
  void getDirection(float &directionX, float &directionY);
  float getDirectionX();
  float getDirectionY();
  
  void setBrickCounter(int* _brickCounter);
  void setballLives(int* _ballLives);
  int* getballLives();

protected:
  int *brickCounter; //pointer to the game's brick counter
  int *ballLives;

  //Handle's paddle collision events.
  void handlePaddleCollision(Paddle* paddle);

  //Handle brick collision events
  void handleBrickCollision(Brick* brick);

  //Ball member variables
  float m_Radius;
  float m_Speed;
  float m_DirectionX;
  float m_DirectionY;
};

#endif
