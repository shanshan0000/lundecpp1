// https://leetcode.com/problems/reverse-string/

#include <iostream>
#include <vector>

using namespace std;

void inverse(char* a, char* b)
{
    char tmp=*a;
    *a=*b;
    *b=tmp;
}

void inverse(char& a, char& b)
{
    char tmp=a;
    a=b;
    b=tmp;
}

class Solution {
public:
    void reverseString(vector<char>& s)
    {
        int i = 0, j = s.size() - 1;
        while(i < j)
        {
            inverse(s[i], s[j]);
            i ++;
            j --;
        }
        for(char c:s) cout << c;
    }
};

// https://leetcode.com/problems/reverse-string/

int main() {
    Solution solution;
    vector<char> v;
    v.push_back('H');
    v.push_back('E');
    v.push_back('L');
    v.push_back('L');
    v.push_back('O');
    solution.reverseString(v);
    return 0;
}
