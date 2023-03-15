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

    int i = 0;
    int j = str.length() - 1;

    bool palindrome = true;
    while(i < j && palindrome)
        palindrome = (str[i++] == str[j--]);
    
    std::cout << palindrome << "\n";

    return 0;
}