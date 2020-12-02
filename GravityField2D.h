#pragma once
#include "scene/2d/area_2d.h"

class RigidBody2D;

class GravityField2D : public Area2D {
	GDCLASS(GravityField2D, Area2D);


public:
	GravityField2D();
	virtual Vector2 calcForce(RigidBody2D *body) = 0;


	void _notification(int p_what);
	void applyForce();
};
