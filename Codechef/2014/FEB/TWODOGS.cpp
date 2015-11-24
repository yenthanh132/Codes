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

const int maxn=500007;
const int maxv=1000007;

int n,a[maxn],k;
int lm[maxv],rm[maxv];


int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",&a[i]);
    int res=oo;
    reset(lm,0); reset(rm,0);
    FORD(i,n,(n-1)/2+2){
        if(a[i]*2==k) continue;
        if(a[i]<k && rm[k-a[i]]) res=min(res,n-i+1);
        if(rm[a[i]]==0) rm[a[i]]=n-i+1;
    }
    FOR(i,1,(n-1)/2+1){
        if(a[i]*2==k) continue;
        if(a[i]<k){
            if(lm[k-a[i]]) res=min(res,i);
            if(rm[k-a[i]]) res=min(res,max(i,rm[k-a[i]]));   
        }  
        if(lm[a[i]]==0) lm[a[i]]=i;
    }
    if(res==oo) res=-1;
    printf("%d\n",res);
    return 0;   
}
