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

const int maxn=307;

bool win[maxn][maxn];
#include <conio.h>
int main(){
    win[0][0]=0;
        FOR(i,0,300) FOR(j,0,300){
            FOR(x,0,i-1) if(!win[x][j]) win[i][j]=1;
            FOR(x,0,j-1) if(!win[i][x]) win[i][j]=1;
            FOR(x,1,min(i,j)) if(!win[i-x][j-x]) win[i][j]=1;
        }
    int n,a[5];
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    if(n==1){
        if(a[1]>0) puts("BitLGM");
        else puts("BitAryo");
    }else if(n==2){
        if(win[a[1]][a[2]]) puts("BitLGM");
        else puts("BitAryo");
    }else{
        if((a[1]^a[2]^a[3])==0) puts("BitAryo"); else puts("BitLGM");
    }
        
    
    return 0;
}
/*

#include <conio.h>

bool cmp(const int &a, const int &b){return a>b;}
int main(){
    int n,a[5];
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    while(n>1 && a[n]==0) n--;
    
    if(n==1){
        if(a[1]>0) puts("BitLGM");
        else puts("BitAryo");
    }else if(n==2){
        if(a[1]==a[2] || (a[2]>1 && abs(a[1]-a[2])%2==1) || (a[2]==1 && abs(a[1]-a[2])%2==0)) puts("BitLGM");
        else puts("BitAryo");
    }else{
        if((a[1]^a[2]^a[3])==0) puts("BitAryo"); else puts("BitLGM");
    }
        
    //getch();    
    return 0;
}
*/
