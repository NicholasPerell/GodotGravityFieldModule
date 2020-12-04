#pragma once
#include "GravityField2D.h"

class RigidBody2D;

class CurveGravityField2D : public GravityField2D {
	GDCLASS(CurveGravityField2D, GravityField2D);

	float height = 2, width = 2;

protected:
	static void _bind_methods();

public:
	virtual Vector2 calcForce(RigidBody2D *body);
	void setHeight(float h);
	float getHeight();

	void setWidth(float w);
	float getWidth();
};
