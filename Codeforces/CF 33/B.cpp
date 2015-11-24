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

char s1[maxn],s2[maxn],res[maxn],buf1[5],buf2[5];
int rescost,n,m,cost[26][26];

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    n=strlen(s1+1);
    if(n!=strlen(s2+1)){
        puts("-1");
        return 0;
    }
    scanf("%d",&m);
    REP(i,26) REP(j,26) if(i==j) cost[i][j]=0; else cost[i][j]=oo;
    int w;
    REP(index,m){
        scanf("%s%s%d",buf1,buf2,&w);
        int &val=cost[buf1[0]-'a'][buf2[0]-'a'];
        val=min(val,w);
    }
    REP(k,26) REP(i,26) REP(j,26) cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
    rescost=0;
    FOR(i,1,n)
        if(s1[i]==s2[i]) res[i]=s1[i];
        else{
            int minv=oo;
            char ch;
            REP(j,26) if(minv>cost[s1[i]-'a'][j]+cost[s2[i]-'a'][j]){
                minv=cost[s1[i]-'a'][j]+cost[s2[i]-'a'][j];
                ch=j+'a';
            }
            if(minv==oo){
                rescost=oo;
                break;
            }
            rescost+=minv;
            res[i]=ch;
        }
    if(rescost>=oo) puts("-1");
    else{
        res[n+1]='\0';
        printf("%d\n",rescost);
        puts(res+1);
    }
    return 0;
}
        
