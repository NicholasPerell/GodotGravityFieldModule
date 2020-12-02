#pragma once
#include "GravityField2D.h"

class RigidBody2D;

class SquareGravityField2D : public GravityField2D {
	GDCLASS(SquareGravityField2D, GravityField2D);

	float height = 2, width = 2, gravityScale = 1;
public:
	virtual Vector2 calcForce(RigidBody2D *body);
};
