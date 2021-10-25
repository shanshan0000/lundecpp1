#include "graph.h"

void Graph::addEdge(unsigned int i, unsigned int j){
    if (i>=getNbVertices()||j>=getNbVertices())
        throw GraphException("bad argument: a vertex of the edge is not defined");
    if (std::find(adj[i].begin(),adj[i].end(),j)!=adj[i].end())
        throw GraphException("edge has already been defined");
    adj[i].push_back(j);
// OU adj[i].insert(adj[i].end(),j); -> plus intéressant si on veut changer de conteneur
    nb_edges++;
}

void Graph::removeEdge(unsigned int i, unsigned int j){
    if (i>=getNbVertices()||j>=getNbVertices())
        throw GraphException("bad argument: a vertex of the arc is not defined");
    // Should include <algorithm>
    // ref: https://stackoverflow.com/questions/4604136/how-to-search-for-an-element-in-an-stl-list/4604177
    list<unsigned int>::iterator it=find(adj[i].begin(),adj[i].end(),j);
    if (it!=adj[i].end()) { adj[i].erase(it); nb_edges--;}
    else throw GraphException("bad argument: a vertex of the arc is not defined");
}

const list<unsigned int>& Graph::getSuccessors(unsigned int i) const{
    if (i>=getNbVertices())
        throw GraphException("bad argument: vertex not defined");
    return adj[i];
}

const list<unsigned int> Graph::getPredecessors(unsigned int j) const{
    if (j>=getNbVertices())
        throw GraphException("bad argument: vertex not defined");
    list<unsigned int> res;
    for(unsigned int i=0; i<adj.size(); i++)
        if (find(adj[i].begin(),adj[i].end(),j)!=adj[i].end())
            res.insert(res.end(),i);
    return res;
}

ostream& operator<<(ostream& f, const Graph& G){
    f<<"Graph "<<G.getName()<<" ("<<G.getNbVertices()
     <<" vertices and "<<G.getNbEdges()<<" edges)"<<"\n";
    for(size_t i=0; i<G.getNbVertices(); i++) {
        f<<i<<":";
        for(list<unsigned int>::const_iterator it=G.getSuccessors(i).begin(); it!=G.
                getSuccessors(i).end(); ++it) f<<*it<<" ";
        f<<"\n";
    }
    return f;
}