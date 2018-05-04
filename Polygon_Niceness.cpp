#include "Polygon_Niceness.h"
//#include<predicates.h>
#include <fstream>
using namespace std;
#define delta 0.5
//typedef ostream_iterator<Point_2>(cout,"\n") out;
#define SPIKE_GAP 20

/*
void generate_polygon_plus()
{
	ofstream file;
        file.open("polygons_with_spikes.txt");
        //Point_Set poly_point_set;
        CGAL:Random rand;
	
	//get the first rectangle
	int x1 = rand.get_int(10,2000);	
	int x2 = rand.get_int(10,2000);
	int b1 = x1>x2 ? x1-x2 : x2-x1;
	
	int y1 = rand.get_int(10,2000);
	int y2 = rand.get_int(10,2000); 

	int b2 = y1>y2 ? y1-y2 : y2-y1;
	
	int l1= b1>b2 ? b2:b2;
	if(l1==b1) b1=b2;

	//generate second polygon such that it cuts the first 

	






	return;

}
*/
void generate_parameterised_cross_polygons(int k1,int k2,int k3,int k4,int k5,int k6) 
{
	/*These are parameters definings the length, width of the two rectangles. Also, the relative position w.r.t each other*/
	/*   __
	     | |
_____________| |_________
|_____________   ________|
		|		


	*/	
	ofstream file;
        file.open("plus.txt");
        
	CGAL:Random rand;
        Point_2 p[12];
        for(int i=0;i<12;i++)	
	{
		p[i]=Point_2(0,0);
        }
	int x=	rand.get_int(10,2000);
        int y= 	rand.get_int(10,2000);
	
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
		
	for(int j=0;j<12;j++)
              file << p[j]<<endl;
	file<<endl;
}
void generate_random_plus()
{
	ofstream file;
        file.open("plus.txt");
        //Point_Set poly_point_set;
        CGAL:Random rand;
	for(int k=0;k<100;k++)
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
		
		for(int j=0;j<12;j++)
			file << p[j]<<endl;
		
		file<<endl;
	}
	
}


