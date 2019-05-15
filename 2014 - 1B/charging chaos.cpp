// Ganis Zulfa Santoso
// ganiszulfa [at] gmail [dot] com

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

// OPTIONAL
#include <cmath>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <string>


#include <sstream>

using namespace std;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

int main(int argc, const char *argv[])
{
  ifstream read("input.txt");
  ofstream write;
  write.open ("output.txt");
  // START HERE

  long long tot_case;
  read >> tot_case;

  int div; 
  double x;
  vector<string> dev, out, dev_x, out_x, exploded;
  string temp ;
  string np = "NOT POSSIBLE";

  for (long long case_no = 1; case_no <= tot_case; ++case_no) {
	
	long long P, Q, ans;
	ans = 0;
	bool solved = false;
	
	read >> temp;
	cout << temp << endl;
	exploded = split(temp, '/');
	cout << exploded[0] << endl;
	cout << exploded[1] << endl;
	Q = stoi(exploded[1]);
	P = stoi(exploded[0]);
	x = Q/P;
	if ( floor(x) != ceil(x) ) {
		x = Q;
	}
	
	int z = 1;

	while(z<=Q){
		ans++;
		if (int(x)%2==0){
			solved = true;
			break;
		}
		z*=2;
	}
	
    // END HERE
    printf("Case #%d:", case_no);
    write << "Case #" << case_no << ": ";

    // ANSWER HERE
	if (solved) {
		printf("%d\n", ans);
		write << ans << endl;
	} else {
		printf("impossible\n");
		write << "impossible" << endl;
	}

  } // end for case_no 
  
  return 0;
}
