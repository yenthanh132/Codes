#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

int lab[maxn],res[maxn];
int t[maxn],x[maxn],y[maxn],rbound[maxn],lbound[maxn];
int n,q;

vector<int> list[maxn];
map<pii,int> pos;
int cnt;

struct Save{
    int u,r,x;
    Save(){}
    Save(int a, int b, int c):u(a),r(b),x(c){}
};

int getroot(int u){
    if(lab[u]<0) return u;
    return getroot(lab[u]);
}

Save dsu(int r1, int r2){
    Save res;
    if(lab[r1]<lab[r2]){
        res=Save(r2,r1,lab[r2]);
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        res=Save(r1,r2,lab[r1]);
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
    return res;
}



void solve(int l, int r){
    if(l==r){
        if(t[l]==3){
            res[l] = (getroot(x[l])==getroot(y[l]));
        }
        return;
    }
    int mid=(l+r)/2;

    //LEFT PART
    vector<Save> ds;
    for(int i=mid+1; i<=r; ++i) if(t[i]==2 && lbound[i]<l){
        int j=lbound[i];
        int r1=getroot(x[j]), r2=getroot(y[j]);
        if(r1==r2) continue;
        ds.pb(dsu(r1,r2)); //save for restoring
    }
    solve(l,mid);
    //restore
    for(int i=sz(ds)-1; i>=0; --i){
        lab[ds[i].u] = ds[i].x;
        lab[ds[i].r] -= ds[i].x;
    }


    //RIGHT PART
    ds.clear();
    for(int i=l; i<=mid; ++i) if(t[i]==1 && rbound[i]>r){
        int r1=getroot(x[i]), r2=getroot(y[i]);
        if(r1==r2) continue;
        ds.pb(dsu(r1,r2)); //save for restoring
    }
    solve(mid+1,r);
    //restore
    for(int i=sz(ds)-1; i>=0; --i){
        lab[ds[i].u] = ds[i].x;
        lab[ds[i].r] -= ds[i].x;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d%d",&n,&q);
    for(int i=1; i<=q; ++i){
        scanf("%d%d%d",&t[i],&x[i],&y[i]);
        if(x[i]>y[i]) swap(x[i],y[i]);
    }
    cnt=0;
    for(int i=q; i>=1; --i)
        if(t[i]==2){
            if(!pos.count(pii(x[i],y[i]))) pos[pii(x[i],y[i])]=++cnt;
            int id=pos[pii(x[i],y[i])];
            list[id].pb(i);
            lbound[i]=oo;
        }else if(t[i]==1){
            if(!pos.count(pii(x[i],y[i]))) pos[pii(x[i],y[i])]=++cnt;
            int id=pos[pii(x[i],y[i])];
            if(list[id].empty()) rbound[i]=oo;
            else{
                rbound[i]=list[id].back();
                lbound[rbound[i]]=i;
                list[id].pop_back();
            }
        }
    for(int u=1; u<=n; ++u) lab[u]=-1;
    solve(1,q);
    for(int i=1; i<=q; ++i) if(t[i]==3) printf("%d",res[i]);
    puts("");

    return 0;
}
