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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin >> N;

    std::string A, B;
    std::map<std::string, bool> person;
    person["ChongChong"] = false;

    int ans = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A >> B;
        if(A == "ChongChong" && !person[A]) {
            person[A] = true;
            ans++;
        }
        else if(B == "ChongChong" && !person[B]) {
            person[B] = true;
            ans++;
        }
        else;

        if(person[A] && !person[B]) {
            person[B] = true;
            ans++;
        }
        else if(!person[A] && person[B]) {
            person[A] = true;
            ans++;
        }
        else;
    }

    std::cout << ans << "\n";

    return 0;
}