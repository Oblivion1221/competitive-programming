/*
ID: oblivio7
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#define MAX 10
using namespace std;

int n;
void rotate(char mtrx[MAX][MAX], char M[MAX][MAX])  // from mtrx to M
{
    // char** M = new char *[n];
    // for (int i = 0; i < n; i++)
    //     M[i] = new char[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[j][n - 1 - i] = mtrx[i][j];
}

void reflect(char mtrx[MAX][MAX], char M[MAX][MAX]) // form mtrx to M 
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][n - 1 - j] = mtrx[i][j];
}

bool check(char mtrx1[MAX][MAX], char mtrx2[MAX][MAX])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mtrx1[i][j] != mtrx2[i][j])
                return 0;
    return 1;
}

int main()
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    fin >> n;
    
    char mtrx1[MAX][MAX], mtrx2[MAX][MAX], M[MAX][MAX], tmp[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> mtrx1[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> mtrx2[i][j];
    
    rotate(mtrx1, M);   // rotate 1 time
    if (check(M, mtrx2)) 
    {
        fout << 1 << endl;
        return 0;
    }
    rotate(M, tmp); // rotate 2 times
    if (check(tmp, mtrx2)) 
    {
        fout << 2 << endl;
        return 0;
    }
    rotate(tmp, M); // rotate 3 times
    if (check(M, mtrx2))
    {
        fout << 3 << endl;
        return 0;
    }
    reflect(mtrx1, M);  // reflect 1 time
    if (check(M, mtrx2))
    {
        fout << 4 << endl;
        return 0;
    }
    for (int i = 0; i < 3; i++)
    {
        rotate(M, tmp); // rotate 1 time from the reflected one (Not including the first 3 times)
        memcpy(M, tmp, sizeof(tmp));    // store changes
        if (check(tmp, mtrx2))
        {
            fout << 5 << endl;
            return 0;
        }
    }
    if (check(mtrx2, mtrx1))
    {
        fout << 6 << endl;
        return 0;
    }
    fout << 7 << endl;
    return 0;
}