/*
void generate_comd()
{
	ofstream file;
        file.open("polygons_with_spikes.txt");
        //Point_Set poly_point_set;
        CGAL:Random rand;

	//for(int i=0;i<100;i++)
	//{
		int x= rand.get_int(10,20);
		int y=rand.get_int(10,20);
		
		//Base of the comb;
		int base_len =  rand_int(100,500);
		Point_2 base_x = Point_2(x,y);
		Point_2 base_y = Point_2(x+ base_len,y);
			
		//Length of spikes : 
		int spike_len[10];
		for(int j=0;j<10;j++)
			spike_len[j]= base_len/(j+2);
		
		int base_width = rand_int(50,100);
		//varying width might help as it would change the fatness
		
		int spike_width[10]; //also increases the fatness as its increased;
		
		
		for(int j=0;j<10;j++)
		{
			spike_width[j]= base_width/(j+5);
			
		}				
		
	for(int i=0;i<10;i++) //for different spike lengths
        {
                //for different spike widths
                for(int j=0;j<10;j++)
                {
			 generate_comb_given(base_len,base_width, spike_len[i],spike_width[j]);
                }
        }
	
}
void generate_comb_given(int base_len, int base_width, int spike_len[],int spike_width[])
{
	Point_2 base_left = Point_2(x,y);
        Point_2 base_right = Point_2(x+ base_len,y);	
	int num_spikes = base_width/(spike_width+SPIKE_GAP);
	int num_points= 4*num_spikes;
	int p[num_points];
	for(int i=base_left[0] ;i<= base_right[0] ;i++)
	{
		if(i==base_left[0] || i==base_right[0])
		{
										
		}
	}
			
}	
void generate_polygons_with_spikes()
{
	
	ofstream file;
	file.open("polygons_with_spikes.txt");
	//Point_Set poly_point_set;
	CGAL:Random rand;
	//Generate 100- Polygons with random size;
	
	for(int i=0;i<100;i++)
	{
		int chord_fscore = 1;
		Polygon_2 Poly;
		int Poly_size = rand.get_int(10,200);
		for(int i=0;i<Poly_size;i++)
		{
			Poly.push_back(Point_2(0,0));
		}
		VertexIterator Vertex_it;
        	Vertex_it = Poly.vertices_begin();
        	CGAL::random_convex_set_2(Poly_size,Vertex_it, Point_generator(100));
		
		for(EdgeIterator ei=Poly.edges_begin();ei!=Poly.edges_end();ei++)
		{
			Point_2 p1(ei[0][0][0],ei[0][0][1]);	
			Point_2 p2(ei[0][1][0],ei[0][1][1]);
			Segment_2 s(p1,p2);
		        FT dist = s.squared_length();
        		FT distance= sqrt((dist));
        		FT total_points= approximate_division (distance,delta);
			
			vector<Point_2>ps;
			for(int i=0;i<total_points;i++)
			{
				ps.push_back(Point_2(0,0));
					
			}
                        Vector_2 vec = s.to_vector();
			for(int i=0;i<total_points;i++)
        		{
				
				if(i==0) 
				{
					ps[i]=p1;
                			file <<ps[i] <<endl;
				}
				else if(i==total_points-1)
				{
					ps[i]=p2;
					file <<ps[i] <<endl;
				}
				else
				{ 
					ps[i] =ps[i-1]+(delta*delta/vec.squared_length())*vec;
					file <<ps[i] <<endl;
				}
			}
						
		}
	}
	//CGAL::random_convex_set_2(100,ostream_iterator<Point_2>(file,"\n"), Point_generator(100)); //lets write to a file later
	//Here argument to 100 gives its standard deviation
	file.close();
}

void generate_polygons_with_dents()
{
	
}

void generate_convex_polygons()
{

}
void generate_orthogonal_polygons()
{
	//Generating Orthogonal Polygons is not straightforward. Needs some time
	for(int i=0;i<100;i++)
	{
		int size = Get_rand_int(100,300);
		int grid[size][size];
		for(int i=0;i<100;i++)
		{
			for(int j=0;j<n;j++)
				grid[i][j]=0;	
		}
		int block_size = Get_rand_int(0,size);
		for(int i=0;i<block_size;i++)
		{
			int block_x=Get_rand_int(0,block_size);
			int block_y=Get_rand_int(0,block_size);	
			//block selected is on the corners
			if(block_x == 0 || block_y==0 || block_x ==block_size-1 ||block_y==block_size-1)
			{
				//check if it is connected to atleast one of its adjacent block
				if(block_x==0)
				{
					if(block_y!=0 && block_y!= n-1)
					{
						if(grid[i][j-1]==0||grid[i][j+1]==0)	
							grid[i][j]=1;			  	
					}
					else
					{
						if(block_y==0)
							
					}					
				}
				if(block_x==n-1)
				{	
					if(block_)	
				}	
				if(block_y==0)
				{
		
				}
				if(block_y==n-1)
				{
					
				}
			}	
		}
	}
}
	
void chord_fscore(EdgeIterator e)
{	
	
	for(int i=0;i<n-2;i++)
	{
		resolute_segment(polygon+i,polygon+i+1,);
	}
	resolute_segment(polygon+n-1,polygon);
				
}
void resolute_edge(Point_2 p1,Point_2 p2,Point_set *ps)
{
	
	for(int i=0;i<)
	{
		Segment s(p1,p2);
		Vector_2 vec = s.to_vector();
		Point_2 new = p1 + (d * d / v.squared_length()) * v;
		ps.ps
	}	
	//Point_2 mp= midpoint(p1,p2);
	resolute_edge(p1,mp,ps);
	resolute_edge(mp,p2,ps+total_points_);
	return;						
}

void alpha_fatness_score();

*/
int main()
{

	generate_plus();
	return 0;
}
