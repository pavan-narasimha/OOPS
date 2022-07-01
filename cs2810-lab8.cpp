#include<bits/stdc++.h>

using namespace std;

template <class T>
class Node{
    public:
        T key,val;
        Node<T>* top;
        Node<T>* bottom;
        Node<T>* left;
        Node<T>* right;
        Node(){
            top=NULL;
            bottom=NULL;
            left=NULL;
            right=NULL;
        }
        Node(T key,T val)
        {
            this->key=key;
            this->val=val;
            top=NULL;
            bottom=NULL;
            left=NULL;
            right=NULL;
        }
};

template <class T>
class Skiplist{
    private:
        Node<T>* head;
        int size=0;
    public:
        Skiplist(){
            head=new Node<T>;
            Node<T> * ptr=head;
            ptr->right=new Node<T> ;
            ptr->right->left=ptr;
            for(int i=0;i<9;i++)
            {
                ptr->bottom=new Node<T>;
                Node<T>* ptr1=ptr->bottom;
                ptr1->top=ptr;
                ptr1->right=new Node<T> ;
                ptr1->right->left=ptr1;
                ptr1->right->top=ptr1->top->right;
                ptr1->top->right->bottom=ptr1->right;

                ptr=ptr->bottom;
            }
        }
        void insert(T key,T value){
            Node<T>* ptr=new Node<T>(key,value);
            Node<T>* temp=search(key);
            if (key==temp->key) return;
            else {
                size++;
                Node<T>* ptr=temp->right;
                
            }

        }
        Node<T> * search(T key)
        {
            Node<T> *ptr=head;
            for(int i=0;i<9;i++)
            {
                if(ptr->right->right){
                    while(key>=ptr->right->key&&ptr->right->right){
                        ptr=ptr->right;
                    }
                }
            }
            return ptr;
        }
};

template<class T>
class dictionary{
    private:
        Skiplist<T> S;
    
    public:
        bool empty(){
                return S.size();
        }
        void insert(T key,T value){
                S.insert(key,value);
        }
        void delete(T k){
            S.delete(k);
        }
        void find(T k){
            S.
        }
        void size(){

        }
        
};

template<T>
void Function(){
    dictionary<T>D;

     int n; cin>>n;  

    for(int i=0 ; i<n; i++)
    {
        string s; cin>>s;

        if(s=="ISEMPTY") 
        {
            if(D.empty())
                cout<<"True"<<endl;
            else 
                cout<<"False"<<endl;
        }
        else if(s=="INSERT")
        {
            T K; T V;
            cin>>K>>V;
            D.insert(K,V);
        }
        else if(s=="DELETE")
        {
            T K; cin>>K;
            D.Delete(K);
        }                }
        else if(s=="FIND")
        {
            T K; cin>>K;
            node<T> *D.find(K);
            if(d->key==K)
                cout<<d->val<<endl;
            else 
                cout<<"NOT FOUND"<<endl;
        }
        else if(s=="SIZE")
        {
            cout<<D.size()<<endl;
        }
    }
}

int main(){
    string s;
    cin>>s;
    if (s=="STRINGDICT"){
        Function<string>();
    }
    else if(s=="INTEGERDICT"){
        Function<int>();
    }
    return 0;
    
}