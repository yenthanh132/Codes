#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int mark[1000007];

int main(){
//    freopen("input.txt","r",stdin);
    ll h1,h2,a1,a2,x1,y1,x2,y2,m;
    cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
    ll res=0;
    while(res<=1000000 && h1!=a1){
        h1=(x1*h1+y1)%m;
        h2=(x2*h2+y2)%m;
        ++res;
    }
    if(h1!=a1){
        cout<<-1<<endl;
        return 0;
    }
    if(h2==a2){
        cout<<res<<endl;
        return 0;
    }

    int c=1;
    h1=(x1*h1+y1)%m;
    while(h1!=a1){
        h1=(x1*h1+y1)%m;
        ++c;
        if(c>1000000) break;
    }

    if(h1!=a1){
        cout<<-1<<endl;
        return 0;
    }

    reset(mark,0);
    mark[h2]=1;
    int c2=1,mindis=-1;
    h2=(x2*h2+y2)%m;
    while(!mark[h2]){
        if(h2==a2 && mindis==-1){
            mindis=c2;
        }
        mark[h2]=++c2;
        h2=(x2*h2+y2)%m;
    }
    if(mindis==-1){
        cout<<-1<<endl;
        return 0;
    }
    int len = c2-mark[h2]+1;

    for(ll num=1; num<=1000000; ++num)
        if(num*c>=mindis && (num*c - mindis)%len==0){
            res+=num*c;
            cout<<res<<endl;
            return 0;
        }

    cout<<-1<<endl;

}

