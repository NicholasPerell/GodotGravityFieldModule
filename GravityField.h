#pragma once
#include "scene/3d/area.h"

class RigidBody;

class GravityField : public Area {
	GDCLASS(GravityField, Area);

protected:
	float gravityScale = 1;
	static void _bind_methods();

public:
	GravityField();
	virtual Vector3 calcForce(RigidBody *body) = 0;

	void _notification(int p_what);
	void applyForce();

	float getGravityScale();
	void setGravityScale(float s);
};
