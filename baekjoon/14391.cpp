#include <iostream>
#include <vector>

std::vector<int> mask;
std::vector<std::vector<int>> map;

int N, M;
int ans = 0;

void func(int i, int n) {
    mask[i] = n;
    if(i == mask.size() -1) {

        return;
    }

    func(i+1, 0);
    func(i+1, 1);
}

int main()
{
    std::cin >> N >> M;

    mask.resize(N*M);
    map.resize(N, std::vector<int>(M));

    for(int r = 0; r < N; r++)
        for(int c = 0; c < M; c++)
            std::cin >> map[r][c];

    func(0, 0);
    func(0, 1);

    return 0;
}