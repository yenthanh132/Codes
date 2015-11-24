#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1000007;

int a[maxn],n,m;
int L[maxn],R[maxn],mys[maxn],last;
pii p[maxn];
ll sum[maxn],val[maxn];

int findLeft(int v){
    int left=1, right=n, mid, res=0;
    while(left<=right){
        mid=(left+right)/2;
        if(p[mid].first<v){
            res=mid;
            left=mid+1;
        }else right=mid-1;
    }
    return res;
}

int findRight(int v){
    int left=1, right=n, mid, res=n+1;
    while(left<=right){
        mid=(left+right)/2;
        if(p[mid].first>v){
            res=mid;
            right=mid-1;
        }else left=mid+1;
    }
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);

    a[0]=oo;
    a[n+1]=oo;
    mys[last=0]=0;
    for(int i=1; i<=n; ++i){
        while(a[mys[last]]<=a[i]) --last;
        L[i] = mys[last];
        mys[++last]=i;
    }
    mys[last=0]=n+1;
    for(int i=n; i>=1; --i){
        while(a[mys[last]]<=a[i]) --last;
        R[i] = mys[last];
        mys[++last]=i;
    }

    for(int i=1; i<=n; ++i) p[i] = pii(a[i], i);
    sort(p+1,p+n+1);

    for(int i=1; i<=n; ++i){
        int toL = L[p[i].second], toR = R[p[i].second];
        if(i>1 && p[i-1].first == p[i].first)
            toL = max(toL, p[i-1].second);
        val[i] = 1ll * (p[i].second - toL) * (toR - p[i].second);
        sum[i] = sum[i-1] + val[i];
    }

    char s1[5],s2[5];
    int v;
    for(int i=1; i<=m; ++i){
        scanf("%s%d%s",s1,&v,s2);
        ll gameSum;
        if(s1[0]=='='){
            int pos1 = findLeft(v);
            int pos2 = findRight(v);
            gameSum = sum[pos2-1] - sum[pos1];
        }else if(s1[0]=='<'){
            int pos1 = findLeft(v);
            gameSum = sum[pos1];
        }else{
            int pos2 = findRight(v);
            gameSum = sum[n] - sum[pos2-1];
        }
        char ans = ((s2[0]-'C')^(gameSum&1)^1) + 'C';
        putchar(ans);
    }
}

