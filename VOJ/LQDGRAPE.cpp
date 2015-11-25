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

//fast input
template<typename T>
void read(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}



const int maxn=507;
const int maxq=10007;
const int maxv=100001;

int m,n,q,ans[maxq],a[maxn][maxn];
struct query{int l,r,i;} list[maxq];
int minv[maxv][maxn],arrmin[maxn][maxn][2],arrmax[maxn][maxn][2];
int BIT[maxv+1];

void update(int pos, int v){
    pos++;
    for(int i=pos; i; i-=i&(-i)) BIT[i]=max(BIT[i],v);
}

int get(int pos){
    pos++;
    int res=0;
    for(int i=pos; i<=maxv; i+=i&(-i)) res=max(res,BIT[i]);
    return res;
}

bool cmplist(const query &a, const query &b){
    return a.r<b.r;
}

void updatemax(int &v, const int &t){
    v=max(v,t);
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    read(m); read(n); read(q);
    FOR(i,1,m) FOR(j,1,n) read(a[i][j]);
    FOR(i,1,q){
        read(list[i].l); read(list[i].r);
        list[i].i=i;
    }
    REP(i,maxv) FOR(j,1,n) minv[i][j]=-1;
    FOR(i,1,m) FOR(j,1,n){
        arrmin[i][j][1]=arrmax[i][j][1]=a[i][j];
        updatemax(minv[a[i][j]][1],a[i][j]);
    }
    int flag=1;
    FOR(k,2,min(m,n)){
        flag^=1;
        FOR(i,k,m) FOR(j,k,n){
            arrmin[i][j][flag]=min(min(arrmin[i-1][j-1][flag^1],a[i][j]),min(arrmin[i-1][j][flag^1],arrmin[i][j-1][flag^1]));
            arrmax[i][j][flag]=max(max(arrmax[i-1][j-1][flag^1],a[i][j]),max(arrmax[i-1][j][flag^1],arrmax[i][j-1][flag^1]));
            updatemax(minv[arrmax[i][j][flag]][k],arrmin[i][j][flag]);
        }
    }
            
    sort(list+1,list+q+1,cmplist);
    int i=1;
    FOR(v,0,100000){
        while(i<=q && list[i].r<v){
            ans[list[i].i]=get(list[i].l);
            i++;
        }
        FOR(j,1,n) if(minv[v][j]!=-1)
            update(minv[v][j],j);
    }
    while(i<=q){
        ans[list[i].i]=get(list[i].l);
        i++;
    }
    
    FOR(i,1,q) printf("%d\n",ans[i]*ans[i]);
    //cout<<clock()*1.0/CLOCKS_PER_SEC<<endl;
    //getch();
    return 0;
}
    
