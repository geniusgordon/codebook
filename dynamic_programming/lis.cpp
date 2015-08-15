#include <iostream>
#include <algorithm>
#include <vector>
#define N 10000000
using namespace std;

vector<long long> array;
long long dp[N], len[N], pos[N];
const long long INF = 0x3fffffffffffffff;

vector<long long> findLIS()
{
	int n = array.size();

	for (int i = 0; i <= n; i++)
		len[i] = INF;
	for (int i = 0; i < n; i++) {
		int k = lower_bound(len+1, len+n+1, array[i]) - len;
		dp[i] = k;
		len[k] = array[i];
	}
	long long L = 0;
	for (int i = 0; i < n; i++)
		L = max(L, dp[i]);

	vector<long long> lis = vector<long long>(L, 0);
	int tmp = L;
	for (int i = n-1; i >= 0; i--) {
		if (dp[i] == tmp) {
			lis[tmp-1] = array[i];
			tmp--;
		}
	}
	return lis;
}

