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
class endorelation : public relation<A, A> {
public:
    endorelation(const string &n, const string &sym, const set<A> &sd) : relation<A, A>(n, sym, sd, sd) {}

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
    fonction(const string &n, const string &sym, const set<A> &s, const set<B> &d) :
            relation(n, sym, s, d) {}

    void ajouter(const A &, const B &);
};

template<class A, class B>
void fonction<A, B>::ajouter(const A &a, const B &b) {
    if (this->source->find(a) == this->source->end() ||
        this->destination->find(b) == this->destination->end())
        throw "erreur";
    for (typename set<pair<A, B> >::iterator it = this->couples.begin(); it != this->couples.end();
         ++it) { if (it->first == a) throw "erreur"; }
    this->couples.insert(make_pair(a, b));
}


int main() {
    set<unsigned int> chiffres;
    for (unsigned int i = 0; i <= 9; i++) chiffres.insert(i);
    set<char> voy;
    voy.insert('a');
    voy.insert('e');
    voy.insert('i');
    voy.insert('o');
    voy.insert('u');
    relation<unsigned int, char> R("chiffre-voyelle", "R", chiffres, voy);
    R.ajouter(0, 'e');
    R.ajouter(0, 'o');
    R.ajouter(1, 'u');
    R.ajouter(2, 'e');
    R.ajouter(2, 'u');
    R.ajouter(3, 'o');
    R.ajouter(3, 'i');
    R.ajouter(4, 'u');
    R.ajouter(4, 'a');
    R.ajouter(4, 'e');
    R.ajouter(5, 'i');
    R.ajouter(6, 'i');
    R.ajouter(7, 'e');
    R.ajouter(8, 'u');
    R.ajouter(8, 'i');
    R.ajouter(9, 'e');
    R.ajouter(9, 'u');
    std::cout << R;
    if (R.est_en_relation(8, 'u')) cout << "oui\n"; else cout << "non\n";
    set<individu> s;
    s.insert("Bao");
    s.insert("Charles");
    s.insert("Cheng");
    s.insert("Suzanne");
    s.insert("Li");
    s.insert("Pierre");
    s.insert("Xiaokang");
    endorelation<individu> A("amour", "@", s);
    A.ajouter(individu("Bao"), individu("Pierre"));
    A.ajouter(individu("Pierre"), individu("Bao"));
    std::cout << A;
    return 0;
}
