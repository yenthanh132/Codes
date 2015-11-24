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
#define oo 1000000007;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=57;
const int dx[8]={-1,-1,0,1,1,1,0,-1};
const int dy[8]={0,1,1,1,0,-1,-1,-1};

char Survey(int x, int y) {
    printf("S %d %d\n", x-1, y-1);
    fflush(stdout);
    char res[5];
    scanf("%s", res);
    return res[0];
}

void Neutralize(int x, int y) {
    printf("N %d %d\n", x-1, y-1);
}


int a[maxn][maxn],checked[maxn][maxn];
char status[maxn][maxn],survey_map[maxn][maxn];
int n,m,k,remain,x,y;

bool guess_move(int &x, int &y){
    vector<pii> list;
    int xt,yt;
    FOR(i,1,n) FOR(j,1,n) if(status[i][j]=='@'){
        REP(kt,8){
            xt=i+dx[kt]; yt=j+dy[kt];
            if(xt>=1 && xt<=n && yt>=1 && yt<=n && survey_map[xt][yt]!='M' && survey_map[xt][yt]!='?')
            list.pb(pii(i,j));
        }
    }
    if(list.empty()) return 0;
    int t=rand()%sz(list);
    x=list[t].fi; y=list[t].se;
    return 1;
}

bool random_move(int &x, int &y){
    vector<pii> list;
    FOR(i,1,n) FOR(j,1,n) if(status[i][j]=='?') list.pb(pii(i,j));
    if(list.empty()) return 0;
    int t=rand()%sz(list);
    x=list[t].fi; y=list[t].se;
    return 1;
}

void process(){
    int c,c2,c3,xt,yt;
    bool stop;
    do{
        stop=1;
        FOR(x,1,n) FOR(y,1,n) if(survey_map[x][y]!='?' && survey_map[x][y]!='M'){
            c=survey_map[x][y]-'0';
            c2=c3=0;
            REP(kt,8){
                xt=x+dx[kt]; yt=y+dy[kt];
                if(xt>=1 && xt<=n && yt>=1 && yt<=n){
                    if(survey_map[xt][yt]=='M') c2++;
                    if(status[xt][yt]!='x') c3++;
                }
            }
            if(c==c2){
                REP(kt,8){
                    xt=x+dx[kt]; yt=y+dy[kt];
                    if(xt>=1 && xt<=n && yt>=1 && yt<=n && status[xt][yt]!='x'){
                        status[xt][yt]='x';
                        remain--;
                        stop=0;
                    }
                }   
            }else if(c==c2+c3){
                REP(kt,8){
                    xt=x+dx[kt]; yt=y+dy[kt];
                    if(xt>=1 && xt<=n && yt>=1 && yt<=n && status[xt][yt]!='x'){
                        status[xt][yt]='x';
                        remain--;
                        survey_map[xt][yt]='M';
                        m--;
                        k--;
                        c2++;
                        c3--;
                        stop=0;
                    }
                }
           }
        
            //check for winning status - delete all other cells
            if(c-c2==m){
                FOR(x2,1,n) FOR(y2,1,n) if(abs(x2-x)>1 || abs(y2-y)>1)
                    if(status[x2][y2]!='x'){
                        status[x2][y2]='x';
                        remain--;
                        stop=0;
                    }
            }
            
        }
    }while(!stop);
}
        
      
        
//#include <conio.h>
int main(){
    int xt,yt;
    srand(time(NULL));
    scanf("%d%d%d",&n,&m,&k);
    reset(checked,0);
    remain=n*n;
    FOR(i,1,n) FOR(j,1,n) status[i][j]=survey_map[i][j]='?';
    while(1){
        if(m==0 || remain<=k){
            break;
        }
        if(!guess_move(x,y)) random_move(x,y);
        
        //----------
            remain--;
            survey_map[x][y]=Survey(x,y);
            status[x][y]='x';
            if(survey_map[x][y]!='M'){
                REP(kt,8){
                    xt=x+dx[kt]; yt=y+dy[kt];
                    if(xt>=1 && xt<=n && yt>=1 && yt<=n && status[xt][yt]=='?') status[xt][yt]='@';
                }
            }else{
                m--;
                k--;
            }
        //--------
        process();
    }
    FOR(x,1,n) FOR(y,1,n) if(survey_map[x][y]=='M')
        Neutralize(x,y);
    if(remain<=k){
        FOR(x,1,n) FOR(y,1,n) if(status[x][y]!='x') 
            Neutralize(x,y);
    }
    
    printf("Done\n");
    
    //getch();
    return 0;
}
    
