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


//Bignum-----------------
typedef vector<long long> bignum;
const int BASE = 1000000000;
const int NUMLEN = 9;

bignum int2bignum(int v){
    bignum c(1,v);
    return c;
}

string bignum2str(bignum a){
    string s="",st;
    REP(i,sz(a)){
        stringstream ss;
        ss<<a[i]; st=ss.str();
        if(i<sz(a)-1) while(st.length()<NUMLEN) st="0"+st;
        s=st+s;
    }
    return s;
}

bignum operator+(bignum &a, bignum &b){
    bignum c;
    ll t=0;
    while(sz(a)<sz(b)) a.pb(0);
    while(sz(a)>sz(b)) b.pb(0);
    REP(i,max(sz(a),sz(b))){
        t+=a[i]+b[i];
        c.pb(t%BASE);
        t/=BASE;
    }
    if(t>0) c.pb(t);
    while(sz(c)>1 && *c.rbegin()==0) c.pop_back();
    return c;
}

//--------------------------------------
const int maxn=207;

int m,n,d[maxn][maxn][4],xs,ys,xf,yf,ks;
char arr[maxn][maxn];
bignum cnt[maxn][maxn][4];

struct node{
    int x,y,k;
    node (int _x, int _y, int _k){
        x=_x;
        y=_y;
        k=_k;
    }
};
queue<node> q;

bool update(int &v, bignum &c, bignum &c0, int x){
    if(v>x){
        v=x;
        c=c0;
        return 1;
    }else if(v==x)
        c=c+c0;
    return 0;
}
        

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&m,&n);
    FOR(i,1,m) scanf("%s",arr[i]+1);
    FOR(i,1,m) FOR(j,1,n) if(arr[i][j]!='.' && arr[i][j]!='*')
        if(arr[i][j]=='X') xf=i, yf=j;
        else{
            xs=i; ys=j;
            if(arr[i][j]=='N') ks=0;
            else if(arr[i][j]=='E') ks=1;
            else if(arr[i][j]=='S') ks=2;
            else ks=3;
        }
    
    FOR(i,1,m) FOR(j,1,n) REP(k,4) d[i][j][k]=oo;
    d[xs][ys][ks]=0; cnt[xs][ys][ks]=int2bignum(1); 
    int x,y,k0;
    q.push(node(xs,ys,ks));
    while(!q.empty()){
        x=q.front().x; y=q.front().y; k0=q.front().k; q.pop();
        REP(k,4) if(k!=k0 && k!=(k0+2)%4)
            if(update(d[x][y][k],cnt[x][y][k],cnt[x][y][k0],d[x][y][k0]+1))
                q.push(node(x,y,k));
        if(k0==0 || k0==2){
            FOR(xt,x+1,m){
                if(arr[xt][y]=='*') break;
                if(update(d[xt][y][k0],cnt[xt][y][k0],cnt[x][y][k0],d[x][y][k0]+1))
                    q.push(node(xt,y,k0));
            }
            FORD(xt,x-1,1){
                if(arr[xt][y]=='*') break;
                if(update(d[xt][y][k0],cnt[xt][y][k0],cnt[x][y][k0],d[x][y][k0]+1))
                    q.push(node(xt,y,k0));
            }
        }else{
            FOR(yt,y+1,n){
                if(arr[x][yt]=='*') break;
                if(update(d[x][yt][k0],cnt[x][yt][k0],cnt[x][y][k0],d[x][y][k0]+1))
                    q.push(node(x,yt,k0));
            }
            FORD(yt,y-1,1){
                if(arr[x][yt]=='*') break;
                if(update(d[x][yt][k0],cnt[x][yt][k0],cnt[x][y][k0],d[x][y][k0]+1))
                    q.push(node(x,yt,k0));
            }
        }
    }
    int res=oo-1;
    bignum res2;
    REP(k,4) update(res,res2,cnt[xf][yf][k],d[xf][yf][k]);
    
    if(res==oo-1) puts("0 0");
    else printf("%d %s\n",res,bignum2str(res2).c_str());
    
    //getch();
    return 0;
}
    
