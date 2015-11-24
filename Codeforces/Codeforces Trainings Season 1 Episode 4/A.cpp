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

int main(){
    int T,a[3];
    cin>>T;
    REP(i,T){
        REP(j,3) cin>>a[j];
        sort(a,a+3);
        if(a[2]-a[0]>1) puts("0");
        else{
            int j=2;
            while(j>0 && a[j-1]==a[2]) j--;
            if(j==2){
                if(a[0]==0) puts("1");
                else puts("2");
            }
            else if(j==1) puts("2");
            else puts("6");
        }
    }
    return 0;
}
    
