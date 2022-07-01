#include<bits/stdc++.h>
using namespace std;

class Dictionary{
    private:
        map<int,set<string> >gmap;
    public:
        void buildDict(vector<string> words)
        {
            for(int i=0;i<words.size();i++)
            {
                addWordToDict(words[i]);
            }
        }
        void addWordToDict(string word)
        {
           // cout<<"vasthunna"<<endl;
            int a=word.size();
            gmap[a].insert(word);
        }
        bool search(string target)
        {
            int a=target.size();
            set<string>::iterator itr;
            for(itr=gmap[a].begin();itr!=gmap[a].end();itr++){
                if(*itr==target){
                    return true;
                }
            }
            return false;
        }
        set<string> getWordsAfterReplace(string target)
        {
            int a=target.size();
            int b=0;
            set<string>::iterator itr;
            set<string> s;
            for(itr=gmap[a].begin();itr!=gmap[a].end();itr++){
                int c=0;
                for(int i=0;i<a;i++){
                    if(target[i]!=(*itr)[i]){
                        c=c+1;
                    }
                }
                if(c<=1){
                    s.insert(*itr);
                }
            }
            return s;
        }
        set<string> getWordsAfterSwap(string target)
        {
            int len=target.size();
            set<string> s;
            set<string> ::iterator itr;
            for(itr=gmap[len].begin();itr!=gmap[len].end();itr++)
            {
                string k=*itr;
                int c=0;
                for(int j=0;j<len-1;j++)
                {
                    swap(k[j],k[j+1]);
                    if(k==target)
                        c++;
                    swap(k[j],k[j+1]);
                }
                if(c==1)
                    s.insert(*itr);
            }
            return s;
        }
        int maxChangeableWord(){
            int max=0;
            for(int len=1;len<=10;len++)
            {
                set<string> :: iterator itr;
                for(itr=gmap[len].begin();itr!=gmap[len].end();itr++)
                {
                    int k=getWordsAfterReplace(*itr).size();
                    if(max<k)
                        max=k;
                }
            }
            return max-1;
        }
        int maxSwappableWord() 
        {
            int max=0;
            for(int len=1;len<=10;len++)
            {
                set<string> :: iterator itr;
                for(itr=gmap[len].begin();itr!=gmap[len].end();itr++)
                {
                    int k=getWordsAfterSwap(*itr).size();
                    if(max<k)
                        max=k;
                }
            }
            return max;
        }
};

int main(){
    int N;
    cin>>N;
    vector<string> words;
    words.resize(N);
    for(int i=0;i<N;i++)
    {
        cin>>words[i];
        //cout<<words[i]<<endl;
    }
    Dictionary d;
    d.buildDict(words);
    int Q;
    cin>>Q;
    while(Q--)
    {
        int x;
        cin>>x;
        int op=x;
        if (op==1){
            string word;
            cin>>word;
            d.addWordToDict(word);
        }
        else if(op==2){
            string word;
            cin>>word;
            if(d.search(word))
            {
                cout<<"true"<<endl;
            }else cout<<"false"<<endl;
        }
        else if (op==3){
            string target;
            cin>>target;
            set<string> s=d.getWordsAfterReplace(target);
            set<string>::iterator itr;
            if(s.size()==0){
                cout<<"-1";
            }
            else{
                for(itr=s.begin();itr!=s.end();itr++){
                cout<<*itr<<" ";
                }
            }
            cout<<endl;
        }
        else if(op==4){

            string target;
            cin>>target;
            set<string> :: iterator itr;
            set<string> s=d.getWordsAfterSwap(target);
            if(s.size()!=0)
            {
             for(itr=s.begin();itr!=s.end();itr++){
                cout<<*itr<<" ";
                }
            cout<<endl;
            }
            else 
            {
                cout<<"-1"<<endl;
            }
        }
        else if(op==5){
            cout<<d.maxChangeableWord()<<endl;
        }
        else if(op==6)
        {
            cout<<d.maxSwappableWord()<<endl;
        }
        
    }
    return 0;
    
}  