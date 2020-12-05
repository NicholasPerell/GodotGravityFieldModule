#include "ElipsoidGravityField.h"
#include <core\engine.h>
#include <scene\3d\physics_body.h>
#include <cmath>

Vector3 ElipsoidGravityField::calcForce(RigidBody *body) {

	Vector3 ret;

	//TODO: Add calculations here

	return ret;
}

//TODO: Add getters and setters for prameters
void ElipsoidGravityField::setA(float aPram) {
	a = aPram;
}
float ElipsoidGravityField::getA() {
	return a;
}

//Bind getters and setters and add paramters as property
void ElipsoidGravityField::_bind_methods() {
	ClassDB::bind_method(D_METHOD("setA", "h"), &ElipsoidGravityField::setA);
	ClassDB::bind_method(D_METHOD("getA"), &ElipsoidGravityField::getA);

	ADD_PROPERTY(PropertyInfo(Variant::REAL, "a", PROPERTY_HINT_RANGE, "-1024,1024,0.001"), "setA", "getA");
}
