
#include <Polygon_Niceness.h>
#include <fstream>
#define delta 0.5
#define SPIKE_GAP 20
using namespace std;

void generate_parameterised_cross_polygons(Point_2 *p, int k1,int k2,int k3,int k4,int k5,int k6)
{       
        /*These are parameters definings the length, width of the two rectangles. Also, the relative position w.r.t each other*/
        
        CGAL:Random rand;
        //Point_2 p[12];
        for(int i=0;i<12;i++)
        {       
                p[i]=Point_2(0,0);
        }
        int x=  rand.get_int(10,2000);
        int y=  rand.get_int(10,2000);
        
        /* This is the startpoint of the polygon from where we construct the cross by using the parameters provided */
        p[0] = Point_2(x,y);  
        p[1]= Point_2(x,y+k2);
        p[2]= Point_2(x+k3,y+k2);
        p[3]= Point_2(x+k3,y+k2+k4);
        p[4]= Point_2(x,y+k2+k4);
        p[5]= Point_2(x,y+k2+k4+k5);
        p[6]= Point_2(x-k1,y+k2+k4+k5);
        p[7]= Point_2(x-k1,y+k2+k4);
        p[8]= Point_2(x-k1-k6,y+k2+k4);
        p[9]= Point_2(x-k1-k6,y+k2);
        p[10] =Point_2(x-k1,y+k2);
        p[11]= Point_2(x-k1,y);
                
       // for(int j=0;j<12;j++)
         //     file << p[j]<<endl;
        
}
void generate_random_plus(int num)
{
        ofstream file;
        file.open("plus_random_.txt");
        //Point_Set poly_point_set;
        CGAL:Random rand;
        for(int k=0;k<num;k++)
        {
                Point_2 p[12];
                for(int i=0;i<12;i++)
                p[i]=Point_2(0,0);
                int x=rand.get_int(10,2000);
                int y= rand.get_int(10,2000);
                
                p[0] = Point_2(x,y);
                
                int k1,k2,k3,k4,k5,k6;
                  
                k1=rand.get_int(50,100);
                k2=rand.get_int(50,100);
                k3=rand.get_int(50,100);
                k4=rand.get_int(50,100);
                k5=rand.get_int(50,100);
                k6=rand.get_int(50,100);
                
        	       	
		generate_parameterised_cross_polygons(p,k1,k2,k3,k4,k5,k6);	 
                for(int j=0;j<12;j++)
                        file << p[j]<<endl;
                
                file<<endl;
        }
	return;
                
}     
int main()
{
	generate_random_plus(100);
	return 0;	
}
