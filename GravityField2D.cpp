#include "GravityField2D.h"
#include <scene\2d\physics_body_2d.h>
#include <core\engine.h>


GravityField2D::GravityField2D() {

}

void GravityField2D::_notification(int p_what) {
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


void GravityField2D::applyForce() {
	Array arr = get_overlapping_bodies();
	for (int i = 0; i < arr.size(); i++) 
	{
		if (PhysicsServer::get_singleton()->body_get_mode(Object::cast_to<PhysicsBody2D>(arr[i])->get_rid()) == Physics2DServer::BODY_MODE_RIGID)
		{
			RigidBody2D* body = Object::cast_to<RigidBody2D>(arr[i]);
			body->add_central_force(calcForce(body));
		}
	}
}

float GravityField2D::getGravityScale() {
	return gravityScale;
}
void GravityField2D::setGravityScale(float s) {
	gravityScale = s;
}

void GravityField2D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("setGravityScale", "s"), &GravityField2D::setGravityScale);
	ClassDB::bind_method(D_METHOD("getGravityScale"), &GravityField2D::getGravityScale);

	ADD_PROPERTY(PropertyInfo(Variant::REAL, "Gravity Scale", PROPERTY_HINT_RANGE, "0,1024,0.001"), "setGravityScale", "getGravityScale");
}
