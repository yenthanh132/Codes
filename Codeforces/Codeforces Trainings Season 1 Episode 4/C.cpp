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


int n,a[20];
int myq[2][3000000][2],last[2];
bool dp[1<<13][1<<13];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int T;
    cin>>T;
    FOR(tt,1,T){
        cin>>n;
        FOR(i,1,n){
            cin>>a[i];
            a[i]--;
        }
        dp[0][0]=1;
        last[0]=1;
        myq[0][1][0]=0;
        myq[0][1][1]=0;
        int u,v,flag=0,u2,v2,val;
        FOR(i,1,n){
            last[1^flag]=0;
            FOR(x,1,last[flag]){
                u=myq[flag][x][0]; v=myq[flag][x][1];
                dp[u][v]=0;
                FOR(t,1,n) if(((u>>(t-1))&1)==0){
                    val=(a[i]+t)%n;   
                    u2=u | (1<<(t-1));                    
                    if(((v>>val)&1)==0){
                        v2=v | (1<<val);
                        if(!dp[u2][v2]){
                            dp[u2][v2]=1;
                            myq[1^flag][++last[1^flag]][0]=u2;  
                            myq[1^flag][last[1^flag]][1]=v2; 
                        }                       
                    }
                }
            }
            flag^=1;
        }
        if(dp[(1<<n)-1][(1<<n)-1]) puts("Sepehr");
        else puts("Sohrab");
        dp[(1<<n)-1][(1<<n)-1]=0;
    }
    

    //getch();
    return 0;
}
