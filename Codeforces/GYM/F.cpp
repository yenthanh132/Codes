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

const int maxn=57;

int test;
int m,T,a[maxn];
double f[maxn][maxn];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>test;
    REP(tt,test){
        cin>>m>>T;
        string st;
        FOR(i,1,m){
            cin>>st;
            if(st!="L")
                a[i]=atoi(st.c_str());   
            else a[i]=oo;
        }
        a[m+1]=0;
        FOR(x,0,T) FOR(y,0,m+1) f[x][y]=0;
        f[0][0]=1;
        REP(step,T){
            FOR(x,0,m) FOR(v,1,2){
                int xt=x+v;
                if(xt>m+1) xt=m+1;
                if(a[xt]==oo)
                    f[step+2][xt]+=f[step][x]*0.5;   
                else{
                    xt+=a[xt];
                    f[step+1][xt]+=f[step][x]*0.5;
                }                    
            }   
        }
       //FOR(i,1,m) cout<<a[i]<<' '; cout<<endl;
        double res=0;
       
        FOR(i,0,T) res+=f[i][m+1];
        if(res==0.5) puts("Push. 0.5000");
        else if(res<0.5) printf("Bet against. %0.4lf\n",res);
        else printf("Bet for. %0.4lf\n",res);
    }
    //getch();   
    return 0;
}
