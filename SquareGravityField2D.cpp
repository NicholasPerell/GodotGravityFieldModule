#include "SquareGravityField2D.h"
#include <scene\2d\physics_body_2d.h>
#include <core\engine.h>
#include <cmath>


Vector2 SquareGravityField2D::calcForce(RigidBody2D* body) {
	Point2 bodyPos = body->get_global_position();
	Vector2 difference = bodyPos - get_global_position();

	difference.x /= width;
	difference.y /= height;

	Vector2 ret;
	if (std::abs(difference.x) > std::abs(difference.y))
	{
		ret = Vector2(-difference.x, 0);
		ret.normalize();
		ret *= gravityScale;
	}
	else
	{
		ret = Vector2(0,-difference.y);
		ret.normalize();
		ret *= gravityScale;
	}
	return ret;
}
