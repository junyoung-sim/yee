#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int a, b, c;
    int d, e, f;

    std::cin >> a >> b >> c >> d >> e >> f;

    for(int x = -999; x <= 999; x++) {
        for(int y = -999; y <= 999; y++) {
            if(a*x+b*y==c && d*x+e*y==f) {
                std::cout << x << " " << y << "\n";
                break;
            }
        }
    }

    return 0;
}