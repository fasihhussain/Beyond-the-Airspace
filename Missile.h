#pragma once

#include "GameObject.h"

class Missile : public GameObject
{
private:
    int damage = 50;

public:
    void init(Manager *m, Vector2D pos, Vector2D vel, int range, int speed, std::string id);        //initalize components

    int getDamage();        //get the damage value of missle hit
};