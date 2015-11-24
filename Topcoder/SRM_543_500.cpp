#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

struct bitarr{long long a[32];};

bitarr count(long long v){
    bitarr bit;
    fill_n(bit.a,32,0);
    for(int i=0;i<=31;i++){
        int l=1,r=1,j;
        for(j=i-1;j>=0;j--) if (((v>>j) & 1) == 1) r+=(1<<j);
        if (((v>>i) & 1) == 1) bit.a[i]+=r;
        for(j=i+1;j<=31;j++) if (((v>>j)&1)==1) l+=(1<<(j-i-1));
        bit.a[i]+=(1<<i)*(l-1);
    }
    return bit;
}
    

struct EllysXors{
    long long getXor(long long L, long long R){
        bitarr bl=count(L-1), br=count(R);
        long long res=0;
        double t;
        for(int i=0;i<=31;i++)
            if ((br.a[i]-bl.a[i])%2!=0){
                t=pow(2.0,i);
                res=res+(long long)t;
            }
        return res;
    };
};
