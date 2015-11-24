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

const int maxl=4007;
int T,n,dp[maxl][6];
char s[maxl];
set<string> mys;

#include <conio.h>
int main(){
    string st;
    
    freopen("garbled_email_dictionary.txt","r",stdin);
    while(scanf("%s",s+1)!=EOF){
        n=strlen(s+1);
        mys.insert(string(s+1,s+n+1));
        FOR(i,1,n){
            st=string(s+1,s+n+1);
            st[i-1]='@';
            mys.insert(st);
        }
        FOR(i,1,n-5) FOR(j,i+5,n){
            st=string(s+1,s+n+1);
            st[i-1]=st[j-1]='@';
            mys.insert(st);
        }
    }
                        
    freopen("C-large-practice.in","r",stdin);
    freopen("C-large-practice.out","w",stdout);
    scanf("%d",&T);
    FOR(tt,1,T){
        scanf("%s",s+1);
        n=strlen(s+1);
        FOR(i,0,n) FOR(j,0,4) dp[i][j]=oo;
        dp[0][4]=0;
        FOR(i,1,n)
            FOR(j,max(0,i-10),i-1){
                st=string(s+j+1,s+i+1);
                if(mys.find(st)!=mys.end()){
                    FOR(k,0,4) if(dp[j][k]!=oo){
                        int d=min(k+i-j,4);
                        dp[i][d]=min(dp[i][d],dp[j][k]);
                    }
                }   
                REP(z,i-j){
                    st=string(s+j+1,s+i+1);
                    st[z]='@';
                    if(mys.find(st)==mys.end()) continue;
                    FOR(k,0,4) if(k+z>=4 && dp[j][k]!=oo){
                        int d=min(i-j-z-1,4);
                        dp[i][d]=min(dp[i][d],dp[j][k]+1);
                    }
                }
                REP(z,i-j) FOR(z2,z+5,i-j-1){
                    st=string(s+j+1,s+i+1);
                    st[z]=st[z2]='@';
                    if(mys.find(st)==mys.end()) continue;
                    FOR(k,0,4) if(k+z>=4 && dp[j][k]!=oo){
                        int d=min(i-j-z2-1,4);
                        dp[i][d]=min(dp[i][d],dp[j][k]+2);
                    }
                }
            }
        int res=oo;
        FOR(j,0,4) res=min(res,dp[n][j]);
        printf("Case #%d: %d\n",tt,res);
    }
    
    return 0;
}
