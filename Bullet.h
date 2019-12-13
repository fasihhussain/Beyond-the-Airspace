#pragma once

#include "GameObject.h"

class Bullet : public GameObject
{
private:
    int damage = 50;

public:
    void init(Manager *m, Vector2D pos, Vector2D vel, int range, int speed, std::string id);

    int getDamage(); //returns the damage value of the bullet when it strikes the plane
};