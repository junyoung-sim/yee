#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

#define MAX 50

int N;
int A[MAX];
int B[MAX];

bool ascend(int a, int b) { return a < b; }
bool descend(int a, int b) { return a > b; }

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	for(int i = 0; i < N; i++) std::cin >> A[i];
	for(int i = 0; i < N; i++) std::cin >> B[i];

	std::sort(A, A+N, ascend);
	std::sort(B, B+N, descend);

	int sum = 0;
	for(int i = 0; i < N; i++) sum += A[i] * B[i];

	std::cout << sum;
	
	return 0;
}
