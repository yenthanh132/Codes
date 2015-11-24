#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

vector<int> num[17];
bool mark[17];
ll dp[2][2][1<<15];
int inv[1<<15][15];

ll calc(int x, int y){
    int pos = (x-1)*4 + y;
    reset(dp,0);
    int flag = 0;
    dp[0][0][0]=1;
    for(int i=1; i<=16; ++i) if(i!=pos){
        reset(dp[flag^1],0);
        for(int v=0; v<2; ++v) for(int state=0; state<(1<<15); ++state) if(dp[flag][v][state]){
            for(int j=0; j<sz(num[i]); ++j){
                int x=num[i][j];
                if(state>>x&1) continue;
                int v2 = (v + inv[state][x])&1;
                dp[flag^1][v2][state | (1<<x)] += dp[flag][v][state];
            }
        }
        flag ^= 1;
    }
    int bit=0;
    if(x==1 || x==3) bit=1;
    return dp[flag][bit][(1<<15)-1];
}

int main(){
//    freopen("input.txt","r",stdin);
    for(int i=1; i<=16; ++i){
        int c;
        cin>>c;
        for(int j=0; j<c; ++j){
            int v;
            cin>>v;
            if(v!=0) num[i].pb(v-1);
            else mark[i]=1;
        }
    }

    for(int state=0; state<(1<<15); ++state){
        int c=0;
        for(int j=14; j>=0; --j){
            if(state>>j&1) ++c;
            inv[state][j]=c;
        }
    }

    ll res=0;
    for(int x=1; x<=4; ++x) for(int y=1; y<=4; ++y){
        int pos = (x-1)*4 + y;
        if(mark[pos]) res += calc(x,y);
    }

    cout<<res<<endl;
}

