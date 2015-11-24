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
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1000007;

int n,k,a[maxn],b[maxn],val[maxn];
char s[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    for(int i=1; i<=n; ++i) a[i]=s[i]-'A';

    while(k>0){
        val[0]=0;
        for(int i=1; i<=n; ++i) val[i]=val[i-1]^a[i];
        int x=1;
        while(x*2<=k+1) x*=2;
        int time = x/n, left = x%n;
        for(int i=1; i<=n; ++i){
            a[i] = 0;
            if(time&1) a[i]=val[n];
            if(i+left-1<=n) a[i]^=val[i+left-1]^val[i-1];
            else{
                a[i]^=val[n]^val[i-1];
                a[i]^=val[i+left-1-n];
            }
        }
        k-=x-1;
    }

    for(int i=1; i<=n; ++i) putchar(a[i]+'A');
    puts("");
    return 0;
}
