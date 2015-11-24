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

int a[2222],n;
char arr[2222][2222];

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n;
    int x0=0,x1=0,x=0;
    int w=0,h;
    FOR(i,1,n){
        cin>>a[i];
        w+=a[i];
        if(i&1) x+=a[i]; else x-=a[i];
        x0=min(x0,x);
        x1=max(x1,x);
    }
    h=x1-x0;
    FOR(x,1,h) FOR(y,1,w) arr[x][y]=' ';
    int p=h-x1+1;
    x=1;
    FOR(i,1,n){
        REP(j,a[i]){
            arr[p][x++]=(i&1)?'/':'\\';
            p+=((i&1)?1:-1);
        }
        p-=((i&1)?1:-1);
    }


    FORD(i,h,1){
        FOR(j,1,w) putchar(arr[i][j]);
        puts("");
    }
    return 0;
}
