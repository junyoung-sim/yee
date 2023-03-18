#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cout.precision(12);
    std::cout << std::fixed;

    double dot = 0.00;
    int credits = 0;

    std::string subject, letter;
    double credit, grade;

    while(std::cin >> subject >> credit >> letter) {
        if(letter == "A+") grade = 4.5;
        else if(letter == "A0") grade = 4.0;
        else if(letter == "B+") grade = 3.5;
        else if(letter == "B0") grade = 3.0;
        else if(letter == "C+") grade = 2.5;
        else if(letter == "C0") grade = 2.0;
        else if(letter == "D+") grade = 1.5;
        else if(letter == "D0") grade = 1.0;
        else grade = 0.0;

        if(letter == "P") credit = 0.0;

        dot += credit * grade;
        credits += credit;
    }

    std::cout << dot / credits << "\n";

    return 0;
}