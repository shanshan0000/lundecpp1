#ifndef CPP_GRAPH_H
#define CPP_GRAPH_H

#include <vector>
#include <stdexcept>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

class GraphException : public exception {
    string info;
public:
    GraphException(const string& i) noexcept :info(i){}
    virtual ~GraphException() noexcept {}
    const char* what() const noexcept { return info.c_str(); }
};

class Graph {
private:
    vector<list<unsigned int> > adj;
    unsigned int nb_edges;
    string name;

public:
    Graph(const string& n,size_t nb):name(n),adj(nb),nb_edges(0){}
    const string& getName() const { return name; }
    size_t getNbVertices() const { return adj.size(); }
    size_t getNbEdges() const { return nb_edges; }
    void addEdge(unsigned int i, unsigned int j);
    void removeEdge(unsigned int i, unsigned int j);
    const list<unsigned int>& getSuccessors(unsigned int) const;
    const list<unsigned int> getPredecessors(unsigned int) const;
};

ostream& operator<<(ostream& f, const Graph& G);


#endif //CPP_GRAPH_H
