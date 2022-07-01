#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix{
    public: 
           Matrix();
           Matrix(int ,int) ;
          // Matrix(int ,int,int vector<vector<int>> );
           void setvalue(int ,int ,int );
           int getvalue(int  ,int );
           int getNoRows();
           int getNocolumns();
           void printSpiral();
           int trace();
           bool checkTriangular();
           bool isSpecialMatrix();

    private :
           int r,c;
           vector<vector<int>> mat;
 

};

Matrix:: Matrix(){
    r=0;
    c=0;
    
}
Matrix:: Matrix(int x,int y)
{
    r=x;
    c=y;

    mat.resize(r);
    for(int i=0;i<r;i++)
    {
        mat[i].resize(c,0);
    }

}
/*
Matrix:: Matrix(int x,int y,vector<vector<int>> m){
    r=x;
    c=y;
    mat=m;
}
*/

void Matrix::setvalue(int row,int column,int value){
    mat[row][column]=value;
}
int Matrix::trace(){

    int sum=0;
    if (r==c){
        for (int i=0;i<r;i++){
             sum=sum+mat[i][i];
        }
        return sum;
    }
    else{
        return -1;
    }
}
bool Matrix::checkTriangular()
{
    if(r==c)
    {
        int flag1=0,flag2=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(mat[i][j]!=0)
                    flag1++;
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=i+1;j<c;j++)
            {
                if(mat[i][j]!=0)
                    flag2++;
            }
        }
        if(flag1==0 || flag2==0)
            return true;
        else 
            return false;
    }
    else
    {
        return false;
    }

    return false;
}
bool Matrix::isSpecialMatrix()
{
    int sum1=0,sum2=0,f=0;
    for(int j=0;j<c;j++)
    {
        sum1=sum1+mat[0][j];
    }
    for(int i=0;i<r;i++){
        sum2 +=mat[i][0];
    }
    if (sum1==sum2){
        for(int i=1;i<r;i++)
        {
            int rsum=0;
            for(int j=0;j<c;j++)
            {
                rsum += mat[i][j];
            }
            if (rsum!=sum1){
                 f=1;
            }

        }
        for (int j=1;j<c;j++){
            int csum=0;
            for (int i=0;i<r;i++){
                csum += mat[i][j];
            }
            if (csum!=sum1){
                f=1;
            }
        }
    }
    else{
        f=1;
    }
    if(f==1)
    return false;
    else
    return true;
}

void Matrix::printSpiral(){

     // base case
    if (mat.size() == 0) {
        return;
    }
 
    int top = 0, bottom = mat.size() - 1;
    int left = 0, right = mat[0].size() - 1;
 
    while (1)
    {
        if (left > right) {
            break;
        }
        // print top row
        for (int i = left; i <= right; i++) {
            cout << mat[top][i] << " ";
        }
        top++;
 
        if (top > bottom) {
            break;
        }
        // print right column
        for (int i = top; i <= bottom; i++) {
            cout << mat[i][right] << " ";
        }
        right--;
 
        if (left > right) {
            break;
        }
        // print bottom row
        for (int i = right; i >= left; i--) {
            cout << mat[bottom][i] << " ";
        }
        bottom--;
 
        if (top > bottom) {
            break;
        }
        // print left column
        for (int i = bottom; i >= top; i--) {
            cout << mat[i][left] << " ";
        }
        left++;
    }
}

int main() {
     int N,M;
    cin >> N >>M;
    Matrix m(N,M);
    for (int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int val;
            cin >>val;
            m.setvalue(i,j,val);
        }
    }
    int Q;
    cin>>Q;

    while(Q--){
        int opcode;
        cin>>opcode;
         switch(opcode){
                case 1:m.printSpiral();break;
                case 2:cout<<m.trace()<<endl;break;
                case 3:
                    if(m.checkTriangular())
                        cout<<"true"<<endl;
                    else    
                        cout<<"false"<<endl;
                    break;
                case 4:
                    if(m.isSpecialMatrix())
                        cout<<"true"<<endl;
                    else 
                        cout<<"false"<<endl;
                    break;
                default:
                    break;
         }
    }
    return 0;
}