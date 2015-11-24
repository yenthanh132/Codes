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
int n,cnt[26];

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    scanf("%s",s+1);
    n=(n-1)*2;
    int res = 0;
    for(int i=1; i<=n; i+=2){
        cnt[s[i]-'a']++;
        int v=s[i+1]-'A';
        if(cnt[v]) --cnt[v];
        else ++res;
    }
    cout<<res<<endl;
}

