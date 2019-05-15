// Ganis Zulfa Santoso
// ganiszulfa [at] gmail [dot] com

#include <stdio.h>
#include <iostream>
#include <fstream>

// OPTIONAL
// #include <cmath>
// #include <climits>
#include <algorithm>
// #include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  ifstream read("input.txt");
  ofstream write;
  write.open ("output.txt");
  // STARTS HERE

  int tot_case;
  read >> tot_case;

  int A, N, temp, op;
  vector<int> motes;

  for (int case_no = 1; case_no <= tot_case; ++case_no) {

    read >> A >> N;
    motes.resize(0);
    for (int i = 0; i < N; ++i) {
      read >> temp;
      motes.push_back(temp);
    } // end for i 

    sort(motes.begin(), motes.end());

    op = 0;
    for (int i = 0; i < N; ++i) {
      if(A > motes[i])
      {
        A+=motes[i];
      }
      else
      {
        ++op;
        A+=A;
        --A;
      }
    } // end for i 

    // END HERE
    printf("Case #%d:", case_no);
    write << "Case #" << case_no << ": ";

    // ANSWER HERE
    printf("%d\n", op);
    write << op << endl;

  } // end for case_no 
  return 0;
}
