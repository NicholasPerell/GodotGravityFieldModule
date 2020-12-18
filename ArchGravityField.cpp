#include "ArchGravityField.h"
#include <core\engine.h>
#include <scene\3d\physics_body.h>
#include <cmath>

Vector3 ArchGravityField::calcForce(RigidBody *body) {
	//Vector3 ret = get_translation() - body->get_translation();
	Vector3 ret = get_global_transform().origin - body->get_global_transform().origin;


	//ROTATE NEEDS TO BE FIXED FOR 3D
	/*ret.rotate(Vector3(0,0,1),Math::deg2rad(eulerAngles.z));
	ret.rotate(Vector3(0,1,0),Math::deg2rad(eulerAngles.y));
	ret.rotate(Vector3(1,0,0),Math::deg2rad(eulerAngles.x));*/

	ret = Vector3(ret.x, ret.y,0);

	/*ret.rotate(Vector3(1, 0, 0), Math::deg2rad(-eulerAngles.x));
	ret.rotate(Vector3(0, 1, 0), Math::deg2rad(-eulerAngles.y));
	ret.rotate(Vector3(0, 0, 1), Math::deg2rad(-eulerAngles.z));*/
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
	//ClassDB::bind_method(D_METHOD("setAxes", "axes"), &ArchGravityField::setAxes);
	//ClassDB::bind_method(D_METHOD("getAxes"), &ArchGravityField::getAxes);
	//ClassDB::bind_method(D_METHOD("setRotation", "rotation"), &ArchGravityField::setRotation);
	//ClassDB::bind_method(D_METHOD("getRotation"), &ArchGravityField::getRotation);

//	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "axes", PROPERTY_HINT_RANGE, "0,1024,0.001"), "setAxes", "getAxes");
	//ADD_PROPERTY(PropertyInfo(Variant::VECTOR3, "rotation", PROPERTY_HINT_RANGE, "-1024,1024,0.001"), "setRotation", "getRotation");
}
