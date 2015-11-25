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
const int maxv=5007;

int n,move[maxv][maxn];
ll s,a[maxn],f[maxn][maxv];
vector<ll> p;

ll gcd(ll a, ll b){
    if(b==0) return a;
    if(a<b) return gcd(b,a);
    return gcd(b,a%b);
}

int dp(int i, int j){
    if(j==-1) return (n-i)%2==0;
    if(i>n) return 0;
    if(j==sz(p)-1) return 0;
    if(f[i][j]!=-1) return f[i][j];
    f[i][j]=0;
    int c=0;
    FOR(z,1,n) if(p[j]%a[z]==0) c++;
    else
        if(dp(i+1,move[j][z])==0) f[i][j]=1;
    if(c>=i && dp(i+1,j)==0) f[i][j]=1;
    return f[i][j];
}       

//#include <conio.h>   

int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>s;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,int(sqrt(s))) if(s%i==0){
        p.pb(i);
        if(i*i!=s) p.pb(s/i);
    }
    
    
    sort(p.begin(),p.end());
    reset(f,-1);
    ll lcm;
    int pos;
    REP(i,sz(p))
        FOR(j,1,n){
            lcm=p[i]/gcd(p[i],a[j])*a[j];
            pos=lower_bound(p.begin(),p.end(),lcm)-p.begin();
            if(pos<sz(p) && p[pos]==lcm) move[i][j]=pos;
            else move[i][j]=-1;
        }
    if(dp(1,0)){
        puts("Raldono");
        FOR(i,1,n) if(dp(2,move[0][i])==0) printf("%d ",i);
    }else{
        puts("Balitello");
        FOR(i,1,n){
            int v;
            if(move[0][i]==-1){
                printf("%d ",(i==1?2:1));
            }else{
                FOR(j,1,n) if(i!=j && dp(3,move[move[0][i]][j])==0){
                    v=j;
                    break;
                }
                printf("%d ",v);
            }
        }
    }
    
    //getch();
    return 0;
}
    
