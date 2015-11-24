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

int mark[maxn];
int n,cnt;
vector<int> list;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);   
    
    reset(mark,0);
    int x;
    FOR(i,1,n){
        scanf("%d",&x);
        mark[x]=1;
    }
    cnt=0;
    FOR(i,1,1000000){
        if(mark[i] && !mark[1000000-i+1]){
            list.pb(1000000-i+1);
            mark[1000000-i+1]=1;
        }else if(i<=500000 && mark[i] && mark[1000000-i+1]){
            ++cnt;
        }
    }
    x=1;
    while(cnt){
        while(mark[x] || mark[1000000-x+1]) ++x;
        list.pb(x); list.pb(1000000-x+1);
        mark[x]=mark[1000000-x+1]=1;
        ++x;
        --cnt;
    }
    
    printf("%d\n",sz(list));
    REP(i,sz(list)) printf("%d ",list[i]);
    
    return 0;
    

    
}
