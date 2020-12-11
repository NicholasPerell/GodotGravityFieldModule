#pragma once
#include "GravityField2D.h"
#include <scene\2d\collision_shape_2d.h>

class RigidBody;

class WireGravityField2D : public GravityField2D {
	GDCLASS(WireGravityField2D, GravityField2D);

	Vector2 a;
	Vector2 b;

protected:
	static void _bind_methods();

public:
	virtual Vector2 calcForce(RigidBody2D *body);
	void set_a(const Vector2 &p_a);
	void set_b(const Vector2 &p_b);

	Vector2 get_a() const;
	Vector2 get_b() const;

	
};
