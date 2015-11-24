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

const int maxn=100007;
const ll base=31;

int a,SA[maxn],RA[maxn],tSA[maxn],tRA[maxn],cnt[maxn],n;
char s[maxn];

ll val[maxn],pw[maxn];

int fRA(int i){ if(i<=n) return RA[i]; else return 0; }

void sort(int k){
    reset(cnt,0);
    FOR(i,1,n) cnt[fRA(SA[i]+k)]++;
    for(int sum=0,t,i=0; i<=max(300,n); i++){
        t=cnt[i];
        cnt[i]=sum;
        sum+=t;   
    }   
    FOR(i,1,n) tSA[++cnt[fRA(SA[i]+k)]]=SA[i];
    FOR(i,1,n) SA[i]=tSA[i];    
}

void construct(){
    FOR(i,1,n) RA[i]=s[i], SA[i]=i;
    int r;
    for(int k=1; k<n; k*=2){
        sort(k); sort(0);
        tRA[SA[1]]=r=1;
        FOR(i,2,n) tRA[SA[i]] = (RA[SA[i]]==RA[SA[i-1]] && fRA(SA[i]+k)==fRA(SA[i-1]+k))?r:++r;
        FOR(i,1,n) RA[i]=tRA[i];
    }
}

int cmp(int x1, int len1, int x2, int len2){
    int l=1, r=min(len1,len2), mid, res=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(val[x1+mid-1]-val[x1-1]*pw[mid] == val[x2+mid-1]-val[x2-1]*pw[mid]){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }   
    int v1=s[x1+res], v2=s[x2+res];
    if(res>=len1) v1=0;
    if(res>=len2) v2=0;
    if(v1==v2) return 0;
    if(v1<v2) return -1;
    return 1;
}

int cal(int len){
    int l,r,mid,x1=oo,x2=-oo;
    l=1; r=n; 
    while(l<=r){
        mid=(l+r)/2;
        if(cmp(1,len,SA[mid],min(n-SA[mid]+1,len))<=0){
            x1=mid;
            r=mid-1;   
        }else l=mid+1;
    }
    l=1; r=n;
    while(l<=r){
        mid=(l+r)/2;
        if(cmp(1,len,SA[mid],min(n-SA[mid]+1,len))>=0){
            x2=mid;
            l=mid+1;
        }else r=mid-1;
    }
    if(x1<=x2) return x2-x1+1; else return 0;
}

vector<pii> res;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
        
    scanf("%s",s+1); n=strlen(s+1);
    val[0]=0; pw[0]=1;
    FOR(i,1,n){
        val[i]=val[i-1]*base+s[i];
        pw[i]=pw[i-1]*base;   
    }
    construct();
    
    FOR(i,1,n)
        if(val[i]==val[n]-val[n-i]*pw[i]){
            int v=cal(i);
            if(v>0)
                res.pb(pii(i,v));  
        }

    printf("%d\n",sz(res));
    REP(i,sz(res)) printf("%d %d\n",res[i].fi,res[i].se);
    return 0;
}
