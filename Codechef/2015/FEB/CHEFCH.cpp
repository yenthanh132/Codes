#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char s[100007];
int T,n;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1); n=strlen(s+1);
        int r1=0, r2=0;
        for(int i=1; i<=n; ++i){
            char ch='+';
            if(i&1) ch='-';
            if(s[i]!=ch) ++r1; else ++r2;
        }
        printf("%d\n",min(r1,r2));
    }
}

