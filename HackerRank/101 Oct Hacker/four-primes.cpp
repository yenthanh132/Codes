#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

vector<int> plist;

bool isprime(int n){
    if(n==2 || n==3) return 1;
    if(n<2 || n%2==0 || n%3==0) return 0;
    int k=0;
    int sn=int(sqrt(n)+1e-9);
    do{
        k+=6;
        if(n%(k-1)==0 || n%(k+1)==0) break;
    }while((k-1)<=sn);
    return k-1>sn;
}

bool ok[5][1<<13];

int main(){
//    freopen("input.txt","r",stdin);
    for(int i=1; i<=8000; ++i)
        if(isprime(i)){
            plist.pb(i);
            ok[1][i]=1;
        }

    for(int i=1; i<4; ++i) for(int v=0; v<(1<<13); ++v) if(ok[i][v])
        for(int j=0; j<sz(plist); ++j) ok[i+1][v | plist[j]]=1;

    for(int v=0; v<(1<<13); ++v){
        for(int i=1; i<=4; ++i) ok[0][v]|=ok[i][v];
    }

    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        if(ok[0][n]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}

