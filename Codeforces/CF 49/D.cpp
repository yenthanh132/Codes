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

int a[307],b[307];
int n;
vector<pii> list;

#include <conio.h>
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) scanf("%d",&b[i]);
    FOR(i,1,n-1)
        if(a[i]!=b[i]){   
            int u=-1;
            FOR(j,i+1,n) if(b[j]==a[i]){
                u=j;
                break;
            }
            while(u>i){
                swap(b[u],b[u-1]);
                list.pb(pii(u-1,u));
                u--;
            }
        }
    printf("%d\n",sz(list));
    REP(i,sz(list)) printf("%d %d\n",list[i].fi,list[i].se);
    //getch();
}
