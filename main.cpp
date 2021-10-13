#include <iostream>
#include <vector>

using namespace std;

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    int prev;
    bool end;
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        this->prev = Iterator::next();
        this->end = 0;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return this->prev;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int ans = this->prev;
        if(Iterator::hasNext() == 0) this->end = 1;
        else this->prev = Iterator::next();
        return ans;
    }

    bool hasNext() const {
        return !(this->end);
    }
};

int main() {
    // https://leetcode.com/problems/peeking-iterator/discuss/1498942/C%2B%2B%3A-Simple-Solution-using-Iterator-Interface

    const vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};

    PeekingIterator pi(v);

    while(pi.hasNext()){
        cout << "pop:  " << pi.next();
        cout << "peek: " << pi.peek();
        cout << endl;
    }

    return 0;
}
