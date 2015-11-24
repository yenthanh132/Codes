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

int a[10][10];
int per[10];

int main(){

    FOR(i,1,5) FOR(j,1,5) scanf("%d",&a[i][j]);
    
    FOR(i,1,5) per[i]=i;
    int res=0;
    do{
        int v=0;
        FOR(i,1,4){
            for(int j=i+1; j<=5; j+=2){
                v+=a[per[j-1]][per[j]]+a[per[j]][per[j-1]];     
            }   
        }
        res=max(res,v);
    }while(next_permutation(per+1,per+6));       
    
    cout<<res<<endl;
}
