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

const int base=73471;
const int dx[8]={-1,-1,0,1,1,1,0,-1};
const int dy[8]={0,1,1,1,0,-1,-1,-1};

set<ll> myset;
char s[250][250];
int m,n,d[250][250],cc,res,minx,miny;
vector<pii> a;

void init(){
    int x1,y1,x2,y2,x3,y3,x4,y4;
    vector<pii> list;
    ll hashval;
    FOR(i,2,250){
        list.clear();
        x1=y1=1; x2=1; y2=i; x3=y3=i; x4=i; y4=1;
        list.pb(pii(x1,y1)); list.pb(pii(x2,y2)); list.pb(pii(x3,y3)); list.pb(pii(x4,y4));
        REP(j,i-2){
            y1++; x2++; y3--; x4--;
            list.pb(pii(x1,y1)); list.pb(pii(x2,y2)); list.pb(pii(x3,y3)); list.pb(pii(x4,y4));
        }
        sort(list.begin(), list.end());
        hashval=0;
        REP(i,sz(list)){
            hashval=hashval*base+list[i].fi;
            hashval=hashval*base+list[i].se;
        }
        myset.insert(hashval);
    }
    
    FOR(i,2,125){
        list.clear();
        x1=1; y1=i; x2=i; y2=i*2-1; x3=i*2-1; y3=i; x4=i; y4=1;
        list.pb(pii(x1,y1)); list.pb(pii(x2,y2)); list.pb(pii(x3,y3)); list.pb(pii(x4,y4));
        REP(j,i-2){
            x1++; y1++; x2++; y2--; x3--; y3--; x4--; y4++;
            list.pb(pii(x1,y1)); list.pb(pii(x2,y2)); list.pb(pii(x3,y3)); list.pb(pii(x4,y4));
        }
        sort(list.begin(), list.end());
        hashval=0;
        REP(i,sz(list)){
            hashval=hashval*base+list[i].fi;
            hashval=hashval*base+list[i].se;
        }
        myset.insert(hashval);
    }
}

void bfs(int x, int y){
    d[x][y]=cc;
    queue<pii> myqueue;
    a.clear();
    a.pb(pii(x,y));
    myqueue.push(pii(x,y));
    pii u;
    int xt,yt;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        REP(k,8){
            xt=u.fi+dx[k]; yt=u.se+dy[k];
            if(xt<0 || xt==m || yt<0 || yt==n || s[xt][yt]=='0' || d[xt][yt]==cc) continue;
            d[xt][yt]=cc;
            a.pb(pii(xt,yt));
            myqueue.push(pii(xt,yt));
        }
    }
}   

#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);    
    init();
    int T;
    ll hashval;
    scanf("%d\n",&T);
    reset(d,0); cc=0;
    REP(index,T){
        scanf("%d%d\n",&m,&n);
        REP(i,m) gets(s[i]);
        res=0;
        cc++;
        REP(i,m) REP(j,n) if(s[i][j]=='1' && d[i][j]!=cc){
            minx=miny=oo;
            bfs(i,j);
            hashval=0;
            REP(z,sz(a)) minx=min(a[z].fi,minx), miny=min(a[z].se,miny);
            sort(a.begin(), a.end());
            REP(z,sz(a)){
                hashval=hashval*base+a[z].fi-minx+1;
                hashval=hashval*base+a[z].se-miny+1;;
            }
            if(myset.find(hashval)!=myset.end()) res++;
        }
        printf("%d\n",res);
    }
    //getch();
    return 0;
}
