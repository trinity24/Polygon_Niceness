#include <Polygon_Niceness.h>
#include <climits>

int main()
{
	ifstream file;
	file.open("polygons_resoluted.txt");
		
}
void chord_f_Score(vector<Point_2> &p)
{
	int min_square= INT_MAX;
	for(int i=0;i<p.size()-1;i++)
	{
		for(int j=i+1;j<p.size())
		{
			if(CGAL::squared_distance(p[i],p[j])<min )
				min=CGAL::squared_distance(p[i],p[j]);
			
		}
	}
}

