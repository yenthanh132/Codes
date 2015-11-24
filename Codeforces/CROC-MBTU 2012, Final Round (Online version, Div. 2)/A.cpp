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

int n,a[maxn];
vector<int> list;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    int i,j,v;
    i=1;
    while(i<=n){
        j=i; v=(a[i]<0);
        while(j<n && (v<2 || (v==2 && a[j+1]>=0))){
            j++;
            if(a[j]<0) v++;
        }
        list.pb(j-i+1);
        i=j+1;
    }
    printf("%d\n",sz(list));
    REP(i,sz(list)) printf("%d ",list[i]);
    //getch();
    return 0;
}
            
    
