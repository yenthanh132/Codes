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

int a[2000007],last,first,n;

#include <conio.h>
int main(){
    cin>>n;
    FOR(i,1,n) a[i]=i;
    first=1; last=n;
    FOR(i,2,n){
        int v=a[first],p,t;
        for(int j=first; j<=last; j+=i){
            p=i+j;
            if(p>last+1) p=last+1;
            t=a[p];
            a[p]=v;
            v=t;
        }
        first++; last++;
    }
    REP(i,n) printf("%d ",a[first+i]);
    
    //getch();
    return 0;
}

    
