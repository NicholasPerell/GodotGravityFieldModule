#pragma once
#include "GravityField.h"

class RigidBody;

class ArchGravityField : public GravityField {
	GDCLASS(ArchGravityField, GravityField);

	Vector3 eulerAngles;
	Vector2 axes;

protected:
	static void _bind_methods();

public:
	virtual Vector3 calcForce(RigidBody *body);
	void setAxes(Vector2 a);
	Vector2 getAxes();
	void setRotation(Vector3 rot);
	Vector3 getRotation();
};
