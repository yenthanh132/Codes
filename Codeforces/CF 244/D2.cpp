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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


const int maxn=10007;

char s[maxn];
int res,m,n,sa[maxn],tSa[maxn],ra[maxn],tRa[maxn],cnt[maxn];

int fRa(int i){
    if(i<=n) return ra[i];
    else return 0;
}

void sort(int k){
    reset(cnt,0);
    FOR(i,1,n) cnt[fRa(sa[i]+k)]++;
    for(int sum=0,t, i=0; i<=max(300,n); ++i){
        t=cnt[i];
        cnt[i]=sum;
        sum+=t;
    }   
    FOR(i,1,n) tSa[++cnt[fRa(sa[i]+k)]]=sa[i];
    FOR(i,1,n) sa[i]=tSa[i];
}

void construct_sa(){
    int r;
    FOR(i,1,n) sa[i]=i, ra[i]=s[i];
    
    for(int k=1; k<n; k<<=1){
        sort(k); sort(0);
        tRa[sa[1]]=r=1;   
        FOR(i,2,n){
            if(!(ra[sa[i]] == ra[sa[i-1]] && fRa(sa[i]+k) == fRa(sa[i-1]+k))) ++r;
            tRa[sa[i]] = r;
        }
        FOR(i,1,n) ra[i]=tRa[i];
    }   
}

int lcp[maxn],plcp[maxn],prev[maxn];

void do_lcp(){
    prev[sa[1]]=-1;
    FOR(i,2,n) prev[sa[i]]=sa[i-1];
    int l=0;
    FOR(i,1,n){
        if(prev[i]==-1){
            plcp[i]=0;
            continue;   
        }   
        while(i+l<=n && prev[i]+l <=n && s[i+l] == s[prev[i]]) ++l;
        plcp[i]=l;
        l=max(l-1,0);
    }   
    FOR(i,1,n) lcp[i]=plcp[sa[i]];
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    
    scanf("%s",s+1);
    m=strlen(s+1);
    s[m+1]='.';
    scanf("%s",s+m+2);
    n=strlen(s+1);
    puts(s+1);
    
    construct_sa();
    do_lcp();
    FOR(i,1,n) cout<<sa[i]<<' '<<lcp[i]<<endl;
    
    FOR(i,1,n-1){
        if(sa[i]<=m && sa[i+1]>m+1){
            int len=lcp[i+1];
            int l1,l2;
            l1=lcp[i-1];
            l2=0; if(i<n-1) l2=lcp[i+2];
            if(max(l1,l2)<len) res=min(res,max(l1,l2)+1);
        }   
    }
    
    if(res==oo) res=-1;
    printf("%d\n",res);
    
    return 0;
}

