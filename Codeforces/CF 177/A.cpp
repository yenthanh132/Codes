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
    int n,k;
    cin>>n>>k;
    if(k>n || (k==1 && n>1)) puts("-1");
    else{
        if(k==1){
            putchar('a');
        }else{
            putchar('a');
            bool a=1;
            FOR(i,2,n-(k-2)){
                if(a) putchar('b');else putchar('a');
                a^=1;
            }
            FOR(i,1,k-2) putchar('b'+i);
        }
        puts("");
    }
    //system("pause");
    return 0;
}
            
