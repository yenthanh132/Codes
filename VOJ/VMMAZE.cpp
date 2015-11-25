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
typedef pair<pii,int> piii;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const int dxX[4][2]={{-1,1},{1,1},{1,-1},{-1,-1}};
const int dyY[4][2]={{-1,-1},{-1,1},{1,1},{1,-1}};
const int idmove[4]={0,1,2,3};

int m,n,k,kt,kn,x,y,res,oldmove,maxX,maxY,minX,minY,cc,d[200][200],trace[200][200],deg[200][200];
bool free1[200][200],locked[200][200],ok;
pii doorpos[200];
vector<int> doorlist;

void visit(int x, int y){
    free1[x][y]=false;
    REP(k,4) deg[x+dx[k]][y+dy[k]]--;
}

bool outsize(int x, int y){
    if(minX+m-3<x || minY+n-3<y || maxX-m+3>x || maxY-n+3>y) return true; else return false;
}

bool checkok(int x, int y){
    REP(k,4) if(free1[x+dx[k]][y+dy[k]] && !outsize(x+dx[k],y+dy[k])) return 1;
    return 0;
}

int nearestdoor(int x, int y){
    int res=oo;
    REP(i,sz(doorlist)) res=min(res,abs(x-doorpos[doorlist[i]].fi)+abs(y-doorpos[doorlist[i]].se));
    return res;
}

bool mycmp(const pii &a, const pii &b){
    return(a.fi>b.fi);
}

vector<int> bfs(int x, int y){
    queue<pii> myqueue;
    pii u;
    int xt,yt,X,Y,k;
    bool found=0;
    myqueue.push(pii(x,y));
    d[x][y]=++cc; trace[x][y]=0;
    while(!myqueue.empty()){
        u=myqueue.front();myqueue.pop();
        REP(k,4){
            xt=u.fi+dx[k]; yt=u.se+dy[k];
            if(outsize(xt,yt) || locked[xt][yt] || d[xt][yt]==cc) continue;
            d[xt][yt]=cc;
            trace[xt][yt]=k;
            if(checkok(xt,yt)){
                found=1;
                X=xt; Y=yt;
                break;
            }
            myqueue.push(pii(xt,yt));
        }
        if(found) break;
    }
    vector<int> movelist;
    while(X!=x || Y!=y){
        k=trace[X][Y];
        movelist.pb(k);
        X-=dx[k]; Y-=dy[k];
    }
    reverse(movelist.begin(), movelist.end());
    return movelist;
}

int main(){
    srand(time(NULL));
    cc=0; reset(d,0); 
    reset(free1,true); reset(locked,false);
    x=y=minX=minY=maxX=maxY=100; visit(x,y);
    res=-1; oldmove=-1;
    REP(i,200) REP(j,200) deg[i][j]=4;
    
    cin>>m>>n>>k; kt=kn=0;
   
    while(1){
        /*FOR(i,99,104){
            FOR(j,99,106) if(locked[i][j]) cout<<'x'; else if(i==x && j==y) cout<<'S'; else cout<<'.';
            cout<<endl;
        }*/
        minX=min(minX,x); minY=min(minY,y);
        maxX=max(maxX,x); maxY=max(maxY,y);
        
        //Dat cua
        /*if(kt==0 || (kt<k && nearestdoor(x,y)>=int(sqrt((m-1)*(n-1))) && deg[x][y]>1)){
            doorpos[++kt]=pii(x,y);
            doorlist.pb(kt);
            cout<<"4 "<<kt<<' ';
            fflush(stdout);
            cin>>res;
            continue;
        }*/
            
        
        // Di chuyen thang tien
        
        if(oldmove!=-1 && free1[x+dx[oldmove]][y+dy[oldmove]] && !outsize(x+dx[oldmove],y+dy[oldmove])){
            int xt=x+dx[oldmove], yt=y+dy[oldmove];
            visit(xt,yt);
            cout<<idmove[oldmove]<<' ';
            fflush(stdout);
            cin>>res;
            if(res==999) return 0;
            else if(res==0) locked[xt][yt]=1;
            else{
                x=xt; y=yt;
                continue;
            }
        }
            
        ok=false;
        
        // Di chuyen 4 huong
        vector<pii> move;
        REP(k,4){
            int xt=x+dx[k], yt=y+dy[k];
            if(k!=oldmove && free1[xt][yt] && !locked[xt][yt] && !outsize(xt,yt))
                move.pb(pii(deg[xt][yt],k));
        }
        if(!move.empty()){
            pii arr[4];
            int dem=sz(move);
            REP(i,dem) arr[i]=move[i];
            sort(arr,arr+dem); 
            /*REP(index,2){
                int u=rand()%dem, v=rand()%dem;
                if(arr[u].fi==arr[v].fi) swap(arr[u].se,arr[v].se);
            }*/
            REPD(k,dem){
                int xt=x+dx[arr[k].se], yt=y+dy[arr[k].se];
                cout<<idmove[arr[k].se]<<' ';
                visit(xt,yt);
                fflush(stdout);
                cin>>res;
                if(res==999) return 0;
                else if(res==0) locked[xt][yt]=1;
                else{
                    x=xt; y=yt;
                    oldmove=arr[k].se;
                    ok=true;
                    break;
                }
            }
        }
         
        if(ok) continue;
        
        // Di chuyen ve cua gan nhat
        
        vector<int> movelist=bfs(x,y);
        
        /*while(!doorlist.empty() && deg[doorpos[doorlist.back()].fi][doorpos[doorlist.back()].se]==0) doorlist.pop_back() ;
        if(!doorlist.empty() && nearestdoor(x,y)<=sz(movelist)*2){
            cout<<"6 "<<doorlist.back()<<' ';
            fflush(stdout);
            cin>>res;
            x=doorpos[doorlist.back()].fi; y=doorpos[doorlist.back()].se;
            ok=true;
        }
        
        
        if(ok) continue;*/
        
        //Di chuyen ve vi tri co duong di
        
        REP(i,sz(movelist)){
            cout<<idmove[movelist[i]]<<' ';
            fflush(stdout);
            cin>>res;
            x+=dx[movelist[i]]; y+=dy[movelist[i]];
            oldmove=-1;
        }
    }
    return 0;
}


