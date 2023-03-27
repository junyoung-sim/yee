#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int N, M;
std::vector<int> cards;

int ans = 0;

// pick three cards from the deck
// sum of the three cards should not exceed M
// find the maximum possible sum

void func(int i, int sum, int count) {
    if(sum > M) return;
    if(count == 3) {
        ans = std::max(sum, ans);
        return;
    }

    for(int j = i+1; j < N; j++)
        func(j, sum+cards[j], count+1);
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> M;

    cards.resize(N);
    for(int i = 0; i < N; i++)
        std::cin >> cards[i];
    
    for(int i = 0; i < N-1; i++)
        func(i, cards[i], 1);
    
    std::cout << ans << "\n";

    return 0;
}