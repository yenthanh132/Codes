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

int m,n,res;
ll a[56],b[56],maxv,v;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    REP(i,n) cin>>a[i];
    cin>>m;
    REP(i,m) cin>>b[i];
    maxv=-1;
    REP(i,n) REP(j,m) if(b[j]%a[i]==0){
        v=b[j]/a[i];
        if(v>maxv){
            maxv=v;
            res=1;
        }else if(v==maxv) res++;
    }
    cout<<res<<endl;
    //getch();
    return 0;
}
