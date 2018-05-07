
#include "Polygon_Utilities.h"
#include "Polygon_Niceness.h"

/*Reference: Computational Geometry in C by O'Rourke*/
#define XOR(x,y) (!x ^ !y)

bool collinear(Point_2 a ,Point_2 b, Point_2 c)
{
        return CGAL::area(a,b,c)==0;
}
bool Left(Point_2 a,Point_2 b,Point_2 c)
{
        return CGAL::area(a,b,c)>0;
}
bool intersect_prop(Point_2 a,Point_2 b,Point_2 c, Point_2 d)
{
        if(collinear(a,b,c)|| collinear(a,b,d)||collinear(b,c,d)||collinear(a,c,d))
                return 0;
        return (XOR(Left(a,b,c),Left(a,b,d)) & XOR(Left(c,d,a),Left(c,d,b)));
}

bool is_chord(Polygon_2 &Poly,Point_2 p1,Point_2 p2 )
{
        for(EdgeIterator ei=Poly.edges_begin();ei!=Poly.edges_end();ei++)
        {
                 Segment_2 s=Segment_2(p1,p2);
                if(s!=*ei)
                {
                        Point_2 e1(ei[0][0][0],ei[0][0][1]);
                        Point_2 e2(ei[0][1][0],ei[0][1][1]);
                        if(intersect_prop(p1,p2,e1,e2))
                         {
                                return false;
                        }
                }
        }
        return true;
}
