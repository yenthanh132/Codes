#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

string arr[55555];
vector<int> lst;
int T,R,C,cnt;

void dfs(int i, int j){
    arr[i][j]='#';
    ++cnt;
    for(int k=0; k<4; ++k){
        int i2=i+dx[k], j2=j+dy[k];
        if(0<=i2 && i2<R && 0<=j2 && j2<C && arr[i2][j2]=='o') dfs(i2,j2);
    }
}

double res;

void calc(int sum, int state, double val, int step){
    res += step * (val*lst[0]/sum);
    for(int i=1; i<sz(lst); ++i) if(state>>i&1){
        calc(sum - lst[i], state ^ (1<<i), val*lst[i]/sum, step+1);
    }
}



int main(){
    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&R,&C);
        for(int i=0; i<R; ++i) cin>>arr[i];
        lst.clear();
        cnt=0; dfs(0,0);
        lst.pb(cnt);
        for(int i=0; i<R; ++i) for(int j=0; j<C; ++j)
            if(arr[i][j]=='o'){
                cnt=0;
                dfs(i,j);
                lst.pb(cnt);
            }
        int sum=0;
        for(int i=0; i<sz(lst); ++i) sum+=lst[i];


        res=0;
        calc(sum,(1<<sz(lst)) - 1,1,1);
        printf("%0.9f\n",res);

    }
}

