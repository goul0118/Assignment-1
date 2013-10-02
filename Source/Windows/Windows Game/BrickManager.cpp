#include "BrickManager.h"

BrickManager::BrickManager()
{
    levelIsComplete = false;
     gameIsComplete = false;

}

BrickManager::~BrickManager()
{

}

void BrickManager::clearBrickList()
{
    if (brickList.size() > 0)
    {
        brickList.resize(0);    //resizes and destroys

    }

}

bool BrickManager::isLevelComplete()
{
    return levelIsComplete;

}

bool BrickManager::isGameComplete()
{
    return gameIsComplete;

}

std::vector<Brick*> BrickManager::getBrickList()
{
    std::vector<Brick*> ptrBrickList;

    for (int i = 0; i < brickList.size(); i++)
    {
        ptrBrickList.push_back(&brickList[i]);

    }

    return ptrBrickList;

}

void BrickManager::createLevel(int _LevelNumber)
{
    clearBrickList(); //check and possibly resize brick list

    Brick newBrick; //used to populate the brick list with level information

    if ( _LevelNumber == 0 )
    {
        
        //Row 1
        #define ROWSTART  50
        #define ROWHEIGHT 50

        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 100);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 300);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

		newBrick.setX(ROWSTART + 400);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART +500);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 600);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

		newBrick.setX(ROWSTART + 750);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

		newBrick.setX(ROWSTART + 850);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        //Row 2
        #define ROWHEIGHT 150
        
        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 100);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 300);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

		newBrick.setX(ROWSTART + 400);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 500);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 600);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

		newBrick.setX(ROWSTART + 800);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);
        
        //Row 3
        #define ROWHEIGHT 250

           newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 100);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 300);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

		newBrick.setX(ROWSTART + 400);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 500);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 600);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

		newBrick.setX(ROWSTART + 800);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);


    }

    else if ( _LevelNumber == 1 )
    {
        //Row 1
        #define ROWSTART 450
        #define ROWHEIGHT 100

        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);
        
        //Row 2
        #define ROWHEIGHT 150

        newBrick.setX(ROWSTART - 50);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 50);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        //Row 3
        #define ROWHEIGHT 200

		newBrick.setX(ROWSTART + -350);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

		newBrick.setX(ROWSTART + -250);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART - 100);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

		newBrick.setX(ROWSTART + 100);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 250);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

		newBrick.setX(ROWSTART + 350);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

    }

    else if ( _LevelNumber == 2 )
    {
        //Row 1
        #define ROWSTART 250
        #define ROWHEIGHT 100

        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);
        
        #define ROWSTART 650

        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        //Row 2
        #define ROWSTART 250
        #define ROWHEIGHT 150

        newBrick.setX(ROWSTART - 50);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 50);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        #define ROWSTART 650

        newBrick.setX(ROWSTART - 50);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);
        
        newBrick.setX(ROWSTART + 50);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        //Row 3
        #define ROWSTART 250
        #define ROWHEIGHT 200

        newBrick.setX(ROWSTART - 100);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 100);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART - 100);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);
        
        #define ROWSTART 650

        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);
        
        newBrick.setX(ROWSTART + 100);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        //Row 4
        #define ROWSTART  50
        #define ROWHEIGHT 300

        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 100);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        
        newBrick.setX(ROWSTART + 300);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 400);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        
        newBrick.setX(ROWSTART + 600);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        
        newBrick.setX(ROWSTART + 800);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

    }

    else if (_LevelNumber == 3)
    {
        //Row 1
        #define ROWSTART  350
        #define ROWHEIGHT 50

        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

		newBrick.setX(ROWSTART + 100);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 200);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        //Row 2
        #define ROWSTART  450
        #define ROWHEIGHT 150
        
        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

		newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT+50);
        brickList.push_back(newBrick);

		newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT+100);
        brickList.push_back(newBrick);

        //Row 3
        #define ROWSTART  350
        #define ROWHEIGHT 250
        
        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART+100);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART+200);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        //Row 4
        #define ROWSTART  250
        #define ROWHEIGHT 300

        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART +400);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

    }

    else if (_LevelNumber == 4)
    {
        //Row 1
        #define ROWSTART  350
        #define ROWHEIGHT 50

        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART + 200);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        //Row 2
        #define ROWSTART  450
        #define ROWHEIGHT 150
        
        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        //Row 3
        #define ROWSTART  250
        #define ROWHEIGHT 300

		newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT+50);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART+400);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

		newBrick.setX(ROWSTART+400);
        newBrick.setY(ROWHEIGHT+50);
        brickList.push_back(newBrick);

        //Row 4
        #define ROWSTART  350
        #define ROWHEIGHT 350
        
        newBrick.setX(ROWSTART);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART+100);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

        newBrick.setX(ROWSTART+200);
        newBrick.setY(ROWHEIGHT);
        brickList.push_back(newBrick);

    }

    else
    {
        gameIsComplete = true;

    }

}