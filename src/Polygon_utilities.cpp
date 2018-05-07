
#include "Polygon_Utilities.h"
#include "Polygon_Niceness.h"

/*Reference: Computational Geometry in C by O'Rourke*/
bool intersect(Segment_2 s1, Segment_2 s2)
{
	return CGAL::do_intersect(s1._seg, s2._seg);
}
bool is_chord(Polygon_2 &Poly,Point_2 p1,Point_2 p2 )
{
	for(EdgeIterator ei=edges_begin();ei!=edges_end();ei++)
	{
		if(s=Segment_2(p1,p2)!=*ei)
		{
			if(intersect(s1,*ei))	
				return FALSE;		
		}
	}
	return TRUE;		
}
