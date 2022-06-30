/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
PROG: castle
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

#define MAX_N 51

int M, N;
int floor[MAX_N][MAX_N];

// 1: wall to the west
// 2: wall to the north
// 4: wall to the east
// 8: wall to the south


int main() {
  ofstream fout("castle.out");
  ifstream fin("castle.in");
  fin >> M >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      fin >> floor[i][j];
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << floor[i][j] << " ";
    }
    cout << endl;
  }


  return 0;
}