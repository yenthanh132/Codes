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

string a[37][37],t;
int n,m,k;
char buf[5];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) FOR(j,1,m) a[i][j]="";
    int x,y;
    REP(index,k){
        scanf("%s",buf);
        if(buf[0]=='+'){
            scanf("%d%d",&x,&y);
            cin>>t;
            while(x<=n){
                if(a[x][y]=="") break;
                if(y<m) y++; else{
                    x++;
                    y=1;
                }
            }
            if(x<=n) a[x][y]=t;
        }else{
            cin>>t;
            for(x=1;x<=n;x++) for(y=1;y<=m;y++) if(a[x][y]==t) goto labelout;
        labelout:
            if(x<=n) a[x][y]="";
            if(x<=n) printf("%d %d\n",x,y); else puts("-1 -1");
        }
    }
    return 0;
}    
            
    
