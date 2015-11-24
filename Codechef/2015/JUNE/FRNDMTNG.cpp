#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

double getv(double x, double T2, double t1, double t2){
    double d=0;
    if(x<=T2){
        if(x+t1<=T2) d+=t1; else d+=T2-x;
        if(x-t2>=0) d+=t2; else d+=x;
    }else{

        if(x<=T2+t2) d+=min(T2,(T2+t2-x));
    }
    return d;
}

double brute(double T1, double T2, double t1, double t2){
    double res=0;
    double jump=100000;
    double width = T1/jump;
    for(int i=0; i<jump; ++i){
        res+=getv(i*width+width/2,T2,t1,t2)*width;
    }
    return res/T1/T2;
}

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    double t1,t2,T1,T2;
    cin>>T;
    while(T--){
        cin>>T1>>T2>>t1>>t2;

//        cout<<endl;
//        cout<<brute(T1,T2,t1,t2)<<endl;

        double x = 0, y = T1*T2;
        double x1, x2, h;

        if(t1+t2<=T2){
            x1=t2;
            x2=T2-t1;
            h=t1+t2;
        }else{
            x1=max(T2-t1,0.0);
            x2=t2;
            h=T2;
        }

        if(T1<=x1){
            x=t1*T1 + T1*T1/2;
        }else if(T1<=x2){
            x=t1*x1 + x1*x1/2 + (T1-x1)*h;
        }else{
            double xsub = max(0.0, x2+h-T1);
            x=t1*x1 + x1*x1/2 + (x2-x1)*h;

                x+= h*h/2 - xsub*xsub/2;
        }



        printf("%0.9f\n",x/y);
    }
}

