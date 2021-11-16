#include<iostream>
using namespace std;
int main()
{
	int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
	cout<<"no of process ";
	cin>>n;
	cout<<"\n enter brust time\n ";
	for(i=0;i<n;i++)
	{
		cout<<"p["<<i+1<<"]:";
		cin>>bt[i];
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		wt[i]+=bt[j];
	}
	cout<<"\nprocess\tburst time\twaiting time\tturnaround time\n";
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		avwt+=wt[i];
		avtat+=tat[i];
		cout<<"p["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
	}
	avwt/=i;
	avtat/=i;
	cout<<"\navg waiting time "<<avwt;
	cout<<"\navg turnaround time "<<avtat;
	return 0;
	}
