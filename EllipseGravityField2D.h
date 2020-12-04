#pragma once
#include "GravityField2D.h"

class RigidBody2D;

class EllipseGravityField2D : public GravityField2D {
	GDCLASS(EllipseGravityField2D, GravityField2D);

	Vector2 axes;

protected:
	static void _bind_methods();

public:
	virtual Vector2 calcForce(RigidBody2D* body);
	void setAxes(Vector2 a);
	Vector2 getAxes();
};
