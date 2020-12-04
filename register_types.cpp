#include "register_types.h"
#include "core/class_db.h"
#include "GravityField2D.h"
#include "SquareGravityField2D.h"
#include "EllipseGravityField2D.h"

void register_GodotGravityFieldModule_types(){
	ClassDB::register_class<SquareGravityField2D>();
	ClassDB::register_class<EllipseGravityField2D>();
}

void unregister_GodotGravityFieldModule_types() {
}
