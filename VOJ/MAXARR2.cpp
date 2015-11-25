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

int a[maxn];

void init(){
    a[0]=0;
    a[1]=1;
    FOR(i,2,100000) 
    if(i%2) a[i]=a[i/2]+a[i/2+1]; 
    else a[i]=a[i/2];
}
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int v,test;
    init();
    int maxi=0;
    FOR(i,1,20) if(maxi==0 || a[maxi]<a[i]) maxi=i;
    cout<<maxi<<" "<<a[maxi]<<endl;
    maxi=0;
    FORD(i,80,63) if(maxi==0 || a[maxi]<a[i]) maxi=i;
    cout<<maxi<<" "<<a[maxi]<<endl;
    scanf("%d",&test);
    REP(index,test){
        scanf("%d",&v);
        if(v) printf("%d\n",max(a[v],a[v-1])); else printf("0\n");
    }
    //getch();
    return 0;
}
    
        
