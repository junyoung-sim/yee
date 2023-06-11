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

void merge(std::vector<int> &v, int p, int q, int r) {
    int i = p, j = q+1;
    std::vector<int> tmp;
    while(i <= q && j <= r) {
        if(v[i] < v[j]) tmp.push_back(v[i++]);
        else tmp.push_back(v[j++]);
    }
    while(i <= q) tmp.push_back(v[i++]);
    while(j <= r) tmp.push_back(v[j++]);

    i = p; int k = 0;
    while(i <= r)
        v[i++] = tmp[k++];
}

void mergesort(std::vector<int> &v, int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        mergesort(v, p, q);
        mergesort(v, q+1, r);
        merge(v, p, q, r);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<int> v(N);
    for(int i = 0; i < N; i++)
        std::cin >> v[i];
    
    mergesort(v, 0, N-1);

    for(int i = 0; i < N; i++)
        std::cout << v[i] << " ";
    std::cout << "\n";  

    return 0;
}