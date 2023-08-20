#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <map>
#include <set>

long long int gcd(long long int a, long long int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int N;
    std::cin >> N;

    std::vector<long long int> v(N);
    std::vector<long long int> d(N-1);

    for(int i = 0; i < N; i++) {
        std::cin >> v[i];
        if(i > 0)
            d[i-1] = v[i] - v[i-1];
    }

    // plant the "least" number of trees such that all trees are planted in equal intervals
    // (1) find the gcd of the distances between existing trees to divide the extra space into biggest possible chunks
    // (2) number of trees that have to be added equals the sum of (distance / gcd - 1), -1 for excluding the end

    long long int div = d[0];
    for(int i = 1; i < N-1; i++)
        div = gcd(div, d[i]);

    long long int ans = 0;
    for(int i = 0; i < N-1; i++)
        ans += d[i] / div - 1;
    std::cout << ans << "\n";

    return 0;
}