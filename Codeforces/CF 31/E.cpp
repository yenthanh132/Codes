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

int a[50],n,trace[50][50];
ll f[50][50],pow10[50];
char s[50];

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    scanf("%s",s+1);
    pow10[0]=1;
    FOR(i,1,18) pow10[i]=pow10[i-1]*10;
    FOR(i,1,n*2) a[i]=s[n*2-i+1]-'0';
    FOR(i,1,n*2)
        FOR(j,0,min(n,i)){
            f[i][j]=-oo;
            if(j>0 && f[i][j] < a[i]*pow10[j-1] + f[i-1][j-1]){
                f[i][j]=a[i]*pow10[j-1] + f[i-1][j-1];
                trace[i][j]=0;
            }
            if(j<min(i,n) && f[i][j] < a[i]*pow10[i-j-1] + f[i-1][j]){
                f[i][j]=a[i]*pow10[i-j-1] + f[i-1][j];
                trace[i][j]=1;
            }
        }
    int x=n;
    FORD(i,n*2,1){
        if(trace[i][x]==0){
            s[n*2-i+1]='H';
            x--;
        }else s[n*2-i+1]='M';
    }
    s[n*2+1]='\0';
    puts(s+1);
    return 0;
}
    
