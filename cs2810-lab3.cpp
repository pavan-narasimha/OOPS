#include <bits/stdc++.h>
using namespace std;

template<typename E>

class node{
    public :
        E val;
       node<E> *prev;
       node<E> *next;
       node(){
           prev=NULL;
           next=NULL;
       }
};

template<typename E>
class DLL{
     private :
       node<E> *head;
       node<E> *tail;
    public :

           DLL(){
           head=NULL;
           tail=NULL;
       }
       void push_front( E n){
           node<E> *newnode = new node<E>();
           newnode->val=n;
           if (head==NULL&&tail==NULL){
               head=newnode;
               tail=newnode;
           }
           else {
               node<E> *temp=head;
               newnode->next=temp;
               temp->prev=newnode;
               head=newnode;
           }
       }
       void push_end( E n){
           node<E> *newnode = new node<E>();
           newnode->val=n;
           if (head==NULL&&tail==NULL){
               head=newnode;
               tail=newnode;
           }
           else {
               node<E> *temp;
               temp=tail;
               newnode->prev=temp;
               temp->next=newnode;
               tail=newnode;
           }
       }
         E pop_front(){
           node<E> *temp1,*temp2;
           temp1=head;
            E n=temp1->val;
           if(head==tail){
               head=NULL;   
               tail=NULL;
               delete temp1;
               return n;
           }
           
           temp2=temp1->next;
           temp1->next=NULL;
           temp2->prev=NULL;
           head=temp2;
           free(temp1);
           return  n;
       }
         E pop_end(){
           node<E> *temp1,*temp2;
           temp1=tail;
            E n=temp1->val;
           if(head==tail){
               head=NULL;   
               tail=NULL;
               delete temp1;
               return n;
           }
           temp2=temp1->prev;
           temp1->prev=NULL;
           temp2->next=NULL;
           tail=temp2;
           free (temp1);
           return n;
           
       }
       int size(){
           int x=0;
           node<E> *temp=head;
           while(temp){
               x=x+1;
               temp = temp->next;
           }
           return x;
       }

       void print()
       {
           node<E>* temp=head;
           while(temp!=NULL)
           {
               cout<<temp->val<<" ";
               temp=temp->next;
           }
       }

};

template<class E>
class Stack{
     private :
        DLL<E> l1;

    public :
       void Push( E n){
           
           l1.push_front(n);
           
       }
        E Pop(){
           return l1.pop_front();
           
       }
        E Top(){
           E n;
           n=l1.pop_front();
           l1.push_front(n);
           return n;
       }
       int Size(){
           int x;
           x=l1.size();
           return x;
       }
       bool compare ( E n){
           if(n>l1.top()){
               return true;
           }
           else 
           return false;
       }

       void print_stack()
       {
           l1.print();
       }
    
};

template<typename E>
void encrypt(int N)
{
     Stack<E>s;
     E temp;
     int n=0;
     cin>>temp;

     while(n!=N)
     {
         if(s.Size()==0)
         {
             s.Push(temp);
             cin>>temp;
             n=n+1;
         }
         else if(temp>s.Top())
         {
             s.Push(temp);
             cin>>temp;
             n=n+1;
         }
         else if(temp<=s.Top())
         {
             cout<<s.Pop();
         }

     }
     if(n==N)
     {
     while(s.Size())  cout<<s.Pop();
     }

}



int main() {
     int N;
     char T;
     cin>>N >>T;
     if (T=='I')
     {
         encrypt<int>(N);
     }
     else if(T=='C')
     {
         encrypt<char>(N);
     }
     else if(T=='F')
     {
         encrypt<float>(N);
     } 

    
}