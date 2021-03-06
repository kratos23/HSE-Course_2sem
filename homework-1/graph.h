
#ifndef HOMEWORK_1_GRAPH_H
#define HOMEWORK_1_GRAPH_H

#include <vector>
#include "src/node.h"

template<typename T, typename Vertex, typename GraphType> class GraphTraveler;

template<typename T>
class IGraph {
public:
    virtual ~IGraph() {}

    IGraph() {};

    IGraph(IGraph<T> *_oth) {};

    virtual void AddEdge(int from, int to, T &&_obj) = 0;

    virtual int VerticesCount() const = 0;

    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0;

    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0;

    virtual void DeepFirstSearch(int vertex, std::vector<int> &vertices) const {
        graphTraveler.DeepFirstSearch(vertex, vertices);
    }

    virtual void BreadthFirstSearch(int vertex, std::vector<int> &vertices) const {
        graphTraveler.BreadthFirstSearch(vertex, vertices);
    }

    virtual void GetAllVertices(std::vector<int> &vertices) const  = 0;

    virtual T GetWeight(int from, int to) const = 0;

private:
    mutable GraphTraveler<T, int, IGraph> graphTraveler = GraphTraveler<T, int, IGraph>(this);
};

template<typename T = void>
class IPtrsGraph {
public:
    virtual ~IPtrsGraph() {}

    IPtrsGraph() {};

    virtual void AddEdge(Node<T> *from, Node<T> *to, T &&_obj) = 0;

    virtual int VerticesCount() const = 0;

    virtual void GetNextVertices(Node<T> *vertex, std::vector<Node<T> *> &vertices) const = 0;

    virtual void GetPrevVertices(Node<T> *vertex, std::vector<Node<T> *> &vertices) const = 0;

    virtual void DeepFirstSearch(Node<T> *vertex, std::vector<Node<T> *> &vertices) const {
        graphTraveler.DeepFirstSearch(vertex, vertices);
    }

    virtual void BreadthFirstSearch(Node<T> *vertex, std::vector<Node<T> *> &vertices) const  {
        graphTraveler.BreadthFirstSearch(vertex, vertices);
    }

private:
    mutable GraphTraveler<T, Node<T>*, IPtrsGraph> graphTraveler = GraphTraveler<T, Node<T>*, IPtrsGraph>(this);
};

#endif //HOMEWORK_1_GRAPH_H
