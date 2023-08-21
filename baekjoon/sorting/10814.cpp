#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

struct Person {
    int age;
    std::string name;
};

bool compare(const Person &now, const Person &last) {
    if(now.age != last.age)
        return now.age < last.age;
    else
        return false;
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int N;
    std::cin >> N;

    Person p[N];
    for(int i = 0; i < N; i++)
        std::cin >> p[i].age >> p[i].name;
    
    std::stable_sort(p, p+N, compare);

    for(int i = 0; i < N; i++)
        std::cout << p[i].age << " " << p[i].name << "\n";

    return 0;
}