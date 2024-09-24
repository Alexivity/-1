#include<bits/stdc++.h>
using namespace std;
#define int long long
queue<int>q;
int a[100];
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            q.push(i);
        }
        int m;
        cin>>m;
        int now_m=0;
        while(!q.empty())
        {
            int now_data=q.front();
            q.pop();
            now_m++;
            if(now_m==m)
            {
                now_m=0;
                std::cout<<now_data<<" ";
                m=a[now_data];
            }else{
                q.push(now_data);
            }
        }
       std::cout<<endl;
    }
}