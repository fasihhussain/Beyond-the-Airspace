#include "GameObject.h"

class Enemy : public GameObject
{
private:
    int health = 150;
    int xpos;
    int ypos;

public:
    Enemy();

    void init(Manager *m, std::string id);

    void setXY();

    void take_damage(int damage);

    int get_health();
};