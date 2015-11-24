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

int gcd(int a, int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    else return gcd(b,a%b);
}

int n,di,m;
ll res;

#include <conio.h>
int main(){
    int v;
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("%d",&v);
        if(i==1) di=v-1; else di=gcd(di,v-1);
    }
    res=0;
    for(int i=1; i*i<=di; i++) if(di%i==0){
        if(i&1){
            ll t=1;
            while(t*i<=m) res+=m-t*i, t<<=1;
        }
        if(i*i!=di && ((di/i)&1)){
            ll t=1;
            while(t*(di/i)<=m) res+=m-t*(di/i), t<<=1;
        }
    }
    
    cout<<res<<endl;
    //getch();
    return 0;
}
    
