#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define N 110
using namespace std;

vector<int> adj[N];
int clk[N], low[N];
int t;

vector<int> ap;
vector< pair<int, int> > bridge;

void dfs(int cur, int parent)
{
	int child = 0;
	bool flag = false;

	low[cur] = clk[cur] = t;
	t++;
	
	for (int i = 0; i < adj[cur].size(); i++) {
		int next = adj[cur][i];
		if (!clk[next]) {
			child++;
			dfs(next, cur);
			low[cur] = min(low[cur], low[next]);

			if (low[next] >= clk[cur])
				flag = true;
			if (low[next] > clk[cur])
				bridge.push_back(make_pair(cur, next));
		} else if (next != parent) {
			low[cur] = min(low[cur], clk[next]);
		}
	}

	if (parent == -1 && child >= 2)
		ap.push_back(cur);
	else if (parent != -1 && flag)
		ap.push_back(cur);
}

void tarjan(int n)
{
	t = 1;
	ap.clear();
	bridge.clear();
	memset(clk, 0, sizeof(clk));
	memset(low, 0, sizeof(low));

	dfs(0, -1);
}

