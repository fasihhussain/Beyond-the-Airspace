#pragma once

#include "GameObject.h"

class Missile : public GameObject
{
private:
    int damage = 50;

public:
    void init(Manager *m, Vector2D pos, Vector2D vel, int range, int speed, std::string id);

    int getDamage();

    void Follow(Vector2D pos);
};