#include "Polygon_Niceness.h"
using namespace std;

int main() 
{

	CGAL:Random rand;

	Point_2 p1= Point_2(rand.get_int(5,10),rand.get_int(10,20));
	Point_2 p2= Point_2(rand.get_int(5,10),rand.get_int(10,20));
	Point_2 mp= CGAL::midpoint(p1,p2);
        K::FT squared_dis = CGAL::squared_distance(p1,p2);
        K::FT dis = CGAL::sqrt(squared_dis);
	cout<<dis<<endl;
		
	return 0;
}
