#pragma once
#include "GravityField.h"

class RigidBody;

class WireGravityField : public GravityField {
	GDCLASS(WireGravityField, GravityField);

	float a;

protected:
	static void _bind_methods();

public:
	virtual Vector3 calcForce(RigidBody *body);
	void setA(float aPram);
	float getA();
};
