#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char s[2][1111111];

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s[0]+1);
        scanf("%s",s[1]+1);
        int a=oo, b=oo;
        if(s[0][1]=='.') a=0;
        if(s[1][1]=='.') b=0;
        int n=strlen(s[0]+1);
        for(int i=2; i<=n; ++i){
            int a2,b2;
            if(s[0][i]=='#') a2=oo; else a2=min(a,b+1);
            if(s[1][i]=='#') b2=oo; else b2=min(a+1,b);
            a=a2; b=b2;
        }
        int res=min(a,b);
        if(res==oo) puts("No");
        else printf("%s\n%d\n","Yes",res);
    }
}

