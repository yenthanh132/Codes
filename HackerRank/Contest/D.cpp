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

const int maxn=1007;

struct node{
    char mud[7];
    int id, x,y;
}war[maxn*maxn];

double val[maxn][maxn],sum[maxn];
char arr[maxn][maxn];
int w,h,n,p,mark[maxn][maxn];
vector<pii> best,list;

bool cmp(const node &a, const node &b){
    int x,y;
    x=(a.x!=-1);
    y=(b.x!=-1);
    if(x>y) return 1;
    if(x<y) return 0;
    x=(a.mud[0]=='t');
    y=(b.mud[0]=='t');
    if(x<y) return 1;
    if(x>y) return 0;
    return sum[a.id]<sum[b.id];
}
    
double cal(int x, int y, int id){
    double res=0;
    FOR(i,1,h) FOR(j,1,w) if(mark[i][j])
        res+=val[id][mark[i][j]]/(abs(i-x)+abs(j-y));
    return res;
}

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d%d%d%d",&w,&h,&n,&p);
    FOR(i,1,h) scanf("%s",arr[i]+1);
    string st;
    FOR(i,1,n){
        scanf("%d%s",&war[i].id,&war[i].mud);
        war[i].id++;
        getline(cin,st);
        if(sz(st)>=3){
            stringstream ss;
            ss<<st;
            ss>>war[i].y>>war[i].x;
            war[i].y++; war[i].x++;
        }
        else war[i].x=-1;
    }
    int u,v;
    double tmp;
    FOR(i,1,p){
        scanf("%d%d%lf",&u,&v,&tmp);
        u++; v++;
        val[u][v]=tmp;
    }
    FOR(i,1,n){
        sum[i]=0;
        FOR(j,1,n) sum[i]+=val[i][j];
    }
    
    reset(mark,0);
    sort(war+1,war+n+1,cmp);
    list.resize(n+6);
    FOR(i,1,n) if(war[i].x!=-1){
        if(mark[war[i].x][war[i].y] || arr[war[i].x][war[i].y]=='.' || (war[i].mud[0]!='t' && arr[war[i].x][war[i].y]=='M')){
            puts("error");
            return 0;
        }
        list[war[i].id]=pii(war[i].x,war[i].y);
        mark[war[i].x][war[i].y]=war[i].id;
    }else{
         double maxval=-oo;
         int xt,yt;
         FOR(x,1,h) FOR(y,1,w) if(!mark[x][y])
            if(arr[x][y]=='D' || (arr[x][y]=='M' && war[i].mud[0]=='t')){
                tmp=cal(x,y,war[i].id);
                if(tmp>maxval){
                    maxval=tmp;
                    xt=x; yt=y;
                }
            }
        if(maxval<0){
            puts("error");
            return 0;
        }
        mark[xt][yt]=war[i].id;
        list[war[i].id]=pii(xt,yt);    
    }
    
    FOR(i,1,n) printf("%d %d %d\n",i-1,list[i].se-1,list[i].fi-1);
    
    getch();
    return 0;   
}
