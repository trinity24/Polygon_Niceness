#include "Polygon_Niceness.h"
#include <CGAL/basic.h>
#include <cassert>
#include <vector>
#include <algorithm>
#include <CGAL/circulator.h>

typedef  std::vector<int>::iterator                  I;
typedef  CGAL::Circulator_from_iterator<I>           Circulator;
typedef  CGAL::Container_from_circulator<Circulator> Container;
typedef  Container::iterator                         Iterator;
using namespace std;
int main() 
{
    std::vector<int> v;
    v.push_back(5);
    v.push_back(2);
    v.push_back(9);

	Polygon_2 P;
	P.push_back(Point_2(1,2));
	P.push_back(Point_2(2,8));
	P.push_back(Point_2(5,6));
	P.push_back(Point_2(10,10));

	VertexIterator left= P.left_vertex();
	VertexIterator right= P.right_vertex();
	VertexIterator top= P.top_vertex();
	VertexIterator bottom= P.bottom_vertex();

	cout<<left[0][0]<<endl;
	cout<<right[0][1]<<endl;
	cout<<top[0][1]<<endl;
	cout<<bottom[0][1]<<endl;

    Circulator c( v.begin(), v.end());
    Container  container( c);
    std::sort( container.begin(), container.end());
    Iterator i = container.begin();
    assert( *i == 2);
    i++;    assert( *i == 5);
    i++;    assert( *i == 9);
    i++;    assert(  i == container.end());
    return 0;
}
