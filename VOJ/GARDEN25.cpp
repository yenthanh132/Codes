#include <iostream>
#include <algorithm>
#include <cstdio>
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
#define REP(a,b) for(int a=0;a<b;a++)
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
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

#define maxn 251

int n,m, a[maxn][maxn], deg[maxn*2],b[maxn*2][maxn*2];
bool mark[maxn*2][maxn*2];

void euler(int start){
    int i,j;
    stack<int> mystack;
    vector<int> ds;
    mystack.push(start);
    while (!mystack.empty()){
        i=mystack.top();
        for(j=1;j<=m+n;j++) if (b[i][j]){
            b[i][j]--;b[j][i]--;
            deg[i]--; deg[j]--;
            mystack.push(j);
            break;
        }
        if(j>m+n) ds.pb(mystack.top()), mystack.pop();
    };
    for(i=0;i<sz(ds)-1;i++) if (mark[ds[i]][ds[i+1]])
        if (ds[i]<=m) a[ds[i]][ds[i+1]-m]=1; else a[ds[i+1]][ds[i]-m]=2;
}
void solve(){
    int i,j;
    for(i=1;i<=m+n;i++) if (deg[i]%2==1){
        for(j=i+1;j<=m+n && deg[j]%2==0;j++);
        b[i][j]++; b[j][i]++;
        deg[i]++; deg[j]++;
        i=j;
    }
    do{
        for(i=1;i<=m+n && deg[i]==0;i++);
        if (i<=m+n) euler(i);
    }while (i<=m+n);
    
};
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&m,&n);
    reset(deg,0); reset(mark,false); reset(b,0);
    FOR(i,1,m) FOR(j,1,n){
        scanf("%d",&a[i][j]);
        if (a[i][j]){
            b[i][j+m]++;b[j+m][i]++;
            mark[i][j+m]=mark[j+m][i]=true;
            deg[i]++; deg[j+m]++;
        }
    };
    solve();
    FOR(i,1,m){
        FOR(j,1,n) printf("%d ",a[i][j]);
        printf("\n");
    }
    //getch();
    return 0;
}
