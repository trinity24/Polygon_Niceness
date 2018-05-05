

#include "Polygon_Niceness.h"
#include <vector>
#include <fstream>
#define DELTA 0.01
using namespace std;
void resolute_Edge(vector<Point_2> &v,Point_2 p1,Point_2 p2);

void resolute_Polygon(Polygon_2 Poly,vector<Point_2> &resolved_vertices)
{
	for(EdgeIterator ei=Poly.edges_begin();ei!=Poly.edges_end();ei++)
        {
                Point_2 p1(ei[0][0][0],ei[0][0][1]);
                Point_2 p2(ei[0][1][0],ei[0][1][1]);
              	
                resolute_Edge(resolved_vertices,p1,p2);
		
        }
	
}
void resolute_Edge(vector<Point_2> &v,Point_2 p1,Point_2 p2)
{
	if(CGAL::square(DELTA) < CGAL::squared_distance(p1,p2))
	{
		Point_2 mp= CGAL::midpoint(p1,p2);	
		v.push_back(mp);
		resolute_Edge(v, p1,mp);
		resolute_Edge(v, mp,p2);
				
        }
	
	return;
}

int main()
{
	ofstream file;
	file.open("polygons_resoluted.txt");
	Polygon_2 poly_test;
	
	vector<Point_2> resolved_vertices;
	poly_test.push_back(Point_2(1,1));
	poly_test.push_back(Point_2(1,0));
	poly_test.push_back(Point_2(0,0));
	poly_test.push_back(Point_2(0,1));	
	resolute_Polygon(poly_test,resolved_vertices);
	for(vector<Point_2>::iterator it =resolved_vertices.begin();it!=resolved_vertices.end();it++)
	{
		file<<*it<<endl;
	}
	cout
		
	return 0;
}
