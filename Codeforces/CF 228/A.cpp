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

const int maxn=111;
int a[maxn],n,c,d[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    c=0;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    reset(d,0);
    sort(a+1,a+n+1);
    FOR(i,1,n){
        int u=-1;
        FOR(j,1,c){
            if(d[j]<=a[i]){
                u=j;
                break;
            }
        }
        if(u!=-1) d[u]++;
        else d[++c]=1;
    }
    cout<<c<<endl;
    return 0;
}
