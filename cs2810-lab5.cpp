#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node{
    private:
    
    public :
    int val;
    node* above;
    node* below;
    node(){
        above=NULL;
        below=NULL;
    }
    
};

class stack{
    private:
        node* up;
        node* bottom;
    public:
        stack(){
            up=NULL;
            bottom=NULL;
        }
        void push(int x){
            node* newnode=new node();
            newnode->val=x;
            if(up==NULL){
                up=newnode;
                bottom=newnode;
                cout<<up->val<<endl;
            }
            else{
                node* temp;
                temp=up;
                temp->above=newnode;
                newnode->below=temp;
                up=newnode;
            }
        }
        int pop(){
            if(up==NULL){
                return -1;
            }
            else{
                node *temp1,*temp2;
                int a;
                a=up->val;
                if (up==bottom){
                    temp1=up;
                    up=NULL;
                    bottom=NULL;
                    free(temp1);
                    return a;
                }
                temp1=up;
                temp2=up->below;
                temp2->above=NULL;
                temp1->below=NULL;
                up=temp2;
                free (temp1);
                return a;
            }
        }
        int top(){
            if (up==NULL){
                return -1;
            }
            else{
                int a;
                a=up->val;
                return a;
            }
        }
        int isempty(){
            if (up==NULL){
                return 1;
            }
            return 0;
        }
};

void matrix(int n){
    int matrix[n][n];
}

class Graph{
    private:
    int size;
    int **matrix;
    public:
    Graph(int n){
        size=n;
        matrix = new int*[n];
        for(int i=0;i<n;i++)
        {
            matrix[i]=new int[n];
        }
    }
    void operator +=(pair<int,int> p){
        matrix[p.first][p.second]=1;
        matrix[p.second][p.first]=1;
        cout<<"hm";
    }
    void operator -=(pair<int,int> p){
        matrix[p.first][p.second]=0;
        matrix[p.second][p.first]=0;
    }


};

int main(){
    int Q;
    cin>>Q;
    stack stack;
    while(Q--){
        string c;
        cin>>c;
        if (c=="push"){
            int x;
            cin>>x;
            stack.push(x);
        }
        else if(c=="pop"){
            int x=stack.pop();
            cout<<x<<endl;
        }
        else if(c=="top"){
            int x=stack.top();
            cout<<x<<endl;
        }
        else if(c=="empty"){
            cout<<stack.isempty()<<endl;
        }
    }
    int n;
    cin>>n;
    Graph graph(n);
    int q1;
    cin>>q1;
    while(q1--){
        string d;
        cin>>d;
        if(d=="add"){
            int a,b;
            cin>>a>>b;
            pair<int,int> pair(a,b);
            graph += pair;
        }
        else if(d=="del")
        {
            int a,b;
            cin>>a>>b;
            pair<int,int> pair(a,b);
            graph -= pair;
        }
        else if(d=="cycle"){
            
        }
    }    
    return 0;
}