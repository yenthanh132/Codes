#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int cnt[2][26];
int n,a,b,c;
char s[100001];
int main(){
//    freopen("input.txt","r",stdin);

    int T;
    scanf("%d",&T);
    while(T--){
        reset(cnt,0);
        int len1,len2;
        scanf("%s",s);
        len1=strlen(s);
        for(int i=0; i<len1; ++i) cnt[0][s[i]-'a']++;
        scanf("%s",s);
        len2=strlen(s);
        for(int i=0; i<len2; ++i) cnt[1][s[i]-'a']++;

        scanf("%d%d%d",&a,&b,&c);
        c=min(c,a+b);
        int diff=0;
        for(int i=0; i<26; ++i) diff+=abs(cnt[0][i]-cnt[1][i]);

        int cost=0;
        if(len1<len2){
            cost += b*(len2-len1);
            diff -= len2-len1;
        }else if(len1>len2){
            cost += a*(len1-len2);
            diff -= len1-len2;
        }
        cost += (diff/2) * c;

        printf("%d\n",cost);
    }
}

