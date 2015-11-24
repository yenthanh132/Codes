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
typedef pair<int,pii> piii;

vector<piii> a,b;

bool cmp_a(const piii &a, const piii &b){
    return (a.se.fi>b.se.fi || (a.se.fi==b.se.fi && a.se.se>b.se.se));
}
bool cmp_b(const piii &a, const piii &b){
    return (a.se.se>b.se.se || (a.se.se==b.se.se && a.se.fi>b.se.fi));
}

bool free1[200007];

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    int t,n,x,y,c;
    ll A,B,sa,sb;
    scanf("%d",&t);
    REP(i,t){
        scanf("%d",&n);
        a.clear();
        A=B=sa=sb=0;
        FOR(i,1,n*2-1){
            scanf("%d%d",&x,&y);
            a.pb(mp(i,mp(x,y)));
            A+=x; B+=y;
        }
        A=(A+1)/2; B=(B+1)/2;
        b=a;
        sort(a.begin(),a.end(),cmp_a);
        sort(b.begin(),b.end(),cmp_b);
        FOR(i,1,n*2-1) free1[i]=1;
        c=0;
        REP(i,n) if(free1[a[i].fi]){
            sa+=a[i].se.fi; sb+=a[i].se.se;
            free1[a[i].fi]=0;
            c++;
            if(sa>=A) break;
        }
        REP(i,n) if(free1[b[i].fi]){
            sa+=b[i].se.fi; sb+=b[i].se.se;
            free1[b[i].fi]=0;
            c++;
            if(sb>=B && c>=n) break;
        }
        if(c>n) printf("NO\n");
        else{
            printf("YES\n");
            FOR(i,1,n*2-1) if(!free1[i]) printf("%d ",i); printf("\n");
        }
    }
    getch();
    return 0;
}
    
