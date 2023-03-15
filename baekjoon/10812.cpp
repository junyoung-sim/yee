#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

void rotate(std::vector<int> &arr, int first, int last, int mid) {
    std::vector<int> rotated = {arr.begin() + mid, arr.begin() + last + 1};
    rotated.insert(rotated.end(), arr.begin() + first, arr.begin() + mid);
    std::copy(rotated.begin(), rotated.end(), arr.begin() + first);
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> v;
    for(int i = 1; i <= N; i++)
        v.push_back(i);

    for(int m = 0; m < M; m++) {
        int i, j, k;
        std::cin >> i >> j >> k;
        rotate(v, i-1, j-1, k-1);
    }

    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";

    return 0;
}