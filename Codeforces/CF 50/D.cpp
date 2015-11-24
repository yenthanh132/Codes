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

int n,k,next[107][107],m;
char mark[107],p[107];

bool dp[107][107];
int trace[107][107],ch[107][107];
bool check[107];
string res;

bool build(){
    m=strlen(p+1);
    reset(check,0);
    FOR(i,1,n-m+1) if(mark[i]=='1') check[i+m-1]=1;
    
    reset(next,0);
    FOR(i,1,m){
        int prefix=next[i-1][p[i]-'a'];
        next[i-1][p[i]-'a']=i;
        REP(j,k) next[i][j]=next[prefix][j];
    }
    
    reset(dp,0);
    dp[0][0]=1;
    FOR(i,0,n-1) FOR(j,0,m) if(dp[i][j]){
        REP(x,k){
            int y=next[j][x];
            if((y<m && !check[i+1]) || (y==m && check[i+1])){
                dp[i+1][y]=1;
                ch[i+1][y]=x;
                trace[i+1][y]=j;
            }
        }
    }
    int u=-1;
    FOR(i,0,m) if(dp[n][i]){
        u=i;
        break;
    }
    if(u==-1) return 0;
    
    res="";
    FORD(i,n,1){
        res = char(ch[i][u]+'a') + res;
        u=trace[i][u];
    }
    
    return 1;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>k;
    scanf("%s",p+1);
    scanf("%s",mark+1);
    if(build()) cout<<res<<endl;
    else cout<<"No solution"<<endl;
    //getch();
    return 0;
}
