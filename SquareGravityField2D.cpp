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
		ret *= gravityScale * body->get_gravity_scale();
	}
	return ret;
}

void SquareGravityField2D::setHeight(float h) {
	height = h;
}
float SquareGravityField2D::getHeight() {
	return height;
}

void SquareGravityField2D::setWidth(float w) {
	width = w;
}
float SquareGravityField2D::getWidth() {
	return width;
}

void SquareGravityField2D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("setHeight", "h"), &SquareGravityField2D::setHeight);
	ClassDB::bind_method(D_METHOD("getHeight"), &SquareGravityField2D::getHeight);

	ADD_PROPERTY(PropertyInfo(Variant::REAL, "height", PROPERTY_HINT_RANGE, "0,1024,0.001"), "setHeight", "getHeight");

	ClassDB::bind_method(D_METHOD("setWidth", "w"), &SquareGravityField2D::setWidth);
	ClassDB::bind_method(D_METHOD("getWidth"), &SquareGravityField2D::getWidth);

	ADD_PROPERTY(PropertyInfo(Variant::REAL, "width", PROPERTY_HINT_RANGE, "0,1024,0.001"), "setWidth", "getWidth");
}
