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
char s1[maxn],s2[maxn];
int n;
bool l[maxn],r[maxn];
vector<int> res;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%s",s1+1); n=strlen(s1+1);
    scanf("%s",s2+1);
    l[0]=1;
    for(int i=1; i<n; ++i){
        if(s1[i]==s2[i]) l[i]=1;
        else break;
    }
    r[n+1]=1;
    for(int i=n; i>=2; --i){
        if(s1[i]==s2[i-1]) r[i]=1;
        else break;
    }
    for(int i=1; i<=n; ++i) if(l[i-1] && r[i+1]) res.pb(i);
    printf("%d\n",sz(res));
    for(int i=0; i<sz(res); ++i) printf("%d ",res[i]);

    return 0;
}
