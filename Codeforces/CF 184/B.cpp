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

const int maxn=100;

ll p,q;
int a[maxn],n;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>p>>q;
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n-1){
        ll v;
        if(p%q==0){
            v=p/q-1;
            p=q;
        }else{
            v=p/q;
            p=p%q;
        }        
        swap(p,q);
        if(v!=a[i]){
            puts("NO");
            return 0;
        }
    }
    if(p%q!=0 || p/q!=a[n]) puts("NO"); else
    puts("YES");
    //getch();
    return 0;
}
