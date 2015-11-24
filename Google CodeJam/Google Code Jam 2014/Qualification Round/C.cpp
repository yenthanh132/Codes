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
    
char s[57][57]; 
int T,r,c,m;   
    
int main(){
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small-attempt2_2.out","w",stdout);
    
    cin>>T;
    FOR(tt,1,T){
       
        
        cin>>r>>c>>m;   
        printf("Case #%d: %d %d %d\n",tt,r,c,m);
        
        if(r==1 || c==1){            
            FOR(i,1,r) FOR(j,1,c) if(m>0){
                s[i][j]='*';
                m--;   
            }else s[i][j]='.';
            s[r][c]='c';
        }else if(m==r*c-1){
            FOR(i,1,r) FOR(j,1,c) s[i][j]='*';
            s[1][1]='c';
        }else{
            if(2<=r*c-m && r*c-m<=3){
                puts("Impossible");
                continue;
            }
            else{
                FOR(i,1,r) FOR(j,1,c) s[i][j]='*';
                m=r*c-m;
                if(c<r){
                    FOR(j,1,c) if(m>0){
                        m-=2;
                        s[1][j]=s[2][j]='.';                           
                    }   
                    if(m<0 || m==1){ puts("Impossible"); continue; }
                    FOR(i,3,r) if(m>=2){
                        m-=2;
                        s[i][1]=s[i][2]='.';                           
                    }
                    FOR(i,3,r) FOR(j,3,c) if(m>0){
                        s[i][j]='.';
                        m--;
                    }
                }else{
                    FOR(i,1,r) if(m>0){
                        m-=2;
                        s[i][1]=s[i][2]='.';                           
                    }   
                    if(m<0 || m==1) { puts("Impossible"); continue; }
                    FOR(j,3,c) if(m>=2){
                        m-=2;
                        s[1][j]=s[2][j]='.';                           
                    }
                    FOR(i,3,r) FOR(j,3,c) if(m>0){
                        s[i][j]='.';
                        m--;
                    }
                }
                s[1][1]='c';
            }
        }
        FOR(i,1,r){
            FOR(j,1,c) putchar(s[i][j]);
            puts("");
        }   
    }
    return 0;
}
