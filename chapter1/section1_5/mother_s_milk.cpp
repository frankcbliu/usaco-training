/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
TASK: milk3
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <cstring>
#include <set>

using namespace std;
int A, B, C; // 1~20
set<int> ans;
bool state[21][21][21];

void dfs(int a, int b, int c) {
  if (state[a][b][c]) return;
  if (a == 0)
    ans.insert(c);
  state[a][b][c] = true;

  int ra = A - a, rb = B - b, rc = C - c;
  // 6 sub state
  dfs(a - min(a, rb), b + min(a, rb), c); // A -> B
  dfs(a - min(a, rc), b, c + min(a, rc)); // A -> C
  dfs(a + min(b, ra), b - min(ra, b), c); // B -> A
  dfs(a, b - min(b, rc), c + min(b, rc)); // B -> C
  dfs(a + min(c, ra), b, c - min(c, ra)); // C -> A
  dfs(a, b + min(c, rb), c - min(c, rb)); // C -> B
}

int main() {
  // init, memset included by <cstring>
  memset(state, false, sizeof(bool));
  // handle input
  ifstream fin("milk3.in");
  fin >> A >> B >> C;
  fin.close();
  // handle solve
  dfs(0, 0, C);
  // handle output
  ofstream fout("milk3.out");
  int cnt = int(ans.size());
  for (auto item: ans) {
    fout << item;
    if (--cnt > 0)
      fout << " ";
  }
  fout << endl;
  fout.close();
  return 0;
}
