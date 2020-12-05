#pragma once
#include "GravityField.h"

class RigidBody;

class CubeGravityField : public GravityField {
	GDCLASS(CubeGravityField, GravityField);

	float length;
	float width;
	float height;


protected:
	static void _bind_methods();

public:
	virtual Vector3 calcForce(RigidBody *body);
	void setLength(float l);
	float getLength();

	void setWidth(float w);
	float getWidth();

	void setHeight(float h);
	float getHeight();
};
