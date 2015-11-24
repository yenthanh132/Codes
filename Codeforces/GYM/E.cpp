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

const int dx[4]={-2,-2,2,2};
const int dy[4]={-2,2,2,-2};

int id[8][8],r,w,m;
int a[8][8];
pii pos[50];

int move(int u, int v, int color, bool &promoted, bool &attack){
    promoted=false;
    attack=0;
    int x1=pos[u].fi, y1=pos[u].se;
    if(abs(a[x1][y1])!=color) return 0;
    int x2=pos[v].fi, y2=pos[v].se;
    if(a[x1][y1]==0) return 0;
    if(a[x2][y2]) return 0;
    if(abs(x1-x2)==1 && abs(y1-y2)==1){
        if(a[x1][y1]<0)
            if((a[x1][y1]==-1 && x2<x1) || (a[x1][y1]==-2 && x2>x1)) return 0;            
        a[x2][y2]=a[x1][y1];
        a[x1][y1]=0;
        if(abs(a[x2][y2])==1 && x2==7){
            a[x2][y2]=1;
            promoted=1;
        }
        if(abs(a[x2][y2])==2 && x2==0){
            a[x2][y2]=2;
            promoted=1;
        }
        return 1;
    }
    if(abs(x1-x2)==2 && abs(y1-y2)==2){
        int x3=(x1+x2)/2, y3=(y1+y2)/2;
        if(a[x3][y3]==0 || abs(a[x3][y3])==abs(a[x1][y1])) return 0;
        if(a[x1][y1]<0)
            if((a[x1][y1]==-1 && x2<x1) || (a[x1][y1]==-2 && x2>x1)) return 0;
        a[x2][y2]=a[x1][y1];
        a[x1][y1]=0;
        a[x3][y3]=0;
        if(abs(a[x2][y2])==1 && x2==7){
            a[x2][y2]=1;
            promoted=1;
        }
        if(abs(a[x2][y2])==2 && x2==0){
            a[x2][y2]=2;
            promoted=1;
        }
        attack=1;
        return 2;
    }
}

bool canmove(int u){
    int x=pos[u].fi, y=pos[u].se, xt,yt, x2,y2;
    REP(k,4){
        xt=x+dx[k]; yt=y+dy[k];
        x2=x+dx[k]/2; y2=y+dy[k]/2;
        if(0<=xt && xt<8 && 0<=yt && yt<8){
            if(a[xt][yt]==0 && a[x2][y2]!=0 && abs(a[x2][y2])!=abs(a[x][y]))
                if(a[x][y]>0 || ((a[x][y]==-1 && xt>x) || (a[x][y]==-2 && xt<x)))
                    return 1;                    
        }
    }
    return 0;
}

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    int t=0,flag=0;
    REP(x,8) REP(y,8){
        if(flag){
            id[x][y]=++t;
            pos[t]=pii(x,y);
        }
        if(y!=7) flag^=1;
    }
    cin>>r>>w;
    while(r!=0){
        REP(x,8) REP(y,8) a[x][y]=0;
        FOR(i,1,r){
            cin>>t;
            if(t<0)
                a[pos[-t].fi][pos[-t].se]=1;
            else
                a[pos[t].fi][pos[t].se]=-1;
        }
        FOR(i,1,w){
            cin>>t;
            if(t<0)
                a[pos[-t].fi][pos[-t].se]=2;
            else
                a[pos[t].fi][pos[t].se]=-2;
        }
        cin>>m;
        int mark=0,color;
        string s,st;
        vector<int> list;
        bool promoted,attacked,tmp,can_jump;
        
        cin>>s;
        if(s[0]=='R') color=1; else color=2;
        FOR(i,1,m){
            
            cout<<i<<endl;
            REP(x,8){
                REP(y,8) printf("%2d ",a[x][y]);
                cout<<endl;
            }
            
            cin>>s;
            if(mark) continue;
            list.clear();
            while(s.find("-")!=-1){
                st=s.substr(0,s.find("-"));
                s.erase(0,s.find("-")+1);
                list.pb(atoi(st.c_str()));   
            }
            list.pb(atoi(s.c_str()));
            attacked=0;
            can_jump=0;
            if(sz(list)==2){
                REP(x,8) REP(y,8) if(abs(a[x][y])==color && id[x][y]!=list[0] && canmove(id[x][y])) can_jump=1;
            }
            REP(j,sz(list)-1){
                t=move(list[j],list[j+1],color,promoted,tmp);
                
                if(t==0 || (sz(list)>2 && !tmp) || (sz(list)==2 && !tmp && can_jump)){
                    mark=i;
                    break;
                }
                attacked|=tmp;
                if(j<sz(list)-2 && promoted){
                    mark=i;
                    break;
                }                
            }
            if(attacked && !mark && !promoted && canmove(list.back())) mark=i;
            color=3-color;
        }
        if(!mark) printf("All moves valid\n");
        else printf("Move %d is invalid\n",mark);
        
        cin>>r>>w;
    }
    
    getch();
    return 0;
}
    
