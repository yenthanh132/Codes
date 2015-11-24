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

const int maxn = 50;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int n;
struct state{char a[maxn][maxn];} root;
struct move{int x1,y1,x2,y2;};

bool found_move(state a){
    int x1,y1,x2,y2,res=0;
    bool ok;
    REP(x,n) REP(y,n) if(a.a[x][y]=='*'){
        ok=0;
        REP(k,4){
            x1=x+dx[k]; y1=y+dy[k];
            x2=x1+dx[k]; y2=y1+dy[k];
            if(x2>=0 && x2<n && y2>=0 && y2<n && a.a[x2][y2]=='.' && a.a[x1][y1]=='*') ok=1;
        }
        if(ok) res++;
    }
    return res;
}

state change(state a, int x1, int y1, int x2, int y2){
    a.a[x1][y1]='.';
    a.a[x2][y2]='*';
    a.a[(x1+x2)/2][(y1+y2)/2]='.';
    return a;
}

vector<move> count_move(state a){
    int x1,y1,x2,y2,v,minv=oo;
    vector<move> list;
    move t;
    REP(x,n) REP(y,n) if(a.a[x][y]=='*')
        REP(k,4){
            x1=x+dx[k]; y1=y+dy[k];
            x2=x1+dx[k]; y2=y1+dy[k];
            if(x2>=0 && x2<n && y2>=0 && y2<n && a.a[x2][y2]=='.' && a.a[x1][y1]=='*'){
                v=found_move(change(a,x,y,x2,y2));
                t.x1=x; t.y1=y; t.x2=x2; t.y2=y2;
                if(v<minv){
                    list.clear();
                    list.pb(t);
                    minv=v;
                }else if(v==minv) list.pb(t);
            }
        }
    return list;
}

//#include <conio.h>
int main(){
    srand(time(NULL));
    
    //freopen("test.txt","r",stdin);
    
    scanf("%d\n",&n);
    REP(i,n) gets(root.a[i]);
    int pos;
    move t;
    vector<move> res;
    while(found_move(root)){    
        vector<move> list=count_move(root);
        pos=rand()%sz(list);
        t=list[pos];
        res.pb(list[pos]);

        root=change(root,t.x1,t.y1,t.x2,t.y2);  
    }

    printf("%d\n",sz(res));
    REP(i,sz(res)){
        t=res[i];
        printf("%d %d %d %d\n",t.y1,t.x1,t.y2,t.x2);      
    }
    //getch();
    return 0;
}
        
