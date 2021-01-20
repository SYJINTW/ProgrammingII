#include <string>

#include "SpeedEnemy.h"
#include "time.h"

SpeedEnemy::SpeedEnemy(int x, int y) : Enemy("play/enemy-4.png", x, y, 10, 40, 5, 5) {
	// TODO 2 (6/8): You can imitate the 2 files: 'SoldierEnemy.hpp', 'SoldierEnemy.cpp' to create a new enemy.
}
void SpeedEnemy::Update(float deltaTime){
	reload -= deltaTime;
	if (reload <= 0) {
		if (speed == 40) {
			speed *= 5;
		}
		else {
			speed /= 5;
		}
		reload = cooldown;
	}
	Enemy::Update(deltaTime);
}
