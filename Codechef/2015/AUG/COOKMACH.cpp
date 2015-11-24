#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int a,b;
map<int,int> dis;
queue<int> myq;

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        cin>>a>>b;
        dis.clear();
        myq = queue<int>();
        dis[a]=0;
        myq.push(a);
        while(!myq.empty()){
            int u=myq.front(); myq.pop();
            int v=u*2;
            if(v<=b){
                if(!dis.count(v)){
                    dis[v]=dis[u]+1;
                    myq.push(v);
                }
            }
            v=u/2;
            if(!dis.count(v)){
                dis[v] = dis[u]+1;
                myq.push(v);
            }
        }
        cout<<dis[b]<<endl;
    }
}

