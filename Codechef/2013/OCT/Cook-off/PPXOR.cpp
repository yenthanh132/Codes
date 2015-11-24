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

int d[30][2],s[30],n;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);   
    REP(tt,T){
        scanf("%d",&n);   
        int v;
        reset(d,0); reset(s,0);
        REP(j,30) d[j][0]=1;
        ll res=0;
        REP(i,n){
            scanf("%d",&v);
            REP(j,30) if((v>>j)&1) s[j]++;   
            REP(j,30){
                int b=s[j]&1;
                res+=(1ll<<j)*d[j][1^b];
            }
            REP(j,30) d[j][s[j]&1]++;
        }
        cout<<res<<endl;
    }
    //getch();
    return 0;
}

