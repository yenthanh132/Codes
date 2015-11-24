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

int n,a[1111];

bool intersect(int i, int j){
    int l1=a[i], r1=a[i+1], l2=a[j], r2=a[j+1];
    if(l1>r1) swap(l1,r1);
    if(l2>r2) swap(l2,r2);
    if(l1>l2){
        swap(l1,l2);
        swap(r1,r2);
    }
    if(l1!=l2 && l2<r1 && r1<r2) return 1;
    return 0;
}


int main(){
    //freopen("input.txt","r",stdin);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    if(n<=2){
        puts("no");
        return 0;
    }
    FOR(i,1,n-2) FOR(j,i+1,n-1)
        if(intersect(i,j)){
            puts("yes");
            return 0;
        }
    puts("no");
    return 0;
}
