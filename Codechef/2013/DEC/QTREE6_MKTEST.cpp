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


const int N=1000;
const int M=1000;
int lab[N+1];

int getroot(int u){
    if(lab[u]<0) return u;
    lab[u]=getroot(lab[u]);
    return lab[u];   
}

void dsu(int r1, int r2){
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;   
    }else{
        lab[r2]+=lab[r1];
        lab[r2]=r1;   
    }
}

int main(){
    srand(time(NULL));
    ios::sync_with_stdio(0);
    freopen("input.txt","w",stdout);
    cout<<N<<endl;
    FOR(i,1,N) lab[i]=-1;
    int u,v,r1,r2;
    
    REP(i,N-1){
        u=rand()%(i+1)+1;
        v=i+2;
        if(u>=v) u=v-1;
        cout<<u<<' '<<v<<endl;
    }
    cout<<M<<endl;
    REP(i,M){
        cout<<rand()%2<<' '<<rand()%N+1<<endl;   
    }
    
    return 0;
    REP(i,N-1){
        u=rand()%(2)+1;
        v=i+2;
        if(u>=v) u=v-1;
        cout<<u<<' '<<v<<endl;
    }
    cout<<M<<endl;
    REP(i,M){
        cout<<rand()%2<<' '<<rand()%2+1<<endl;   
    }
}
