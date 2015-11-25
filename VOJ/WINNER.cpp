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

int func(int v){
    if(v==0) return 0;
    int res=0;
    while(v%2==0){
        res++;
        v/=2;
    }
    return res+1;
}

const int maxn=100007;

int n,a[maxn],b[maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int bit=0,bit2,pos,val,res;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]), b[i]=func(a[i]), bit^=b[i];
    if(bit){
        puts("Bom");
        res=-1;
        FOR(i,1,n){
            bit2=(b[i]^bit);
            if(bit2==0) val=a[i];
            else if(bit2<b[i]){
                val=a[i]/(1<<(b[i]-bit2));
            }else{
                int sub=1<<(bit2-1);
                int x=a[i]-sub;
                val=0;
                while(x>0){
                    if(x<res) break;
                    if(a[i]%x==0){
                        val=x;
                        break;   
                    }
                    x-=2*sub;
                }
            }
                
            if(res<val || (res==val && a[pos]<a[i])){
                res=val;
                pos=i;
            }
        }
        printf("%d %d\n",res,a[pos]);
    }else puts("Cuoi");
    //getch();
    return 0;
}
            
