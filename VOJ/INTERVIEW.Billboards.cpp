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

#define maxn 100007
int a[maxn],n,k;
ll sum,f[maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k);
    sum=0;
    FOR(i,1,n){
        scanf("%d",a+i);
        sum+=a[i];
    }
    a[++n]=0;
    deque<int> list;
    f[0]=0; list.push_back(0);
    FOR(i,1,n){
        while(list[0]<i-k-1) list.pop_front();
        f[i]=f[list[0]]+a[i];
        while(!list.empty() && f[list[list.size()-1]]>=f[i]) list.pop_back();
        list.push_back(i);
    }
    cout<<sum-f[n]<<endl;
    //getch();
    return 0;
}
        
    
