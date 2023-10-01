/*
ID: jysim.n1
TASK: test
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream fin("test.in");
	std::ofstream fout("test.out");

	int a, b;
	fin >> a >> b;
	fout << a + b << "\n";

	return 0;
}
