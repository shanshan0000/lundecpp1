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

    virtual void ajouter(const A &, const B &);

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
    return f;
}


template<class A>
class endorelation : public relation<A, A> {
public:
    endorelation(const string &n, const string &sym,
                 const set<A> &sd) : relation<A, A>(n, sym, sd, sd) {}

    bool est_transitive() const;

    bool est_reflexive() const;

    bool est_symetrique() const;
};


template<class A>
bool endorelation<A>::est_symetrique() const {
    for (typename set<pair<A, A> >::const_iterator it = this->couples.begin(); it != this->couples.
            end(); ++it) {
        if (!this->est_en_relation(it->second, it->first)) return false;
    }
    return true;
}


template<class A, class B>
class fonction : public relation<A, B> {
public:
    fonction(const string &n, const string &sym,
             const set<A> &s, const set<B> &d) :
            relation<A, B>(n, sym, s, d) {}

    void ajouter(const A &, const B &);
};

template<class A, class B>
void fonction<A, B>::ajouter(const A &a, const B &b) {
    if (this->source->find(a) == this->source->end() ||
        this->destination->find(b) == this->destination->end())
        throw "erreur";
    for (typename set<pair<A, B> >::iterator it = this->couples.begin();
         it != this->couples.end(); ++it) {
        if (it->first == a) throw "erreur";
    }
    this->couples.insert(make_pair(a, b));
}


#endif //CPP_RELATION_H
