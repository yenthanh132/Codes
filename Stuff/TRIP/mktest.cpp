#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

//Random function
double randf() {
    double base = 0.1;
    double res = 0;
    for (int i = 0; i < 15; i++) {
        res += base * (rand() % 10);
        base /= 10;
    }
    return res;
}

int randi(int n) {
    return (int)floor(randf() * n);
}

int N=10;
int M=10;
int W=100;

map<pii,bool> mark;

bool exist(int x, int y){
    if(x>y) swap(x,y);
    return mark[pii(x,y)];
}

void gen(int id, int minN, int maxN, int minM, int maxM, int maxW){
    stringstream ss;
    ss<<id;
    string s=ss.str()+".in";
    freopen(s.c_str(),"w",stdout);

    W=maxW; N=randi(maxN-minN+1)+minN;
    M = randi(maxM-minM+1)+minM;

    printf("%d %d\n",N,M);

    mark.clear();
    for(int i=0; i<M; ++i){
        int x=randi(N)+1, y=randi(N)+1;
        while(y==x || exist(x,y)) y=randi(N)+1;
        int w=randi(W)+1;
        if(id==29) w=1000000000;
        printf("%d %d %d\n",x,y,w);

        if(x>y) swap(x,y);
        mark[pii(x,y)]=1;
    }

}

int main(){
    srand(time(NULL));
    for(int i=27; i<30; ++i){
        gen(i,100000,100000,100000,100000,1000000000);
    }
}


