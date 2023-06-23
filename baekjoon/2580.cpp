#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

#define ROW 0
#define COL 1

std::vector<std::vector<int>> sudoku(9, std::vector<int>(9, 0));
std::vector<std::vector<int>> empty;

bool found = false;

bool check(std::vector<int> &pos) {
    for(int j = 0; j < 9; j++)
        if(j != pos[COL] && sudoku[pos[ROW]][pos[COL]] == sudoku[pos[ROW]][j]) return false;
    for(int i = 0; i < 9; i++)
        if(i != pos[ROW] && sudoku[pos[ROW]][pos[COL]] == sudoku[i][pos[COL]]) return false;
    
    int square_row = pos[ROW] / 3;
    int square_col = pos[COL] / 3;
    for(int i = square_row*3; i < square_row*3+3; i++)
        for(int j = square_col*3; j < square_col*3+3; j++)
            if(i != pos[ROW] && j != pos[COL] && sudoku[pos[ROW]][pos[COL]] == sudoku[i][j]) return false;
    
    return true;
}

void solve(int i) {
    if(i == empty.size()) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++)
                std::cout << sudoku[i][j] << " ";
            std::cout << "\n";
        }
        found = true;
        return;
    }
    for(int x = 1; x <= 9; x++) {
        sudoku[empty[i][ROW]][empty[i][COL]] = x;
        if(check(empty[i])) solve(i+1);
        if(found) return;
    }
    sudoku[empty[i][ROW]][empty[i][COL]] = 0;
    return;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            std::cin >> sudoku[i][j];
            if(!sudoku[i][j])
                empty.push_back(std::vector<int>({i, j}));
        }
    }

    solve(0);

    return 0;
}