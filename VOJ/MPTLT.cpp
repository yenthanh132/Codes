#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sstream>

using namespace std;
typedef long long ll;
struct matrix{int arr[9][9];} base;

matrix operator*(matrix a, matrix b){
    matrix c ;
    memset(c.arr,0,sizeof(c.arr));
    int i,j,k;
    for (i=0;i<9;i++)
        for (j=0;j<9;j++)
            for (k=0;k<9;k++)
                c.arr[i][j]=(c.arr[i][j]+(ll)a.arr[i][k]*b.arr[k][j])%1000000;
    return c;
}

matrix pow(ll n){
    if (n==1) return base;
    matrix t=pow(n/2);
    if (n%2==1) return base*t*t; else return t*t;
}

int main(){
    ll n;
    cin>>n;
    memset(base.arr,0,sizeof(base.arr));
    base.arr[0][3]=1;
    base.arr[1][4]=1;
    base.arr[2][5]=1;
    base.arr[3][6]=1;
    base.arr[4][7]=1;
    base.arr[5][8]=1;
    base.arr[6][6]=1;
    base.arr[6][7]=1;
    base.arr[6][8]=1;
    base.arr[7][4]=1;
    base.arr[7][5]=1;
    base.arr[8][2]=1;
    switch (n){
        case 1:cout<<1;break;
        case 2:cout<<2;break;
        case 3:cout<<3;break;
        default: 
            int mul[9]={1,0,0,1,1,0,2,0,1},res[9];
            matrix kq=pow(n-3);
            int i,j;
            for (i=0;i<9;i++){
                res[i]=0;
                for (j=0;j<9;j++) res[i]=(res[i]+(ll)kq.arr[i][j]*mul[j])%1000000;
            }
            int ans=(res[6]+res[7]+res[8])%1000000; 
            if (n>=1093){
                stringstream ss; 
                ss<<ans<<endl;
                string s=ss.str();
                while (s.size()<=6) s='0'+s; 
                cout<<s<<endl;
            }else cout<<ans<<endl;
    }       
    return 0;
}
