#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::vector<int> ascii(123,0);

    std::string str;
    std::cin >> str;

    for(char c: str)
        ascii[c]++;
    
    int maximum = 0;
    int index = 0;
    int count = 0;

    for(int i = 'A'; i <= 'Z'; i++) {
        count += (ascii[i] + ascii[i+32] == maximum);
        if(ascii[i] + ascii[i+32] > maximum) {
            maximum = ascii[i] + ascii[i+32];
            index = i;
            count = 1;
        }
    }

    if(count == 1) std::cout << (char)index << "\n";
    else std::cout << "\?\n";

    return 0;
}