#include "Curve2D.h"
#include <core\engine.h>
#include <scene\2d\physics_body_2d.h>
#include <cmath>

Vector2 CurveGravityField2D::calcForce(RigidBody2D *body) {
	Point2 bodyPos = body->get_global_position();
	Vector2 difference = bodyPos - get_global_position();

	Vector2 ret;

	//TODO: Do gravity calculations here:
	
	return ret;
}


//TODO: Add getters and setters for paramters
void CurveGravityField2D::setHeight(float h) {
	height = h;
}
float CurveGravityField2D::getHeight() {
	return height;
}

void CurveGravityField2D::setWidth(float w) {
	width = w;
}
float CurveGravityField2D::getWidth() {
	return width;
}


//TODO: Bind getters and setters and add properties so they are visable from the inspector
void CurveGravityField2D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("setHeight", "h"), &CurveGravityField2D::setHeight);
	ClassDB::bind_method(D_METHOD("getHeight"), &CurveGravityField2D::getHeight);

	ADD_PROPERTY(PropertyInfo(Variant::REAL, "height", PROPERTY_HINT_RANGE, "0,1024,0.001"), "setHeight", "getHeight");

	ClassDB::bind_method(D_METHOD("setWidth", "w"), &CurveGravityField2D::setWidth);
	ClassDB::bind_method(D_METHOD("getWidth"), &CurveGravityField2D::getWidth);

	ADD_PROPERTY(PropertyInfo(Variant::REAL, "width", PROPERTY_HINT_RANGE, "0,1024,0.001"), "setWidth", "getWidth");
}
