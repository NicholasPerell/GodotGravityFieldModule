#include "register_types.h"
#include "core/class_db.h"
#include "GravityField2D.h"
#include "ArchGravityField.h"

#include "CubeGravityField.h"
#include "SquareGravityField2D.h"
#include "DiskGravityField.h"
#include "WireGravityField2D.h"


void register_GodotGravityFieldModule_types(){
	ClassDB::register_class<SquareGravityField2D>();
	ClassDB::register_class<ArchGravityField>();
	ClassDB::register_class<CubeGravityField>();
	ClassDB::register_class<DiskGravityField>();
	ClassDB::register_class<WireGravityField2D>();
}

void unregister_GodotGravityFieldModule_types() {
}
