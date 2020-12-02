#pragma once
#include "scene/2d/area_2d.h"
class GravityField2D : public Area2D {
	GDCLASS(SubdivisionNode, MeshIhnstance2D);

protected:
	int numSubdivisions;
	int numTriangles;
	meshparse::mesh *he_mesh;
	//original
	PoolVector2Array vertices;
	PoolColorArray colors;
	//updated
	PoolVector2Array _vertices;
	PoolColorArray _colors;

	bool redraw;

public:
	SubdivisionNode();
	void _notification(int p_what);
	void _update();
	void _ready();
	void _draw();
	void _input(InputEvent *e);
	void catmull_clark(int numDivisions);
};
#endif
