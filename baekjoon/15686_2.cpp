#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<int>> home;
std::vector<std::vector<int>> chicken;

int ans = 0;

int main()
{
    std::cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int val;
            std::cin >> val;

            if(val == 1)
                home.push_back(std::vector<int>({i, j}));
            else if(val == 2)
                chicken.push_back(std::vector<int>({i, j}));
            else {}
        }
    }


    for(int i = 0; i < M; i++) {
        int min_dist_sum = 10000;
        int arg_min = i;

        for(int j = i; j < chicken.size(); j++) {
            int dist_sum = 0;
            for(int k = 0; k < home.size(); k++)
                dist_sum += abs(chicken[j][0] - home[k][0]) + abs(chicken[j][1] - home[k][1]);

            if(dist_sum < min_dist_sum) {
                min_dist_sum = dist_sum;
                arg_min = j;
            }
        }

        std::swap(chicken[i], chicken[arg_min]);
    }

    for(int k = 0; k < home.size(); k++) {
        int chicken_road = 10000;
        for(int i = 0; i < M; i++)
            chicken_road = std::min(abs(chicken[i][0] - home[k][0]) + abs(chicken[i][1] - home[k][1]), chicken_road);
        ans += chicken_road;
    }

    std::cout << ans << "\n";

    return 0;
}
