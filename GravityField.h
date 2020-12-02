#pragma once
#include "scene/3d/area.h"

class RigidBody;

class GravityField : public Area {
	GDCLASS(GravityField, Area);

public:
	GravityField();
	virtual Vector3 calcForce(RigidBody *body) = 0;

	void _notification(int p_what);
	void applyForce();
};
