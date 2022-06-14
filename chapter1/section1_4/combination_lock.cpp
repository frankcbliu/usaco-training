/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
PROG: combo
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

void show(const vector<int>& arr) {
  for (int i: arr) {
    cout << i << " ";
  }
  cout << endl;
}



int main() {
  ofstream fout("combo.out");
  ifstream fin("combo.in");
  int n;
  fin >> n;
  vector<int> c1, c2;
  c1.resize(3);
  c2.resize(3);
  for (int& i: c1) fin >> i;
  for (int& i: c2) fin >> i;
  show(c1);
  show(c2);

  return 0;
}