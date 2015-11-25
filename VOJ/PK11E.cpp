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

int grundy[1001][1001];
bool mark[1000];

int main(){
    grundy[1][1]=0;
    FOR(i,2,1000) grundy[i][1]=grundy[1][i]=i-1;
    FOR(i,2,25) FOR(j,2,1000){
        reset(mark,1);
        FORD(k,i-1,1) mark[grundy[k][j]]=0;
        FORD(k,j-1,1) mark[grundy[i][k]]=0;
        FORD(k,min(i,j)-1,1) mark[grundy[i-k][j-k]]=0;
        int p;
        for(p=0; !mark[p]; p++);
        grundy[i][j]=p;
    }
    FOR(i,1,25){
        FOR(j,1,25) printf("%3d",grundy[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}
