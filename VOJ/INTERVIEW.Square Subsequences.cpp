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

#define maxn 201
#define BASE 1000000007

char s[maxn];
int test,n,f[maxn][maxn],res;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d\n",&test);
    REP(index,test){
        scanf("%s\n",&s);
        n=strlen(s);
        res=0;
        FOR(i,2,n){
            reset(f,0); 
            FOR(j,1,i-1) if(s[j-1]==s[i-1]) f[j][i]=1;
            FOR(x,1,i-1) FOR(y,i,n){
                f[x][y]=(f[x][y]+f[x-1][y]+f[x][y-1]-f[x-1][y-1])%BASE;
                if(s[x-1]==s[y-1]) f[x][y]=(f[x][y]+f[x-1][y-1])%BASE;
            }
            res=(res+f[i-1][n])%BASE;
        }
        printf("%d\n",res);
    }
    //getch();
    return 0;
}
