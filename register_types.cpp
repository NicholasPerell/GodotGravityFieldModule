#include "register_types.h"
#include "core/class_db.h"
#include "GravityField2D.h"
#include "Arch3D.h"
#include "Curve2D.h"
#include "Cube3D.h"
#include "SquareGravityField2D.h"
#include "EllipseGravityField2D.h"
#include "Disk3D.h"
#include "Elipsoid.h"
#include "Torus.h"
#include "Wire3D.h"


void register_GodotGravityFieldModule_types(){
	ClassDB::register_class<SquareGravityField2D>();
	ClassDB::register_class<EllipseGravityField2D>();
	ClassDB::register_class<ArchGravityField>();
	ClassDB::register_class<CurveGravityField2D>();
	ClassDB::register_class<CubeGravityField>();
	ClassDB::register_class<DiskGravityField>();
	ClassDB::register_class<ElipsoidGravityField>();
	ClassDB::register_class<TorusGravityField>();
	ClassDB::register_class<WireGravityField>();
}

void unregister_GodotGravityFieldModule_types() {
}
