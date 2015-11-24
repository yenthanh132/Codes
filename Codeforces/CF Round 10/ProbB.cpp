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

const int maxn = 100;

bool a[maxn][maxn];

int n,k,m,X,Y1,Y2;
bool ok=0;

int csc(int n){return (n*(n+1)/2);}

int getval(int x, int y1){
    int mid=(k+1)/2,res=abs(mid-x)*m,y2=y1+m-1;
    if(y1<=mid && mid<=y2)
        res+=csc(abs(y2-mid))+csc(abs(y1-mid));
    else if(y2<mid) res+=csc(abs(y1-mid))-csc(abs(y2-mid)-1);
    else res+=csc(abs(y2-mid))-csc(abs(y1-mid)-1);
    return res;
}

void solve(){
    int minv=oo;
    FOR(i,1,k){
        int j1,j2;
        j1=1;
        while(j1<=k && a[i][j1]) j1++;
        while(j1<=k){
            j2=j1;
            while(j2+1<=k && !a[i][j2+1]) j2++;
            FOR(z,j1,j2-m+1){
                int v=getval(i,z);
                if(v<minv || (v==minv && (i<X || (i==X && z<Y1)))){
                    minv=v;
                    X=i; Y1=z; Y2=z+m-1;
                    ok=1;
                }
            }
            j1=j2+1;
            while(j1<=k && a[i][j1]) j1++;
        }
    }
    if(ok) FOR(j,Y1,Y2) a[X][j]=1;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    reset(a,0);
    cin>>n>>k;
    REP(index,n){
        cin>>m;
        ok=0;
        solve();
        if(ok) cout<<X<<' '<<Y1<<' '<<Y2<<endl; else cout<<"-1\n";
    }
    //getch();
    return 0;
}
