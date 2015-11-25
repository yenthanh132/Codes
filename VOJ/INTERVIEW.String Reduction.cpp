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

#define maxn 101

bool f[maxn][maxn][3];
int g[maxn][maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int test,n;
    string s;
    scanf("%d\n",&test);
    REP(i,test){
        getline(cin,s);
        n=s.length();
        reset(f,false);
        FOR(i,1,n) f[i][i][s[i-1]-'a']=true;
        FOR(len,2,n)
            FOR(i,1,n-len+1){
                int j=i+len-1;
                FOR(k,i,j-1) FOR(x,0,1) FOR(y,x+1,2) if((f[i][k][x] && f[k+1][j][y]) || (f[i][k][y] && f[k+1][j][x]))
                    f[i][j][3-x-y]=true;
            }
        FOR(i,1,n) FOR(j,i,n){
            bool ok=false;
            FOR(x,0,2) if(f[i][j][x]){ok=true; break;}
            if (ok) g[i][j]=1; else g[i][j]=j-i+1;
        }
        FOR(len,2,n)
            FOR(i,1,n-len+1){
                int j=i+len-1;
                FOR(k,i,j-1) g[i][j]=min(g[i][j],g[i][k]+g[k+1][j]);
            }
        cout<<g[1][n]<<endl;
    }
    //getch();
    return 0;
}
                
        
