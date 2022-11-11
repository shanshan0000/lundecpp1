#include <iostream>

#include <set>
#include <vector>
#include <map>
#include <list>
#include <algorithm>


class FrequencySet : public std::list<char> {
public:
    FrequencySet() : std::list<char>() {
        counter = new std::map<char, int>();
        v = new std::vector<char>();
    }

    ~FrequencySet() {
        delete counter;
        delete v;
    }

    void insert(const char e) {
        if(std::find(v->begin(), v->end(), e) == v->end()) {
            v->push_back(e);
        }
        this->std::list<char>::push_back(e);
        (*counter)[e] ++;
    }

    class iterator {
    public:
        iterator(std::vector<char>::iterator it = std::vector<char>::iterator())
            : it_freq(it) {}

        iterator &operator++() {
            ++it_freq;
            return *this;
        }

        bool operator==(const iterator& it) const {
            return it_freq == it.it_freq;
        }

        bool operator!=(const iterator& it) const {
            return it_freq != it.it_freq;
        }

        char operator*() const {
            return *it_freq;
        }

    private:
        std::vector<char>::iterator it_freq;
    };

    iterator begin() const {
        auto cam = [&](char a, char b) {
        return (*counter)[a] == (*counter)[b] ? a > b : (*counter)[a] < (*counter)[b];
        };
        std::sort(v->begin(), v->end(), cam);
        return iterator(v->begin());
    }

    iterator end() const {
        return iterator(v->end());
    }



private:
    std::map<char, int>* counter;
    std::vector<char>* v;
};




int main() {
    FrequencySet s;
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
        std::cout << p << " ";
    }
    return 0;
}
