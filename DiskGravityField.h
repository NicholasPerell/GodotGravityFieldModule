#pragma once
#include "GravityField.h"

class RigidBody;

class DiskGravityField : public GravityField {
	GDCLASS(DiskGravityField, GravityField);

	float radius = 1;
	float thickness = 1;

protected:
	static void _bind_methods();

public:
	virtual Vector3 calcForce(RigidBody *body);
	void setRadius(float rad);
	float getRadius();
	void setThickness(float thick);
	float getThickness();
};
