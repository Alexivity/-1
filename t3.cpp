#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
typedef struct pnode	
{ 
	float xishu;		
	int zhishu;		
	struct pnode *next;		
}pnode,*polynomial;		
int InitList(polynomial &L)		
{
	L=new pnode;	
	L->next=NULL;	
	return 0;
}
 //reerererererererrenothing 
 //writebyme
void CreatePolyn(polynomial &p,int n)	
{
	polynomial s,pre,q;		
	for(int i=1;i<=n;++i)		
	{
		s=new pnode;	
		cin>>s->xishu>>s->zhishu;	
		pre=p;		
		q=p->next;	
		while(q&&q->zhishu<s->zhishu)	
		{
			pre=q;
			q=q->next;
		}
		s->next=q;		
		pre->next=s;
	}
}
 
void Print(polynomial &p)	
{
	pnode *q;	
	q=p->next;	
	
	
	{
		{
			cout<<q->xishu<<"X^"<<q->zhishu;
		}
	}
	q=q->next;	
	while(q)	
	{
		
		{
			if(q->xishu>0)
			{
				
				{
					cout<<"+"<<q->xishu<<"X^"<<q->zhishu;
				}
			}
			else
			{
				{
					cout<<q->xishu<<"X^"<<q->zhishu;
				}
			}
		}
		q=q->next;	
	}
	cout<<endl;
}
 
void AddPolyn(polynomial &pa,polynomial &pb)	
{
	int sum;	
	polynomial p1,p2,p3,r;	
	p1=pa->next;
	p2=pb->next;
	p3=pa;
	while(p1&&p2) 
	{
		if(p1->zhishu==p2->zhishu)	
		{
			sum=p1->xishu+p2->xishu;
			if(sum!=0)	
			{
				p1->xishu=sum;	
				p3->next=p1;	
				p3=p1;
				p1=p1->next;
				r=p2;	
				p2=p2->next;
				delete r;	
			}
			else	
			{
				r=p1;
				p1=p1->next;
				delete r;
				r=p2;
				p2=p2->next;
				delete r;
			}
 
		}
		else if(p1->zhishu<p2->zhishu)	
		{
			p3->next=p1;	
			p3=p1;		
			p1=p1->next;
		}
		else		
		{
			p3->next=p2;	
			p3=p2;		
			p2=p2->next;
		}
	}
	p3->next=p1?p1:p2;	
	delete pb;	
}
 
void SubPolyn(polynomial &pa,polynomial &pb)
{
	int sum;	
	polynomial p1,p2,p3,r;	
	p1=pa->next;
	p2=pb->next;
	p3=pa;
	while(p1&&p2)	
	{
		if(p1->zhishu==p2->zhishu)	
		{
			sum=p1->xishu-p2->xishu;
			if(sum!=0)	
			{
				p1->xishu=sum;	
				p3->next=p1;	
				p3=p1;
				p1=p1->next;
				r=p2;		
				p2=p2->next;
				delete r;
			}
			else	
			{
				r=p1;
				p1=p1->next;
				delete r;
				r=p2;
				p2=p2->next;
				delete r;
			}
 
		}
		else if(p1->zhishu<p2->zhishu)	
		{
			p3->next=p1;	
			p3=p1;		
			p1=p1->next;
		}
		else	
		{
			p2->xishu=0-p2->xishu;		
			p3->next=p2;		
			p3=p2;
			p2=p2->next;
		}
	}
	if(p1!=NULL)		
	{
        p3->next=p1;
	}
    else		
	{
        p3->next=p2;
        while(p2)
       {
        p2->xishu=0-p2->xishu;
        p2=p2->next;
       }
    }
    delete pb;	
}

void copyPolyn(polynomial &pa, polynomial &pcopy)
{
	pcopy = new pnode;
	polynomial p1 = pa->next;
	polynomial p = pcopy;
	while(p1!=NULL)
	{
		p ->next = new (pnode);
		p->next->xishu=p1->xishu;
		p->next->zhishu = p1->zhishu;
		p = p->next;
		p1 = p1->next;
	}
	p->next=NULL;
	return;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	polynomial pa;
	InitList(pa);	
	polynomial pb;	
	InitList(pb);	
	int n,m;
	
	cin>>n>>m;
	CreatePolyn(pa,n);
	CreatePolyn(pb,m);
	int q;
	cin>>q;
	while(q--)
	{
	polynomial P;
	copyPolyn(pb,P);
	int op;
	cin>>op;
	if(op==2)
	{
		AddPolyn(pa,P);
	
		
	}
	else if(op==3)
	{
		
		SubPolyn(pa,P);
		
		
	}
	else if(op==1)
	{
		Print(pa);
		Print(pb);
	}
	}
	}
	
	
	return 0;
}