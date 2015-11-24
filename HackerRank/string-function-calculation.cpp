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

char T[maxn];
int n,sa[maxn],tsa[maxn],ra[maxn],tra[maxn],cnt[maxn],plcp[maxn],lcp[maxn],previous[maxn];

int fra(int i){
    if(i<=n) return ra[i]; else return 0;
}

void sort(int k){
    int maxv=max(300,n);
    for(int i=0; i<=maxv; ++i) cnt[i]=0;
    for(int i=1; i<=n; ++i) ++cnt[fra(sa[i]+k)];
    for(int i=0, sum=0, tmp; i<=maxv; ++i){
        tmp=sum;
        sum+=cnt[i];
        cnt[i]=tmp;
    }
    for(int i=1; i<=n; ++i) tsa[++cnt[fra(sa[i]+k)]]=sa[i];
    for(int i=1; i<=n; ++i) sa[i]=tsa[i];
}

void suffixArray(){
    for(int i=1; i<=n; ++i){
        sa[i]=i;
        ra[i]=T[i];
    }
    for(int k=1; k<n; k*=2){
        sort(k); sort(0);
        int tmp=1;
        tra[sa[1]]=tmp;
        for(int i=2; i<=n; ++i){
            if(ra[sa[i]]!=ra[sa[i-1]] || fra(sa[i]+k)!=fra(sa[i-1]+k)) ++tmp;
            tra[sa[i]]=tmp;
        }
        for(int i=1; i<=n; ++i) ra[i]=tra[i];
    }
    previous[sa[1]]=-1;
    for(int i=2; i<=n; ++i) previous[sa[i]]=sa[i-1];
    int len=0;
    for(int i=1; i<=n; ++i){
        if(previous[i]==-1){
            plcp[i]=0;
            continue;
        }
        while(previous[i]+len<=n && i+len<=n && T[previous[i]+len]==T[i+len]) ++len;
        plcp[i]=len;
        len=max(len-1,0);
    }
    for(int i=1; i<=n; ++i) lcp[i]=plcp[sa[i]];
}

int toLeft[maxn], toRight[maxn], mystack[maxn];
ll res;

void solve(){
    res=n;
    int last=0;
    for(int i=2;i<=n; ++i){
        while(last>0 && lcp[mystack[last]] >= lcp[i]) --last;
        if(last==0) toLeft[i]=1;
        else toLeft[i]=mystack[last];
        mystack[++last]=i;
    }
    last=0;
    for(int i=n; i>=2; --i){
        while(last>0 && lcp[mystack[last]] >= lcp[i]) --last;
        if(last==0) toRight[i]=n+1;
        else toRight[i]=mystack[last];
        mystack[++last]=i;
    }
    for(int i=1; i<=n; ++i){
        int cnt=toRight[i]-toLeft[i];
        res=max(res, 1ll*cnt*lcp[i]);
    }
    printf("%d\n",res);
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%s",T+1);
    n=strlen(T+1);
    suffixArray();
    solve();
    return 0;
}
