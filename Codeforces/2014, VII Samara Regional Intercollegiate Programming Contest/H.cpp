#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

char s[maxn],buf[10];
int n,m,vt[26];
string word = "desmond";

bool check(int i){
    for(int j=0; j<sz(word); ++j) if(i+j>n || s[i+j]!=word[j]) return 0;
    return 1;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%s",s+1); n=strlen(s+1);
    scanf("%d",&m);
    int res = -1;
    for(int i=1; i<=n; ++i) if(check(i)){
        res=0;
        break;
    }
    int pos;
    for(int i=1; i<=m && res==-1; ++i){
        scanf("%d%s",&pos,buf);
        s[pos]=buf[0];
        bool found=0;
        for(int j=pos-sz(word)+1; j<=pos; ++j) if(check(j)){
            found=1;
            break;
        }
        if(found){
            res=i;
            break;
        }
    }
    if(res!=-1){
        puts("I love you, Desmond!");
        printf("%d\n",res);
    }else puts("Goodbye, my love!");
}

