#include<bootst/graph/graphviz.hpp>
std::ostream& operator<<*std::ostream & out,const graph_type &g)
{
	detail::vertex_writer<graph_type>vw(g);
	boost::write_graphviz(out,g,vw);
	return out;
}

namespace detail
{
	template<class GraphT>
	class vertex_writer
	{
		public:
			explicit vertetx_writer(const GraphT &g)
			{
				g_(g)
			}


	template<class VertexDescriptorT>
	void operator()(std::ostream& out,const VertexDescriptorT &d)const
	{
		out<<boost::get(boost::vertex_bundle,g)[d]<<std::endl;
	}

	};
}



