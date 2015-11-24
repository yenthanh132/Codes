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

const int maxn=1007;

char s[maxn],res[maxn];
int n,k;
bool found;

bool dfs(int i, bool first){
    if(i>n){
        for(int j=1; j<=n; ++j) res[j]=s[j];
        return 1;
    }
    char tmp = s[i];
    for(int v=0; v<k; ++v){
        char ch = 'a' + v;
        if(first && ch <= s[i]) continue;
        if( (i <= 2 || s[i-2] != ch) && (i <= 1 || s[i-1] != ch) ){
            s[i] = ch;
            bool r = dfs(i+1, 0);
            s[i] = tmp;
            return r;
        }
    }
    return 0;
}


int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    found = 0;
    for(int i=n; i>=1; --i)
        if(dfs(i,1)){
            found = 1;
            break;
        }
    if(found){
        for(int i=1; i<=n; ++i) printf("%c",res[i]); printf("\n");
    }else{
        printf("NO\n");
    }
    return 0;
}
