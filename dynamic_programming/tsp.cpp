#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define N 15
using namespace std;

const int INF = 1000;
int graph[N][N];
int dp[1<<N][N];

int _TSP(int mask, int x, int n)
{
	if (!(mask & (mask-1)))
		return 0;
	if (dp[mask][x] != -1)
		return dp[mask][x];
	int res = INF;
	for (int i = 0; i < n; i++) {
		if (i == x)
			continue;
		if (mask & (1<<i)) {
			int tmp = _TSP(mask^(1<<x), i, n) + graph[x][i];
			res = min(res, tmp);
		}
	}
	return dp[mask][x] = res;
}

int TSP(int n)
{
	int res = INF;
	int e = (1<<n) - 1;
	for (int i = 0; i < n; i++) {
		memset(dp, -1, sizeof(dp));
		int tmp = _TSP(e, i, n);
		res = min(res, tmp);
	}
	return res;
}

