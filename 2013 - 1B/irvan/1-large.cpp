#include <iostream>
//#include <string>
//#include <Cmath>
#include <algorithm>
//#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ofstream output;
	output.open ("output01-large.in");
	
	vector<long long> motes;
	
	int T,N;
	long long A, Nx;
	//int Nx[10];
	cin >> T ;
	
	for (int i=0; i< T; ++i)
	{
		cin >> A >> N;
		motes.resize(0);
		for (int j=0; j< N; ++j)
		{
			cin >> Nx;
			motes.push_back(Nx);
		}
		
		sort(motes.begin(), motes.end());
		
		int count = 0;
		long long total=A;
		bool solvable=true, Break = false;
		if (A > 1)
		{
			for ( int j=0; j< N; ++j)
			{
				if (total <= motes[j]) solvable = false;
				int temp=0;
				while(!solvable)
				{
					total += (total-1);
					++count;
					++temp;
					if (temp == N-j) 
					{
						solvable = true;
						Break = true;
					}
					if (total > motes[j]) solvable = true;
				}
				if (Break) break;
				if (total > motes[j]) total += motes[j];
				//cout << motes[j] << " " ;
			}
			//cout << endl;
		}
		else count=motes.size();
		
		if (count > motes.size()) count = motes.size();
		output << "Case #"<<i+1<<": "<<count<< endl;
		//output << count<< endl;
	}

	output.close();
	return 0;
}