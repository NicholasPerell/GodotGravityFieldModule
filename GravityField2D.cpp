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

	for (int i = 0; i < arr.size(); i++) {
		RigidBody2D * body = Object::cast_to<RigidBody2D>(arr[i]);

		body->add_central_force(calcForce(body));
	}
}
