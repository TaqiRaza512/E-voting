#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
void InIt(string PNames[],int &PCount,int Vs[],int &VCount)
{
	ifstream Rdr("Votes.txt");
	Rdr >> PCount; 
	for (int i=1;i<=PCount;i++)
	{
		Rdr >> PNames[i];
	}
	Rdr >> VCount;
	for (int i=0;i<VCount;i++)
	{
		Rdr >> Vs[i];
	}
}
void CompileElection(int Vs[],int VCount,int PVCount[])
{
	for (int i=0;i<VCount;i++)
	{
		int v = Vs[i];
		PVCount[v]++;
	}
}
void PrintElectionResult(string PNames[],int PVCount[],int PCount)
{
	char fchar = -37;
	for(int pi=1;pi<=PCount;pi++)
	{
		cout << PNames[pi] << " " << PVCount[pi] << "\t";
		for(int t=1;t<=PVCount[pi];t++)
		{
			cout << fchar;
		}
		cout << endl << endl;
	}
}
void Swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Swaps(string l,string p)
{
	string temp = l;
	l = p;
	p = temp;
}
void Sort(string PNames[], int PVCount[],int PCount)
{
	for (int t=1;t<=PCount;t++)
	{

		for (int i=1;i+1<PCount;i++)
		{
			if (PVCount[i]<PVCount[i+1])
			{
				Swap(PVCount[i], PVCount[i + 1]);
				Swaps(PNames[i],PNames[i + 1]);

			}

		}
	}

}
int main()
{

	const int MaxNoOfParties = 100,capacity=100;
	int PCount,VCount;
	string PNames[MaxNoOfParties];
	int Vs[capacity] = {};
	int PVCount[MaxNoOfParties] = {};
	InIt(PNames, PCount, Vs, VCount);
	CompileElection(Vs,VCount,PVCount);
	PrintElectionResult(PNames, PVCount, PCount);
	Sort(PNames,PVCount,PCount);
	cout << endl << endl;
	cout << "Following the election result is sorted in ascending order............\n\n\n";
	PrintElectionResult(PNames, PVCount, PCount);


}