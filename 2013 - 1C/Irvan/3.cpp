#include <iostream>
//#include <string>
//#include <Cmath>
#include <algorithm>
//#include <sstream>
#include <fstream>
//#include <vector>
#include <climits>

using namespace std;

int main()
{
	ofstream output;
	output.open ("output03.in");
	
	int T, N, AT, ans;
	cin >> T; 
	
	int di[1000], ni[1000], wi[1000], ei[1000], si[1000], delta_di[1000], delta_pi[1000], delta_si[1000];
	int wall[2001], upgrade[2001];
	bool succ;
	
	for (int i=0; i< T; ++i)
	{
		cin >> N;
		AT=0;
		ans=0;
		for (int j = 0; j < N; ++j) 
		{
			cin >> di >> ni >> wi >> ei >> si >> delta_di >> delta_pi >> delta_si;
			wi[j]+=1000;
			ei[j]+=1000;
			
			AT += ni[j];
		}
		for (int j = 0; j < 2001; ++j) 
		{
			wall[j] = 0;
			upgrade[j] = 0;
		} 
		for (int day = 0; day < INT_MAX; ++day) 
		{
		  for (int tribe = 0; tribe < N; ++tribe) {
			if(di[tribe]==day && ni[tribe]>0 )
			{
			  succ = false;
			  for (int pos = wi[tribe]; pos < ei[tribe]; ++pos) 
			  {
				if(wall[pos] >= si[tribe])
				{
				  // strong enough
				}
				else
				{
				  // not strong enough
				  succ = true;
				  if(upgrade[pos]<si[tribe]) upgrade[pos] = si[tribe];
				}
			  } 
			  if(succ) ++ans;
			  
			  si[tribe] += delta_si[tribe];
			  ei[tribe] += delta_pi[tribe];
			  wi[tribe] += delta_pi[tribe];
			  di[tribe] += delta_di[tribe];
			  --ni[tribe];
			  --AT;
			}
		  }  
		  for (int j = 0; j < 2001; ++j) 
		  {
			wall[j] = upgrade[j];
		  }  
		  if(!AT) break;
		} 
		
		output << "Case #"<<i+1<<": "<<ans<< endl;
	}
	
	output.close();
	return 0;
}