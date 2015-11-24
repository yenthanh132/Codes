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
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxv=1000000;
const int maxn=1000007;
const int maxn2=10000007;

bool isprime[maxn];
int lst[maxn],cnt;
int a[maxn2],n,jmp[maxn2],v[maxn2],m,head[maxn2];

int main(){
//    freopen("input.txt","r",stdin);
    isprime[2]=1;
    for(int i=3; i<=maxv; i+=2) isprime[i]=1;
    for(int i=3; i*i<=maxv; ++i) if(isprime[i])
        for(int j=i*i; j<=maxv; j+=2*i) isprime[j]=0;
    lst[cnt=1]=2;
    for(int i=3; i<=maxv; i+=2) if(isprime[i]) lst[++cnt]=i;

    n=0;
    m=0;
    for(int i=1; i<=cnt; ++i){
        for(int j=1; j<i; ++j) if(lst[i]*lst[j]>100000000) break;
        else{
            int x=lst[i]*lst[j];
            ++a[x/10];
            v[++m]=x;
            jmp[m]=head[x/10];
            head[x/10]=m;
        }
    }
    for(int i=1; i<=10000000; ++i) a[i]+=a[i-1];
    int t,L,R;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&L,&R);
        int i=L/10, j=R/10,res=0;
        if(i<j){
            res+=a[j-1]-a[i];
            for(int z=head[j]; z!=0; z=jmp[z])
                if(L<=v[z] && v[z]<=R) ++res;
        }
        for(int z=head[i]; z!=0; z=jmp[z])
            if(L<=v[z] && v[z]<=R) ++res;
        printf("%d\n",res);
    }
}


