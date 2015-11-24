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

const int maxn=100007;
char s[maxn],t[maxn];
int prev[maxn],f[maxn],g[maxn];
int n,m,len;

int init(){
    prev[1]=0;
    int i=1, j=0;
    while(i<=len){
        while(j>0 && t[i]!=t[j]) j=prev[j];
        ++i;
        ++j;
        if(t[j]==t[i]) prev[i]=prev[j]; else prev[i]=j;
    }

}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%s",s+1); n=strlen(s+1);
    scanf("%d",&m);
    int res = 0;
    for(int r=0; r<m; ++r){
        scanf("%s",t+1);
        len=strlen(t+1);
        init();
        int i=1, j=1;

        f[0]=0;
        while(i<=n){
            while(j>0 && s[i]!=t[j]) j=prev[j];
            f[i]=max(f[i-1],j);
            ++i;
            ++j;
            if(j>len) j=prev[j];
        }

        reverse(t+1,t+len+1);
        init();

        i=n; j=1; g[n+1]=0;
        while(i>=1){
            while(j>0 && s[i]!=t[j]) j=prev[j];
            g[i]=max(g[i+1],j);
            --i;
            ++j;
            if(j>len) j=prev[j];
        }

        bool found = 0;
        for(int i=0; i<=n; ++i)
            if(f[i] + g[i+1] >= len) found = 1;

        if(found && len>1) ++res;

    }
    cout<<res<<endl;
    return 0;
}
