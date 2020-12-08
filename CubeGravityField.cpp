#include "CubeGravityField.h"
#include <core\engine.h>
#include <scene\3d\physics_body.h>
#include <cmath>
#include <iostream>

Vector3 CubeGravityField::calcForce(RigidBody *body) {
	std::cout << "This is getting called?\n";
	Vector3 ret;
	Vector3 bodyPos = body->get_translation();
	Vector3 localSpace = bodyPos - get_translation();

	if (localSpace.x > length / 2 && localSpace.y > width / 2 && localSpace.z > height / 2) {
		//Not inside cube
		std::cout << "Not in the cube\n";
		std::cout << "Local space coords are " << localSpace.x << " " << localSpace.y << " " << localSpace.z << "\n";
		ret = -localSpace;
	}
	ret = -localSpace;

	return ret;
}

//TODO: Add getters and setters for prameters
void CubeGravityField::setLength(float l) {
	length = l;
}
float CubeGravityField::getLength() {
	return length;
}

void CubeGravityField::setWidth(float w) {
	width = w;
}
float CubeGravityField::getWidth() {
	return width;
}

void CubeGravityField::setHeight(float h) {
	height = h;
}
float CubeGravityField::getHeight() {
	return height;
}

//Bind getters and setters and add paramters as property
void CubeGravityField::_bind_methods() {
	ClassDB::bind_method(D_METHOD("setLength", "l"), &CubeGravityField::setLength);
	ClassDB::bind_method(D_METHOD("getLength"), &CubeGravityField::getLength);

	ClassDB::bind_method(D_METHOD("setWidth", "w"), &CubeGravityField::setWidth);
	ClassDB::bind_method(D_METHOD("getWidth"), &CubeGravityField::getWidth);

	ClassDB::bind_method(D_METHOD("setHeight", "h"), &CubeGravityField::setHeight);
	ClassDB::bind_method(D_METHOD("getHeight"), &CubeGravityField::getHeight);


	ADD_PROPERTY(PropertyInfo(Variant::REAL, "Length", PROPERTY_HINT_RANGE, "-1024,1024,0.001"), "setLength", "getLength");
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "Width", PROPERTY_HINT_RANGE, "-1024,1024,0.001"), "setWidth", "getWidth");
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "Height", PROPERTY_HINT_RANGE, "-1024,1024,0.001"), "setHeight", "getHeight");
}
