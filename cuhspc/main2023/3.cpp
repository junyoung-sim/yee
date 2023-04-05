#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::string line;
    std::getline(std::cin, line);

    int i = 0;
    std::string ans = "";

    while(i < line.length()) {
        if(i == 0 && line.substr(i, 3) == "is ") {
            ans += "isnt ";
            i += 3;
        }
        else if(i == 0 && line.substr(i, 5) == "isnt ") {
            ans += "is ";
            i += 5;
        }
        else if(line.substr(i, 4) == " is ") {
            ans += " isnt ";
            i += 4;
        }
        else if(line.substr(i, 6) == " isnt ") {
            ans += " is ";
            i += 6;
        }
        else if(line.substr(i, 3) == " is" && i+2 == line.length() - 1) {
            ans += " isnt";
            i += 3;
        }
        else if(line.substr(i, 5) == " isnt" && i+4 == line.length() - 1) {
            ans += " is";
            i += 5;
        }
        else if(line == "is") {
            ans += "isnt";
            i += 2;
        }
        else if(line == "isnt") {
            ans += "is";
            i += 4;
        }
        else
            ans += line[i++];
    }

    std::cout << ans << "\n";

    return 0;
}