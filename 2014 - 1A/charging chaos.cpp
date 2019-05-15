// Ganis Zulfa Santoso
// ganiszulfa [at] gmail [dot] com

#include <stdio.h>
#include <iostream>
#include <fstream>

// OPTIONAL
// #include <cmath>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  ifstream read("input.txt");
  ofstream write;
  write.open ("output.txt");
  // START HERE

  long long tot_case;
  read >> tot_case;

  long long N, L, ans;
  vector<string> dev, out, dev_x, out_x;
  string temp;
  string np = "NOT POSSIBLE";

  for (long long case_no = 1; case_no <= tot_case; ++case_no) {
	
	ans = 0;
	bool solved = true;
	
	read >> N >> L;
	dev.resize(0);
	out.resize(0);
	
	for (int i = 0; i < N; i++) {
		read >> temp;
		dev.push_back(temp);
	}
	
	for (int i = 0; i < N; i++) {
		read >> temp;
		out.push_back(temp);
	}
	
    sort(dev.begin(), dev.end());
    sort(out.begin(), out.end());
	
	// first check
	for (int i = 0; i < L; i++) {
		if (dev[i] != out[i]) {
			solved = false;
		}
	}
	
	if (!solved) {
		for (int i = 0; i < 55; i++) {
			for	(int j = 0; j < L; j++) {
				// flip it
				if ( out[i][j] == "0" ) {
					out[i][j] = "1";
				} else {
					out[i][j] = "0";
				}
			}
		}
	}
	
	for (int i = 0; i < L; i++) { // for device
		for	(int j = 0; j < L; j++) { // for outlet
			for (int k = 0; k < N; k++) {
				
			}
		}
	}
	
    // END HERE
    printf("Case #%d:", case_no);
    write << "Case #" << case_no << ": ";

    // ANSWER HERE
    write << ans << endl;
    printf("%d\n", ans);

  } // end for case_no 
  
  return 0;
}
