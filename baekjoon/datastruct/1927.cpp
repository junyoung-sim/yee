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

std::vector<long long int> heap;

void shiftdown(int root) {
    while(root*2+1 < heap.size()) {
        long long int child = root*2+1;
        if(child+1 < heap.size() && heap[child+1] < heap[child]) child++;
        if(heap[root] > heap[child]) {
            std::swap(heap[root], heap[child]);
            root = child;
        }
        else break;
    }
}

long long int pop() {
    if(heap.size() == 0)
        return 0;
    long long int min = heap[0];
    std::swap(heap.front(), heap.back());
    heap.pop_back(); shiftdown(0);
    return min;
}

void insert(long long int x) {
    heap.push_back(x);
    int i = heap.size() - 1;
    while(i > 0 && heap[i] < heap[(i-1)/2]) {
        std::swap(heap[i], heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    while(N--) {
        long long int x;
        std::cin >> x;

        if(x == 0) std::cout << pop() << "\n";
        else insert(x);
    }

    return 0;
}