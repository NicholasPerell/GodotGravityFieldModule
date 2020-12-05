#include "ArchGravityField.h"
#include <core\engine.h>
#include <scene\3d\physics_body.h>
#include <cmath>

Vector3 ArchGravityField::calcForce(RigidBody *body) {
	
	Vector3 ret;

	//TODO: Add calculations here

	return ret;
}


//TODO: Add getters and setters for prameters
void ArchGravityField::setA(float aPram) {
	a = aPram;
}
float ArchGravityField::getA() {
	return a;
}

//Bind getters and setters and add paramters as property
void ArchGravityField::_bind_methods() {
	ClassDB::bind_method(D_METHOD("setA", "h"), &ArchGravityField::setA);
	ClassDB::bind_method(D_METHOD("getA"), &ArchGravityField::getA);

	ADD_PROPERTY(PropertyInfo(Variant::REAL, "a", PROPERTY_HINT_RANGE, "-1024,1024,0.001"), "setA", "getA");
}
