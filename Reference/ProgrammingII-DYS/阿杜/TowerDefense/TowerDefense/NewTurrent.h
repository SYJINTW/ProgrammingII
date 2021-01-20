#ifndef NEWTURRET_HPP
#define NEWTURRET_HPP
#include "Turret.hpp"

class NewTurret : public Turret {
public:
	static const int Price;
	NewTurret(float x, float y);
	void CreateBullet() override;
};
#endif // NEWTURRET_HPP
