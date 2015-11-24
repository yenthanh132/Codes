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
//#include <conio.h>


ll f[31][31]; 
int T, n, m, val;

void dfs(int l, int r, ll id){
    if(l>r) return;
    int len=r-l+1;
    val+=len+1;
    if(l==r) return;
    FORD(i,l+(len+1)/2-1,l){
        if(f[l][i-1]*f[i+1][r]<id) id-=f[l][i-1]*f[i+1][r];
        else{
            dfs(l,i-1,(id-1)/f[i+1][r]+1);
            dfs(i+1,r,(id-1)%f[i+1][r]+1);
            return;
        }
    } 
}
            
int getvalue(ll id){
    val=0;
    dfs(1,n,id);
    return val;
}

void solve(){
    ll l=1; ll r=f[1][n];
    int res=-1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(getvalue(mid)<=m){
            res=val;
            l=mid+1;
        }else r=mid-1;
    }
    if(res==-1) cout<<-1<<endl; else cout<<m-res<<endl;
}

int main(){
    reset(f,0);
    FOR(i,1,31) f[i][i]=f[i][i-1]=1;
    FOR(len,2,30) FOR(i,1,30-len+1){
        int j=i+len-1;
        f[i][j]=0;
        FOR(k,i,i+(len+1)/2-1) f[i][j]+=f[i][k-1]*f[k+1][j];
    }
    /*n=10;
    cout<<f[1][n]<<endl;
    FOR(i,1,f[1][n]) cout<<getvalue(i)<<endl;
    getch();
    */
    //freopen("test.txt","r",stdin);
    cin>>T;
    REP(index,T){
        cin>>n>>m;
        solve();
    }
    
    //getch();
    return 0;
}
