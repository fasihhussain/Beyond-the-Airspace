#pragma once

#include "GameObject.h"

class ScoreUp : public GameObject
{

private:
    int addition;
    int xpos;
    int ypos;

public:
    int getAddition();

    void init(Manager *m, std::string id);

    void setXY();
};