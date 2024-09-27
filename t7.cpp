#include<bits/stdc++.h>
using namespace std;
stack<char>stk;
int main()
{
	string s;
	cin>>s;
	int l=0,r=s.size()-1;
	while(l<=r)
	{
		if(s[l]==s[r])l++,r--;
		else {
			cout<<"no";
			return 0;
		}
	}
	cout<<"yes";
	return 1;
}

