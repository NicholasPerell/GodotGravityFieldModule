#include "ArchGravityField.h"
#include <core\engine.h>
#include <scene\3d\physics_body.h>
#include <cmath>

Vector3 ArchGravityField::calcForce(RigidBody *body) {
	
	Vector3 ret = body->get_translation() - get_translation();
	ret.rotate(eulerAngles, 1);

	ret = Vector3(ret.x / axes.x, ret.y / axes.y,0);

	ret.rotate(-eulerAngles, 1);
	ret.normalize();
	ret *= gravityScale * body->get_gravity_scale();
	return ret;
}


//TODO: Add getters and setters for prameters

void ArchGravityField::setAxes(Vector2 a)
{
	axes = a;
}

Vector2 ArchGravityField::getAxes()
{
	return axes;
}

void ArchGravityField::setRotation(Vector3 rot) {
	eulerAngles = rot;
}
Vector3 ArchGravityField::getRotation() {
	return eulerAngles;
}

//Bind getters and setters and add paramters as property
void ArchGravityField::_bind_methods() {
	ClassDB::bind_method(D_METHOD("setAxes", "axes"), &ArchGravityField::setAxes);
	ClassDB::bind_method(D_METHOD("getAxes"), &ArchGravityField::getAxes);
	ClassDB::bind_method(D_METHOD("setRotation", "rotation"), &ArchGravityField::setRotation);
	ClassDB::bind_method(D_METHOD("getRotation"), &ArchGravityField::getRotation);

	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "axes", PROPERTY_HINT_RANGE, "0,1024,0.001"), "setAxes", "getAxes");
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR3, "rotation", PROPERTY_HINT_RANGE, "-1024,1024,0.001"), "setRotation", "getRotation");
}
