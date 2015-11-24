#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;
int f[maxn];

int get(int v){
    if(f[v]!=-1) return f[v];
    int &r = f[v];
    r=0;
    for(int i=2; i*i<=v; ++i) if(v%i==0){
        while(v%i==0){
            v/=i;
            ++r;
        }
    }
    if(v>1) ++r;
    return r;
}

int main(){
//    freopen("input.txt","r",stdin);

    reset(f,-1);
    int N,v,res=0;
    scanf("%d",&N);
    for(int i=0; i<N; ++i){
        scanf("%d",&v);
        res^=get(v);
    }
    if(res) puts("ALICE"); else puts("BOB");
}

