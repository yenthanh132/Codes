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

int ex[100],ey[100];
int n,m,k;
ll dp[11][1<<10][1<<10];
vector<int> list[10];

int count(int v){
    int res=0;
    while(v){
        res+=v%2;
        v/=2;
    }
    return res;   
}

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    cin>>n>>m>>k;
    FOR(i,1,m){
        cin>>ex[i]>>ey[i];
        ex[i]--; ey[i]--;
    }
    FOR(i,1,(1<<n)-1) list[count(i)].pb(i);
    FOR(i,1,m) dp[2][(1<<ex[i]) | (1<<ey[i])][(1<<ex[i]) | (1<<ey[i])]=1;
    int u,v,id,id2,new_id,new_id2;
    FOR(i,2,n-1){
        for(vector<int>::iterator it=list[i].begin(); it!=list[i].end(); ++it){
            id=*it;
            FOR(j,1,m){
                u=ex[j]; v=ey[j];
                if( ((id>>u)&1) != ((id>>v)&1) ){
                    if((id>>v)&1) swap(u,v);
                    id2=id;
                    new_id=id | (1<<v);
                    while(id2){
                        if(dp[i][id][id2]){
                            new_id2=id2 | (1<<v);
                            if((new_id2>>u)&1) new_id2-=1<<u;
                            dp[i+1][new_id][new_id2]+=dp[i][id][id2]/(i-1);
                        }
                        id2=(id2-1)&id;
                    }
                }
            }
        }
        
    }
    
    ll res=0;
    REP(i,sz(list[k])) res+=dp[n][(1<<n)-1][list[k][i]]/(n-1);
    cout<<res<<endl;
    getch();
    return 0;
}
