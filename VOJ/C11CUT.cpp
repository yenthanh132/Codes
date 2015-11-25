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

int a[5][5],d[5][5],m,n;
bool mark[5][5];
int res;

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&m,&n);
    FOR(i,1,m) FOR(j,1,n) scanf("%d",&a[i][j]);
    res=0;
    int sum,t;
    REP(id,1<<(m*n)){
        REP(j,m*n) d[j/n+1][j%n+1]=(id>>j)&1;
        reset(mark,1); sum=0;
        FOR(i,1,m) FOR(j,1,n) if(mark[i][j])
            if(d[i][j]){
                t=a[i][j];
                mark[i][j]=0;
                for(int j2=j+1; j2<=n && d[i][j2]==d[i][j]; j2++) 
                    t=t*10+a[i][j2], mark[i][j2]=0;
                sum+=t;
            }else{
                t=a[i][j];
                mark[i][j]=0;
                for(int i2=i+1; i2<=m && d[i2][j]==d[i][j]; i2++)
                    t=t*10+a[i2][j], mark[i2][j]=0;
                sum+=t;
            }
        res=max(res,sum);
    }
    cout<<res<<endl;
    return 0;
}
