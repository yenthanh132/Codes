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
int cnt[26];
string Vowels="aeoui";

int main(){
    freopen("34.in","r",stdin);
    freopen("34.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        int len=strlen(s);
        reset(cnt,0);
        for(int i=0; i<len; ++i) cnt[s[i]-'a']++;
        int sum=0;
        for(int i=0; i<5; ++i) sum += cnt[Vowels[i]-'a'];
        if(sum&1) puts("PESAR");
        else puts("DOKHTAR");
    }
}


