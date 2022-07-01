#include<bits/stdc++.h>

using namespace std;

class base
{
    public:

        int n;
        int total_revenue;

        base()
        {
            cin>>n;
        }
       virtual int max_revenue(int w, int wt[],int r[])
        {
            return 0;
        }     
};

class child : public base
{
    public:

        int max_revenue(int w, int wt[], int r[])
        {
           int dp[w+1];
           memset(dp,0 , sizeof dp);
           for (int i=0;i<=w;i++){
             for(int j=0;j<n;j++){
                if (wt[j]<=i){
                  dp[i]=max(dp[i],dp[i-wt[j]]+r[j]);
                }
             }
            }
            total_revenue=dp[w];
            return total_revenue;
        }
};

int main(){
    int w;
    cin>>w;
    base *p;
    child d;
    p = &d;
    int n=p->n;
    int wt[n];
    int r[n];
    for (int i=0;i<n;i++){
        cin>>r[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout<<p->max_revenue(w,wt,r);
    return 0;
}