#ifndef CPP_RELATION_H
#define CPP_RELATION_H

#include <iostream>
#include<set>
#include<string>

using namespace std;

template<class A, class B>
class relation {
public:
    relation(const string &n, const string &sym, const set<A> &s, const set<B> &d);

    const string &get_nom() const { return nom; }

    const string &get_symbole() const { return symbole; }

    const set<A> &get_source() const { return *source; }

    const set<B> &get_destination() const { return *destination; }

    void ajouter(const A &, const B &);

    bool est_en_relation(const A &, const B &) const;

    class iterator : public set<pair<A, B> >::const_iterator {
    public:
        iterator(typename set<pair<A, B> >::const_iterator it
        = set<pair<A, B> >::const_iterator()) :
                set<pair<A, B> >::const_iterator(it) {}
    };

    iterator begin() const { return iterator(couples.begin()); }

    iterator end() const { return iterator(couples.end()); }

protected :
    string symbole;
    string nom;
    const set<A> *source;
    const set<B> *destination;
    set<pair<A, B> > couples;
};


template<class A, class B>
ostream &operator<<(ostream &f, const relation<A, B> &r);


template<class A>
class endorelation : public relation<A, A> {
public:
    endorelation(const string &n, const string &sym, const set<A> &sd) : relation<A, A>(n, sym, sd, sd) {}

    bool est_transitive() const;

    bool est_reflexive() const;

    bool est_symetrique() const;
};



template<class A, class B>
class fonction : public relation<A, B> {
public:
    fonction(const string &n, const string &sym, const set<A> &s, const set<B> &d) :
            relation(n, sym, s, d) {}

    void ajouter(const A &, const B &);
};





#endif //CPP_RELATION_H
