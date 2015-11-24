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

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int n,d,v1,v2;
    cin>>n>>d;
    cin>>v1;
    ll res=0;
    REP(i,n-1){
        cin>>v2;
        if(v1>=v2){
            res=res+(v1-v2)/d+1;
            v1=v2+((v1-v2)/d+1)*d;
        }else v1=v2;
    }
    cout<<res;
    //getch();
    return 0;
}
