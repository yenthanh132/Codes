#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char s[100];

int main(){
    freopen("67.in","r",stdin);
    freopen("67.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        int len=strlen(s);
        for(int i=len-1; i>=0; --i) printf("%c",s[i]);
        puts("");
    }
}

