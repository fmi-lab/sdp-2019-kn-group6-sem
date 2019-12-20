#include<forward_list>
//#include<pair>

using namespace std;

template <typename T>
class Graph{
private:
    forward_list<forward_list<T>> graph;

public:
//    Graph();
//    Graph(const Graph&);
//    ~Graph();
//    Graph& operator=(const Graph&);

    typename forward_list<forward_list<T>>::const_iterator getVertexPosition(const T&) const;
    typename forward_list<T>::iterator getEdgePosition(const pair<T,T>& edge) const;

    void addVertex(const T&);
    void addEdge(const pair<T,T>&);

};
