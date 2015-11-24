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

const int maxn=27;

int a[maxn];

//#include <conio.h>
int main(){
    int n;
    cin>>n;
    a[1]=1;
    a[2]=2;
    a[3]=3;
    int v=3;
    bool ok;
    FOR(i,4,n){
        do{
            ok=1;
            a[i]=++v;
            FOR(x,1,i-1) FOR(y,1,i-1) if(y!=x) FOR(z,1,i-1) if(z!=x && z!=y) 
                if(a[x]+a[y]-a[z]==v){
                    ok=0;
                    break;
                }
        }while(!ok);
    }
    FOR(i,1,n){
        FOR(j,1,n)
            if(i==j) cout<<"0 "; else cout<<a[i]+a[j]<<' ';
        cout<<endl;
    }
    //getch();
    return 0;
}
        
