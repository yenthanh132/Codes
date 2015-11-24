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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n,v;
vector<pii> l1,l2;
vector<int> lans;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&v);
    int a,b;
    REP(i,n){
        scanf("%d%d",&a,&b);
        if(a==1) l1.pb(mp(b,i));
        else l2.pb(mp(b,i));
    }
    int res=0,i=0,j=0,vol=0,n1,n2;
    sort(l1.rbegin(),l1.rend()); n1=sz(l1); l1.pb(mp(0,0)); l1.pb(mp(0,0));
    sort(l2.rbegin(),l2.rend()); n2=sz(l2);
    while(vol<v)
        if(vol+2<=v && j<n2 && l1[i].fi+l1[i+1].fi<=l2[j].fi){
            res+=l2[j].fi; 
            vol+=2;
            lans.pb(l2[j].se);
            j++;
        }else if(i<n1){
            res+=l1[i].fi; 
            vol++;
            lans.pb(l1[i].se);
            i++;
        }else break;
    printf("%d\n",res);
    REP(i,sz(lans)) printf("%d ",lans[i]+1);
    //getch();
    return 0;
}
