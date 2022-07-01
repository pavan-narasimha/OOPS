#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Node{
    private :
        bool isend;
        vector <Node*> next;
        friend class TRIE;
    public :
        Node(){
            next.resize(26,NULL);
            isend=false;
        }

};

class TRIE{
    private :
        Node *root;
    public :
        TRIE(){
            root =  new Node();
        }
        void insert(string key)
        {
            Node* ptr=root;
            for (int i=0;i<key.size();i++){
                int index=key[i]-'a';
                if(ptr->next[index]==NULL)
                     {ptr->next[index]=new Node;}
                ptr=(ptr->next)[index];
            }
            //cout<<"hello"<<endl;
            ptr->isend=true;
        }
        void search(string key){
            Node *ptr=root;
            int i=0;
            string s="";
            while(i<key.length()){
                int index=key[i]-'a';
                //cout<<i<<endl;
                if(ptr->next[index]!=NULL){
                    s=s+key[i];
                    ptr=ptr->next[index];
                }
                else{
                if(ptr->isend==true){
                    cout<<s<<" ";
                    return;
                }
                else{
                    cout<<key<<" ";
                    return ;
                }
                }
                i++;
            }
            cout<<s<<" ";
            return ;
        }
    
};

int main(){
    int p;
    cin>>p;
    TRIE t;
    while(p--){
        string s;
        cin>>s;
        t.insert(s);
    }
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        t.search(s);

    }
    return 0;
}