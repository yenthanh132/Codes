#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
//    freopen("input.txt","r",stdin);
    int n,k;
    cin>>n>>k;
    int d1=n-k, d2=k-1;
    bool ok=1;
    while(d1+d2>0){
        --d1;
        if(d1<0) ok=0;
        if(d1+d2==0) break;
        --d2;
        if(d2<0) ok=0;
        if(d1+d2==0) break;
        if(d2>=d1) --d2; else --d1;
    }
    if(ok) puts("YES"); else puts("NO");

}

