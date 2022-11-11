#ifndef LO02_GRAPH_H
#define LO02_GRAPH_H

#include<map>
#include<set>
#include<iostream>
#include<string>

using namespace std;

class GraphException {
    string info;
public:
    GraphException(const string &str) : info(str) {}

    string getInfo() const { return info; }
};

template<class Vertex>
class GraphG {
private:
    map<Vertex, set<Vertex> > adj;
    unsigned int nbEdges;
    string name;
public:
    GraphG(const string &n) : name(n), nbEdges(0) {}

    const string &getName() const { return name; }

    unsigned int getNbVertices() const { return adj.size(); }

    unsigned int getNbEdges() const { return nbEdges; }

    void addVertex(const Vertex &i);

    void addEdge(const Vertex &i, const Vertex &j);

    void removeEdge(const Vertex &i, const Vertex &j);

    void print(ostream &f) const;

    class vertex_iterator : public map<Vertex, set<Vertex> >::const_iterator {
    public:
        vertex_iterator() : map<Vertex, set<Vertex> >::const_iterator() {}

        vertex_iterator(typename map<Vertex, set<Vertex> >::const_iterator it) :
                        map<Vertex, set<Vertex> >::const_iterator(it) {}

        const Vertex &operator*() const {
            return map<Vertex, set<Vertex> >::const_iterator::operator*().first;
        }
    };

    vertex_iterator begin_vertex() const { return vertex_iterator(adj.begin()); }

    vertex_iterator end_vertex() const { return vertex_iterator(adj.end()); }

    class successor_iterator : public set<Vertex>::const_iterator {
    public:
        successor_iterator() : set<Vertex>::const_iterator() {}

        successor_iterator(typename set<Vertex>::const_iterator it) :
                                    set<Vertex>::const_iterator(it) {}
    };

    successor_iterator begin_successor(const Vertex &x) const;

    successor_iterator end_successor(const Vertex &x) const;

};

template<class V>
void GraphG<V>::addVertex(const V &i) {
    adj[i];
// OU
// adj.insert(make_pair(i,set<V>()));
// OU
//map<V,set<V> >::iterator it=adj.find(i);
//if (it==adj.end()) adj[i]=set<V>();
}

template<class V>
void GraphG<V>::addEdge(const V &i, const V &j) {
    if (adj[i].insert(j).second)
        nbEdges++;
    adj[j];
}

template<class V>
void GraphG<V>::removeEdge(const V &i, const V &j) {
    typename map<V, set<V> >::iterator it = adj.find(i);
    if (it != adj.end())
        nbEdges -= it->second.erase(j);
}

template<class V>
void GraphG<V>::print(ostream &f) const {
    f << "Graph " << getName() << " (" << getNbVertices()
            << " vertices and " << getNbEdges() << "edges)" << "\n";
    for (typename map<V, set<V> >::const_iterator it = adj.begin(); it != adj.end(); ++it) {
        f << it->first << ":";
        for (typename set<V>::const_iterator it2 = it->second.begin();
                    it2 != it->second.end(); ++it2)
            f << *it2 << " ";
        f << "\n";
    }
}

template<class V>
ostream &operator<<(ostream &f, const GraphG<V> &G) {
    G.print(f);
    return f;
}

template<class V>
class print {
    const GraphG<V> &G;
    ostream &flux;
public:
    print(ostream &f, const GraphG<V> &g) : flux(f), G(g) {}

    void operator()(const V &x) {
        flux << x << ":";
        for (typename GraphG<V>::successor_iterator it = G.begin_successor(x); it != G.
                end_successor(x); ++it) {
            flux << *it << " ";
        }
        flux << "\n";
    }
};

//template<class V>
//ostream& operator<<(ostream& f, const GraphG<V>& G){
//    f<<"Graph "<<G.getName()<<" ("<<G.getNbVertices()<<" vertices and "<<G.getNbEdges
//            ()<<" edges)"<<"\n";
//    for_each(G.begin_vertex(), G.end_vertex(), print<V>(f,G) );
//    return f;
//}

template<class V>
typename GraphG<V>::successor_iterator GraphG<V>::begin_successor(const V &x) const {
    typename map<V, set<V> >::const_iterator it = adj.find(x);
    if (it != adj.end())
        return successor_iterator(it->second.begin());
    throw GraphException("bad argument: vertex not defined");
}


template<class V>
typename GraphG<V>::successor_iterator GraphG<V>::end_successor(const V &x) const {
    typename map<V, set<V> >::const_iterator it = adj.find(x);
    if (it != adj.end())
        return successor_iterator(it->second.end());
    throw GraphException("bad argument: vertex not defined");
}

#endif