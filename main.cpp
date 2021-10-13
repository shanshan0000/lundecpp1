#include <iostream>
#include <vector>

using namespace std;

class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        this->rectangle = move( rectangle );
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int j = row1; j <= row2; ++j) {
            for (int i = col1; i <= col2; ++i) {
                rectangle[j][i] = newValue;
            }
        }
    }

    int getValue(int row, int col) {
        return rectangle[row][col];
    }

private:
    vector<vector<int>> rectangle;
};

int main() {

    vector<vector<int>> vec{ { 1, 2, 3 },
                             { 4, 5, 6 },
                             { 7, 8, 9 } };

    for(int i = 0; i <= 2; i ++) {
        for (int j = 0; j <= 2; j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }

    cout << endl;
    cout << endl;
    for(auto it_i = vec.begin(); it_i != vec.end(); ++ it_i) {
        for (int j = 0; j <= 2; j++)
            cout << (*it_i)[j] << " ";
        cout << endl;
    }

    cout << endl;
    cout << endl;
    for(int i = 0; i <= 2; i ++) {
        for (auto it_j = vec[i].begin(); it_j != vec[i].end(); ++ it_j)
            cout << *it_j << " ";
        cout << endl;
    }

    cout << endl;
    cout << endl;
    for(auto it_i = vec.begin(); it_i != vec.end(); ++ it_i) {
        for (auto it_j = (*it_i).begin(); it_j != (*it_i).end(); ++ it_j)
            cout << *it_j << " ";
        cout << endl;
    }

    return 0;
}
