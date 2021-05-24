#include<iostream>
#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/graphviz.hpp>
#include<boost/graph/properties.hpp>
#include<boost/property_map/property_map.hpp>
#include<boost/graph/named_function_params.hpp>
#include<boost/graph/dijkstra_shortest_paths.hpp>
#include<vector>
#include<malloc.h>
struct VertexData
{
        std::string first_name;
        int num;
        int pred;
        int dist;
};


struct EdgeData
{
        std::string edge_name;
        double dist;
};

void exmaple1()
{
        typedef boost::adjacency_list<boost::vecS,boost::vecS,
                                        boost::directedS,
                                        boost::no_property,
                                        boost::property<boost::edge_weight_t,int> >MyGraphType;


        MyGraphType G;
        int v0=add_vertex(G);
        int v1=add_vertex(G);
        int v2=add_vertex(G);

        //always write the .first,.second tells you if this is a new edge was added
        //(alternately,the edge already existed)
        //
        auto e1=add_edge(v0,v1,10,G).first;
        auto e2=add_edge(v1,v2,20,G).first;

        typedef typename boost::graph_traits<MyGraphType>::vertex_descriptor vertex_descriptor;
        typedef boost::property_map<MyGraphType, boost::vertex_index_t>::type IdMap;
        std::vector<vertex_descriptor>pred(num_vertices(G));
        boost::iterator_property_map<std::vector<vertex_descriptor>::iterator,
                                       IdMap,
                                       vertex_descriptor,
                                       vertex_descriptor&>
                predmap(pred.begin(),get(boost::vertex_index,G));
        //this is property map based on a c style array. The predmap above and dist_map vect use stl vectors
        //
        int *dist=(int *) malloc (num_vertices(G)*sizeof(int));
        boost::iterator_property_map<int *,IdMap, int, int &>
          distmap_ptr(dist,get(boost::vertex_index,G));

        std::vector<int> distvector(num_vertices(G));
        boost::iterator_property_map<std::vector<int>::iterator,IdMap,int, int&>
        distmap_vect(distvector.begin(),get(boost::vertex_index,G));
        dijkstra_shortest_paths(G,v0,predecessor_map(predmap).distance_map(distmap_vect));
}

int main()
{
        exmaple1();
        return 0;
}

