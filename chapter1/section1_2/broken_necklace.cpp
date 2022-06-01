/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
TASK: beads
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ofstream fout("beads.out");
  ifstream fin("beads.in");
  int n;
  string circle;
  fin >> n >> circle;
//  circle = circle + circle;
  cout << circle << endl;
  circle = "11234511234561111211112312345";
  std::reverse(circle.begin(), circle.end());
  cout << circle << endl;

  // wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
  // 12345123111121111234561223451
  // brrwrwbrwwrwrbrbrrbrbrwrbbwww
  // 11234511234561111211112312345
  // 54321321111211116543211543211

//  fout << a + b << endl;
  return 0;
}
