#include "WireGravityField2D.h"
#include <core\engine.h>
#include <scene\3d\physics_body.h>
#include <cmath>
#include <iostream>
#include <scene\2d\physics_body_2d.h>

Vector2 WireGravityField2D::calcForce(RigidBody2D *body) {
	Point2 bodyPos = body->get_global_position();
	Vector2 ret;

	Vector2 slope = (b - a);
	slope.normalize();
	Vector2 perpSlope = -slope;
	std::cout << "Slope: " << slope.x << " " << slope.y << std::endl;
	std::cout << "Perpindicular slope: " << perpSlope.x << " " << perpSlope.y << std::endl;
	ret = perpSlope * gravityScale;

	float x = bodyPos.x - a.x;
	float y = bodyPos.y - b.y;
	float angle = atan2f(x, y);

	std::cout << "x is " << x << " y " << y << " angle " << angle << std::endl;

	float distance = sin(angle) * x;
	std::cout << "Distance between point and line is " << distance << std::endl;

	//ret *= distance;

	std::cout << "Ret is " << ret.x << " " << ret.y << std::endl;

	//Split distnace into components
	float distAngle = 90 - (90 - angle);

	float distX = cos(angle) * distance;
	float distY = sin(angle) * distance;



	std::cout << "Distance: " << distX << " " << distY << std::endl;

	return Vector2(distX, distY);
}

void WireGravityField2D::set_a(const Vector2 &p_a) {

	a = p_a;
}
Vector2 WireGravityField2D::get_a() const {

	return a;
}

void WireGravityField2D::set_b(const Vector2 &p_b) {

	b = p_b;
}
Vector2 WireGravityField2D::get_b() const {

	return b;
}


//Bind getters and setters and add paramters as property
void WireGravityField2D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_a", "a"), &WireGravityField2D::set_a);
	ClassDB::bind_method(D_METHOD("get_a"), &WireGravityField2D::get_a);

	ClassDB::bind_method(D_METHOD("set_b", "b"), &WireGravityField2D::set_b);
	ClassDB::bind_method(D_METHOD("get_b"), &WireGravityField2D::get_b);

	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "a"), "set_a", "get_a");
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "b"), "set_b", "get_b");

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "Line Shape", PROPERTY_HINT_RESOURCE_TYPE, "SegmentShape2D"), "setTheLine", "getTheLine");
}
