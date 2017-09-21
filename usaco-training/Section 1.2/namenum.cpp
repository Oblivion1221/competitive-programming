/*
 ID: oblivio7
 PROG: namenum
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>
#define MAX_R 5000
#define MAX_C 15
using namespace std;

ofstream fout("namenum.out");
ifstream fin("namenum.in");
ifstream file("dict.txt");

int main()
{
    int cnt = 0;
    char n[MAX_C];
    string map("22233344455566670778889990");
    char dict[MAX_R][MAX_C];
    bool name = 0;

    fin >> n;
    while (file >> dict[cnt])
        cnt++;
    for (int i = 0; i < cnt; i++)
    {
        bool flag = 0;
        if(strlen(n) != strlen(dict[i])) continue; // Lengths should be the same. Test 3: 5747867437 --> KRIST (x), should be KRISTOPHER
        for (int j = 0; j < strlen(dict[i]); j++)
            if (map[dict[i][j] - 'A'] == n[j]);
            else { flag = 1; break; }
        if (!flag) { name = 1; fout << dict[i] << endl; }   // Ensure the output is not "GREG\nNONE\n"
    }
    if (!name) fout << "NONE" << endl;

    return 0;
}