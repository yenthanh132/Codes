#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1007;

char a[2][maxn][maxn];
int n;

string get(int k, int dir, int id){
    string res="";
    if(dir==0){
        for(int i=k; i<=n-k+1; ++i) res+=a[id][k][i];
    }else if(dir==1){
        for(int i=k; i<=n-k+1; ++i) res+=a[id][i][n-k+1];
    }else if(dir==2){
        for(int i=n-k+1; i>=k; --i) res+=a[id][n-k+1][i];
    }else{
        for(int i=n-k+1; i>=k; --i) res+=a[id][i][k];
    }
    return res;
}

bool check(int k){
    string s1[4],s2[4];
    for(int i=0; i<4; ++i) s1[i]=get(k,i,0), s2[i]=get(k,i,1);
//    cout<<k<<endl;
//    for(int i=0; i<4; ++i) cout<<s1[i]<< ' ' <<s2[i]<<endl;
    for(int i=0; i<4; ++i){
        bool ok=1;
        for(int j=0; j<4; ++j) if(s1[j]!=s2[(i+j)%4]){
            ok=0;
            break;
        }
        if(ok) return 1;
    }
    return 0;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);gets(a[0][0]);
    for(int i=1; i<=n; ++i) gets(a[0][i]+1);
    for(int i=1; i<=n; ++i) gets(a[1][i]+1);
    for(int k=1; k<=(n+1)/2; ++k) if(!check(k)){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
}

