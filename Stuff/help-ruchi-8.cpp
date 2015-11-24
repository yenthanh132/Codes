#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int a[10][10],b[10][10];
int N;
bool found;

bool mark[10][10];

void quet(int i){
    if(found) return;

        reset(mark,0);
        for(int x=1; x<i; ++x) for(int y=1; y<=N; ++y){
            if(mark[a[x][y]][b[x][y]]) return;
            mark[a[x][y]][b[x][y]]=1;
        }
    if(i>N){
            for(int x=1; x<=N; ++x) {for(int y=1; y<=N; ++y) cout<<a[x][y]<<' '; cout<<endl;}
            cout<<endl;
            for(int x=1; x<=N; ++x) {for(int y=1; y<=N; ++y) cout<<b[x][y]<<' '; cout<<endl;}


            found=1;

        return;
    }
    for(int y=1; y<=N; ++y) b[i][y]=y;
    do{
        bool ok=1;
        for(int y=1; y<=N && ok; ++y){
            for(int x=1; x<i; ++x) if(b[x][y]==b[i][y]){
                ok=0;
                break;
            }
        }
        if(ok) quet(i+1);
    }while(next_permutation(b[i]+1,b[i]+N+1));
}

int main(){
//    freopen("input.txt","r",stdin);
    N=7;
    for(int i=1; i<=N; ++i){
        int cnt=i;
        for(int j=1; j<=N; ++j){
            a[i][j]=cnt++;
            if(cnt>N) cnt=1;
        }
    }
    for(int i=1; i<=N; ++i) b[1][i]=i;
    found=0;
    quet(2);
    cout<<found<<endl;
    return 0;
    int T,n;
    scanf("%d",&T);
    for(int i=0; i<T; ++i){
        scanf("%d",&n);
        puts("Yes");
    }
}

