#include <iostream>

using namespace std;

template<typename T>

class node{
    public:
    T val;
    node<T> *prev;
    node<T> *next;
    node(){
        next=NULL;
        prev=NULL;
    }
};

template<typename T>
class queue{
    public:
        queue(){
            head=NULL;
            tail=NULL;
        }
        void enqueue(T n){
            node<T> *newnode = new node<T>();
           newnode->val=n;
           if (head==NULL&&tail==NULL){
               head=newnode;
               tail=newnode;
           }
           else {
               node<T> *temp;
               temp=tail;
               newnode->prev=temp;
               temp->next=newnode;
               tail=newnode;
           }
        }
        T dequeue(){
            node<T> *temp1,*temp2;
           temp1=head;
            T n=temp1->val;
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
        int size(){
            int x=0;
           node<T> *temp=head;
           while(temp){
               x=x+1;
               temp = temp->next;
           }
           return x;
        }
        bool isempty(){
            if (head==NULL){
                return true;
            }
            return false;
        }
    private:
        node<T> *head;
        node<T> *tail;
};

template<typename T>
class printer{
    public:
        printer(int m,int n){
            capacity=m;
            ink=n;
        }
        void addDocument(T n){
            if(q.size()>=capacity){
                throw PrinterBusy("PRINTER_BUSY");
            }
            q.enqueue(n);
        }
        T printDocument(){
            if(q.size()<=0)
                throw NoDocument("NO_DOCUMENT");
            if(ink<=0)
                throw InsufficientInk("INSUFFICIENT_INK");
            ink--;
            T document=q.dequeue();
            cout<<document<<endl;
            return document;
        }
        void fillInk(int n){
            ink=n;
        }
        class InsufficientInk{
            public:
            InsufficientInk(string reason)
            {
                cout<<reason<<endl;
            }
        };
        class PrinterBusy
        {
            public:
            PrinterBusy(string  reason){
                cout<<reason<<endl;
            }
        };
        class NoDocument
        {
            public:
                NoDocument(string reason)
                {
                    cout<<reason<<endl;
                }
        };

        private:
        int capacity;
        int ink;
        queue<T> q;
};

template<typename T>
void functioning(int M,int N,int Q){
    printer<T> p(M,N);
    int c;
    for (int i=0;i<Q;i++){
    try{
        cin>>c;
        if (c==1){
            T doc;
            cin>>doc;
            p.addDocument(doc);
        }
        else if(c==2)
            T document=p.printDocument();
        else if (c==3){
            int d;
            cin>>d;
            p.fillInk(d);
        }
    }
    catch(typename printer<T>::InsufficientInk){}
    catch(typename printer<T>::NoDocument){}
    catch(typename printer<T>::PrinterBusy){}
    }
    return ;
}

int main() {
    int M,N;
    char T;
    cin>>M >>N >>T;
    int Q;
    cin>>Q;
    if (T=='I'){
        functioning<int> (M,N,Q);
    }
    else if (T=='C'){
        functioning<char> (M,N,Q);
    }
    else if(T=='F'){
        functioning<float> (M,N,Q);
    }

    return 0;
}