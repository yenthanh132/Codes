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
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
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
typedef pair<pii,int> iii;

const int maxn = 107;
const int dx[8]={-1,-1,0,1,1,1,0,-1};
const int dy[8]={0,1,1,1,0,-1,-1,-1};

int n,p[4][4],cost[4][4],t0,totaltime,len,v[maxn],w[maxn],dp[maxn],res;
string s[maxn],tab[4],sfind;
vector<pii> list, list0;
bool free1[4][4];

void dfs(int i, int x, int y){
    if(i==len){
        list0.pb(pii(v[i],w[i]));
        return;
    }
    free1[x][y]=false;
    int xt,yt;
    REP(k,8){
        xt=x+dx[k]; yt=y+dy[k];
        if(xt<0 || xt>3 || yt<0 || yt>3) continue;
        if(free1[xt][yt] && sfind[i]==tab[xt][yt]){
            w[i+1]=w[i]+dx[k]*dx[k]+dy[k]*dy[k];
            v[i+1]=v[i]+cost[xt][yt];
            dfs(i+1,xt,yt);
        }
    }
    free1[x][y]=true;
}

void optimize(){
    FOR(i,1,totaltime) dp[i]=-oo; dp[0]=0;
    REP(i,n)
        FORD(j,totaltime,0)
            if(j>=list[i].se) dp[j] = max(dp[j], dp[j-list[i].se] + list[i].fi);
    res=dp[0]; FOR(j,1,totaltime) res=max(res,dp[j]);
}
            
//#include<conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    FOR(i,1,n) cin>>s[i];
    REP(i,4) cin>>tab[i];
    REP(i,4) REP(j,4) cin>>cost[i][j];
    REP(i,4) REP(j,4) cin>>p[i][j];
    cin>>t0>>totaltime;
    //-------------------
    sort(s+1,s+n+1);
    FOR(i,1,n) if(i==1 || s[i]!=s[i-1]){
        list0=vector<pii>();
        reset(free1,true);
        len=s[i].length();
        sfind=s[i];
        REP(x,4) REP(y,4) if(tab[x][y]==sfind[0]){
            w[1]=p[x][y];
            v[1]=cost[x][y];
            dfs(1,x,y);
        }
        if(!list0.empty()){
            sort(list0.begin(), list0.end());
            list.pb(list0[0]);
            FOR(j,1,sz(list0)-1) if(list0[j].fi!=list0[j-1].fi) list.pb(list0[j]);
        }
        
        /*cout<<sfind<<" "<<sz(list0)<<endl;
        REP(j,sz(list0)) cout<<list0[j].fi<<" "<<list0[j].se<<endl;*/
    }
    /*cout<<endl;
    sort(list.begin(), list.end());
    REP(j,sz(list)) cout<<list[j].fi<<" "<<list[j].se<<endl;*/
    
    n=sz(list); totaltime-=t0;
    optimize();
    if(totaltime>=0) cout<<res; else cout<<0;
    
    //getch();
    return 0;
}
        

