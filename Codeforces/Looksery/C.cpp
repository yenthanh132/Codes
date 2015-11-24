
#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int c0,c1,n,k;

bool StannisWin(){
    int x=n-k;
    if(x==0) return (c1&1);
    int xD = x/2;
    int xS = x-xD;

    if(xD >= c1)
        return 0;

    if(x&1){
        if(xD < c0) return 1;
        if((c1 - (x - c0))&1) return 1;
        return 0;
    }else{
        if(xD < c0) return 0;
        if((c1 - (x - c0))&1) return 1;
        return 0;
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n>>k;
    int v;
    c0=c1=0;
    for(int i=0; i<n; ++i){
        cin>>v;
        if(v&1) c1++; else c0++;
    }
    if(StannisWin()) cout<<"Stannis"; else cout<<"Daenerys"<<endl;
}

