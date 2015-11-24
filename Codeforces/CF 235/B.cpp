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

const int maxn=4007;

int x,k;
pii a[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>x>>k;
    FOR(i,1,k){
        int v;
        cin>>v;
        cin>>a[i].fi;
        if(v==1) cin>>a[i].se; else a[i].se=a[i].fi;
    }
    sort(a+1,a+k+1);
    int r1=0,r2=0;
    a[0].se=0;
    a[k+1].fi=x;
    FOR(i,1,k+1){
        int len=a[i].fi-a[i-1].se-1;
        if(len>0){
            r1+=len/2+(len&1);
            r2+=len;   
        }
    }
    cout<<r1<<' '<<r2<<endl;
    
}
