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

const int maxn=407;

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
int a[maxn][maxn];
int x,y;

#include <conio.h>
int main(){
    x=200; y=200;
    int k=0,len=1,t=0;
    a[x][y]=0;
    while(1){
        REP(i,len){
            x=x+dx[k];
            y=y+dy[k];
            a[x][y]=t;
        }
        k=(k+1)%4;
        t++;
        REP(i,len){
            x=x+dx[k]; 
            y=y+dy[k];
            a[x][y]=t;
        }
        k=(k+1)%4;
        t++;
        len++;
        if(abs(x-200)>120 || abs(y-200)>120) break;
    }
    cin>>x>>y;
    cout<<a[x+200][y+200];
    //getch();
    return 0;
}
            
