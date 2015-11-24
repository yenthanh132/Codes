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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=100007;

char s[maxn],t[maxn];
int n,ct[26],cs[26];
vector<int> list;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%s",s+1);
    scanf("%s",t+1);
    n=strlen(s+1);
    reset(ct,0);
    FOR(i,1,n){
        cs[s[i]-'A']++;
        ct[t[i]-'A']++;
    }
    int res=0;
    REP(i,26) res+=abs(cs[i]-ct[i]);
    res/=2;
    printf("%d\n",res);
    int i=0;
    FOR(j,1,n){
        while(cs[i]>=ct[i]) i++;
        if(cs[s[j]-'A']>ct[s[j]-'A'] && (i<s[j]-'A' || ct[s[j]-'A']==0)){
            cs[s[j]-'A']--;
            cs[i]++;
            s[j]=i+'A';
        }else{
            cs[s[j]-'A']--;
            ct[s[j]-'A']--;
        }
        
    }
    FOR(i,1,n) printf("%c",s[i]);
    puts("");
    return 0;
}
        
            
