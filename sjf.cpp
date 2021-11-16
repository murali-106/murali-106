#include<iostream>
using namespace std;
int main()
{
	int n,temp,min,tt=0,d,i,j;
	float avtat=0,avwt=0,stat,swt;
	cout<<"enter no of process : ";
	cin>>n;
	int at[n],bt[n],e[n],wt[n],tat[n];
	for(i=0;i<n;i++)
	{
		cout<<"enter arrival time ";
		cin>>at[i];
	}
	for(i=0;i<n;i++)
	{
		cout<<"enter brust time ";
		cin>>bt[i];
	}
	for(i=0;i<n;i++)
	{
       for(j=i+1;j<n;j++)
	   {
		 if(bt[i]>bt[j])
		  {
		  	temp=at[i];
		 	at[i]=at[j];
		 	at[j]=temp;
		 	
		 	temp=bt[i];
		 	bt[i]=bt[j];
		 	bt[j]=temp;
		  }
		}	
	}
	min=at[0];
	for(i=0;i<n;i++)
	{
		if(min>at[i])
		{
			min=at[i];
			d=i;
		}
	}
	tt=min;
	e[d]=tt+bt[d];
	tt=e[d];
	for(i=0;i<n;i++)
	{
		if(at[i]!=min)
		{
	    	e[i]=tt+bt[i];
	        tt=e[i];	
		}
	}
	for(i=0;i<n;i++)
	{
		tat[i]=e[i]-at[i];
		stat=stat+tat[i];
		wt[i]=tat[i]-bt[i];
		swt=swt+wt[i];
	}
	avtat=stat/n;
	avwt=swt/n;
	cout<<"\nprocess\t\tarrival time\tbrust time\twaiting time\tturnaround time";
	for(i=0;i<n;i++)
    {
    cout<<"\nP"<<i+1<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
    cout<<"avwt="<<avwt<<" avtat="<<avtat; 
    return 0;	 		
}
