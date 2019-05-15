#include <iostream>
#include <string>
#include <Cmath>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
	ofstream output;
	output.open ("test_beda.txt");
	int data1[10000]={}, data2;
	for (int i=0; i<100; ++i)
	{
		cin >> data1[i];
	}
	int count=0;
	for (int i=0; i<100; ++i)
	{
		cin >> data2;
		if (data2 != data1[i]) 
		{
			output << i+1<< endl;
			count++;
		}
	}
	cout << endl << "yang beda ada = "<< count ;
	output.close();
	return 0;
}