#ifndef CPP_RELATION_H
#define CPP_RELATION_H

#include <iostream>
#include <set>
#include <string>

using namespace std;

template<class A, class B>
class relation {
public:
    relation(const string &n, const string &s, const set<A> &src, const set<B> &dst);

    const string &get_nom() const { return this->name; }

    const string &get_symbol() const { return this->symbol; }

    const set<A> &get_source() const { return *(this->source); }

    const set<A> &get_destination() const { return *(this->destination); }

    void ajouter(const A &a, const B &b);

    bool est_en_relation(const A &a, const B &b) const;

    class iterator : public set<pair<A, B>>::iterator {
    public:
        iterator(typename set<pair<A, B>>::iterator it) :
                set<pair<A, B>>::iterator(it) {}
    };

    iterator begin() const { return iterator(couples.begin()); }

    iterator end() const { return iterator(couples.end()); }

protected:
    const set<A> *source;
    const set<B> *destination;
    set<pair<A, B>> couples;
private:
    string name;
    string symbol;
};

template<class A, class B>
relation<A, B>::relation(const string &n, const string &s, const set<A> &src, const set<B> &dst):
        name(n), symbol(s), source(&src), destination(&dst) {}

template<class A, class B>
void relation<A, B>::ajouter(const A &a, const B &b) {
    if (source->find(a) != source->end() && destination->find(b) != destination->end())
        couples.insert(make_pair(a, b));
    else
        throw "erreur";
}

template<class A, class B>
bool relation<A, B>::est_en_relation(const A &a, const B &b) const {
    return couples.find(make_pair(a, b)) != couples.end();
}

template<class A, class B>
ostream &operator<<(ostream &f, const relation<A, B> &r) {
    f << "Relation name: " << r.get_nom() << " : \n";
    for (typename relation<A, B>::iterator it = r.begin(); it != r.end(); ++it) {
        f << it->first << r.get_symbol() << it->second << endl;
    }
    return f;
}

template<class A>
class endorelation : public relation<A, A> {
public:
    endorelation(const string &n, const string &s, const set<A> &sd);

    bool est_transitive() const;

    bool est_reflexive() const;

    bool est_symetrique() const;
};

template<class A>
bool endorelation<A>::est_symetrique() const {
    for (typename set<pair<A, A>>::iterator it = this->couples.begin();
         it != this->couples.end(); it++) {
        if (this->couples.find(make_pair((*it).second, (*it).first)) == this->couples.end())
            return false;
    }
    return true;
}

template<class A>
endorelation<A>::endorelation(const string &n, const string &s, const set<A> &sd) :
        relation<A, A>(n, s, sd, sd) {}

template<class A, class B>
class fonction : public relation<A, B> {
public:
    fonction(const string &n, const string &s, const set<A> &src, const set<B> &dst) :
            relation<A, B>(n, s, src, dst) {}

    bool est_injective() const;

    bool est_surjective() const;

    void ajouter(const A &, const B &);
};

template<class A, class B>
void fonction<A, B>::ajouter(const A &a, const B &b) {
    for (typename set<pair<A, B>>::iterator it = this->couples.begin();
         it != this->couples.end(); ++it) {
        if (it->first == a)
            throw "erreur";
    }
    this->relation<A, B>::ajouter(a, b);
}


#endif //CPP_RELATION_H
