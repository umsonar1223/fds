#include<iostream>
#include<stdlib.h>
using namespace std; 
class node
{
int data;
node *next;
friend class sll;
};
class sll
{
node *head1, *head2,*last;
public:
sll()
{
head1=head2=NULL;
}
 
void insert();
void display1();
void delnegative();
void split();
void merge();
void display2();
void sortlists();
void sort(node *t);
};
 
&nbsp;
 
void sll::insert()
{
int n,i;
node *t,*p;
cout<<"\nEnter total nodes of insert";
cin>>n;
for(i=0;i<n;i++)
{
t=new node; //ew node creation
cout<<"\nEnter data";
cin>>t->data;
t->next=NULL;
if(head1==NULL)
head1=t;
else
{
 
p=head1; //set p on first node
while(p->next!=NULL)
p=p->next; //p would be last node
p->next=t; //place t after p
}
}
}
 
&nbsp;
 
&nbsp;
 
void sll::display1()
{
node *t;
cout<<"list is shown below"<<endl;
if (head1==NULL)
cout<<"\nEMPTY";
else
t=head1;
do
{
cout<<t->data<<endl;
t=t->next;
}
while(t!=NULL);
 
}
 
void sll::display2()
{
node *t;
cout<<"list is shown below"<<endl;
if (head1==NULL)
cout<<"\nEMPTY";
else
t=head2;
do
{
cout<<t->data<<endl;
t=t->next;
}
while(t!=NULL);
 
}
 
&nbsp;
 
&nbsp;
 
void sll::delnegative()
{
node *t,*p;
if (head1==NULL)
cout<<"\nEmpty list..... nothing to be delete"<<endl;
else
{
////startind from 2nd node----> 1st left
t=head1->next; //t on 2nd
p=head1; //p on 1st previous to t
while(t!=NULL)
{
if (t->data<0) //negativ value in t
{
p->next=t->next;
delete t;
t=p->next;
}//if
else
{
p=t;
t=p->next;
}//else
 
}//while
 
if(head1->data<0) ////considering 1st node
{
t=head1;
head1=head1->next;
delete t;
}//if
 
}//else
 
}//delnegative
 
&nbsp;
 
&nbsp;
 
void sll::split()
{
node *t,*p;
if (head1==NULL)
cout<<"\nEmpty list..... nothing to be split"<<endl;
else
{
////startind from 2nd node----> 1st left
t=head1->next; //t on 2nd
p=head1; //p on 1st previous to t
while(t!=NULL)
{
if (t->data<0) //negative value in t
{
p->next=t->next;
if(head2==NULL)
{
head2=t;
last=t;
last->next=NULL;
}//if
else
{
last->next=t;
last=t;
last->next=NULL;
}//else
t=p->next;
}//if
else
{
p=t;
t=p->next;
}//else
 
}//while
 
if(head1->data<0) ////considering 1st node
{
t=head1;
head1=head1->next;
if(head2==NULL)
{
head2=t;
last=t;
last->next=NULL;
}//if
else
{
t->next=head2;
head2=t;
}//else
 
}//if
 
}//else
 
}//split
 
&nbsp;
 
&nbsp;
 
void sll::sortlists()
{
sort(head1);
cout<<"\nAfter sorting first ";
display1();
sort(head2);
cout<<"\nAfter sorting second ";
display2();
 
}//sortlists
 
&nbsp;
 
void sll::sort(node *t)
{
node *t1,*t2;
int temp;
if(t==NULL)
return;
for(t1=t;t1->next!=NULL;t1=t1->next)
{
for(t2=t1->next;t2!=NULL;t2=t2->next)
{
if(t1->data > t2->data)
{
temp=t1->data;
t1->data=t2->data;
t2->data=temp;
}//if
 
}//for
 
}//for
 
}//sort(node *t)
 
&nbsp;
 
void sll::merge()
{
last->next=head1; //attach list 1st at end of 2nd list
head1=head2;
head2=NULL;
cout<<"\nMerged ";
display1();
 
}//merge
 
int main()
{
sll obj;
int ch;
while(1)
{
cout<<"\n---------MENU---------"<<endl;
cout<<"\n1.INSERT \n2.DISPLAY \n3.DELETE NEGATIVE \n4.SPLIT \n5.SORT & MERGE \n6.EXIT"<<endl;
cout<<"\nEnter your choice"<<endl;
cin>>ch;
switch(ch)
{
case 1:
obj.insert();
break;
case 2:
obj.display1();
 
break;
case 3 :
obj.delnegative();
cout<<"\nAfter deletion ";
obj.display1();
break;
case 4:
obj.split();
cout<<"\nAfter splitting:"<<endl;
cout<<"\nFirst ";
obj.display1();
cout<<"\nSecond ";
obj.display2();
break;
case 5:
obj.sortlists();
obj.merge();
break;
case 6:
exit(0);
default:
cout<<"\nWrong choice";
 
}
}
return 0;
}
