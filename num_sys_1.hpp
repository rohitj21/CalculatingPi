#define M 32
#include<iostream>
using namespace std;
typedef struct Num
{
    char x[2*M];

} num;

void prt(num n){
    int i =0;
    while(n.x[i]==0&&i<M-1)i++;
    for(; i<M; i++) printf("%d", n.x[i]);
    int t=2*M-1;
    while(n.x[t]==0 && t>M-1) t--;
    if(t!=M-1){
        cout<<'.';
        for(int i=M; i<=t;i++)
            printf("%d", n.x[i]);
    }
}
num number(const char k[]){
    num n;
    for(int i = 0; i<2*M; i++) n.x[i]=0;
    int a=0, b=0, c;
    for(;;b++)if(k[b]=='\0') break;
    for(;;a++)if(k[a]=='.'||k[a]=='\0') break;
    if(a==b) c=0;
    else c = b-a-1;
    for(int i=0; i<a; i++)n.x[M-a+i] = k[i] - '0';
    for(int i = 0; i<c; i++)n.x[M+i] = k[i+a+1]-'0';
    return n;
}
num add(num a, num b){
    num ans;
    char carry = 0;
    for(int i= 2*M - 1; i>=0; i--){
        ans.x[i] = (a.x[i]+b.x[i] + carry)%10;
        carry  = (a.x[i]+b.x[i] + carry)/10;
    }
    return ans;
}
num sbt(num a, num b){
    num ans;
    char carry = 0;
    for(int i = 2*M -1; i>=0; i--){
        ans.x[i] = (a.x[i]-b.x[i]+10 + carry)%10;
        carry = (a.x[i]-b.x[i]+carry-9)/10;
    }
    return ans;
}
num neg(num a){
    return sbt(number("0"), a);
}
num lshift(num a, int k);
num rshift(num a, int k){
    num ans ;
    if(k<=0) return lshift(a, -k);
    for(int i= 2*M - 1-k; i>=0; i--){
        ans.x[i+k]= a.x[i];
    }
    for(int i=k-1;i>=0; i--){
        ans.x[i] = 0;
    }
    return ans;
}
num lshift(num a, int k){
    num ans ;
    if(!k) return a;
    if(k<0) return rshift(a, -k);
    for(int i= k; i<2*M; i++){
        ans.x[i-k]= a.x[i];
    }
    for(int i=0; i<k; i++){
        ans.x[2*M -k+i] = 0;
    }
    return ans;
}
num smlt(num a, char b){
    char carry = 0;
    num ans ;
    for( int i= 2*M -1; i>=0; i--){
        ans.x[i] = (a.x[i] * b +carry )%10;
        carry = (a.x[i] * b +carry )/10;
    }
    return ans;

}
num mlt(num a, num b){
    num ans = number("0");
    for(int i = 2*M -1; i>=0; i--){
        if(b.x[i]){
            ans =add(ans, lshift(smlt(a, b.x[i]), M - 1-i));
        }
    }
    return ans;
}