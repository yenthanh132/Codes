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

const int maxn=200007;

ll BIT[maxn],n;
double sum;
int len,arr[maxn];

void update(int pos, ll v){
    for(int i=pos; i; i-=i&(-i)) BIT[i]+=v;
}

ll get(int pos){
    ll res=0;
    for(int i=pos; i<=200000; i+=i&(-i)) res+=BIT[i];
    return res;
}

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    sum=0; len=1;
    scanf("%d",&n);
    int t,a,x;
    arr[1]=0;
    FOR(i,1,n){
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d",&a,&x);
            update(a,x);
            sum+=a*x;
        }else if(t==2){
            scanf("%d",&x);
            len++;
            arr[len]=x;
            sum+=x;
        }else{
            int v=get(len);
            update(len-1,v);
            update(len,-v);
            sum-=arr[len]+v;
            len--;
        }
        printf("%0.12lf\n",sum/len);
    }
    getch();
    return 0;
}
        
