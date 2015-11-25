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

const int maxn = 1007;

int res,n,BIT[maxn],a[maxn];

void update(int i){
    while(i<=n){
        BIT[i]++;
        i+=i&(-i);
    }
}

int get(int i){
    int ans=0;
    while(i>0){
        ans+=BIT[i];
        i&=i-1;
    }
    return ans;
}

int count(){
    int res=0;
    reset(BIT,0);
    update(a[1]);
    FOR(i,2,n){
        res+=(i-1 - get(a[i]));
        update(a[i]);
    }
    return res;
}


#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    res=oo;
    FOR(i,1,n-1) FOR(j,i+1,n){
        swap(a[i],a[j]);
        res=min(res,count());
        swap(a[i],a[j]);
    }
    cout<<res<<endl;
    getch();
    return 0;
}
       
