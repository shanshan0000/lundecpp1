#ifndef CPP_DISTRIBUTEUR_H
#define CPP_DISTRIBUTEUR_H

#include<list>

using namespace std;

template<class T>
class Distributeur {
public:
    virtual void put(const T &x) = 0;

    virtual void remove() = 0;

    virtual const T &item() const = 0;

    virtual unsigned int size() const = 0;

    bool empty() const {
        return size() == 0;
    }
};


template<class T>
class Pile : public Distributeur<T>, private list<T> {
public:
    void put(const T &x);

    void remove();

    const T &item() const;

    unsigned int size() const;
};

template<class T>
void Pile<T>::put(const T &x) { list<T>::push_back(x); }

template<class T>
void Pile<T>::remove() { list<T>::pop_back(); }

template<class T>
const T &Pile<T>::item() const {
    return list<T>::back();
}

template<class T>
unsigned int Pile<T>::size() const {
    return list<T>::size
            ();
}

template<class T>
class File : public Distributeur<T> {
    list<T> l;
public:
    void put(const T &x);

    void remove();

    const T &item() const;

    unsigned int size() const;
};

template<class T>
void File<T>::put(const T &x) {
    l.push_back(x);
}

template<class T>
void File<T>::remove() { l.pop_front(); }

template<class T>
const T &File<T>::item() const {
    return l.front();
}

template<class T>
unsigned int File<T>::size() const {
    return l.size();
}


template<class T>
typename list<T>::const_iterator max(const list<T> &l) {
    typename list<T>::const_iterator m = l.begin();
    for (typename list<T>::const_iterator it = l.begin(); it != l.end(); ++it) {
        if (*it < *m) m = it;
    }
    return m;
}

template<class T>
typename list<T>::iterator max(list<T> &l) {
    typename list<T>::iterator m = l.begin();
    for (typename list<T>::iterator it = l.begin(); it != l.end(); ++it) {
        if (*it < *m) m = it;
    }
    return m;
}

template<class T>
class Tas : public Distributeur<T> {
    list<T> l;
public:
    void put(const T &x);

    void remove();

    const T &item() const;

    unsigned int size() const;
};

template<class T>
void Tas<T>::put(const T &x) {
    l.push_back(x);
}

template<class T>
void Tas<T>::remove() { l.erase(max(l)); }

template<class T>
const T &Tas<T>::item() const {
    return *max(l);
}

template<class T>
unsigned int Tas<T>::size() const {
    return l.size();
}

#endif //CPP_DISTRIBUTEUR_H
