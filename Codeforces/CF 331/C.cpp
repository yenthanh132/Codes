#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int base=100000;
pii p[111111],ans[111111];
int n;
vector<int> val[222222];


int bit[111111];
int get(int i){
    int r=0;
    ++i;
    for( ;i ;i-=i&(-i)) r=max(r,bit[i]);
    return r;
}

void update(int i, int v){
    ++i;
    for( ; i<=base+1; i+=i&(-i))
        bit[i]=max(bit[i],v);
}

bool cmp(const pii &a, const pii &b){
    if(a.second!=b.second) return a.second < b.second;
    return a.first < b.first;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d%d",&p[i].first,&p[i].second);
    sort(p+1,p+n+1,cmp);

    for(int i=1; i<=n; ++i){
        int v;
        scanf("%d",&v);
        v+=base;
        val[v].pb(i);
    }
    for(int i=0; i<=base*2; ++i) reverse(val[i].begin(),val[i].end());
    bool ok=1;
    for(int i=1; ok && i<=n; ++i){
        int x=p[i].first, y=p[i].second;
        int v=y-x;
        v+=base;
        if(val[v].empty()){
            ok=0;
            break;
        }
        int id=val[v].back();
        val[v].pop_back();
        ans[id]=pii(x,y);
        if(get(x)>id){
            ok=0;
            break;
        }
        update(x,id);
    }

    if(!ok) puts("NO");
    else{
        puts("YES");
        for(int i=1; i<=n; ++i) printf("%d %d\n",ans[i].first,ans[i].second);
    }
}

