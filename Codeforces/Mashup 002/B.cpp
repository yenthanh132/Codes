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

const int maxn = 2000007;
const ll hashbase = 73471;

char s[maxn],t[maxn];
int sa[maxn],tsa[maxn],ra[maxn],tra[maxn], cnt[maxn];
int len,n,m;
int fra(int i){return (i>len)?0:ra[i];};

ll hashpw[maxn], vs[maxn], vt[maxn];

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
}

int cmp(int i1, int i2, int j1, int j2){
    int l=1, r= min(i2-i1+1, j2-j1+1), res=0, mid;
    while(l<=r){
        mid=(l+r)/2;
        if(vs[i1+mid-1]-vs[i1-1]*hashpw[mid] == vt[j1+mid-1]-vt[j1-1]*hashpw[mid]){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    int ch1, ch2;
    if(i2-i1+1 == j2-j1+1 && i2-i1+1 == res) return 0;
    if(i1+res<=len) ch1=s[i1+res]; else ch1='@';
    ch2 = t[j1+res];
    if(ch1==ch2) return 0;
    if(ch1 < ch2) return -1;
    return 1;
}

int cal(int idx){
    int j1=idx, j2=idx+m-1;
    int l=1, r=len, mid, r1=-oo, r2=oo;
    while(l<=r){
        mid=(l+r)/2;
        int i1=sa[mid];
        int i2=i1+m-1; if(i2>len) i2=len;
        if(cmp(i1,i2,j1,j2)<=0){
            r1=mid;
            l=mid+1;
        }else r=mid-1;
    }
    l=1, r=r1;
    while(l<=r){
        mid=(l+r)/2;
        int i1=sa[mid];
        int i2=i1+m-1; if(i2>len) i2=len;
        if(cmp(i1,i2,j1,j2)>=0){
            r2=mid;
            r=mid-1;
        }else l=mid+1;
    }
    return max(0,r1-r2+1);
}

int main(){
    //freopen("input.txt","r",stdin);

    hashpw[0]=1;
    for(int i=1; i<=1000000; ++i) hashpw[i]=hashpw[i-1]*hashbase;
    scanf("%s",s+1); len=strlen(s+1);
    suffixArray();
    //for(int i=1; i<=len; ++i) printf("%d %s\n",sa[i], s+sa[i]);

    vs[0]=0;
    for(int i=1; i<=len; ++i) vs[i]=vs[i-1]*hashbase + s[i];
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        scanf("%s",t+1);
        m=strlen(t+1);
        if(m>len){
            puts("0");
            continue;
        }
        for(int i=m+1; i<m*2; ++i) t[i]=t[i-m];
        vt[0]=0;
        for(int i=1; i<m*2; ++i) vt[i]=vt[i-1]*hashbase + t[i];

        int res = 0;
        for(int i=1; i<=m; ++i){
            if(i>1 && vt[i+m-1]-vt[i-1]*hashpw[m]==vt[m]) break;
            res += cal(i);
        }

        printf("%d\n",res);
    }
    return 0;
}
