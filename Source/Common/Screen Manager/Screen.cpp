#include "Screen.h"
#include "ScreenManager.h"


Screen::Screen()
{
    m_backgroundTexture = NULL;
}

Screen::~Screen()
{
    
}

OpenGLTexture * Screen::getBackgroundTexture()
{
    return m_backgroundTexture;
}

void            Screen::setBackgroundTexture(OpenGLTexture * _backgroundTexture)
{
    m_backgroundTexture = _backgroundTexture;
}

void Screen::paint()
{
    if (m_backgroundTexture != NULL)
    {
        OpenGLRenderer::getInstance()->drawTexture ( 
                                                    m_backgroundTexture,
                                                    0,0,
                                                    ScreenManager::getInstance()->getScreenWidth (),
                                                    ScreenManager::getInstance()->getScreenHeight(),
                                                    0.0F
                                                   );
    }

}

void Screen::reset()
{
    
}

void Screen::screenWillAppear()
{
    
}

void Screen::screenWillDisappear()
{
    
}

void Screen::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
    
}

void Screen::mouseLeftClickDownEvent(float positionX, float positionY)
{
    
}

void Screen::mouseRightClickDownEvent(float positionX, float positionY)
{
    
}

void Screen::mouseLeftClickUpEvent(float positionX, float positionY)
{
    
}

void Screen::mouseRightClickUpEvent(float positionX, float positionY)
{
    
}

void Screen::keyDownEvent(int keyCode)
{
    
}

void Screen::keyUpEvent(int keyCode)
{
    
}

float Screen::getWidth()
{
    return ScreenManager::getInstance()->getScreenWidth();
}

float Screen::getHeight()
{
    return ScreenManager::getInstance()->getScreenHeight();
}


