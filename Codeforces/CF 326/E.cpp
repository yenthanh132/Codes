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

int IT2[maxn*4];
vector<int> IT[maxn*4];
int n,q,a[maxn];

void gauss(vector<int> &lst){
    int id=29;
    for(int i=0; i<sz(lst); ++i){
        int u=i;
        for(int j=i+1; j<sz(lst); ++j)
            if(lst[j]>lst[u]) u=j;
        if(lst[u]==0) break;
        swap(lst[u],lst[i]);
        while(!(lst[i]>>id&1)) --id;
        for(int j=i+1; j<sz(lst); ++j) if(lst[j]>>id&1) lst[j] ^= lst[i];
    }
    while(sz(lst)>1){
        int c=sz(lst);
        if(lst[c-1]==0 && lst[c-2]==0)
            lst.pop_back();
        else
            break;
    }
}

void join(vector<int> &l1, vector<int> &l2, vector<int> &lf){
    lf.clear();
    for(int i=0; i<sz(l1); ++i) lf.pb(l1[i]);
    for(int i=0; i<sz(l2); ++i) lf.pb(l2[i]);
    gauss(lf);
}

void append(vector<int> &l1, vector<int> &l2){
    for(int i=0; i<sz(l1); ++i) l2.pb(l1[i]);
    gauss(l2);
}

void lazyUpdate(int i, int l, int r){
    if(IT2[i]==0) return;
    for(int j=0; j<sz(IT[i]); ++j){
        IT[i][j] ^= IT2[i];
    }
    if(l<r){
        IT2[i*2] ^= IT2[i];
        IT2[i*2+1] ^= IT2[i];
    }
    IT2[i] = 0;
    gauss(IT[i]);
}

void init(int i, int l, int r){
    if(l==r){
        IT[i].pb(a[l]);
        return;
    }
    int mid=(l+r)/2;
    init(i*2,l,mid); init(i*2+1,mid+1,r);
    join(IT[i*2],IT[i*2+1],IT[i]);
}

void update(int i, int l, int r, int s, int f, int v){
    lazyUpdate(i,l,r);
    if(f<l || r<s) return;
    if(s<=l && r<=f){
        IT2[i] = v;
        lazyUpdate(i,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,s,f,v);
    update(i*2+1,mid+1,r,s,f,v);
    join(IT[i*2], IT[i*2+1], IT[i]);
}

vector<int> normalList;

void get(int i, int l, int r, int s, int f){
    lazyUpdate(i,l,r);
    if(f<l || r<s) return;
    if(s<=l && r<=f){
        append(IT[i], normalList);
        return;
    }
    int mid=(l+r)/2;
    get(i*2,l,mid,s,f); get(i*2+1,mid+1,r,s,f);
    join(IT[i*2],IT[i*2+1],IT[i]);
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    init(1,1,n);
    int t,l,r,v;
    for(int i=0; i<q; ++i){
        scanf("%d%d%d",&t,&l,&r);
        if(t==1){
            scanf("%d",&v);
            update(1,1,n,l,r,v);
        }else{
            normalList.clear();
            get(1,1,n,l,r);
//            cout<<sz(normalList)<<": "; for(int v:normalList) cout<<v<<' '; cout<<endl;
            int res = 1<<sz(normalList);
            if(normalList[sz(normalList)-1]==0) res/=2;
            printf("%d\n", res);
        }
    }
}

