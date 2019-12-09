#pragma once

#include "Components.h"
#include "../Vector2D.h"
#include "../Game.h"

class HealthComponent : public Component
{
public:
    int health;

    HealthComponent()
    {
        health = 150;
    }

    void init() override
    {
        health = 150;
    }

    void update() override
    {
    }

    void take_damage(int damage)
    {
        health = health - damage;
    }
};