#include <bits/stdc++.h>
#define MAXN 100000
#define MAX_LOG 17
using namespace std;

struct Sparse {
    vector<int> data;
    int table[MAX_LOG+1][MAXN+5];

    void init() {
        for (int i = 0; i < n; i++) table[0][i] = data[i];
        for (int t = 1; (1 << t) <= n; t++)
            for (int i = 0; i + (1 << t) <= n; i++)
                table[t][i] = min(table[t-1][i], table[t-1][i+(1<<(t-1))];
    }

    int RMQ(int L, int R) {
        int k = __log(R - L);
        return min(table[k][L], table[k][R-(1<<k)];
    }
};

