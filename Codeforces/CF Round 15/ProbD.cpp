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
typedef pair<ll,pii> plii;

const int maxn = 1007;
int m,n,a,b,arr[maxn][maxn],minv[maxn][maxn],mincol[maxn][maxn];
ll sum[maxn][maxn];
bool used[maxn][maxn];
vector<plii> list,list2;

ll getS(int x1, int y1, int x2, int y2){
    return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}

void init(){
    deque<int> mydeque;
    FOR(col,1,m){
        mydeque=deque<int>();
        FORD(row,n,1){
            while(!mydeque.empty() && mydeque.front()>=row+a) mydeque.pop_front();
            while(!mydeque.empty() && arr[mydeque.back()][col]>=arr[row][col]) mydeque.pop_back();
            mydeque.push_back(row);
            mincol[row][col]=arr[mydeque.front()][col];
        }
    }
    FOR(row,1,n-a+1){
        mydeque=deque<int>();
        FORD(col,m,1){
            while(!mydeque.empty() && mydeque.front()>=col+b) mydeque.pop_front();
            while(!mydeque.empty() && mincol[row][mydeque.back()]>=mincol[row][col]) mydeque.pop_back();
            mydeque.push_back(col);
            minv[row][col]=mincol[row][mydeque.front()];
        }
    }
    FOR(i,1,n) FOR(j,1,m) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i][j];
    FOR(i,1,n-a+1) FOR(j,1,m-b+1) 
        list.pb(plii(getS(i,j,i+a-1,j+b-1)-ll(a*b)*minv[i][j],pii(i,j)));
    sort(list.begin(),list.end());
    reset(used,0);
}

void solve(){
    int x1,y1,x2,y2;
    REP(i,sz(list)){
        x1=list[i].se.fi; y1=list[i].se.se;
        x2=x1+a-1; y2=y1+b-1;
        if(used[x1][y1] || used[x1][y2] || used[x2][y1] || used[x2][y2]) continue;
        list2.pb(list[i]);
        FOR(x,x1,x2) FOR(y,y1,y2) used[x][y]=1;
    }
    printf("%d\n",sz(list2));
    REP(i,sz(list2)) printf("%d %d %I64d\n",list2[i].se.fi,list2[i].se.se,list2[i].fi);
}

#include<conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d%d",&n,&m,&a,&b);
    FOR(i,1,n) FOR(j,1,m) scanf("%d",&arr[i][j]);
    init();
    solve();
    //getch();
    return 0;
}
