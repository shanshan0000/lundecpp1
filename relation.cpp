#include "relation.h"


template<class A, class B>
relation<A, B>::relation(const string &n, const string &sym,
                         const set<A> &s, const set<B> &d):
        nom(n), symbole(sym), source(&s), destination(&d) {}

template<class A, class B>
void relation<A, B>::ajouter(const A &a, const B &b) {
    if (source->find(a) == source->end() ||
        destination->find(b) == destination->end())
        throw "erreur";
    couples.insert(make_pair(a, b));
}

template<class A, class B>
bool relation<A, B>::est_en_relation(const A &a, const B &b) const {
    return couples.find(make_pair(a, b)) != couples.end();
}

template<class A, class B>
ostream &operator<<(ostream &f, const relation<A, B> &r) {
    f << "Relation " << r.get_nom() << " :\n";
    for (typename relation<A, B>::iterator it = r.begin(); it != r.end(); ++it)
        f << (*it).first << ' ' << r.get_symbole() << ' ' << (*it).second << "\n";
//r.print(f);
    return f;
}

template<class A>
bool endorelation<A>::est_symetrique() const {
    for (typename set<pair<A, A> >::const_iterator it = this->couples.begin(); it != this->couples.
            end(); ++it) {
        if (!this->est_en_relation(it->second, it->first)) return false;
    }
    return true;
}



template<class A, class B>
void fonction<A, B>::ajouter(const A &a, const B &b) {
    if (this->source->find(a) == this->source->end() ||
        this->destination->find(b) == this->destination->end())
        throw "erreur";
    for (typename set<pair<A, B> >::iterator it = this->couples.begin(); it != this->couples.end();
         ++it) { if (it->first == a) throw "erreur"; }
    this->couples.insert(make_pair(a, b));
}

