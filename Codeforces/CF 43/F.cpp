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

int n,m,k;
bool room2key[maxn][maxn];
vector<int> personInRoom[maxn],keyInRoom[maxn];
vector<int> list[maxn];
map<string,int> id;
vector<pii> a[maxn];
vector<int> a2[maxn];
bool free1[maxn];


int lab[maxn];
bool data[2][3][maxn][maxn];
vector<int> mylist[3];

int getroot(int u){
    if(lab[u]<0) return u;
    lab[u]=getroot(lab[u]);
    return lab[u];
}

int dsu(int r1, int r2){
    if(r1==r2) return -1;
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;   
        FOR(key,1,m) room2key[r1][key]|=room2key[r2][key];
        REP(i,sz(list[r2])) list[r1].pb(list[r2][i]);
        return r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
        FOR(key,1,m) room2key[r2][key]|=room2key[r1][key];
        REP(i,sz(list[r1])) list[r2].pb(list[r1][i]);
        return r2;
    }
}

int dfs(int u){
    free1[u]=0;
    int v;
    mylist[0].pb(u);
    REP(i,sz(keyInRoom[u])) mylist[1].pb(keyInRoom[u][i]);
    REP(i,sz(personInRoom[u])) mylist[2].pb(personInRoom[u][i]);
    REP(i,sz(a2[u])){
        v=a2[u][i];
        if(free1[v]) dfs(v);
    }
}

queue<int> myq;

void build(int id){
    reset(free1,1);
    FOR(i,1,n){
        lab[i]=-1;
        myq.push(i);
        list[i].clear();
        list[i].pb(i);
        a2[i].clear();
        free1[i]=0;
    }
    
    while(!myq.empty()){
        int u=myq.front(); myq.pop();
        
        int r=getroot(u);
        
        free1[r]=1;
        bool need_break=0;
        REP(i,sz(list[r])){
            int v=list[r][i];
            REP(j,sz(a[v]))
                if(room2key[r][a[v][j].se]){
                    int r2=dsu(r,getroot(a[v][j].fi));
                    if(r2!=-1){
                        if(free1[r2]){
                            myq.push(r2);
                            free1[r2]=0;
                        }
                        a2[v].pb(a[v][j].fi);
                        a2[a[v][j].fi].pb(v);
                        need_break=1;
                        break;
                    }                    
                }
            if(need_break) break;
        }
        
    }   
    
    reset(free1,1);
    FOR(i,1,n) if(free1[i]){
        REP(j,3) mylist[j].clear();
        int cc=0;
        dfs(i);
        REP(u,2) FOR(v,u+1,2){
            REP(x,sz(mylist[u])) REP(y,sz(mylist[v])){
                data[id][cc][mylist[u][x]][mylist[v][y]]=1;
            }
            cc++;   
        }
    }      
    
}

bool check(){
    REP(i,3) REP(x,1000) REP(y,1000) if(data[0][i][x][y]!=data[1][i][x][y]) return 0;
    return 1;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    int u,v;
    FOR(i,1,m){
        cin>>u>>v;
        a[u].pb(pii(v,i));
        a[v].pb(pii(u,i));
    }
    reset(data,0);
    
    
    reset(room2key,0);
    FOR(i,1,n) personInRoom[i].clear(), keyInRoom[i].clear();
    FOR(i,1,k){
        string name;
        cin>>name;
        id[name]=i;
        int room;
        cin>>room;
        personInRoom[room].pb(i);
        int cntKey;
        cin>>cntKey;        
        REP(j,cntKey){
            int v;
            cin>>v;
            keyInRoom[room].pb(v);
            room2key[room][v]=1;
        }
    }
    build(0);
    
    
    reset(room2key,0);
    FOR(i,1,n) personInRoom[i].clear(), keyInRoom[i].clear();
    FOR(ii,1,k){
        string name;
        cin>>name;
        int i=id[name],room;
        cin>>room;
        personInRoom[room].pb(i);
        int cntKey;
        cin>>cntKey;        
        REP(j,cntKey){
            int v;
            cin>>v;
            keyInRoom[room].pb(v);
            room2key[room][v]=1;
        }
    }
    build(1);
    
    if(check()) cout<<"YES"; else cout<<"NO";
    cout<<endl;
    
    //getch();
    return 0;
}
