#include <vector>
#include "Brick.h"

class BrickManager
{
protected:
    std::vector < Brick > brickList;    //Contains a list of bricks for the level

    bool levelIsComplete;
    bool gameIsComplete;

    //resests the list to length zero
    

public:
    void clearBrickList();

    void createLevel(int _LevelNumber);

    std::vector<Brick*> getBrickList();

    bool isLevelComplete();
    bool isGameComplete();

    BrickManager();
   ~BrickManager();

};