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

const int maxn=107;
const int maxm=10007;

char a[maxn][maxm];
int n,m;
ll res;
bool ok;

void go(int x, int y, int dir){
    if(x==n-1) return;
    int y1=y, y2=y,pos=y,y1old,y2old;
    if(a[x+1][y]=='.'){
        res++;
        go(x+1,y,dir);
        return;
    }
    while((y1>0 && a[x][y1-1]!='#') || (y2<m-1 && a[x][y2+1]!='#')){
        if(dir==1){
            while(y2+1<m && a[x][y2+1]=='.'){
                y2++;
                if(a[x+1][y2]=='.'){
                    res+=y2-pos+1;
                    go(x+1,y2,dir);
                    return;
                }
            }
            if(y2+1<m && a[x][y2+1]=='+') a[x][y2+1]='.';
            res+=y2-pos+1;
            pos=y2;
        }else{
            while(y1>0 && a[x][y1-1]=='.'){
                y1--;
                if(a[x+1][y1]=='.'){
                    res+=pos-y1+1;
                    go(x+1,y1,dir);
                    return;
                }
            }
            if(y1>0 && a[x][y1-1]=='+') a[x][y1-1]='.';
            res+=pos-y1+1;
            pos=y1;
        }
        dir=1-dir;
    }
    ok=0;
}
            
        
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d\n",&n,&m);
    REP(i,n) gets(a[i]);
    res=0;
    ok=1;
    go(0,0,1);
    if(ok) cout<<res<<endl; else cout<<"Never"<<endl;
    //getch();
    return 0;
}
