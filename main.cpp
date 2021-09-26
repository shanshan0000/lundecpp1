#include <iostream>
#include <vector>
#include <unordered_map>

// https://leetcode.com/problems/sum-of-unique-elements/

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int>m;
        int sum=0;
        for(auto val:nums) {
            m[val]++;
        }
        for(auto val:m) {
            if(val.second==1)
                sum+=val.first;
        }
        return sum;
    }
};

int main() {
    Solution solution;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);
    std::cout << solution.sumOfUnique(v) << std::endl;
    return 0;
}
