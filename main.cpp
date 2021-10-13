#include <iostream>
#include <vector>

using namespace std;

class PeekingIterator {
public:
    vector<int> v;
    int i = 0;

    PeekingIterator(const vector<int>& nums) {
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
    PeekingIterator* pi = new PeekingIterator(v);

    while(pi->hasNext()){
        cout << "pop:  " << pi->next();
        cout << "  peek: " << pi->peek();
        cout << endl;
    }

    return 0;
}
