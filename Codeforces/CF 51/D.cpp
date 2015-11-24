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

ll dp[20][1<<10][2521][2];
ll f[20][1<<10],g[20];
unsigned long long d10[20];
int cm,num_id,num[20];
bool allow[10];

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);   
}

int lcm(int a, int b){
    return (a/gcd(a,b))*b;
}

ll get(int x, int y, int z, bool smaller){
    if(x==0){
        if(y!=0 || z!=0) return 0;
        else return 1;
    }
    if(dp[x][y][z][smaller]!=-1) return dp[x][y][z][smaller];
    ll &res=dp[x][y][z][smaller];
    res=0;
    ll val;
    int new_y;
    if(smaller){
        FOR(v,0,9) if(allow[v]){
            val=((v*d10[x-1]%cm)+z)%cm;
            new_y=y;
            if(v && ((new_y>>(v-1))&1)) new_y-=1<<(v-1);
            res+=get(x-1,new_y,val,1);
        }
    }else{
        FOR(v,0,num[x]) if(allow[v]){
            val=((v*d10[x-1]%cm)+z)%cm;
            new_y=y;
            if(v && ((new_y>>(v-1))&1)) new_y-=1<<(v-1);
            res+=get(x-1,new_y,val,v<num[x]);
        }   
    }
    return res;
}

void init(){
    d10[0]=1;
    FOR(i,1,19) d10[i]=d10[i-1]*10;
}

ll cal(ll v){
    int n=0;
    while(v){
        num[++n]=v%10;
        v/=10;
    }
    ll res=0;
    REP(id,1<<9){
        if(id==0) continue;
        cm=1;
        reset(allow,0);
        allow[0]=1;
        REP(j,9) if((id>>j)&1) cm=lcm(cm,j+1), allow[j+1]=1;    
        
        FOR(i,0,n) FOR(j,0,id) REP(z,cm) REP(z2,2) dp[i][j][z][z2]=-1;
        num_id=id; 
        res+=get(n,id,0,0);
    }   
    return res; 
}

int main(){
    init();   
    ll v;
    cin>>v;
    while(v){
        cout<<cal(v)<<endl;
        cin>>v;
    }
}
