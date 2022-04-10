#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
void LRU(int frame_count, vector<int> pages)
{
    int n = pages.size();
    unordered_set<int> s;
    unordered_map<int,int> mp;
    int miss_count =0 , hit_count=0;
    for( int i =0 ; i<n ;i++)
    {
        if( s.size()<frame_count)
        {
            if(s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                miss_count++;
            }
            else    
                hit_count++;
            mp[pages[i]]=i;
        }
        else{
            if(s.find(pages[i])==s.end())
            {
                int lru = INT_MAX;
                int val;
                for( auto it = s.begin(); it!=s.end();it++)
                {
                    if(mp[*it] < lru)
                    {
                        lru = mp[*it];
                        val = *it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                miss_count++;
            }
            else
                hit_count++;
            mp[pages[i]]= i ;
        }

    }
    cout<<"\n Page Faults="<<miss_count<<endl;
    cout<<"\n hit count ="<<hit_count<<endl;
    cout<<"\n Hit Ratio="<<100*(float)hit_count/(hit_count + miss_count)<<" % "<<endl;
    cout<<"\n Miss cont="<<miss_count<<endl;
    cout<<"\n Miss Ratio="<<100*(float)miss_count/(hit_count + miss_count)<<" % "<<endl;
}
int main()
{
    int i ;
    int f, p;
    cout<<"\n input frame count;\n";
    cin>>f;
    cout<<"\n input page count \n";
    cin>>p;
    vector<int> pgs(p);
    cout<<"\n input the page numbers \n";
    for( i =0 ; i<p; i++)
    {
        cin>>pgs[i];
    }
    LRU(f,pgs);
    return 0 ; 
}
