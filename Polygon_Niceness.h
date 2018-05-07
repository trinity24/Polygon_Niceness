// All the headerfiles are included in this
#ifndef POLYGON_NICENESS_H
#define POLYGON_NICENESS_H

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <CGAL/circulator.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
#include <CGAL/Polygon_2.h>
#include <CGAL/point_generators_2.h>
#include <CGAL/random_polygon_2.h>
#include <CGAL/Random.h>
#include <CGAL/algorithm.h>
#include <CGAL/Polygon_with_holes_2.h>
#include <CGAL/Boolean_set_operations_2.h>
#include <CGAL/random_convex_set_2.h>
#include <CGAL/MP_Float.h>
#include <CGAL/number_utils.h>
#include <CGAL/Gmpfr.h>
#include <CGAL/Algebraic_structure_traits.h>
#include <CGAL/Lazy_exact_nt.h>


typedef CGAL::Exact_predicates_exact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef K::Segment_2 Segment_2;
typedef CGAL::Polygon_2<K> Polygon_2;
typedef Polygon_2::Vertex_iterator VertexIterator;
typedef Polygon_2::Edge_const_iterator EdgeIterator;
typedef Polygon_2::Edge_const_circulator EdgeCirculator;
typedef CGAL::Vector_2<K> Vector_2;
typedef CGAL::Polygon_with_holes_2<K> Polygon_with_holes_2;
typedef K::FT FT;
typedef std::vector<Point_2> Point_Set;
typedef std::size_t size_t;
typedef CGAL::Random Random;
typedef Polygon_2::Vertex_circulator VertexCirculator;
//typedef CGAL::<Algebraic_structure_traints<Lazy_exact_nt <Gmpq> >::Sqrt sqrt;
//#define CGAL::Random.get_int Get_rand_int
//#define CGAL::Random.get_double Get_rand_double
//#define CGAL::random_convex_set_2 Get_rand_convex
typedef CGAL::Creator_uniform_2< double, Point_2 > Creator_uniform_2;
typedef CGAL::Random_points_in_square_2< Point_2, Creator_uniform_2 > Point_generator;

/*
random_convex_set_2 (size_t n,
OutputIterator o,
PointGenerator pg,
Traits t = Default_traits)
Example : random_convex_set_2 (n,o,pg,Traits t = Default_traits)

The concept PointGenerator defines the requirements for a point generator, 
which can be used in places where input iterators are called for.
Polygon_Generator : Has CGAL::Random_points_on_square_2<Point_2, Creator>
Creator: Creator_uniform_2<Arg, Result> Results is constructed from two Arg arguments

Default traits :  
*/




//Predicates: We will adopt them from the CGAL libraries
//Predicates needed : 


#endif
