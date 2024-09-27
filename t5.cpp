#include<bits/stdc++.h>
using namespace std;
stack<char>stk;
class myclass{
	public:
	static void tostring(int n,int mod){
		while(n)
		{
			if(n%mod>=0&&n%mod<=9)stk.push(n%mod+'0');
			else stk.push('A'+n%mod-10);
			n/=mod;
		}
		while(!stk.empty())
		{
			cout<<stk.top();
			stk.pop();
		}
		return;
	}

};
int main()
{
	int n,m;
	cin>>n>>m;
	myclass::tostring(n,m);
}

