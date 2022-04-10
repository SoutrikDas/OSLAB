#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n) for( i= 0 ; i<n ; i++)

class block
{
    public: 
    int size = -1 ;
    string nam;
    int psize;
    int IF;
    bool isEmpty=true;
    block()
    {
        size=-1;
    }
    block(int s)
    {
        size = s;
    }

};

void worst_fit(block *arr,int n, int process ,int ind, int &optr)
{
    // optr is old pointer , pointing to the last memory block allocated
    int i =0;
    int ex = 0;
    for( i = optr ; i < n ; i++)
    {
        if( arr[i].isEmpty && arr[i].size>=process)
        {
            arr[i].isEmpty = false;
            arr[i].psize=process;
            arr[i].IF=arr[i].size-process;
            cout<<"P"<<ind<<" size:"<<process<<" is being assigned to  block "<<i<<" with IF="<<arr[i].IF<<endl;
            optr = i;
            return;
        }
    }
    for( i = 0 ; i < optr ; i++)
    {
        if( arr[i].isEmpty && arr[i].size>=process)
        {
            arr[i].isEmpty = false;
            arr[i].psize=process;
            arr[i].IF=arr[i].size-process;
            cout<<"P"<<ind<<" size:"<<process<<" is being assigned to  block "<<i<<" with IF="<<arr[i].IF<<endl;
            optr = i;
            return;
        }
    }
    FOR(i,n)
    {
        if(arr[i].isEmpty)
        {
            ex+=arr[i].size;
        }
        else
        {
            ex+=arr[i].IF;
        }
    }
    cout<<"P"<<ind<<" size:"<<process<<" was not assigned to any of the blocks, EF="<<ex<<endl;
    

}

int main()
{
    int n , s;
    cout<<"Enter no. of blocks \n";
    cin>>n;
    int i =0,j=0,temp=0,c=0;
    int m ;
    block arr[100];
    int process[100];
    for( i =0 ;i < n ;i ++)
    {
        cin>>arr[i].size;
    }



    cout<<"Enter no. of process \n";
    cin>>m;
    FOR(i,m)cin>>process[i];
    int optr=0;
    FOR(i,m)
    {
        worst_fit(arr,n, process[i],i,optr);
    }
    
    
}