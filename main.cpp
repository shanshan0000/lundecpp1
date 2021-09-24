#include <iostream>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> freq;

        for(char& letter : s) freq[letter]++;

        int frequency = -1;
        for(auto iter = freq.begin(); iter != freq.end(); iter++){
            // take the first frequency of our first character in our map
            if(frequency == -1) frequency = iter->second;

                // and compare it to the frequency of the other characters in our map
            else if(iter->second != frequency) return false;
        }

        return true;
    }
};

int main() {
    string s1 = "aaabbb";
    string s2 = "aaaabbb";
    Solution solution;
    cout << solution.areOccurrencesEqual(s1) << endl;
    cout << solution.areOccurrencesEqual(s2) << endl;
    return 0;
}
