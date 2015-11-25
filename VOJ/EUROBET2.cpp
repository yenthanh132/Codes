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
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
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
typedef pair<pii,int> iii;

const int mid = 10000;

double f[102][20001],a,b;
int n,prob[101],scoreA[101],scoreB[101];


//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    FOR(i,1,n) cin>>prob[i]>>scoreA[i]>>scoreB[i];
    
    f[n+1][mid]=0.5;
    FOR(i,0,9999) f[n+1][i]=0, f[n+1][i+mid+1]=1;
    FORD(i,n,1) FOR(j,0,mid*2)
        if(i&1){
            if (j+scoreA[i]<=mid*2) a=prob[i]*f[i+1][j+scoreA[i]]+(100-prob[i])*f[i+1][j]; else a=0;
            if (j+scoreB[i]<=mid*2) b=prob[i]*f[i+1][j]+(100-prob[i])*f[i+1][j+scoreB[i]]; else b=0;
            f[i][j]=max(a,b)/100;
        }else{
            if (j-scoreA[i]>=0) a=prob[i]*f[i+1][j-scoreA[i]]+(100-prob[i])*f[i+1][j]; else a=0;
            if (j-scoreB[i]>=0) b=prob[i]*f[i+1][j]+(100-prob[i])*f[i+1][j-scoreB[i]]; else b=0;
            f[i][j]=min(a,b)/100;
        }
    printf("%0.6lf\n",f[1][mid]);
    //getch();
    return 0;
}
