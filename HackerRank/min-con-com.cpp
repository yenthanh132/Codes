#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;

typedef long long ll;

const int maxn=200007;

int lab[maxn],n,m;
int a[maxn];
multiset<int> mys;

int getroot(int u){
    if(lab[u]<0) return u;
    return (lab[u]=getroot(lab[u]));
}

void dsu(int r1, int r2){
    if(lab[r1]>lab[r2]) swap(lab[r1],lab[r2]);
    mys.erase(mys.find(a[r1]));
    mys.erase(mys.find(a[r2]));
    lab[r1]+=lab[r2];
    lab[r2]=r1;
    a[r1]+=a[r2];
    mys.insert(a[r1]);
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]), mys.insert(a[i]), lab[i]=-1;
    for(int i=0; i<m; ++i){
        int u,v;
        scanf("%d%d",&u,&v);
        int r1=getroot(u), r2=getroot(v);
        if(r1!=r2) dsu(r1,r2);
        printf("%d\n",*mys.begin());
    }
}

