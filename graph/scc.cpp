#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#define N 2000
using namespace std;

vector <int> adj[N]; //adj list
vector <int> rev[N]; //adj list reverse
vector <int> finish;  //the order of leaving 1st dfs
vector <int> scc[N];
int group[N];
bool vst[N];

void dfs1(int x) //first dfs to get the order of leaving dfs
{
	vst[x] = true;
	for (int i = 0; i < adj[x].size(); i++)
		if (!vst[adj[x][i]])
			dfs1(adj[x][i]);
			
	finish.push_back(x);
}

void dfs2(int x, int c) //use the reverse adj list to dfs
{
	scc[c].push_back(x);
	group[x] = c;
	
	vst[x] = true;
	for (int i = 0; i < rev[x].size(); i++)
		if (!vst[rev[x][i]])
			dfs2(rev[x][i], c);
}

void find_scc(int n)
{
		memset(vst, false, sizeof(vst));
		for (int i = 1; i <= n; i++)// first dfs
			if (!vst[i])
				dfs1(i);

		int c = 0;
		memset(vst, false, sizeof(vst));
		for (int i = finish.size()-1; i >= 0; i--) //second dfs using the order of finish from the end
			if (!vst[finish[i]])
				dfs2(finish[i], c++);
}

