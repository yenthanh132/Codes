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

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int n,time,smin[31],smax[31],mint[31],maxt[31],d[31];
    cin>>n>>time;
    smin[0]=smax[0]=0;
    FOR(i,1,n){
        cin>>mint[i]>>maxt[i];
        smin[i]=smin[i-1]+mint[i];
        smax[i]=smax[i-1]+maxt[i];
    }
    if(time<smin[n] || time>smax[n]) cout<<"NO";
    else{
        cout<<"YES\n";
        FORD(i,n,1)
            FOR(j,mint[i],maxt[i]) if(smin[i-1]<=time-j && time-j<=smax[i-1]){
                d[i]=j;
                time-=j;
                break;
            }
        FOR(i,1,n) cout<<d[i]<<' ';
    }
    //getch();
    return 0;
}
    
