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

const int maxn=3000007;

char s[maxn];
int sa[maxn],tsa[maxn],ra[maxn],tra[maxn], cnt[maxn];
int len,len1,len2,len3;
int fra(int i){return (i>len)?0:ra[i];};
int plcp[maxn],pre[maxn],lcp[maxn];

ll sum[3][maxn];

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

int mys[maxn],tl[maxn],tr[maxn];
ll dd[maxn],res[maxn];
set<int> myset;

int main(){
    //freopen("input.txt","r",stdin);

    len=0;
    scanf("%s",s+len+1);
    len1=strlen(s+len+1);
    len+=len1;
    s[++len]='#';
    scanf("%s",s+len+1);
    len2=strlen(s+len+1);
    len+=len2;
    s[++len]='@';
    scanf("%s",s+len+1);
    len3=strlen(s+len+1);
    len+=len3;

    suffixArray();

    reset(sum,0);
    for(int i=1; i<=len; ++i){
        for(int j=0; j<3; ++j) sum[j][i]=sum[j][i-1];
        if(sa[i]<=len1) sum[0][i]++;
        else if(len1+1<sa[i] && sa[i]<=len1+1+len2) sum[1][i]++;
        else if(len1+len2+2<sa[i] && sa[i]<=len1+len2+2+len3) sum[2][i]++;
    }

    int last=0;
    for(int i=1; i<=len; ++i){
        while(last>0 && lcp[mys[last]] >= lcp[i]) --last;
        if(last==0) tl[i]=0; else tl[i]=mys[last];
        mys[++last]=i;
    }
    last=0;
    for(int i=len; i>=1; --i){
        while(last>0 && lcp[mys[last]] >= lcp[i]) --last;
        if(last==0) tr[i]=len+1; else tr[i]=mys[last];
        mys[++last]=i;
    }

    myset.clear();
    reset(dd,0);
    for(int i=1; i<=len; ++i){
        int bound = 0;
        if(lcp[i]==0){
            myset.clear();
            continue;
        }
        if(tl[i]>0) bound = max(bound, lcp[tl[i]]);
        if(tr[i]<=len) bound = max(bound, lcp[tr[i]]);
        int xlen = lcp[i];

        while(1){
            set<int>::iterator it;
            it=myset.lower_bound(xlen+1);
            if(it==myset.end()) break;
            myset.erase(it);
        }
        if(myset.find(xlen)!=myset.end()) continue;
        myset.insert(xlen);

        ll val=1;
        for(int j=0; j<3; ++j) val=val*(sum[j][tr[i]-1]-sum[j][tl[i]-1])%oo;
        dd[xlen]=(dd[xlen]+val)%oo;
        dd[bound]=(dd[bound]-val+oo)%oo;
    }



    int xlen=min(min(len1,len2),len3);
    ll val = 0;
    for(int i=xlen; i>=1; --i){
        val=(val+dd[i]+oo)%oo;
        res[i]=val;
    }
    for(int i=1; i<=xlen; ++i) printf("%I64d ",res[i]);
}
