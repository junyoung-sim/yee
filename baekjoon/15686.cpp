#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<int>> home;
std::vector<std::vector<int>> chicken;

std::vector<int> city;

int ans = 10000;

void func(int c, int m) {
    city[m-1] = c;

    if(m == M) {
        int chicken_dist = 0;
        for(int h = 0; h < home.size(); h++) {
            int min_dist = 10000;
            for(int c: city) {
                int dist = abs(home[h][0] - chicken[c][0]) + abs(home[h][1] - chicken[c][1]);
                min_dist = std::min(dist, min_dist);
            }

            chicken_dist += min_dist;
        }

        ans = std::min(chicken_dist, ans);
        return;
    }

    for(int k = c+1; k < chicken.size(); k++)
        func(k, m+1);

    city[m-1] = -1;
}

int main()
{
    std::cin >> N >> M;
    city.resize(M);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int val; std::cin >> val;
            if(val == 1)
                home.push_back(std::vector<int>({i, j}));
            else if(val == 2)
                chicken.push_back(std::vector<int>({i, j}));
            else {}
        }
    }

    for(int c = 0; c < chicken.size(); c++)
        func(c, 1);

    std::cout << ans << "\n";

    return 0;
}
