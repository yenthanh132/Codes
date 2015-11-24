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

const int maxn=100007;

int n,a[maxn],next[maxn];

queue<int> myq,myq2;
#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    a[n+1]=oo;
    FORD(i,n,1){
        if(i==n) next[i]=n+1;
        else next[i]=i+1;
        if(a[i]>a[next[i]]){
            myq.push(i);
            myq2.push(1);
        }
    }
    
    int res=0;
    while(!myq.empty()){
        int u=myq.front(); myq.pop();
        int t=myq2.front(); myq2.pop();
        res=max(res,t);
        next[u]=next[next[u]];
        if(a[u]>a[next[u]]){
            myq.push(u);
            myq2.push(t+1);
        }   
    }
    cout<<res<<endl;
    getch();
    return 0;   
}
