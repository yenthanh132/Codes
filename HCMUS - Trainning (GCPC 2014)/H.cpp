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

struct ITNode{
    int minv,maxv,T;
} IT[maxn*4];

int C,limit,q,n;
vector<int> lst;

struct QueryNode{
    int t,x,y,s;
}query[maxn];
char str[20];

void lazyUpdate(int i, int l, int r){
    if(IT[i].T==0) return;
    IT[i].minv += IT[i].T;
    IT[i].maxv += IT[i].T;
    if(l<r){
        IT[i*2].T += IT[i].T;
        IT[i*2+1].T += IT[i].T;
    }
    IT[i].T=0;
}

void updateNode(int i){
    IT[i].minv=min(IT[i*2].minv,IT[i*2+1].minv);
    IT[i].maxv=max(IT[i*2].maxv,IT[i*2+1].maxv);
}

int minRet,maxRet;

void get(int i, int l, int r, int s, int f){
    lazyUpdate(i,l,r);
    if(f<l || r<s) return;
    if(s<=l && r<=f){
        minRet=min(minRet,IT[i].minv);
        maxRet=max(maxRet,IT[i].maxv);
        return;
    }
    int mid=(l+r)/2;
    get(i*2,l,mid,s,f); get(i*2+1,mid+1,r,s,f);
    updateNode(i);
}

void update(int i, int l, int r, int s, int f, int v){
    lazyUpdate(i,l,r);
    if(f<l || r<s) return;
    if(s<=l && r<=f){
        IT[i].T+=v;
        lazyUpdate(i,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,s,f,v); update(i*2+1,mid+1,r,s,f,v);
    updateNode(i);
}


int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&C,&limit,&q);
    for(int i=0; i<q; ++i){
        scanf("%s%d",str,&query[i].x); lst.pb(query[i].x);
        if(str[0]=='c'){
            query[i].t=1;
            scanf("%d",&query[i].s);
        }else if(str[0]=='g'){
            query[i].t=2;
            scanf("%d%d",&query[i].y,&query[i].s); lst.pb(query[i].y);
        }else{
            query[i].t=3;
        }
    }
    sort(lst.begin(),lst.end());
    lst.resize(unique(lst.begin(),lst.end())-lst.begin());
    for(int i=0; i<q; ++i){
        query[i].x=lower_bound(lst.begin(),lst.end(),query[i].x)-lst.begin()+1;
        if(query[i].t==2){
            query[i].y=lower_bound(lst.begin(),lst.end(),query[i].y)-lst.begin()+1;
        }
    }
    n=sz(lst);

    reset(IT,0);
    for(int i=0; i<q; ++i)
        if(query[i].t<=2){
            minRet=oo; maxRet=-oo;
            int rightBound = query[i].x;
            if(query[i].t==2) rightBound=query[i].y;
            get(1,1,n,query[i].x,rightBound);
            int ret = query[i].s;
            if(query[i].s>=0){
                ret = min(ret, limit - maxRet);
            }else{
                ret = max(ret, -minRet);
            }

            update(1,1,n,query[i].x,rightBound,ret);
            printf("%d\n",ret);
        }else{
            minRet = oo;
            get(1,1,n,query[i].x,query[i].x);
            printf("%d\n",minRet);
        }
}

