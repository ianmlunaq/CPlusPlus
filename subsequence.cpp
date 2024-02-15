// subsequence.cpp
// Ian Luna Quiroz

#include <algorithm>
#include <iostream>
using namespace std;

int recur(string uno, string due, int ichi, int ni) {
    if (ichi == 0 or ni == 0) {
        return 0;
    }

    if (uno[ichi-1] == due[ni-1]) {
        return 1 + recur(uno, due, ichi-1, ni-1);
    } else {
        return max(recur(uno, due, ichi, ni-1),
                   recur(uno, due, ichi-1, ni));
    }
}

/* To make this program more effecient you can just use an iterative function instead of a recursive one.*/

int main () {
    string S1 = "ROYGBIV";
    string S2 = "RYBOSOME";
    int m = S1.size();
    int n = S2.size();

    cout << "Length of LCS is " << recur(S1, S2, m, n);

    return 0;
}