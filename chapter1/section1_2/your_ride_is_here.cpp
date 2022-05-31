/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
PROG: ride
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

int count(const string& t) {
  assert(!t.empty()); // use assert to debug
  int res = 1;
  for (char i: t) {
    res *= i - 'A' + 1;
  }
  return res % 47;
}

int main() {
  ofstream fout("ride.out");
  ifstream fin("ride.in");
  string a, b;
  fin >> a >> b;
  if (count(a) == count(b)) {
    fout << "GO" << endl;
  } else {
    fout << "STAY" << endl;
  }

  return 0;
}