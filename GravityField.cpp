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
		RigidBody *body = Object::cast_to<RigidBody>(arr[i]);

		body->add_central_force(calcForce(body));
	}
}
