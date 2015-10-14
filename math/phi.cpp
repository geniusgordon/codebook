#include <iostream>
#include <cstring>
#define N 4000005
using namespace std;

int phi[N];
long long prefix[N];
bool is_prime[N];

void init()
{
	memset(is_prime, true, sizeof(is_prime));
	for (int i = 0; i < N; i++)
		phi[i] = i;
	for (int i = 2; i < N; i++) {
		if (is_prime[i]) {
			phi[i] = phi[i]/i * (i-1);
			for (int j = i*2; j < N; j += i) {
				is_prime[j] = false;
				phi[j] = phi[j]/i * (i-1);
			}
		}
	}
}

