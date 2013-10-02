#pragma once

#include "..\..\Common\Game\Paddle.h"

//Since Paddle does not contain any update code, just accessors and rectangle drawing, this is more logical than it seems

class Brick : public Paddle
{
protected:
    float m_StartPositionX;
    float m_StartPositionY;

    void update(double delta);

public:
    void paint();

    void reset();

    const char* getType();
    
	Brick();
    ~Brick();

};