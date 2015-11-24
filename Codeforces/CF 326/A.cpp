#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int mm[2222222];

int main(){
//    freopen("input.txt","r",stdin);
    int n,v;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        scanf("%d",&v);
        ++mm[v];
        while(mm[v]==2){
            mm[v]=0;
            ++mm[v+1];
            ++v;
        }
    }
    int res=0;
    for(int i=0; i<=2000000; ++i) res+=mm[i];
    cout<<res<<endl;
}

