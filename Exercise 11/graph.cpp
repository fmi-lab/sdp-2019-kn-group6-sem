#include "graph.h"
#include<iostream>

template <typename T>
typename forward_list<forward_list<T>>::const_iterator Graph<T>::getVertexPosition(const T& vertex) const
{
    typename forward_list<forward_list<T>>::const_iterator i = graph.begin();
    while(i != graph.end())
    {
        typename forward_list<T>::const_iterator vertexes = i->begin();
        if(vertex == *vertexes)
        {
            return i;
        }
        i++;
    }
    return graph.end();
}

template <typename T>
typename forward_list<T>::iterator Graph<T>::getEdgePosition(const pair<T,T>& edge) const
{
    typename forward_list<forward_list<T>>::iterator i_first = getVertexPosition(edge.first);
    typename forward_list<forward_list<T>>::iterator i_second = getVertexPosition(edge.second);
    if(i_first != graph.end())
    {
        if(i_second != graph.end())
        {
            typename forward_list<T>::iterator vertexes = i_first->begin();
            while(vertexes != i_first->end())
            {
                if(*vertexes == edge.second)
                {
                    return vertexes;
                }
            }
        }
        return i_first->begin();
    }
//    if(graph.empty()){
//        return graph.begin();
//    }
//    return graph.begin()
}

template <typename T>
void Graph<T>::addVertex(const T& vertex)
{
    typename forward_list<forward_list<T>>::const_iterator i = getVertexPosition(vertex);

    if(i != graph.end()){
        return;
    }
    graph.emplace_front(forward_list<T>(vertex));
}

template <typename T>
void Graph<T>::addEdge(const pair<T,T>& edge)
{
    typename forward_list<T>::iterator vertexes = getEdgePosition(edge);
    if(vertexes != graph.end()){
        addVertex(edge.first);
        addVertex(edge.second);
        typename forward_list<forward_list<T>>::iterator i = getVertexPosition(edge.first);
        i->emplace_after(vertexes, edge.second);
        return;
    } else if(*vertexes == edge.first){
        addVertex(edge.second);
        typename forward_list<forward_list<T>>::iterator i = getVertexPosition(edge.first);
        i->emplace_after(vertexes, edge.second);
    } else if (*vertexes == edge.second){
        return;
    }
}



int main()
{
    Graph<int> graph;
    graph.addVertex(3);
    graph.addVertex(5);
    graph.addVertex(10);
    graph.addVertex(7);
    graph.addVertex(3);

    graph.addEdge(pair<int,int>(3,5));
}
