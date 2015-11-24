#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxv=1000000;
set<pii> mys;
bool mark[2222222];

void init(){
    mys.insert(pii(0,0));
    reset(mark,0);
    int i=1,c=1;
    while(1){
        while(mark[i] && i<=maxv) ++i;
        int j=i+(c++);
        if(j>maxv) break;
        mark[i]=mark[j]=1;
        mys.insert(pii(i,j));
    }
}

bool win(int i, int j){
    if(i>j) swap(i,j);
    return !mys.count(pii(i,j));
}

int main(){
//    freopen("input.txt","r",stdin);
    init();


    int T,x,y;
    scanf("%d",&T);

    for(int t=0; t<T; ++t){
        scanf("%d%d",&x,&y);
        if(win(x,y)) puts("Play");
        else puts("Don't Play");
    }
}


//
//int main(){
//    freopen("input.txt","r",stdin);
//    int a[111][111];
//map<int,int> cnt;
//    reset(a,-1);
//    for(int i=0; i<=100; ++i) for(int j=0; j<=100; ++j){
//        if(i+j==0){
//            a[i][j]=0;
//            continue;
//        }
//        a[i][j]=0;
//        for(int k=1; k<=max(i,j); ++k){
//            if(k<=i && a[i-k][j]==0){
//                a[i][j]=1;
//                break;
//            }
//            if(k<=j && a[i][j-k]==0){
//                a[i][j]=1;
//                break;
//            }
//            if(k<=i && k<=j && a[i-k][j-k]==0){
//                a[i][j]=1;
//                break;
//            }
//        }
//    }
//    for(int i=0; i<=100; ++i)
//        for(int j=i; j<=100; ++j) if(a[i][j]==0){
//            cout<<i<<' '<<j<<' '<<j-i<<endl;
//            cnt[i]++;
//            cnt[j]++;
//            if(cnt[i]>1){
//                cout<<"found "<<i<<endl;
//            }
//            if(cnt[j]>1){
//                cout<<"found "<<j<<endl;
//            }
//
//        }
//}
//
