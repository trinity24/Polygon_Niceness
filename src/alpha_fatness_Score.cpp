

#include <climits>
#include "Polygon_Niceness.h"
#include <list>
using namespace std;

K::FT intersection_area(Polygon_2 &p1, Polygon_2 &p2);
void Linfinity_ball(Polygon_2 &p,K::FT radius, Point_2 center)
{	
	p.push_back(Point_2(center[0]-radius,center[1]-radius));
	p.push_back(Point_2(center[0]+radius,center[1]-radius));
	p.push_back(Point_2(center[0]+radius,center[1]+radius));
	p.push_back(Point_2(center[0]-radius,center[1]+radius));
	return;	
}


K::FT get_Linfinity_balls(Point_2 center,Polygon_2 &P)
{
	K:FT max_alpha=0;
	Polygon_2 B;   /*Linfinity ball*/
	/*	Maximum radius of the L-infinity ball =max((center_x-left_x),(right_x-center_x)),
						(right_x-center_x),(top_y-center_y),(center_y-bottom_y)) */
	
		
	//left, right, bottom, top are the boundaries of the Polygon
	VertexIterator left1= P.left_vertex();
        VertexIterator right1= P.right_vertex();
        VertexIterator top1= P.top_vertex();
        VertexIterator bottom1= P.bottom_vertex();
	
	K::FT left= left1[0][0];
	K::FT right= right1[0][1];
	K::FT top= top1[0][1];
	K::FT bottom= bottom1[0][1];
	
	K::FT max_radius= CGAL::max(CGAL::max((center[0]-left),(right-center[0])),CGAL::max((top-center[1]),(center[1]-bottom)));			
	K::FT granularity =(max_radius/10);	
	for(int i=1;i< 20  ;i++)
	{			
		Linfinity_ball(B,(i+1)*granularity,center);
		K::FT alpha=intersection_area(P,B);
		max_alpha= CGAL::max(max_alpha, alpha);	
	}	
	return max_alpha;		
}
K::FT alpha_fatness_Score(Polygon_2 &P)
{
	K::FT max_alpha=0;
	for(VertexIterator vi=P.vertices_begin();vi!=P.vertices_end();vi++)
	{
		/* For each point on boundary, get the max_alpha using the Linfinity balls*/

		max_alpha= CGAL::max(get_Linfinity_balls(*vi,P),max_alpha);
						
		
	}
	cout<<"Alpha-Fatness Score :  "<<max_alpha<<endl;
	return max_alpha;

}


K::FT intersection_area(Polygon_2 &p1, Polygon_2 &p2)
{
		
	list<Polygon_with_holes_2> poly_Intersection;
	CGAL::intersection(p1, p2, back_inserter(poly_Intersection));
 	K::FT intersection_Area = 0;
  	for(LIT lit = poly_Intersection.begin(); lit!=poly_Intersection.end(); lit++)
	{
    		intersection_Area+=lit->outer_boundary().area();
  	}
	return intersection_Area;		
}

int main()
{
	cout<<"Something\n";
	
}
