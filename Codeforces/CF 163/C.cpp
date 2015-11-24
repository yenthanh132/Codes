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

const int maxn=1007;

int n,a[maxn][maxn];
struct cmd{
    int t,a,b;
    cmd(int x, int y, int z){
        t=x;
        a=y;
        b=z;
    }
};
vector<cmd> cmdlist;
struct rowlist{int c; vector<int> list;} row[maxn];

bool cmp(const rowlist &a, const rowlist &b){
    return a.c<b.c;
}

void swapcol(int i, int j){
    FOR(z,1,n) swap(a[z][i],a[z][j]);
}

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    int x,y;
    FOR(i,1,n) row[i].c=0;
    REP(i,n-1){
        scanf("%d%d",&x,&y);
        row[x].c++;
        row[x].list.pb(y);
    }
    FORD(i,n,2){
        int p=i;
        FOR(j,1,i-1) if(row[j].c>row[p].c) p=j;
        if(i!=p){
            cmdlist.pb(cmd(1,p,i));
            swap(row[i],row[p]);
        }
    }
    FOR(i,1,n)
        REP(j,sz(row[i].list)) a[i][row[i].list[j]]=1;
    FOR(i,1,n) {
        FOR(j,1,n)cout<<a[i][j];
        cout<<endl;
    }
    x=0;
    FOR(i,2,n){
        FOR(j,i,n) if(a[i][j]==1){
            x++;
            while(!emptyrow(x)) x++;
            cmdlist.pb(cmd(2,x,j));
            swapcol(x,j);
        }
    }
    FOR(i,1,n) {
        FOR(j,1,n)cout<<a[i][j];
        cout<<endl;
    }
    printf("%d\n",sz(cmdlist));
    REP(i,sz(cmdlist)) printf("%d %d %d\n",cmdlist[i].t,cmdlist[i].a,cmdlist[i].b);
    getch();
    return 0;
}

