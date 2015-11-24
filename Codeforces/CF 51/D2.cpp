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

const int cm=2520;

ll dp[20][48][2521][2];
unsigned long long d10[20];
int num[20],pos[2521],list[50];

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);   
}

int lcm(int a, int b){
    return (a/gcd(a,b))*b;
}

void cal(int x, int y, int z, bool smaller){
    if(dp[x][y][z][smaller]==0) return;
    ll &res=dp[x][y][z][smaller];
    ll val;
    int new_y;
    if(smaller){
        FOR(v,0,9){
            val=((v*d10[x-1]%cm)+z)%cm;
            new_y=list[y];
            if(v>=2) new_y=lcm(new_y,v);
            dp[x-1][pos[new_y]][val][1]+=res;
        }
    }else{
        FOR(v,0,num[x]){
            val=((v*d10[x-1]%cm)+z)%cm;
            new_y=list[y];
            if(v>=2) new_y=lcm(new_y,v);
            dp[x-1][pos[new_y]][val][v<num[x]]+=res;
        }   
    }
}

void init(){
    d10[0]=1;
    FOR(i,1,19) d10[i]=d10[i-1]*10;
    int c=0;
    FOR(i,1,cm) if(cm%i==0){
        list[c]=i;
        pos[i]=c++;
    }
}

ll cal(ll v){
    int n=0;
    while(v){
        num[++n]=v%10;
        v/=10;
    }
    ll res=0;
    reset(dp,0);
    dp[n][0][0][0]=1;
    FORD(i,n,1) REP(id,48) REP(j,cm) REP(z,2) cal(i,id,j,z);
    REP(i,48){
        int m=list[i];
        for(int v=0; v<2520; v+=m) res+=dp[0][i][v][0]+dp[0][i][v][1];
    }
    
    return res; 
}

#include <conio.h>
int main(){
    init();   
    //freopen("test.txt","r",stdin);
    ll t,u,v;
    cin>>t;
    REP(i,t){
        cin>>u>>v;
        cout<<cal(v)-cal(u-1)<<endl;;
    }
    //getch();
    return 0;
}
