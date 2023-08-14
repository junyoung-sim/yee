#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::string str;
    std::vector<std::string> mat;

    int max_length = -RAND_MAX;
    while(std::cin >> str) {
        mat.push_back(str);
        max_length = std::max(max_length, (int)str.length());
    }
    
    for(int k = 0; k < max_length; k++)
        for(int i = 0; i < mat.size(); i++)
            if(k < mat[i].length()) std::cout << mat[i][k];
    std::cout << "\n";

    return 0;
}