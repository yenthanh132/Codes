#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxm=107;
const int maxs=907;

bool dp[maxm][maxs];
int m,s;

void outmin(){
    int S=s;
    for(int i=m; i>=1; --i){
        int start=0;
        if(i==m && m>1) start=1;
        bool found=0;
        for(int x=start; x<=9; ++x) if(dp[i][S] && dp[i-1][S-x]){
            cout<<x;
            S-=x;
            found=1;
            break;
        }
        if(!found){
            cout<<-1;
            return;
        }
    }
}

void outmax(){
    int S=s;
    for(int i=m; i>=1; --i){
        int endnum=0;
        if(i==m && m>1) endnum=1;
        bool found=0;
        for(int x=9; x>=endnum; --x) if(dp[i][S] && dp[i-1][S-x]){
            cout<<x;
            S-=x;
            found=1;
            break;
        }
        if(!found){
            cout<<-1;
            return;
        }
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    reset(dp,0);
    cin>>m>>s;
    dp[0][0]=1;
    for(int i=0; i<m; ++i) for(int j=0; j<=(i)*9; ++j) if(dp[i][j]){
        for(int x=0; x<=9; ++x) dp[i+1][j+x]=1;
    }
    outmin(); cout<<" "; outmax();
}

