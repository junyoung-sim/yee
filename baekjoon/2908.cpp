#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

void reverse(std::string &str) {
    int i = 0;
    int j = str.length() - 1;
    while(i < j)
        std::swap(str[i++], str[j--]);
}

int main()
{
    std::string A, B;
    std::cin >> A >> B;

    reverse(A);
    reverse(B);

    if(std::stoi(A) > std::stoi(B))
        std::cout << A << "\n";
    else
        std::cout << B << "\n";

    return 0;
}