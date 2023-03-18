#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::string str;
    std::cin >> str;

    int i = -1;
    int ans = 0;

    while(++i < str.length()) {
        ans++;
        if(i+1 < str.length() && str.substr(i, 2) == "c=" ||
                                 str.substr(i, 2) == "c-" ||
                                 str.substr(i, 2) == "d-" ||
                                 str.substr(i, 2) == "lj" ||
                                 str.substr(i, 2) == "nj" ||
                                 str.substr(i, 2) == "s=" ||
                                 str.substr(i, 2) == "z=") i++;
         if(i+2 < str.length() && str.substr(i, 3) == "dz=") i += 2;
    }

    std::cout << ans << "\n";

    return 0;
}