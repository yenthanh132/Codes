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
const int base=73471;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

vector<ll> list;
int m,n,k,a[maxn][maxn],cnt,res;
pii v[20],t[20];
bool free1[20][20];
struct node{pii a[7];} move[400];

void duyet(int i){
    if(i>k){
        FOR(i,1,k) t[i]=v[i];
        sort(t+1,t+k+1);
        ll val=0;
        FOR(i,1,k) val=(val*13+t[i].fi)*13+t[i].se;
        list.pb(val);
        return;
    }
    set<pii> s;
    s.clear();
    int x,y;
    FOR(j,1,i-1)
        REP(k,4){
            x=dx[k]+v[j].fi;
            y=dy[k]+v[j].se;
            if(y>=1 && free1[x][y] && !(x<6 && y==1))
                s.insert(pii(x,y));
        }
    for(set<pii>::iterator it=s.begin(); it!=s.end(); it++){
        v[i]=*it;
        free1[it->fi][it->se]=0;
        duyet(i+1);
        free1[it->fi][it->se]=1;
    }
}

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&m,&n,&k);
    FOR(i,1,m) FOR(j,1,n) scanf("%d",&a[i][j]);
    reset(free1,1);
    v[1]=pii(6,1);
    free1[6][1]=0;
    duyet(2);
    free1[6][1]=1;
    sort(list.begin(),list.end());
    list.resize(unique(list.begin(),list.end())-list.begin());
    cnt=sz(list);
    ll val;
    REP(i,cnt){
        val=list[i];
        FOR(j,1,k){
            move[i].a[j].se=val%13-1;
            val/=13;
            move[i].a[j].fi=val%13-6;
            val/=13;
        }
    }
    
    res=0;
    bool ok;
    FOR(i,1,m) FOR(j,1,n) if(!a[i][j])
        REP(z,cnt){
            ok=1;
            FOR(ii,1,k){
                v[ii].fi=i+move[z].a[ii].fi;
                v[ii].se=j+move[z].a[ii].se;
                if(v[ii].fi<1 || v[ii].fi>m || v[ii].se<0 || v[ii].se>n || a[v[ii].fi][v[ii].se]){
                    ok=0;
                    break;
                }
            }
            if(ok) res++;
        }
    cout<<res<<endl;
   
    return 0;
}
