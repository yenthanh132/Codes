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

const int maxn=1000007;

char s[maxn];
int sa[maxn],tsa[maxn],ra[maxn],tra[maxn], cnt[maxn];
int len,n,toRight[maxn];
int fra(int i){return (i>len)?0:ra[i];};
int plcp[maxn],pre[maxn],lcp[maxn];

int sum[maxn];

void sort(int k){
    int maxv=max(300,len);
    for(int i=0; i<=maxv; ++i) cnt[i]=0;
    for(int i=1; i<=len; ++i) ++cnt[fra(sa[i]+k)];
    for(int i=0, sum=0; i<=maxv; ++i){
        int tmp=sum+cnt[i];
        cnt[i]=sum;
        sum=tmp;
    }
    for(int i=1; i<=len; ++i) tsa[++cnt[fra(sa[i]+k)]]=sa[i];
    for(int i=1; i<=len; ++i) sa[i]=tsa[i];
}

void suffixArray(){
    for(int i=1; i<=len; ++i) ra[i]=s[i], sa[i]=i;
    int r;
    for(int k=1; k<len; k<<=1){
        sort(k); sort(0);
        tra[sa[1]]=r=1;
        for(int i=2; i<=len; ++i){
            if(ra[sa[i]]!=ra[sa[i-1]] || fra(sa[i]+k)!=fra(sa[i-1]+k)) ++r;
            tra[sa[i]]=r;
        }
        for(int i=1; i<=len; ++i) ra[i]=tra[i];
    }
    pre[sa[1]]=-1;
    for(int i=2; i<=len; ++i) pre[sa[i]]=sa[i-1];
    int x=0;
    for(int i=1; i<=len; ++i){
        if(pre[i]==-1){
            plcp[i]=0;
            continue;
        }
        while(i+x<=len && pre[i]+x<=len && s[i+x]==s[pre[i]+x]) ++x;
        plcp[i]=x;
        x=max(0,x-1);
    }
    for(int i=1; i<=len; ++i) lcp[i]=plcp[sa[i]];

}

void solve(int k){
    if(k>sum[len]){
        puts("INVALID");
        return;
    }
    int l=1, r=len, mid, res;
    while(l<=r){
        mid=(l+r)/2;
        if(sum[mid]>=k){
            res=mid;
            r=mid-1;
        }else
            l=mid+1;
    }
    int val=sum[res-1];
    int start = sa[res];
    int length = (k-val) + lcp[res];
    for(int i=start; i<start+length; ++i) putchar(s[i]);
    puts("");
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    len = 0;
    for(int i=1; i<=n; ++i){
        scanf("%s",s+len+1);
        len=strlen(s+1);
        if(i<n) s[++len]='#';
    }
    for(int i=len; i>=1; --i)
        if(s[i]=='#') toRight[i]=0;
        else toRight[i]=toRight[i+1]+1;

    suffixArray();

    sum[0]=0;
    for(int i=1; i<=len; ++i){
        sum[i]=sum[i-1];
        sum[i]+=max(0,toRight[sa[i]] - lcp[i]);
    }

    int q,k;
    scanf("%d",&q);
    for(int i=1; i<=q; ++i){
        scanf("%d",&k);
        solve(k);
    }

    return 0;
}
