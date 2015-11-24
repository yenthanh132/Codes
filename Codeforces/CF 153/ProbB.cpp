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

int n,k;
vector<int> q,s,r;

vector<int> move1(vector<int> a){
    vector<int> res(n+1,0);
    FOR(i,1,n) res[i]=a[q[i]];
    return res;
}

vector<int> move2(vector<int> a){
    vector<int> res(n+1,0);
    FOR(i,1,n) res[q[i]]=a[i];
    return res;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>k;
    q.resize(n+1,0); s.resize(n+1,0);
    FOR(i,1,n) cin>>q[i];
    FOR(i,1,n) cin>>s[i];
    r.resize(n+1,0);
    FOR(i,1,n) r[i]=i;
    if(r==s){
        puts("NO");
        return 0;
    }
    
    int dis1,dis2;
    bool ok1=0,ok2=0;
    for(dis1=1; dis1<=k; dis1++){
        r=move1(r);
        if(r==s){
            ok1=1;
            break;
        }
    }
    FOR(i,1,n) r[i]=i;
    for(dis2=1; dis2<=k; dis2++){
        r=move2(r);
        if(r==s){
            ok2=1;
            break;
        }
    }
    if( (ok1 && (k-dis1)%2==0 && (k-dis1==0 || dis2>1 || dis1>1)) ||
     (ok2 && (k-dis2)%2==0 && (k-dis2==0 || dis1>1 || dis2>1))) puts("YES"); else puts("NO");
    //getch();
    return 0;
}
    
