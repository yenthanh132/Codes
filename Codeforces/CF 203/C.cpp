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

struct work{
    int x,y;
    char ch; 
    work(){}
    work(int a, int b, char c){
        x=a; y=b;
        ch=c;
    }
    work(int a){
        x=a;
    }
};

vector<work> list;
pii a[100007];

bool cmp(const pii &a, const pii &b){
    return 1ll*a.fi*a.fi + 1ll*a.se*a.se < 1ll*b.fi*b.fi + 1ll*b.se*b.se;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int n,x,y;   
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%d",&a[i].fi,&a[i].se);
    }
    sort(a+1,a+n+1,cmp);
    FOR(i,1,n){
        int x=a[i].fi, y=a[i].se;
        if(x){
            if(x>0) list.pb(work(1,x,'R'));
            else list.pb(work(1,-x,'L'));
        }
        if(y){
            if(y>0) list.pb(work(1,y,'U'));
            else list.pb(work(1,-y,'D'));
        }
        list.pb(work(2));
        if(x){
            if(x>0) list.pb(work(1,x,'L'));
            else list.pb(work(1,-x,'R'));
        }
        if(y){
            if(y>0) list.pb(work(1,y,'D'));
            else list.pb(work(1,-y,'U'));
        }
        list.pb(work(3));
    }
    printf("%d\n",sz(list));
    REP(i,sz(list)){
        work w=list[i];
        if(w.x==1) printf("%d %d %c\n",w.x,w.y,w.ch);
        else printf("%d\n",w.x);
    }
    
    //getch();
    return 0;
}
