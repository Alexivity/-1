#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,a[100],n,q,l,r;
typedef struct node{
    int data;
    node* next;
}Node,*pNode;
signed main()
{
    cin>>t;
    while(t--)
    {
        pNode head = (pNode) new (Node);
        pNode lastnode = head;
        cin>>n;
        while(n--)
        {
            int data;
            cin>>data;
            lastnode->next = (pNode) new (Node);
            lastnode=lastnode->next;
            lastnode->data=data;
            lastnode->next=NULL;
        }
        cin>>q;
        while(q--)
        {
            int option;
            cin>>option;
            if(option==1)
            {
                //int fl=0;
                pNode p = head->next;
                while(p!=NULL)
                {
                   // if(fl++==50)system("pause");
                    cout<<p->data<<" ";
                    p=p->next;
                }
                cout<<endl;
            }
            else if(option==2)
            {
                cin>>l>>r;
                pNode prept = head;
                pNode pt = head->next;
                while(pt)
                 {
                 if(pt->data>l&&pt->data<r)
                 {
                    prept->next = pt->next;
                    pt->next = NULL;
                    free(pt);
                    pt = prept->next;
                }else{
                    pt=pt->next;
                    prept=prept->next;
                }
              }
            }
        }
    }
}