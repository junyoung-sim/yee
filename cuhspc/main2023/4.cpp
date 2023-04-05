#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

std::string key = "          ";
std::vector<std::string> v(3);

void make(char i, int c) {
    key[c] = i;
    if(c == 9) {
        for(int t = 0; t < 3; t++) {
            std::string decrypted_num = "";
            for(int l = 0; l < v[t].length(); l++)
                decrypted_num += std::to_string(key.find(v[t][l]));
            v[t] = decrypted_num;
        }

        if(std::stoi(v[0]) + std::stoi(v[1]) == std::stoi(v[2]))
            std::cout << key << " " << v[0] << " " << v[1] << " " << v[2] << "\n";

        return;
    }

    for(char j = '0'; j <= '9'; j++) {
        bool valid = true;
        for(int k = 0; k <= c; k++) {
            valid = (j != key[k]);
            if(!valid) break;
        }
        if(valid) make(j, c+1);
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    std::string line;
    std::cin >> line;

    int plus = line.find("+");
    int equal = line.find("=");

    v[0] = line.substr(0, plus);
    v[1] = line.substr(plus+1, equal-plus-1);
    v[2] = line.substr(equal+1, line.length()-equal);

    for(char i = '0'; i <= '9'; i++) make(i, 0);

    return 0;
}