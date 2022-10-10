#include <iostream>
#include <vector>
#include <string>

std::vector<int> mask;
std::vector<std::vector<int>> cut;
std::vector<std::vector<int>> map;

int N, M;
int ans = 0;

void func(int i, int n) {
    mask[i] = n;
    if(i == mask.size() -1) {
        int m = 0;
        for(int r = 0; r < N; r++)
            for(int c = 0; c < M; c++)
                cut[r][c] = mask[m++];

        std::string num = "";
        int sum = 0;

        for(int c = 0; c < M; c++) {
            
        }

        for(int r = 0; r < N; r++) {
            
        }

        ans = std::max(sum, ans);

        return;
    }

    func(i+1, 0);
    func(i+1, 1);
}

int main()
{
    std::cin >> N >> M;

    mask.resize(N*M);
    cut.resize(N, std::vector<int>(M));
    map.resize(N, std::vector<int>(M));

    std::string row;
    for(int r = 0; r < N; r++) {
        std::cin >> row;
        for(int c = 0; c < M; c++)
            map[r][c] = (row[c] - '0');
    }

    func(0, 0);
    func(0, 1);

    std::cout << ans << "\n";

    return 0;
}