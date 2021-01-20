#ifndef SPEEDENEMY_HPP
#define SPEEDENEMY_HPP
#include "Enemy.hpp"

class SpeedEnemy : public Enemy {
protected:
	float reload = 0;
	float cooldown = 5;
public:
	SpeedEnemy(int x, int y);
	void Update(float deltaTime);
};
#endif // SPEEDENEMY_HPP
