#include <iostream>

#include <set>
#include <map>
#include <list>


class FrequencySet : public std::list<char> {
public:
    FrequencySet() : std::list<char>() {
        counter = new std::map<char, int>();
    }

    ~FrequencySet() {
        delete counter;
    }

    void insert(const char e) {
        this->std::list<char>::push_back(e);
        (*counter)[e] ++;
    }

    class iterator {
    public:
        iterator(std::map<char, int>::iterator it = std::map<char, int>::iterator())
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

        char operator*() const {
            return it_value->first;
        }

    private:
        std::map<char, int>::iterator it_value;
    };

    iterator begin() const {
        return iterator(counter->begin());
    }

    iterator end() const {
        return iterator(counter->end());
    }

private:
    std::map<char, int>* counter;
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
