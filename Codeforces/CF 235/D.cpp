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

ll n,f[2][1<<18][100];
int list[111111];
int m,num[20],cnt,k;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>m;
    cnt=0;
    while(n){
        num[cnt++]=n%10;
        n/=10;   
    }
    sort(num,num+cnt);
    k=0;
    REP(mask,1<<cnt){
        bool ok=1;
        REP(j,cnt) 
            if(j>0 && ((mask>>(j-1))&1)==0 && ((mask>>j)&1)==1 && num[j-1]==num[j]) ok=0;
        if(ok) list[k++]=mask;
    }
        
    f[0][0][0]=1;
    
    ll p10=1;
    REP(i,cnt){
        int cur=i&1;
        int next=cur^1;
        REP(j,k) REP(h,m) f[next][list[j]][h]=0;
        REP(j,k) REP(h,m) if(f[cur][list[j]][h]){
            int mask=list[j];
            REP(x,cnt) if( ((mask>>x)&1)==0 && (x==0 || num[x-1]!=num[x] || ((mask>>(x-1))&1)==1) )
                if(i<cnt-1 || num[x]!=0)
                    f[next][mask | (1<<x)][(h + p10*num[x])%m] += f[cur][mask][h];
        }   
        p10 = (p10 * 10)%m;
    }
    
    cout<<f[cnt&1][(1<<cnt)-1][0]<<endl;
    return 0;
}
