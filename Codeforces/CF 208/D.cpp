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

const int maxn=3007;
int a[maxn],b[maxn],c[maxn],f[maxn][2],n,res;

int main(){
    //freopen("input.txt","r",stdin);
    res=0;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n){
        scanf("%d",&b[i]);
        res+=b[i];
    }
    FOR(i,1,n) scanf("%d",&c[i]);
    f[0][1]=0;
    f[0][0]=-oo;
    FOR(i,1,n){
        f[i][0]=f[i][1]=-oo;
        FOR(j,0,i-1){
            f[i][0]=max(f[i][0],f[j][1]);
            f[i][1]=max(f[i][1],f[j][0]);
        }
        if(f[i][0]>-oo) f[i][0]+=a[i]-b[i];
        if(f[i][1]>-oo) f[i][1]+=c[i]-b[i];
    }
    int res2=-oo;
    FOR(i,1,n) res2=max(res2,f[i][0]);
    res+=res2;
    cout<<res<<endl;

    return 0;
}

