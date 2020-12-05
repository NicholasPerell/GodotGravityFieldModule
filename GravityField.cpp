#include "GravityField.h"
#include <core\engine.h>
#include <scene\3d\physics_body.h>

GravityField::GravityField() {
}

void GravityField::_notification(int p_what) {
	switch (p_what) {
		case NOTIFICATION_READY: {

			break;
		}
		case NOTIFICATION_PHYSICS_PROCESS: {
			if (!Engine::get_singleton()->is_editor_hint()) {
				applyForce();
			}

			break;
		}
	}
}

void GravityField::applyForce() {
	Array arr = get_overlapping_bodies();

	for (int i = 0; i < arr.size(); i++) {
		if (Physics2DServer::get_singleton()->body_get_mode(Object::cast_to<PhysicsBody>(arr[i])->get_rid()) == PhysicsServer::BODY_MODE_RIGID)
		{
			RigidBody* body = Object::cast_to<RigidBody>(arr[i]);
			body->add_central_force(calcForce(body));
		}
	}
}

float GravityField::getGravityScale() {
	return gravityScale;
}
void GravityField::setGravityScale(float s) {
	gravityScale = s;
}

void GravityField::_bind_methods() {
	ClassDB::bind_method(D_METHOD("setGravityScale", "s"), &GravityField::setGravityScale);
	ClassDB::bind_method(D_METHOD("getGravityScale"), &GravityField::getGravityScale);

	ADD_PROPERTY(PropertyInfo(Variant::REAL, "Gravity Scale", PROPERTY_HINT_RANGE, "0,1024,0.001"), "setGravityScale", "getGravityScale");
}
