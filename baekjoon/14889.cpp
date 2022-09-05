#include <iostream>
#include <vector>
#include <cmath>

int N;
std::vector<std::vector<int>> skill;

std::vector<int> team1;
std::vector<int> team2;

int ans = 10000;

void func(int n, int i) {
    team1[n] = i;

    if(n+1 == N/2) {
        int k = 0;
        for(int i = 0; i < N; i++) {
            bool valid;
            for(int j: team1) {
                valid = (i != j);
                if(!valid) break;
            }

            if(valid) team2[k++] = i;
        }

        int team1_skill = 0, team2_skill = 0;
        for(int i = 0; i < N/2; i++) {
            for(int j = i+1; j < N/2; j++) {
                team1_skill += skill[team1[i]][team1[j]] + skill[team1[j]][team1[i]];
                team2_skill += skill[team2[i]][team2[j]] + skill[team2[j]][team2[i]];
            }
        }

        ans = std::min(ans, abs(team1_skill - team2_skill));
        return;
    }

    for(int k = i+1; k < N; k++)
        func(n+1, k);
}

int main()
{
    std::cin >> N;
    skill.resize(N, std::vector<int>(N));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            std::cin >> skill[i][j];

    team1.resize(N/2);
    team2.resize(N/2);

    func(0, 0);

    std::cout << ans << "\n";

    return 0;
}
