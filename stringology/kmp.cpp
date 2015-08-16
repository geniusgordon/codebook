#include <iostream>
#include <vector>
using namespace std;

vector<int> build_fail_function(string S)
{
	int len = S.length(), cur;
	vector<int> fail = vector<int>(len, 0);

	cur = fail[0] = -1;
	for (int i = 1; i < len; i++) {
		while (cur != -1 && S[cur+1] != S[i]) {
			cur = fail[cur];
		}
		if (S[cur+1] == S[i])
			cur++;
		fail[i] = cur;
	}
	return fail;
}

vector<int> match(string A, string B)
{
	int lenA = A.length(), lenB = B.length();
	int cur = -1;
	vector<int> pos;
	vector<int> fail = build_fail_function(A);
	for (int i = 0; i < lenA; i++) {
		while (cur != -1 && B[cur+1] != A[i]) {
			cur = fail[cur];
		}
		if (B[cur+1] == A[i])
			cur++;
		if (cur == lenB-1) {
			pos.push_back(i);
			cur = fail[cur];
		}
	}
	return pos;
}

