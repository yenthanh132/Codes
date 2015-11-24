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
int n,x[maxn],y[maxn],r1[maxn],r2[maxn],cnt[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    scanf("%d",&n);
    reset(cnt,0);
    FOR(i,1,n){
        scanf("%d%d",&x[i],&y[i]);
        r1[i]=n-1;
        cnt[x[i]]++;
    }
    
    FOR(i,1,n){
        int t=cnt[y[i]];   
        if(x[i]==y[i]) --t;
        r2[i]=n-1-t;
        r1[i]+=t;
        
        printf("%d %d\n",r1[i],r2[i]);
    }
    
    return 0;
}

