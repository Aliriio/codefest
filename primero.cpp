#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a;
    string s; getline(cin, s);
   
    // Takes only space separated C++ strings.
    stringstream ss(s);  
    string word;
    while (ss >> word) { // Extract word from the stream.
        if (word[0] == ',') word[0] = ' ';
        a.push_back(stoi(word));
    }
   
    sort(a.begin(), a.end());
   
    int n = sqrt(a.size());
   
    vector<vector<int>> m(n, vector<int>(n));
   
   
    int current_row = 0, current_col = -1, c_op_row = 1, c_op_col = 1;
    string iterator = "row";
    int index_a = 0;
   
    int len_t_p = n;
   
    for (int j = 0; j < len_t_p; j++) {
        current_col += c_op_col;
        m[current_row][current_col] = a[index_a++];
    }
    c_op_col = -(c_op_col);
    len_t_p--;
   
    for (int i = 1; i <= (n * 2) - 2; i++) {
       
        if (iterator == "col") {
            for (int j = 0; j < len_t_p; j++) {
                current_col += c_op_col;
                m[current_row][current_col] = a[index_a++];
            }
            c_op_col = -(c_op_col);
            iterator = "row";
        }
       
        else {
            for (int j = 0; j < len_t_p; j++) {
                current_row += c_op_row;
                m[current_row][current_col] = a[index_a++];
            }
            c_op_row = -(c_op_row);
            iterator = "col";
        }
        if (i % 2 == 0) len_t_p--;
    }
   
    for (int i = 0; i < n; i++) {
        cout << "(";
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << ((j == (n - 1)) ? "" : ", ");
        }
        cout << ((i == (n - 1)) ? ")" : "), ");
    }
   
    return 0;
}