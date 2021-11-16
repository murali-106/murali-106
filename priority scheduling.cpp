#include<iostream>
using namespace std;
int main()
{
    int p[20],bt[20],wt[20],tat[20],pr[20],i,n,j,total=0,temp,pos,avwt,avtat;
    cout<<"enter no of process ";
    cin>>n;
    cout<<"enter brust time and priority :\n";
    for(i=0;i<n;i++)
    {
        cout<<"ennter brust time ";
        cin>>bt[i];
        cout<<"enter priority ";
        cin>>pr[i];
        p[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
            pos=j;
        } 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
        
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
     wt[i]=0;
     for(j=0;j<i;j++)
     wt[i]+=bt[j];
     total+=wt[i];
    }
    avwt=total/n;
    total=0;
    
    cout<<"\nprocess\t\tbrust time\twaiting time\tturnaround time ";
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        cout<<"\np["<<p[i]<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }
    avtat=total/n;
    cout<<"\navg wt "<<avwt<<"avg tat"<<avtat;
    return 0;
}
