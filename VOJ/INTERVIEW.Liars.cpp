#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
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
typedef pair<int, int> ii;
typedef pair<ii,int> iii;

#define maxn 107
#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    int n,m;
    vector<iii> a;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        a.pb(iii(ii(x,y),c));
    }
    
}
        
    
