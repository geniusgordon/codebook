#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define N 300
using namespace std;

long long adj[N][N];
int pre[N];
long long vst[N];
int enterNode, exitNode, edgeNum, timeStamp;

bool find_path()
{
	queue<int> q;
	q.push(1);
	bool ok = false;
	while (!q.empty()) {
		int currNode = q.front(); q.pop();
		if (currNode == exitNode) {
			ok = true;
			break;
		}
		for (int i = 0; i < N; i++) {
			if (adj[currNode][i] && vst[i] < timeStamp) {
				vst[i] = timeStamp;
				q.push(i);
				pre[i] = currNode;
			}
		}
	}
	timeStamp++;
	return ok;
}

long long find_min()
{
	int currNode = pre[exitNode];
	long long ret = adj[pre[exitNode]][exitNode];
	while (currNode != enterNode) {
		ret = min(ret, adj[pre[currNode]][currNode]);
		currNode = pre[currNode];
	}
	return ret;
}

void flow(long long x)
{
	int currNode = exitNode;
	while (currNode != enterNode) {
		adj[pre[currNode]][currNode] -= x;
		adj[currNode][pre[currNode]] += x;
		currNode = pre[currNode];
	}
}

long long find_maxflow()
{
	long long ans = 0;
	timeStamp = 1;
	while (find_path()) {
		long long minEdge = find_min();
		flow(minEdge);
		ans += minEdge;
	}
	return ans;
}

int main()
{
	enterNode = 1;
	while (cin >> edgeNum >> exitNode) {
		memset(adj, 0, sizeof(adj));
		memset(vst, 0, sizeof(vst));
		for (int i = 0; i < edgeNum; i++) {
			int a, b;
			long long c;
			cin >> a >> b >> c;
			adj[a][b] += c;
		}
		cout << find_maxflow() << endl;
	}
	return 0;
}

