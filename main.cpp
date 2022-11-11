#include <iostream>

#include <set>
#include <map>
#include <list>
#include <vector>
#include <algorithm>


class Counter : public std::vector<char> {
public:
    Counter() : std::vector<char>() {
        t = new std::set<char>();
    }

    ~Counter() {
        delete t;
    }

    void insert(const char e) {
        this->std::vector<char>::push_back(e);
        t->insert(e);
    }

    class iterator {
    public:
        iterator(std::set<char>::iterator it = std::set<char>::iterator())
            : it_value(it) {}

        iterator &operator++() {
            ++it_value;
            return *this;
        }

        bool operator==(const iterator& it) const {
            return it_value == it.it_value;
        }

        bool operator!=(const iterator& it) const {
            return it_value != it.it_value;
        }

        std::pair<char, int> operator*() const {
            return std::make_pair(*it_value,
                    std::count(v->std::vector<char>::begin(),
                            v->std::vector<char>::end(), *it_value));
        }

        void setCounter(const Counter* c) {
            this->v = c;
        }

    private:
        const Counter *v;
        std::set<char>::iterator it_value;
    };

    iterator begin() const {
        iterator it = iterator(t->begin());
        it.setCounter(this);
        return it;
    }

    iterator end() const {
        iterator it = iterator(t->end());
        it.setCounter(this);
        return it;
    }

private:
    std::set<char>* t;
};




int main() {
    Counter s;
    s.insert('C');
    s.insert('B');
    s.insert('B');
    s.insert('B');
    s.insert('B');
    s.insert('A');
    s.insert('B');
    s.insert('B');
    s.insert('B');
    s.insert('C');
    s.insert('C');
    for(auto p : s) {
        std::cout << p.first << " " << p.second << std::endl;
    }
    return 0;
}
