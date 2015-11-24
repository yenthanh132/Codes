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

const int maxn=10007;
char s[maxn],t[maxn];
int n,len,m;

int main(){
    //freopen("input.txt","r",stdin);
    while(scanf("%d\n",&n),n>0){
        gets(s);
        len=strlen(s);
        m=0;
        for(int i=0; i<len; ++i){
            if(s[i]!=' '){
                if(s[i]>='a') s[i]=s[i]-'a'+'A';
                t[++m]=0;
            }
        }
        int x=0,start=0;
        int idx=0;
        for(int i=0; i<len; ++i) if(s[i]!=' '){
            t[x]=s[i];
            x+=n;
            if(x>=m){
                x=++start;
            }
        }
        for(int i=0; i<m; ++i) printf("%c",t[i]);
        puts("");
    }
    return 0;
}
