#include <vector>
#include <cstring>
#define N 1000
using namespace std;

vector<int> graph[N];
int match[N];
bool vst[N];

bool _bipartite(int x)
{
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!vst[y]) {
			vst[y] = true;
			if (match[y] == -1 || _bipartite(match[y])) {
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}

void bipartite(int n)
{
	memset(match, -1, sizeof(match));
	for (int i = 0; i < n; i++) {
		memset(vst, false, sizeof(vst));
		_bipartite(i);
	}
}

