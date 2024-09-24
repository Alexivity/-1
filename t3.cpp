#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
typedef struct pnode	//定义结构体
{ 
	float xishu;		//系数
	int zhishu;		//指数
	struct pnode *next;		//指针
}pnode,*polynomial;		//结构体名字
int InitList(polynomial &L)		//初始化指针函数，便于后面初始化操作
{
	L=new pnode;	//为创建的链表自动分配空间
	L->next=NULL;	//创建头结点，其next域置为NULL 
	return 0;
}
 
void CreatePolyn(polynomial &p,int n)	//创建链表函数，需要传入创建的链表参数以及项数
{
	polynomial s,pre,q;		//创建s,pre,q三个结构体
	for(int i=1;i<=n;++i)		//做循环，直到达到链表的项数结束循环
	{
		s=new pnode;	//为s动态分配空间
		cin>>s->xishu>>s->zhishu;	//输入要创建的链表的系数和指数	
		pre=p;		//pre用于保存q的前驱，初值为头结点
		q=p->next;	//q初始化，指向首元结点
		while(q&&q->zhishu<s->zhishu)	//比较指数，找到第一个大于输入项指数的项*q
		{
			pre=q;
			q=q->next;
		}
		s->next=q;		//将输入项s插入到q和它的前驱结点pre之间 
		pre->next=s;
	}
}
 
void Print(polynomial &p)	//输出结果多项式
{
	pnode *q;	//用一个指针指向需要输出的链表
	q=p->next;	//指向它的首元结点
	
	
	{
		{
			cout<<q->xishu<<"X^"<<q->zhishu;
		}
	}
	q=q->next;	//让指针指向首元结点的下一个结点，后面的就只需要做一个循环解决系数和指数问题
	while(q)	//当q存在时
	{
		//如果系数为其它，指数>0,<0并且等于1或0的情况，为了解决符号以及显示
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
		q=q->next;	//指针再移动到下一个结点
	}
	cout<<endl;
}
 
void AddPolyn(polynomial &pa,polynomial &pb)	//pa=pa+pb，最终保留在pa中
{
	int sum;	//用于保存指数相同时，系数相加后的结果
	polynomial p1,p2,p3,r;	//p1指向pa,p2指向pb,p3指向当前结点，初值为pa，r用于保存计算后需要释放的p2结点
	p1=pa->next;
	p2=pb->next;
	p3=pa;
	while(p1&&p2) //当p1,p2存在时
	{
		if(p1->zhishu==p2->zhishu)	//进行判断，如果p1的指数和p2的指数相同，那么系数相加，用sum保存结果
		{
			sum=p1->xishu+p2->xishu;
			if(sum!=0)	//对sum保存的系数进行判断。不等于0时
			{
				p1->xishu=sum;	//修改pa当前结点的系数值为两项系数的和
				p3->next=p1;	//将修改后的pa结点加在p3之后，p3指向p1,p1指向后一项	
				p3=p1;
				p1=p1->next;
				r=p2;	//删除pb当前结点，p2指向后一项
				p2=p2->next;
				delete r;	
			}
			else	//如果系数和为0，则删除当前pa,pb结点
			{
				r=p1;
				p1=p1->next;
				delete r;
				r=p2;
				p2=p2->next;
				delete r;
			}
 
		}
		else if(p1->zhishu<p2->zhishu)	//如果pa结点指数小于pb结点指数
		{
			p3->next=p1;	//p1的结点放在p3后面
			p3=p1;		//p3指向p1,p1指向后一项
			p1=p1->next;
		}
		else		//如果pa结点指数大于pb结点指数
		{
			p3->next=p2;	//p2的结点放在p3后面
			p3=p2;		//p3指向p2,p2指向后一项
			p2=p2->next;
		}
	}
	p3->next=p1?p1:p2;	//当循环结束时，p1，p2一定会剩下一项，让剩下的插入pa(p3指向)
	delete pb;	//释放pb
}
 
void SubPolyn(polynomial &pa,polynomial &pb)
{
	int sum;	//用于保存指数相同时，系数相减后的结果
	polynomial p1,p2,p3,r;	//p1指向pa,p2指向pb,p3指向当前结点，初值为pa，r用于保存计算后需要释放的p2结点
	p1=pa->next;
	p2=pb->next;
	p3=pa;
	while(p1&&p2)	//当p1,p2存在时
	{
		if(p1->zhishu==p2->zhishu)	//进行判断，如果p1的指数和p2的指数相同，那么系数相减，用sum保存结果
		{
			sum=p1->xishu-p2->xishu;
			if(sum!=0)	//对sum保存的系数进行判断。不等于0时
			{
				p1->xishu=sum;	//修改pa当前结点的系数值为两项系数的差
				p3->next=p1;	//将修改后的pa结点加在p3之后，p3指向p1,p1指向后一项	
				p3=p1;
				p1=p1->next;
				r=p2;		//删除pb当前结点，p2指向后一项
				p2=p2->next;
				delete r;
			}
			else	//如果系数和为0，则删除当前pa,pb结点
			{
				r=p1;
				p1=p1->next;
				delete r;
				r=p2;
				p2=p2->next;
				delete r;
			}
 
		}
		else if(p1->zhishu<p2->zhishu)	//如果pa结点指数小于pb结点指数
		{
			p3->next=p1;	//p1的结点放在p3后面
			p3=p1;		//p3指向p1,p1指向后一项
			p1=p1->next;
		}
		else	//如果pa结点指数大于pb结点指数
		{
			p2->xishu=0-p2->xishu;		//p2的结点放在p3后面,注意应该变成负的
			p3->next=p2;		//p3指向p2,p2指向后一项
			p3=p2;
			p2=p2->next;
		}
	}
	if(p1!=NULL)		//如果剩余段是p1
	{//插入非空多项式的剩余段
        p3->next=p1;
	}
    else		//如果剩余段是p2
	{
        p3->next=p2;
        while(p2)//第二段连上要变成负的
       {
        p2->xishu=0-p2->xishu;
        p2=p2->next;
       }
    }
    delete pb;	//释放pb
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
	InitList(pa);	//初始化pa
	polynomial pb;	
	InitList(pb);	//初始化pb
	int n,m;
	//cout<<"CIN>>N>>M"<<endl;
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
	//	Print(pa);
		//Print(pb);
	}
	else if(op==3)
	{
		//Print(P);
		SubPolyn(pa,P);
		//Print(pa);
		//Print(pb);
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