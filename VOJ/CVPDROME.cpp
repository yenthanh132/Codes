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

const int maxn=300007;

int n,m;
char a[maxn];
ll v,res;
ll list[maxn],cnt[maxn];

int toint(char ch){
    if(ch<='Z') return ch-'A'; else return ch-'a'+26;
}

int count(ll v){
    int l=1,r=m,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(list[mid]==v) return cnt[mid];
        else if(list[mid]>v) r=mid-1; else l=mid+1;
    }
    return 0;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    scanf("%s",a+1);
    v=res=0;
    FOR(i,1,n) list[i]=(v^=1ll<<toint(a[i]));
    list[++n]=0;
    sort(list+1,list+n+1);
    m=0;
    for(int i=1,j; i<=n; ){
        for(j=i; j<n && list[j+1]==list[i]; j++);
        cnt[++m]=j-i+1;
        list[m]=list[i];
        i=j+1;
    }
    FOR(i,1,m){
        res+=cnt[i]*(cnt[i]-1)/2;
        REP(j,52) if((list[i]&(1ll<<j))) res+=cnt[i]*count(list[i]^(1ll<<j));
    }
    
    printf("%lld\n",res);
    //getch();
    return 0;
}
