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

const int maxn=25;

int a[maxn],n,c1,deg[maxn],s[maxn];
bool ok;

void go(int i){
    if(ok) return;
    if(i==0){
        int need1=0;
        FOR(j,1,n){
            int sub=a[j]-s[j]-1+deg[j];
            if(sub<2) return;
            need1+=a[j]-s[j]-1;   
        }
        if(need1==c1) ok=1;
        return;
    }
    FOR(j,i+1,n)
        if(a[i]+1<a[j] && s[j]+a[i]+1<=a[j]){
            s[j]+=a[i];
            ++deg[j];
            go(i-1);
            s[j]-=a[i];
            --deg[j];
        }       
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int N;
    scanf("%d",&N);
    int v;
    c1=0;
    FOR(i,1,N){
        scanf("%d",&v);
        if(v==1) ++c1;
        else a[++n]=v;
    }
    
    if(n==0){
        if(c1==1) puts("YES");
        else puts("NO");   
        return 0;
    }
    sort(a+1,a+n+1);
    if(a[n]!=N){
        puts("NO");
        return 0;   
    }
    
    reset(deg,0); reset(s,0);
    ok=0;
    go(n-1);
    if(ok) puts("YES"); else puts("NO");
    
    return 0;
}
