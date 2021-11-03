#include <iostream>
#include "graph.h"

int main() {
    try{
        GraphG<char> G2("G2");
        G2.addVertex('a'); G2.addVertex('b'); G2.addEdge('a','c');
        G2.addEdge('a','d'); G2.addEdge('d','e'); G2.addEdge('e','b');
        cout<<G2;
        cout<<"vertices of G2 are: ";
        for(GraphG<char>::vertex_iterator it=G2.begin_vertex();
            it!=G2.end_vertex(); ++it) cout<<*it<<" ";
        cout<<"\nsuccessors of a: ";
        for(GraphG<char>::successor_iterator it=G2.begin_successor('a');it!=G2.end_successor('a'); ++it){ std::cout<<*it<<" "; }
        GraphG<string> G3("Pref");
        G3.addEdge("LO21","IA01"); G3.addEdge("IA02","IA01"); G3.addEdge("IA01","NF17");
        G3.addEdge("IA02","NF16"); G3.addEdge("NF93","NF16");
        cout<<G3;
    }catch(exception e){ std::cout<<e.what()<<"\n"; }
    return 0;
}