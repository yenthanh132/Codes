#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=5007;
const int hashbase=73471;

char s[maxn];
int strrep[maxn];
int n,q;

int SA[maxn],RA[maxn],tSA[maxn],tRA[maxn],lcp[maxn],plcp[maxn],pre[maxn],cnt[maxn], L[maxn],R[maxn],mys[maxn];
int fRA(int i){return (i<=n?RA[i]:0);}

int ans[maxn],T;
ll C[maxn][maxn];

void sort(int k){
    int maxv=max(300,n);
    for(int i=0; i<=maxv; ++i) cnt[i]=0;
    for(int i=1; i<=n; ++i) ++cnt[fRA(SA[i]+k)];
    for(int sum=0,i=0,tmp; i<=maxv; ++i){
        tmp=sum;
        sum+=cnt[i];
        cnt[i]=tmp;
    }
    for(int i=1; i<=n; ++i) tSA[++cnt[fRA(SA[i]+k)]] = SA[i];
    for(int i=1; i<=n; ++i) SA[i] = tSA[i];
}

void constructSA(){
    for(int i=1; i<=n; ++i){
        SA[i] = i;
        RA[i] = s[i];
    }

    for(int k=1; k<n; k*=2){
        sort(k); sort(0);
        tRA[SA[1]] = 1;
        int r=1;
        for(int i=2; i<=n; ++i){
            if(RA[SA[i]]!=RA[SA[i-1]] || fRA(SA[i]+k)!=fRA(SA[i-1]+k)) ++r;
            tRA[SA[i]] = r;
        }
        for(int i=1; i<=n; ++i) RA[i]=tRA[i];
    }

    pre[SA[1]]=-1;
    for(int i=2; i<=n; ++i) pre[SA[i]]=SA[i-1];
    int l=0;
    for(int i=1; i<=n; ++i){
        if(pre[i]==-1){
            l=0;
            plcp[i]=0;
            continue;
        }
        while(i+l<=n && pre[i]+l<=n && s[i+l]==s[pre[i]+l]) ++l;
        plcp[i]=l;
        l=max(l-1,0);
    }

    for(int i=1; i<=n; ++i) lcp[i] = plcp[SA[i]];

    int last=0;
    mys[0]=0;
    for(int i=1; i<=n; ++i){
        while(last>0 && lcp[mys[last]]>=lcp[i]) --last;
        L[i]=mys[last];
        mys[++last]=i;
    }

    last=0;
    mys[0]=n+1;
    for(int i=n; i>=1; --i){
        while(last>0 && lcp[mys[last]]>=lcp[i]) --last;
        R[i]=mys[last];
        mys[++last]=i;
    }
}

int it[maxn*4];

void init(int i, int l, int r){
    if(l==r){
        it[i]=lcp[l];
        return;
    }
    int mid=(l+r)/2;
    init(i*2,l,mid); init(i*2+1,mid+1,r);
    it[i]=min(it[i*2],it[i*2+1]);
}

int minval(int i, int l, int r, int s, int f){
    if(f<l || r<s) return oo;
    if(s<=l && r<=f) return it[i];
    int mid=(l+r)/2;
    return min( minval(i*2,l,mid,s,f), minval(i*2+1,mid+1,r,s,f) );
}

int minpos(int i, int l, int r, int s, int f){
    if(f<l || r<s) return oo;
    if(l==r) return l;
    int minv = minval(i,l,r,s,f);
    int mid=(l+r)/2;
    if(minv == minval(i*2,l,mid,s,f)) return minpos(i*2,l,mid,s,f);
    else return minpos(i*2+1,mid+1,r,s,f);
}

void deal(int l, int r, int base){
    if(l>r) return;
    int i=l;
    while(i<=r){
        int pos=minpos(1,1,n,i,r);
        int len=R[pos]-L[pos];
        strrep[len] += lcp[pos]-base;
        deal(max(l,L[pos]+1),pos-1,lcp[pos]);
        deal(pos+1,min(r,R[pos]-1),lcp[pos]);
        i=R[pos];
    }
}

int main(){
//    freopen("input.txt","r",stdin);

    C[0][0]=1;
    for(int i=1; i<=5000; ++i){
        C[i][0]=1;
        for(int j=1; j<=5000; ++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%oo;
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&q);
        scanf("%s",s+1);

        for(int i=1; i<=n; ++i) strrep[i]=0;

        constructSA();
//        for(int i=1; i<=n; ++i) printf("%3d %3d %3d %s\n",lcp[i],L[i],R[i],s+SA[i]);
        init(1,1,n);
        int prev0pos = 0;
        for(int i=1; i<=n; ++i){
            if(lcp[i]==0){
                deal(prev0pos+1,i-1,0);
                prev0pos = i;
            }
        }
        if(prev0pos < n) deal(prev0pos+1,n,0);
        strrep[1]=n*(n+1)/2;
        for(int i=2; i<=n; ++i) strrep[1] -= strrep[i]*i;

        for(int k=1; k<=n; ++k){
            ans[k] = 0;
            for(int i=k; i<=n; ++i) ans[k] = (ans[k] + C[i][k]*strrep[i])%oo;
        }

        for(int i=0; i<q; ++i){
            int k;
            scanf("%d",&k);
            if(k>n) puts("0");
            else printf("%d\n",ans[k]);
        }
    }
}

