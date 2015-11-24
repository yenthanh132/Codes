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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
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
typedef pair<int, int> pii;

int a[100][100];
vector<int> row[100], col[100];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int r,c;
    scanf("%d%d",&r,&c);
    REP(i,r) REP(j,c){
        scanf("%d",&a[i][j]);
        row[i].pb(a[i][j]); col[j].pb(a[i][j]);
    }
    REP(i,r) sort(row[i].begin(), row[i].end());
    REP(j,c) sort(col[j].begin(), col[j].end());
    REP(i,r) REP(j,c)
        if(a[i][j]==row[i][0] && a[i][j]==col[j][r-1]){
            printf("%d\n",a[i][j]);
            //getch();
            return 0;
        }
    printf("GUESS\n"); 
    //getch();
    return 0;
}
