#include "register_types.h"
#include "core/class_db.h"
#include "GravityField2D.h"
#include "SquareGravityField2D.h"
//#include "2DMeshSubdivisionNode.h"

void register_GodotGravityFieldModule_types(){
	//ClassDB::register_class<SubdivisionNode>();
	//ClassDB::register_class<GravityField2D>();
	ClassDB::register_class<SquareGravityField2D>();
}

void unregister_GodotGravityFieldModule_types() {
}
