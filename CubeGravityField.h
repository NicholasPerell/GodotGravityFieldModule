#pragma once
#include "GravityField.h"

class RigidBody;

class CubeGravityField : public GravityField {
	GDCLASS(CubeGravityField, GravityField);

	float a;

protected:
	static void _bind_methods();

public:
	virtual Vector3 calcForce(RigidBody *body);
	void setA(float aPram);
	float getA();
};