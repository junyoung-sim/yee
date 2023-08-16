#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

int main()
{
    std::string phone;
    std::cin >> phone;

    int time[26] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};

    int ans = 0;
    for(int i = 0; i < phone.length(); i++)
        ans += time[phone[i] - 'A'];
    
    std::cout << ans << "\n";

    return 0;
}