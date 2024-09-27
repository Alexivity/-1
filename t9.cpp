#include<bits/stdc++.h>
#define first x
#define second y
using namespace std;
int mp[50][50];
	int n,m;
struct mynode{
	int x,y;
};
int flag=0,finish=0;
queue<struct mynode> q;
int dir[4][2]={1,0,0,-1,0,1,-1,0};
bool vis(int x,int y)
{
	if((mp[x][y]==1||mp[x][y]==2)&&x<n&&y<m&&x>=0&&y>=0)return true;
	return false;
}
void print()
{
	flag=1;
	printf("YES\n");
	while(q.size()>1)
	{
		printf("(%d,%d)->",q.front().first,q.front().second);
		q.pop();
	}
	printf("(%d,%d)",q.front().first,q.front().second);
}
int k=1;
void dfs(int x,int y)
{
	//printf("(%d,%d)\n",x,y);
///if(k++>=10)return;
	//if(finish)return;
	if(mp[x][y]==2)
	{
		mp[x][y]=-1;
		print();
		finish=1;
	}
	for(int i=0;i<4;i++)
	{
			int nx=x+dir[i][0],ny=y+dir[i][1];
			if(vis(nx,ny))
			{
				mp[x][y]=-1;
				q.push({nx,ny});
				dfs(nx,ny);
				mp[x][y]=1;
				q.pop();
			}
	}
}

int main()
{

	cin>>n>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		cin>>mp[i][j];
	}
	q.push({0,0});
	dfs(0,0);
	if(!flag)printf("NO");
}

