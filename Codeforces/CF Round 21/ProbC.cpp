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

const int maxn = 100007;

int n, a[maxn], s[maxn], sum;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    sum=s[0]=0;
    FOR(i,1,n){
        scanf("%d",a+i);
        s[i]=s[i-1]+a[i];
        sum+=a[i];
    }
    if(sum%3!=0) printf("0\n");
    else{
        ll res=0;
        int v=sum/3,t=0;
        FOR(i,1,n-1){
            if(s[i]==v*2) res+=t;
            if(s[i]==v) t++;
        }
        printf("%I64d\n",res);
    }
    //getch();
    return 0;
}
