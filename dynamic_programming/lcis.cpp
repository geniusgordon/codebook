int LCIS(vector<int>& A, vector<int>& B)
{
	vector<int> C(B.size(), 0);

	for (int i = 0; i < A.size(); i++) {
		int cur = 0;
		for (int j = 0; j < B.size(); j++) {
			if (A[i] == B[j] && cur+1 > C[j]) {
				C[j] = cur + 1;
			} else if (A[i] > B[j] && cur < C[j]) {
				cur = C[j];
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < C.size(); i++) {
		ret = max(ret, C[i]);
	}
	return ret;
}

