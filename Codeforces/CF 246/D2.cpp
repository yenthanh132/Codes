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

int f[maxn],n,cnt[maxn],mark[maxn];
char s[maxn];
vector<pii> list;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    scanf("%s",s+1);
    n=strlen(s+1);
    int k=0;
    f[1]=0;
    FOR(i,2,n){
        while(k && s[k+1]!=s[i]) k=f[k];
        if(s[k+1]==s[i]) ++k;
        f[i]=k;
    }   
    
    k=n;
    while(k){
        mark[k]=1;
        k=f[k];   
    }
    FOR(i,2,n) cnt[f[i]]++;
    FORD(i,n,1) cnt[f[i]]+=cnt[i];
    FOR(i,1,n) if(mark[i]) list.pb(pii(i,cnt[i]+1));
    sort(list.begin(),list.end());
    
    printf("%d\n",sz(list));
    REP(i,sz(list)) printf("%d %d\n",list[i].fi,list[i].se);
    
    return 0;
}
