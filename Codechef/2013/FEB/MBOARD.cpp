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

const int maxn=500007;

int row[2][maxn],col[2][maxn],n,q,vrow[maxn],vcol[maxn],trow[maxn],tcol[maxn];
char buf[10];
void update(int *BIT, int p, int v){
    p++;
    for(int i=p; i; i-=i&(-i)) BIT[i]+=v;
}

int get(int *BIT, int p){
    p++;
    int ans=0;
    for(int i=p; i<=q+1; i+=i&(-i)) ans+=BIT[i];
    return ans;
}
    
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&q);
    int x,y;
    FOR(tt,1,q){
        scanf("%s",buf);
        if(buf[3]=='S'){
            scanf("%d%d",&x,&y);
            if(buf[0]=='R'){
                if(trow[x]) update(col[1^vrow[x]],trow[x],1);
                update(col[1^y],tt,-1);
                vrow[x]=y;
                trow[x]=tt;
            }else{
                if(tcol[x]) update(row[1^vcol[x]],tcol[x],1);
                update(row[1^y],tt,-1);
                vcol[x]=y;
                tcol[x]=tt;
            }
        }else{
            scanf("%d",&x);
            if(buf[0]=='R'){
                if(vrow[x]==0) printf("%d\n",n+get(row[0],trow[x]));
                else printf("%d\n",-get(row[1],trow[x]));
            }else{
                if(vcol[x]==0) printf("%d\n",n+get(col[0],tcol[x]));
                else printf("%d\n",-get(col[1],tcol[x]));
            }
        }
    }
    //getch();
    return 0;
}
