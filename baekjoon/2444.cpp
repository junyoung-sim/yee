#include <iostream>
#include <cstdlib>
#include <cstdio>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    int len = 2*(N-1)+1;

    std::string str = "";
    for(int i = 0; i < len; i++)
        str += " ";
    
    int i = 0;
    while(str[0] == ' ') {
        str[len/2 + i] = '*';
        str[len/2 - i] = '*';

        std::cout << str.substr(0, len/2+i+1) << "\n";
        i++;
    }

    i = 0;
    while(i != len/2) {
        str[i] = ' ';
        str[str.length() - i - 1] = ' ';
        std::cout << str.substr(0, str.length() - i) << "\n";
        i++;
    }

    return 0;
}