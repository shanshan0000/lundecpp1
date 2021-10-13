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
    vector<int> v;
    int i = 0;

    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        v = nums;
    }

    int peek() {
        return v[i];
    }

    int next() {
        i ++;
        return v[i-1];
    }

    bool hasNext() const {
        return i < v.size();
    }
};

int main() {
    const vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};

    PeekingIterator pi(v);

    while(pi.hasNext()){
        cout << "pop:  " << pi.next();
        cout << "peek: " << pi.peek();
        cout << endl;
    }

    return 0;
}
