#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=500007;

int a[maxn],b[maxn],n,cnt,prev[maxn],next[maxn];
vector<int> pos[maxn],ans;
int vt[maxn];
map<int,int> mm;

int IT[maxn*4];

void init(int i, int l, int r){
    if(l==r){
        IT[i]=prev[l];
        return;
    }
    int mid=(l+r)/2;
    init(i*2,l,mid); init(i*2+1,mid+1,r);
    IT[i]=min(IT[i*2],IT[i*2+1]);
}

int get(int i, int l, int r, int s, int f){
    if(f<l || r<s) return oo;
    if(s<=l && r<=f) return IT[i];
    int mid=(l+r)/2;
    return min( get(i*2,l,mid,s,f), get(i*2+1,mid+1,r,s,f) );
}

void update(int i, int l, int r, int p){
    if(p<l || p>r) return;
    if(l==r){
        IT[i]=prev[l];
        return;
    }
    int mid=(l+r)/2;
    update(i*2,l,mid,p); update(i*2+1,mid+1,r,p);
    IT[i]=min(IT[i*2],IT[i*2+1]);
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    cnt=0;
    reset(next,-1);
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i]); b[i]=a[i];
        if(mm[a[i]]==0) mm[a[i]]=++cnt;
        a[i]=mm[a[i]];
        if(!pos[a[i]].empty()){
            prev[i]=pos[a[i]].back();
            next[pos[a[i]].back()]=i;
        }else prev[i]=oo;

        vt[i]=sz(pos[a[i]]);
        pos[a[i]].pb(i);
    }

    init(1,1,n);
    for(int i=1, lbound = 1; i<=n; ++i){
        if(prev[i]==oo) continue;
        bool found = 0;
        int x;
        if(prev[i]+1<i && (x=get(1,1,n,prev[i]+1,i-1))<=prev[i] && x>=lbound){
            found=1;
            ans.pb(b[x]); ans.pb(b[i]); ans.pb(b[x]); ans.pb(b[i]);
        }else if(vt[i]>=3 && pos[a[i]][vt[i]-3]>=lbound){
            found=1;
            ans.pb(b[i]); ans.pb(b[i]); ans.pb(b[i]); ans.pb(b[i]);
        }
        if(found)
            while(lbound<=i){
                if(next[lbound]!=-1){
                    prev[next[lbound]]=oo;
                    update(1,1,n,next[lbound]);
                }
                ++lbound;
            }
    }

    printf("%d\n",sz(ans));
    for(int i=0; i<sz(ans); ++i) printf("%d ",ans[i]);

    return 0;


}

