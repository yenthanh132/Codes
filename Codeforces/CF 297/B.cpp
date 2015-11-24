#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char s[2000007];
int mark[2000007];
int len,m,x;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%s",s+1); len=strlen(s+1);
    scanf("%d",&m);
    for(int i=0; i<m; ++i){
        scanf("%d",&x);
        mark[x]++;
        mark[len-x+2]++;
    }
    int sum=0;
    for(int i=1; i<=len; ++i){
        sum+=mark[i];
        if(sum&1) printf("%c",s[len-i+1]);
        else printf("%c",s[i]);
    }
}

