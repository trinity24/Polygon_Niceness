

#include <Polygon_Niceness.h>
#include <poly_resolution.h>
#include <vector>
#include <fstream>
#include <stack>
#define DELTA 0.25
using namespace std;
void resolute_Edge(vector<Point_2> &v,Point_2 p1,Point_2 p2);
void resolve_Edge(Point_2 p1, Point_2 p2 ,Polygon_2 &resolved_Poly);

void resolute_Polygon(Polygon_2 Poly,vector<Point_2> &resolved_vertices)
{
	
	Polygon_2 resoluted_Poly;
	for(EdgeIterator ei=Poly.edges_begin();ei!=Poly.edges_end();ei++)
        {
                Point_2 p1(ei[0][0][0],ei[0][0][1]);
                Point_2 p2(ei[0][1][0],ei[0][1][1]);
  		resolve_Edge(p1,p2,resoluted_Poly);		            	
     	       	//resolute_Edge(resolved_vertices,p1,p2);
				
        }
	cout<<"Size of resoluted_Polygon is "<<resoluted_Poly.size();
	
}
void resolute_Edge(vector<Point_2> &v,Point_2 p1,Point_2 p2)
{
	
	if(CGAL::square(DELTA) < CGAL::squared_distance(p1,p2))
	{
		Point_2 mp= CGAL::midpoint(p1,p2);						v.push_back(mp);
		resolute_Edge(v, p1,mp);
		resolute_Edge(v, mp,p2);			
        }		
	return;
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
	/*for( vector<Point_2>::iterator it=temp_vec.begin();it!=temp_vec.end();it++)
		cout<<*it<<endl;
*/
	return;
	
}
/*
int main()
{
	ofstream file1;
	file1.open("polygons_resoluted.txt");
	Polygon_2 poly_test;
	
	vector<Point_2> resolved_vertices;
	poly_test.push_back(Point_2(1,1));
	poly_test.push_back(Point_2(1,0));
	poly_test.push_back(Point_2(0,0));
	poly_test.push_back(Point_2(0,1));	
	resolute_Polygon(poly_test,resolved_vertices);
	for(vector<Point_2>::iterator it =resolved_vertices.begin();it!=resolved_vertices.end();it++)
	{
		file1<<*it<<endl;
	}
//	cout<<resolved_vertices.size()<<endl;
		
	return 0;
}*/
