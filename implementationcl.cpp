#include<iostream>
using namespace std;

class NODE
{
    int data;
    NODE* next;
    public:
    NODE(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    void insertF(NODE* &head,NODE* &tail,int x);
    void insertL(NODE* &head,NODE* &tail,int x);
    void insertR(NODE* &head,NODE* &tail,int x,int pos);
    void display(NODE* &head,NODE* &tail);
    int deleteF(NODE* &head,NODE* &tail);
    int deleteL(NODE* &head,NODE* &tail);
    int deleteR(NODE* &head,NODE* &tail,int pos);
    int size(NODE* &head,NODE* &tail);
};

void NODE::insertF(NODE* &head,NODE* &tail,int x)
{
   NODE* temp=new NODE(x);
   if(head==NULL)
   {
     head=tail=temp;
     tail->next=head;
   }
   else
   {
       temp->next=head;
       head=temp;
       tail->next=head;
   }
   
}
void NODE::insertL(NODE* &head,NODE* &tail,int x)
{
    NODE* temp=new NODE(x);
    if(head==NULL)
    head=tail=temp;
    else
    {
        tail->next=temp;
        tail=temp;
    }
    tail->next=head;

}
void NODE::insertR(NODE* &head,NODE* &tail,int x,int pos)
{
  int i;
  int l=size(head,tail);
  if(pos==1)
   insertF(head,tail,x);
  else if(pos==l+1)
    insertL(head,tail,x);
  else if(pos<0||pos>l+1)
    cout<<"invalid position";
  else 
  {
    NODE *temp,*p,*t;
    temp=new NODE(x);
    for(p=head,i=1;i<(pos-1);i++,p=p->next);
    temp->next=p->next;
    p->next=temp;

  }     
}
void NODE::display(NODE* &head,NODE* &tail)
{
     NODE* p;
     if(head==NULL)
       cout<<"no element present in list:";
     else if(head==tail)
     {
      p=head;
      cout<<p->data<<" ";
     } 
     else
     {
        // for(p=head;p!=tail;p=p->next)
        // cout<<p->data<<" ";
        p=head;
        do
        {
          cout<<p->data<<" ";
          p=p->next;
        } while (p!=head);
    }
}
int NODE::deleteF(NODE* &head,NODE* &tail)
{
    int x;
    if(head==NULL)
     cout<<"list is empty";
    else
    {
       NODE*p;
       p=head;
       head=p->next;
       tail->next=head;
       x=p->data;
       delete p;
       return x;
    } 
}
int NODE::deleteL(NODE* &head,NODE* &tail)
{
    int x;
    NODE* p,*t;
    if(head==NULL)
      cout<<"list is empty";
    else if(head==tail)
    {
      head=tail=NULL;
    }  
    else 
    {
      
      for(p=head;p!=tail;t=p,p=p->next);
      tail=t;
      tail->next=head;
    } 
    x=p->data;
      delete p;
      return x; 
}
int NODE::deleteR(NODE* &head,NODE* &tail,int pos)
{   int x,i;
     int l=size(head,tail);
     if(pos==1)
       deleteF(head,tail);
     else if(pos==l)
       deleteL(head,tail);
     else if(pos<0||pos>l)
       cout<<"invalid position";
     else 
     {
        NODE* p,*t;
        for(p=head,i=1;i<(pos-1);i++,p=p->next);
        t=p->next;
        x=t->data;
        p->next=t->next;
        delete t;
        return x;

     }      

}
int NODE::size(NODE* &head,NODE* &tail)
{
    NODE*p;
    int i;
    for(p=head,i=1;p!=tail;i++,p=p->next);
    return i;
}

int main()
{
    NODE* node=new NODE(10);
    NODE*head=NULL;
    NODE* tail=NULL;
    int ch,x,k,pos;
    cout<<"\n1.insert first\n2.insert last\n3.insert random\n4.display\n5.delete first\n6.delete last\n7.delete random\n8.size\n9.exit"<<endl;
    do
    {
        cout<<"enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"enter the value you have to insert";
                cin>>x;
                node->insertF(head,tail,x);
                break;
            case 2:
                 cout<<"enter the value you have to insert:";
                 cin>>x;
                 node->insertL(head,tail,x);
                 break;
            case 3:
                 cout<<"enter the value you have to insert:";
                  cin>>x;
                   cout<<"enter the position at which you have to insert:";
                   cin>>pos;
                   node->insertR(head,tail,x,pos);
                   break;
            case 4:
                      node->display(head,tail);
                    break;
            case 5:
                    k=node->deleteF(head,tail);
                    cout<<"deleted element is:"<<k;
                    break;
            case 6:
                  k=node->deleteL(head,tail);
                    cout<<"deleted value is:"<<k<<endl;
                   break;
            case 7:
               cout<<"enter the position you have to delete";
                 cin>>pos;
                   k=node->deleteR(head,tail,pos);
                   cout<<"deleted element is:"<<k<<endl;
                   break;
            case 8:
                k=node->size(head,tail);
                cout<<"size of list is:"<<k;
                 break;
            case 9:
              cout<<"exit";
              break;
        }
    }while(ch!=9);

    return 0;
}