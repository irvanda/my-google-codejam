#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream output;
	output.open ("output01.in");
	int T, c;
	double C, F, X, A=0.0, R = 2.0, p=0.0;
	cin >> T;
	for (int i=0; i < T; i++)
	{
		cin >> C >> F >> X;
		c = (int)(X/C);
		if (C>1)
		{
			for(int i=0; i<c; i++)
			{
				p+=(C/R);
				R+=F;
				A+=C;
			}	
			p+=((X-A)/R);					
		}
		
		else
		{
			p+=((X-A)/R);
		}
		
		output << "Case #" << i+1 << ": " << p << endl;
	}
	return 0;
}