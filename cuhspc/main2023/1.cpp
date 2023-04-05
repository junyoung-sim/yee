
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int A, B, C;
    std::cin >> A >> B >> C;

    if(A + B == C) std::cout << "Try again, Bob\n";
    else std::cout << "Good job, Bob!\n";

    return 0;
}