#ifndef POLY_RESOLUTION_H
#define POLY_RESOLUTION_H
#include "Polygon_Niceness.h"

#define DELTA 0.25
using namespace std;
void resolve_Edge(Point_2 p1, Point_2 p2 ,Polygon_2 &resolved_Poly);
void resolute_Polygon(Polygon_2 Poly,vector<Point_2> &resolved_vertices);


#endif
