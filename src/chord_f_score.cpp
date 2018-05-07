#include <Polygon_Niceness.h>
#include <Polygon_utilities.h>
#include <climits>
#include <stack>
#include <vector>
#define DELTA 0.25
using namespace std;
void chord_f_Score(Polygon_2 &p);
int get_chord_Score(Point_2 p1,Point_2 p2,Polygon_2 &p);
void get_sub_Polygon(Point_2 p1,Point_2 p2,Polygon_2 &P,Polygon_2 &P_1);
bool intersect_prop(Point_2 a,Point_2 b,Point_2 c, Point_2 d);
bool collinear(Point_2 a ,Point_2 b, Point_2 c);
bool Left(Point_2 a,Point_2 b,Point_2 c);
#define XOR(x,y) (!x)^(!y)
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
void resolve_Edge(Point_2 p1, Point_2 p2,Polygon_2 &resoluted_Poly)
{       
        stack<Point_2> work_Stack;
        work_Stack.push(p1);
        work_Stack.push(p2);
        while(!work_Stack.empty())
        {       
                Point_2 p_right = work_Stack.top();
                work_Stack.pop();
                Point_2 p_left = work_Stack.top();
                work_Stack.pop();
                Point_2 p_mid;
                if(CGAL::square(DELTA) < CGAL::squared_distance(p_left,p_right))              
                {       
                        
                        p_mid= CGAL::midpoint(p_left,p_right);
                        work_Stack.push(p_left);
                        work_Stack.push(p_mid);
                        work_Stack.push(p_right);
                }
                else    
                {       
                        resoluted_Poly.push_back(p_right);
                        if(work_Stack.empty())
                                break;  
                        work_Stack.push(p_left);
                }
        }
        return;
 
}

void resolute_Polygon(Polygon_2 Polygon,Polygon_2 &resoluted_Poly)
{
        
        for(EdgeIterator ei=Polygon.edges_begin();ei!=Polygon.edges_end();ei++)
        {       
                Point_2 p1(ei[0][0][0],ei[0][0][1]);
                Point_2 p2(ei[0][1][0],ei[0][1][1]);                                          	  resolve_Edge(p1,p2,resoluted_Poly);                                               //resolute_Edge(resolved_vertices,p1,p2);
         
        }
}

int main()
{
	Polygon_2 p;
	p.push_back(Point_2(0,0));
	p.push_back(Point_2(0,1));
	p.push_back(Point_2(1,1));
	p.push_back(Point_2(1,0));	
	Polygon_2 resolved_P;
	resolute_Polygon(p,resolved_P);
		
	chord_f_Score(resolved_P);	
	return 0;
}

void chord_f_Score(Polygon_2 &p)
{
	int min= INT_MAX;
	for(VertexIterator vi=p.vertices_begin();vi!=p.vertices_end()-1;vi++)
	{
		for(VertexIterator  vj=p.vertices_begin()+1;vj!=p.vertices_end();vj++)
		{
			if(is_chord(p,*vi,*vj))
				int chord_score=get_chord_Score(*vi,*vj,p)<min ?min=chord_score:min=min;
			
						
		}
	}	
	
}
int get_chord_Score(Point_2 p1,Point_2 p2,Polygon_2 &p)
{
	Polygon_2 P_1,P_2;
	int min=INT_MAX;
	get_sub_Polygon(p1,p2,p,P_1);	
	get_sub_Polygon(p2,p1,p,P_2);
	
	/*Now Polygons P_1,P_2 can be used to get the chord_f_score, by taking their perimeter or area*/	
	return min;
}
void get_sub_Polygon(Point_2 p1,Point_2 p2,Polygon_2 &P,Polygon_2 &P_1)
{
	VertexCirculator vc  = P.vertices_circulator();
	int flag=1;
	if(P.size()>0)
 	{
		while(vc!=NULL)
		{
			if(*vc==p1 && flag==0)
			{	
				flag=1;
				P_1.push_back(p1);
			}
			if(flag)
			{
				P_1.push_back(*vc);
				if(*vc==p2)
				{
					P_1.push_back(*vc);
					break;	
				}
			}
			vc++;	
		}
				
	}
	return;
}
