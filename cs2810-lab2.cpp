#include <cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Book {
    public :
        Book(){
            next=NULL;
        }
        string title;
        string author;
        int year;
        int price;
        Book *next;      
};



class Bookshelf {
    public :
           Book *head=NULL;
        void addBook(Book *ptr);
        void removebook();
        bool checkempty(){
            if (head==NULL){
                return true;
            }
            return false;
        }
        void list();
         void findcheap();
         void reverseunique();

};

class verticalbookshelf :public Bookshelf{
   public: 
  void  addBook(Book *ptr){
        if (head==NULL){
            head=ptr;
        }
        else{
            Book *temp;
            temp=head;
            ptr->next=temp;   
            head=ptr;
        }
    }
 void   removebook(){
        if (head==NULL){
            cout<<"e";
        }
        else {
            Book *ptrbook=head;
            head=ptrbook->next;
            free(ptrbook);
        }
    }
 void   list(){
        if (head==NULL){
            cout<<"e\n";
        }
        else{
            Book *ptrbook=head;
            while(ptrbook!=NULL)
            {
                cout<<ptrbook->title<<","<<ptrbook->author<<","<<ptrbook->year<<","<<ptrbook->price<<"\n";
                ptrbook=ptrbook->next;
            }
        }
    }
 void   findcheap(){
        Book *ptrbook;
        ptrbook=head;
        int c;
        if (checkempty()){
            cout<<"e";
        }
        else{
            c=ptrbook->price;
            for(ptrbook;ptrbook;ptrbook=ptrbook->next){
                if(c<ptrbook->price){
                    cout<<c;
                }else{
                    c=ptrbook->price;
                    cout<<"-1";
                }
                if(ptrbook->next!=NULL){
                    cout<<",";
                }
                else{
                    cout<<"\n";
                }
            }
        }
    }

};

class horizontalbookshelf :public Bookshelf{
  public:
     void addBook(Book* ptr){
        if (head==NULL){
            head=ptr;
        }
        else{
            
            Book *ptrbook=head;
           while(ptrbook->next!=NULL)
            {
                ptrbook=ptrbook->next;
            }
            ptrbook->next=ptr;
        }
    }
void    removebook(){
          if(checkempty())
                    cout<<"e";
        else {
            Book *ptrbook=head;
            head=ptrbook->next;
            free(ptrbook);
        }
    }
 void   list(){
        if (head==NULL){
            cout<<"e\n";
        }
        else{
            Book *ptrbook=head;
            while(ptrbook!=NULL)
            {
                cout<<ptrbook->title<<","<<ptrbook->author<<","<<ptrbook->year<<","<<ptrbook->price<<"\n";
                ptrbook=ptrbook->next;
            }
        }
    }
void    findcheap(){
        Book *ptrbook;
        ptrbook=head;
        int c;
        if (checkempty()){
            cout<<"e";
        }
        else{
            c=ptrbook->price;
            for(ptrbook;ptrbook;ptrbook=ptrbook->next){
                if(c<ptrbook->price){
                    cout<<c;
                }else{
                    c=ptrbook->price;
                    cout<<"-1";
                }
                if(ptrbook->next!=NULL){
                    cout<<",";
                }else{
                    cout<<"\n";
                }
            }
        }
    }
};

int main()
{
    int Q;
    cin>>Q;
    horizontalbookshelf h;
    verticalbookshelf v;
    while (Q--){
        string opcode;
        char scode;
        cin>>opcode;
        if(opcode=="ADD"){
            cin>>scode;
            if (scode=='h'){
                Book *ptr=new Book;
                cin>>ptr->title;
                cin>>ptr->author;
                cin>>ptr->year;
                cin>>ptr->price;
                h.addBook(ptr);
            }
            if (scode=='v'){
                Book *ptr=new Book;
                cin>>ptr->title;
                cin>>ptr->author;
                cin>>ptr->year;
                cin>>ptr->price;
                v.addBook(ptr);
            }

        }
      else  if(opcode=="REMOVE"){
            int n;
            cin>>n;
            cin>>scode;
            for (int i=0;i<n;i++){
                if (scode=='h'){
                    h.removebook();
                }
                if (scode=='v'){
                    v.removebook();
                }
            }
        }
     else   if(opcode=="LIST"){
            cin>>scode;
            if(scode=='h'){
                h.list();
            }
            if (scode=='v'){
                v.list();
            }
        }
        else if(opcode=="FINDC"){
            cin>>scode;
            if(scode=='h'){
                h.findcheap();
            }
            if(scode=='v'){
                v.findcheap();
            }
        }
        else if(opcode=="REVUNI"){


        }
    }
    return 0;
}