#include<bits/stdc++.h>
using namespace std;
stack<char>stk;
int main()
{
	char c;
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='(')
		{
			stk.push(c);
		}else if(c==')')
		{
			if(stk.top()!='(')
			{
				cout<<0;
				return 0;
			}else stk.pop();
		}
		else if(c=='[')
		{
			stk.push(c);
		}else if(c==']')
		{
			if(stk.top()!='[')
			{
				cout<<0;
				return 0;
			}else stk.pop();
		}else if(c=='{')
		{
			stk.push(c);
		}else if(c=='}')
		{
			if(stk.top()!='{')
			{
				cout<<0;
				return 0;
			}else stk.pop();
		}
	}
	if(stk.empty())cout<<1;
	return 1;
}

