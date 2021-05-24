// usage of boost graph library
// very easy to use
// there is three things to remember
// how to store graph structre
// how to associate properties with edges and vertices
// distances weights etc.
// how to get those proprites in and out of those alogrithms
// represnting graph = adjacency list and wrapping and exisitng graph structure
// add_vertex,remove_vertex


#include<iostream>
#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/graphviz.hpp>
#include<boost/graph/properties.hpp>
#include<boost/property_map/property_map.hpp>
#include<boost/graph/named_function_params.hpp>

// we have a struct for vertex and a struct for storing the edge
//
struct VertexData
{
        std::string first_name;
        int num;
};

struct EdgeData
{
        std::string edge_name;
        double dist;
};


// we shall create a simple adjaceny list with no extra properties
//
void example()
{
        typedef boost::adjacency_list<boost::vecS,boost::vecS,
                                        boost::directedS,
                                        boost::no_property,
                                        boost::no_property
                                     > MyGraphType;
        //first two arguments are the too boost::vectors classes to store your vertices and also the edges
        //third template is like a bool directed or undirected
        //no_property(fourth argument) is someting that will hold your store the vertex property and edge property
        //
        //
        MyGraphType G;
        auto v1=add_vertex(G);
        auto v2=add_vertex(G);
        auto e=add_edge(v1,v2,G);
        //add_vertexx and add_edge are global functions
        //depending on the type of graph your passing you can modify the templte
        //
        //we can now print out the graph
        //
        auto vpair=vertices(G);
        // the above function returns pair of first and last iterator pointers
        for(auto iter=vpair.first;iter!=vpair.second;iter++)
        {
                std::cout<<"vertex"<<*iter<<std::endl;
        }

        auto epair=edges(G);
        for(auto iter=epair.first;iter!=epair.second;++iter)
        {
                std::cout<<"edge"<<source(*iter,G)<<"."<<target(*iter,G)<<std::endl;
        }
}


void second_example()
{
        typedef boost::adjacency_list<boost::vecS,boost::vecS,boost::undirectedS,VertexData,boost::property<boost::edge_weight_t,double>> MyGraphType;
        //the parameter VertexData is the structure we declared above and are using here vertex data is storage properies for vertex.
        //edge_weight for each of the edge_weight_t i want to associate a double
        //
        MyGraphType G(5);
        G[0].first_name="Jeremy";
        //first is the edge. second is a bool telling you whether this is a new edge or an existing one
        auto e=add_edge(1,2,G).first;
        //add edge returns a pair.The first is the refrence to the pair and the second is whether the new edge has been created or not.
        //this weight can be assiggned using a weight map
        boost::property_map<MyGraphType,boost::edge_weight_t>::type weightmap=get(boost::edge_weight,G);
        weightmap[e]=10.1;
        std::cout<<"vertex name"<<G[0].first_name<<std::endl;
        std::cout<<"name getter"<<get(&VertexData::first_name,G)[0]<<std::endl;
        std::cout<<"saved weight"<<weightmap[e]<<std::endl;
        put(weightmap,e,20);
        std::cout<<"saved weight"<<get(weightmap,e)<<std::endl;
}

void third_example()
{
        typedef boost::adjacency_list<boost::vecS,boost::vecS, boost::directedS, VertexData,boost::property<boost::edge_weight_t,double,EdgeData>>MyGraphType;
        MyGraphType G(5);
        G[0].first_name="Jeremy";
        auto e=add_edge(1,2,G).first;
        G[e].edge_name="the edge";
        boost::property_map<MyGraphType,boost::edge_weight_t>::type weightmap=get(boost::edge_weight,G);
        weightmap[e]=10.1;
        std::cout<<"vertex name"<<G[0].first_name<<std::endl;
        std::cout<<"name getter"<<get(&VertexData::first_name,G)[0]<<std::endl;
        std::cout<<"saved edge name"<<G[e].edge_name<<std::endl;
        std::cout<<"edge name getter"<<get(&EdgeData::edge_name,G)[e]<<std::endl;
        std::cout<<"saved weight"<<weightmap[e]<<std::endl;
}



int main()
{
        example();
        second_example();
        third_example();
        return 0;
}
