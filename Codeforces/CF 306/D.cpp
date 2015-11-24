#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int a[222][222];
int n,m,k,x,y;
int main(){
//    freopen("input.txt","r",stdin);
    cin>>k;
    if(k%2==0) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        if(k==1){
            cout<<"2 1"<<endl<<"1 2"<<endl;
        }else{
            n = (k+1)*2+2;
            x = n - 1;
            y = n;
            reset(a,0);
            for(int i=1; i<=k+1; ++i)
                for(int j=i+1; j<=k+1; ++j){
                    a[i][j]=a[j][i]=1;
                    int i2=i+k+1, j2=j+k+1;
                    a[i2][j2]=a[j2][i2]=1;
                }
            a[x][y]=a[y][x]=1;
            for(int i=1; i<=k-1; i+=2){
                int j=i+1;
                a[i][j]=a[j][i]=0;
                a[x][i]=a[i][x]=1;
                a[x][j]=a[j][x]=1;

                int i2=i+k+1, j2=j+k+1;
                a[i2][j2]=a[j2][i2]=0;
                a[y][i2]=a[i2][y]=1;
                a[y][j2]=a[j2][y]=1;
            }

            m=0;
            for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) if(a[i][j]) ++m;
            cout<<n<<' '<<m<<endl;
            for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) if(a[i][j]) cout<<i<<' '<<j<<endl;
        }
    }
}

