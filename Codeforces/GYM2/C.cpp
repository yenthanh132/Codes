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

const int maxn=1000007;
const int maxv=1000000;

bool isprime[maxn];
int p[80000],cnt,pos[maxn];
deque<int> list[80000];
vector<int> factors;

int find(int v){
    int l=1, r=cnt, mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(p[mid]==v) return mid;
        else if(v<p[mid]) r=mid-1;
        else l=mid+1;
    }
    return -1;
}

int check(){
    int maxv=0;
    FOR(v,1,300000) if(pos[v]==0) return 0;
    return 1;
}

void init(){
    isprime[2]=1;
    for(int i=3; i<=maxv; i+=2) isprime[i]=1;
    for(int i=3; i*i<=maxv; i+=2) if(isprime[i])
        for(int j=i*i; j<=maxv; j+=2*i) isprime[j]=0;
    p[cnt=1]=2;
    for(int i=3; i<=maxv; i+=2) if(isprime[i]) p[++cnt]=i;   
    
    reset(pos,0);
    int t;
    for(int v=2; v<=maxv; v++){
        t=v;
        for(int i=1; i<=cnt && p[i]*p[i]<=t; ++i) 
            if(t%p[i]==0){
                list[i].pb(v);
                while(t%p[i]==0) t/=p[i];
            }
        if(t>1) list[find(t)].pb(v);
    }
    
    pos[1]=1;
    pos[2]=2;
    int v=2,minv,val;
    
    FOR(step,3,584898){
        t=v;
        minv=oo;
        factors.clear();
        for(int i=1; i<=cnt && p[i]*p[i]<=t; ++i) 
            if(t%p[i]==0){
                if(!list[i].empty()){
                    val=list[i].front();
                    while(pos[val]){
                        list[i].pop_front();
                        if(list[i].empty()) break;
                        val=list[i].front();
                    }
                    if(!list[i].empty()) minv=min(minv,val);
                }
                factors.pb(i);
                while(t%p[i]==0) t/=p[i];
            }  
        if(t>1){
            int i=find(t);
            if(!list[i].empty()){
                val=list[i].front();
                while(pos[val]){
                    list[i].pop_front();
                    if(list[i].empty()) break;
                    val=list[i].front();
                }
                if(!list[i].empty()) minv=min(minv,val);
            }
            factors.pb(i);
        }
        pos[minv]=step;
        REP(i,sz(factors)) if(!list[i].empty() && list[i].front()==minv) list[i].pop_front();
        v=minv;
    }
    
        
}

int main(){
    init();
    //cout<<check()<<' '<<1.0*clock()/CLOCKS_PER_SEC;
    int v;
    cin>>v;
    while(v){
        printf("The number %d appears in location %d.\n",v,pos[v]);
        cin>>v;
    }
    return 0;
}    
