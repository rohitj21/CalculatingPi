#include<iostream>
#include<math.h>
using namespace std;
#define ll long long int
class num
{
public: 
    static const int M = 30;
    static int small;

public:
    char x[2*M];
    
public:
    //constructors
num(){}
num(int n){

    if(n==0){
        for(int i=0; i<2*M; i++) x[i]=0;
    }
    else if(n>0){
        int i=2*M-1;
        for(; i>=M; i--) x[i] = 0;
        for (; i >=0; i--) {x[i]= n %10; n/=10;}
    }
    else {
        n*=-1;
        int i=2*M-1;
        for(; i>=M; i--) x[i] = 0;
        for(; i>=0; i--) { x[i] = 9 - n%10; n/=10;}
        for(i = M-1; i>=0; i--) {
            if(x[i]<9) {
                x[i]++;
                return ;
            }
            else x[i] = 0;
        }
    }  
}
num(double y){
    if(y==0){
        for(int i=0; i<2*M; i++) x[i]=0;
    }
    else if(y>0){
        ll n = y;
        
        for (int i=M-1; i >=0; i--) {x[i]= n %10; n/=10;}
        y = y - ((ll)y);
        for(int i =M; i<2*M; i++){
            y = y*10;
            x[i] = (ll)y;
            y = y - ((ll)y);
        }
    }
    else {
        y*=-1.0;
        int i=M-1;
        ll n = y;
        for(; i>=0; i--) { x[i] = 9 - n%10; n/=10;}

        y = y - ((ll)y);
        for(int i =M; i<2*M; i++){
            y = y*10;
            x[i] = 9-(ll)y;
            y = y - ((ll)y);
        }

        for(i = 2*M-1; i>=0; i--) {
            if(x[i]<9) {
                x[i]++;
                return ;
            }
            else x[i] = 0;
        }
    }

    
}
num(const char k[]){
        int a=0, b=0;
        for(;;b++)if(k[b]=='\0') break;
        for(;;a++)if(k[a]=='.'||k[a]=='\0') break;
        b= a==b? 0:b-a-1;
        if(k[0] == '-'){
            for(int i = 0; i<2*M; i++) x[i]=9;
            a--;
            for(int i=0; i<a; i++) x[M-a+i] -= k[i+1] - '0';
            for(int i = 0; i<b; i++) x[M+i] -= k[i+a+2]-'0';
            for(int i=2*M-1; i>=0; i--){
                if(x[i]<9){x[i]++;return;}
                x[i] = 0;
            }

        }
        else{
            for(int i = 0; i<2*M; i++) x[i]=0;
            for(int i=0; i<a; i++)x[M-a+i] = k[i] - '0';
            for(int i = 0; i<b; i++)x[M+i] = k[i+a+1]-'0';
        }
}
    
// operators
        // assignment
void operator = (num b){
    for(int i=0; i<2*M -1; i++) x[i] = b.x[i];return;
}
void operator = (int n){
    
    if(n==0){
        for(int i=0; i<2*M; i++) x[i]=0;
    }
    else if(n>0){
        int i=2*M-1;
        for(; i>=M; i--) x[i] = 0;
        for (; i >=0; i--) {x[i]= n %10; n/=10;}
    }
    else {
        n*=-1;
        int i=2*M-1;
        for(; i>=M; i--) x[i] = 0;
        for(; i>=0; i--) { x[i] = 9 - n%10; n/=10;}
        for(i = M-1; i>=0; i--) {
            if(x[i]<9) {
                x[i]++;
                return ;
            }
            else x[i] = 0;
        }
    }
}
void operator = (double y){
       
    if(y==0){
        for(int i=0; i<2*M; i++) x[i]=0;
    }
    else if(y>0){
        int n = y;
        
        for (int i=M-1; i >=0; i--) {x[i]= n %10; n/=10;}
        y = y - ((int)y);
        for(int i =M; i<2*M; i++){
            y = y*10;
            x[i] = (int)y;
            y = y - ((int)y);
        }
    }
    else {
        y*=-1.0;
        int i=M-1;
        int n = y;
        for(; i>=0; i--) { x[i] = 9 - n%10; n/=10;}

        y = y - ((int)y);
        for(int i =M; i<2*M; i++){
            y = y*10;
            x[i] = 9-(int)y;
            y = y - ((int)y);
        }

        for(i = 2*M-1; i>=0; i--) {
            if(x[i]<9) {
                x[i]++;
                return ;
            }
            else x[i] = 0;
        }
    }

}
void operator =(const char k[]){
            int a=0, b=0;
        for(;;b++)if(k[b]=='\0') break;
        for(;;a++)if(k[a]=='.'||k[a]=='\0') break;
        b= a==b? 0:b-a-1;
        if(k[0] == '-'){
            for(int i = 0; i<2*M; i++) x[i]=9;
            a--;
            for(int i=0; i<a; i++) x[M-a+i] -= k[i+1] - '0';
            for(int i = 0; i<b; i++) x[M+i] -= k[i+a+2]-'0';
            for(int i=2*M-1; i>=0; i--){
                if(x[i]<9){x[i]++;return;}
                x[i] = 0;
            }

        }
        else{
            for(int i = 0; i<2*M; i++) x[i]=0;
            for(int i=0; i<a; i++)x[M-a+i] = k[i] - '0';
            for(int i = 0; i<b; i++)x[M+i] = k[i+a+1]-'0';
        }
}

public:

    // increment 
void operator ++ (int){
    for(int i=M-1; i>=0; i--) {
        if(x[i]!= 9) {
            x[i]++;
            return;
        }
        x[i]=0;
    }
}
void operator += (num  b){
    char carry = 0, t;
    for(int i= 2*M -1; i>=0; i--){
        t = (x[i] + carry + b.x[i]);
        x[i] = t%10;
        carry = t/10;
    }
}
void operator += (int n){
    num b(n);
    char carry = 0, t;
    for(int i= 2*M -1; i>=0; i--){
        t = (x[i] + carry + b.x[i]);
        x[i] = t%10;
        carry = t/10;
    }
}
void operator +=(double y){
    num b(y);
    char carry = 0, t;
    for(int i= 2*M -1; i>=0; i--){
        t = (x[i] + carry + b.x[i]);
        x[i] = t%10;
        carry = t/10;
    }
}
    // decrement 
void operator -- (int){

    for(int i=M-1; i>=0; i--) {
        if(x[i]) {
            x[i]--;
            return;
        }
        x[i]=9;
    }

}
void operator -= (num  b){
    char carry = 0, t;
    for(int i = 2*M -1; i>=0; i--){
        t = (x[i]- b.x[i]+ carry+10);
        x[i] = t%10;
        carry = (t-19)/10;
    }
}
void operator -= (int n){
    num b(n);
    char carry = 0, t;
    for(int i = 2*M -1; i>=0; i--){
        t = (x[i]- b.x[i]+ carry+10);
        x[i] = t%10;
        carry = (t-19)/10;
    }
}
void operator -=(double y){
    num b(y);
    char carry = 0, t;
    for(int i = 2*M -1; i>=0; i--){
        t = (x[i]- b.x[i]+ carry+10);
        x[i] = t%10;
        carry = (t-19)/10;
    }
}

    // addition
num operator + (num  b){
    num ans;
    char carry = 0;
    for(int i= 2*M - 1; i>=0; i--){
        ans.x[i] = (x[i]+b.x[i] + carry)%10;
        carry  = (x[i]+b.x[i] + carry)/10;
    }
    return ans;
}
num operator + (int n){
    return  (*this) + num(n);
}
num operator + (double y){
    return  (*this) + num(y);
}
    // negetion
num operator - (){
    num b;
    int j=2*M-1;
    for(;!x[j] && j>=0; j--){
        b.x[j] =0;
    }
    if(j>=0)
        b.x[j] = 10 -x[j];
    for(j--;j>=0; j--) 
        b.x[j] =9 - x[j];
    return b;
}
    // subtraction
num operator - (num  b){
    num ans;
    char carry = 0;
    for(int i = 2*M -1; i>=0; i--){
        ans.x[i] = (x[i]-b.x[i]+10 + carry)%10;
        carry = (x[i]-b.x[i]+carry-9)/10;
    }
    return ans;
}
num operator - (int n){
    return  (*this) - num(n);
}
num operator - (double y){
    return  (*this) - num(y);
}

  // comparision
bool operator == (num  b){
    for(int i =2*M-1; i>=0; i--){
        if(x[i]!=b.x[i]) return false;
    }
    return true;
}
bool operator == (int n){
    num b(n);
        for(int i =2*M-1; i>=0; i--){
        if(x[i]!=b.x[i]) return false;
    }
    return true;
}
bool operator == (double y){
    num b(y);
    for(int i =2*M-1; i>=0; i--){
        if(x[i]!=b.x[i]) return false;
    }
    return true;
    
}
bool operator == (const char k[]){
    num b(k);
    for(int i =2*M-1; i>=0; i--){
        if(x[i]!=b.x[i]) return false;
    }
    return true;
    
}

bool operator != (num  b){
    for(int i =2*M-1; i>=0; i--){
        if(x[i]!=b.x[i]) return true;
    }
    return false;
}
bool operator != (int n){
    num b(n);
        for(int i =2*M-1; i>=0; i--){
        if(x[i]!=b.x[i]) return true;
    }
    return false;
}
bool operator != (double y){
    num b(y);
    for(int i =2*M-1; i>=0; i--){
        if(x[i]!=b.x[i]) return true;
    }
    return false;
    
}
bool operator != (const char k[]){
    num b(k);
    for(int i =2*M-1; i>=0; i--){
        if(x[i]!=b.x[i]) return true;
    }
    return false;
    
}

bool operator > (num  b){
    if(x[0]>=5 && b.x[0] < 5) return  false;
    if(x[0]<=5 && b.x[0] > 5) return  true;
    if(x[0]<=5 && b.x[0] < 5) {
        for(int i=0; i<2*M; i++){
            if(x[i] != b.x[i]){
                return x[i]>b.x[i];
            }
        }
        return false;
    }
    
    for(int i=0; i<2*M; i++){
        if(x[i] != b.x[i]){
            return x[i]<b.x[i];
        }
    }
        return false;
}
bool operator > (int n){
    if(!n){
        if(x[0]) return  x[0]<5;
        else for(int i=1; i<2*M;i++) if(x[i]) return  true;
        return false;
    }
    if(x[0]>=5 && n>0) return  false;
    if(x[0]<=5 && n<0) return  true;
    if(x[0]<=5 && n>0) {
        num b(n);
        for(int i=0; i<2*M; i++){
            if(x[i] != b.x[i]){
                return x[i]>b.x[i];
            }
        }
        return false;
    }
    num b(n);
    for(int i=0; i<2*M; i++){
        if(x[i] != b.x[i]){
            return x[i]<b.x[i];
        }
    }
        return false;
}
bool operator > (double y){
    if(!y){
        if(x[0]) return  x[0]<5;
        else for(int i=1; i<2*M;i++) if(x[i]) return  true;
        return false;
    }
    if(x[0]>=5 && y>0) return  false;
    if(x[0]<=5 && y<0) return  true;
    if(x[0]<=5 && y>0) {
        num b(y);
        for(int i=0; i<2*M; i++){
            if(x[i] != b.x[i]){
                return x[i]>b.x[i];
            }
        }
        return false;
    }
    num b(y);
    for(int i=0; i<2*M; i++){
        if(x[i] != b.x[i]){
            return x[i]<b.x[i];
        }
    }
        return false;
}
bool operator > (const char k[]){
    num b(k);
    if(x[0]>=5 && b.x[0] < 5) return  false;
    if(x[0]<=5 && b.x[0] > 5) return  true;
    if(x[0]<=5 && b.x[0] < 5) {
        for(int i=0; i<2*M; i++){
            if(x[i] != b.x[i]){
                return x[i]>b.x[i];
            }
        }
        return false;
    }
    
    for(int i=0; i<2*M; i++){
        if(x[i] != b.x[i]){
            return x[i]<b.x[i];
        }
    }
        return false;
}

bool operator >= (num  b){
    if(x[0]>=5 && b.x[0] < 5) return  false;
    if(x[0]<=5 && b.x[0] > 5) return  true;
    if(x[0]<=5 && b.x[0] < 5) {
        for(int i=0; i<2*M; i++){
            if(x[i] != b.x[i]){
                return x[i]>b.x[i];
            }
        }
        return true;
    }
    
    for(int i=0; i<2*M; i++){
        if(x[i] != b.x[i]){
            return x[i]<b.x[i];
        }
    }
        return true;
}
bool operator >= (int n){
    if(!n) return x[0]<5;
    if(x[0]>=5 && n>0) return  false;
    if(x[0]<=5 && n<0) return  true;
    if(x[0]<=5 && n>0) {
        num b(n);
        for(int i=0; i<2*M; i++){
            if(x[i] != b.x[i]){
                return x[i]>b.x[i];
            }
        }
        return true;
    }
    num b(n);
    for(int i=0; i<2*M; i++){
        if(x[i] != b.x[i]){
            return x[i]<b.x[i];
        }
    }
        return true;
}
bool operator >= (double y){
    if(!y) return x[0] < 5;
    if(x[0]>=5 && y>0) return  false;
    if(x[0]<=5 && y<0) return  true;
    if(x[0]<=5 && y>0) {
        num b(y);
        for(int i=0; i<2*M; i++){
            if(x[i] != b.x[i]){
                return x[i]>b.x[i];
            }
        }
        return true;
    }
    num b(y);
    for(int i=0; i<2*M; i++){
        if(x[i] != b.x[i]){
            return x[i]<b.x[i];
        }
    }
        return true;
}
bool operator >= (const char k[]){
    num b(k);
    if(x[0]>=5 && b.x[0] < 5) return  false;
    if(x[0]<=5 && b.x[0] > 5) return  true;
    if(x[0]<=5 && b.x[0] < 5) {
        for(int i=0; i<2*M; i++){
            if(x[i] != b.x[i]){
                return x[i]>b.x[i];
            }
        }
        return true;
    }
    
    for(int i=0; i<2*M; i++){
        if(x[i] != b.x[i]){
            return x[i]<b.x[i];
        }
    }
        return true;
}


bool operator <= (num  b){
    if(x[0]>=5 && b.x[0] < 5) return  true;
    if(x[0]<=5 && b.x[0] > 5) return  false;
    if(x[0]<=5 && b.x[0] < 5) {
        for(int i=0; i<2*M; i++){
            if(x[i] != b.x[i]){
                return x[i]<b.x[i];
            }
        }
        return true;
    }
    
    for(int i=0; i<2*M; i++){
        if(x[i] != b.x[i]){
            return x[i]>b.x[i];
        }
    }
        return true;
}
bool operator <= (int n){
    if(!n){
        if(x[0]) return  x[0]>=5;
        else for(int i=1; i<2*M;i++) if(x[i]) return  false;
        return true;
    }
    if(x[0]>=5 && n>0) return  true;
    if(x[0]<=5 && n<0) return  false;
    if(x[0]<=5 && n>0) {
        num b(n);
        for(int i=0; i<2*M; i++){
            if(x[i] != b.x[i]){
                return x[i]<b.x[i];
            }
        }
        return true;
    }
    num b(n);
    for(int i=0; i<2*M; i++){
        if(x[i] != b.x[i]){
            return x[i]>b.x[i];
        }
    }
        return true;
}
bool operator <= (double y){
    if(!y){
        if(x[0]) return  x[0]>=5;
        else for(int i=1; i<2*M;i++) if(x[i]) return  false;
        return true;
    }
    if(x[0]>=5 && y>0) return  true;
    if(x[0]<=5 && y<0) return  false;
    if(x[0]<=5 && y>0) {
        num b(y);
        for(int i=0; i<2*M; i++){
            if(x[i] != b.x[i]){
                return x[i]<b.x[i];
            }
        }
        return true;
    }
    num b(y);
    for(int i=0; i<2*M; i++){
        if(x[i] != b.x[i]){
            return x[i]>b.x[i];
        }
    }
        return true;
}
bool operator <= (const char k[]){
    num b(k);
    if(x[0]>=5 && b.x[0] < 5) return  true;
    if(x[0]<=5 && b.x[0] > 5) return  false;
    if(x[0]<=5 && b.x[0] < 5) {
        for(int i=0; i<2*M; i++){
            if(x[i] != b.x[i]){
                return x[i]<b.x[i];
            }
        }
        return true;
    }
    
    for(int i=0; i<2*M; i++){
        if(x[i] != b.x[i]){
            return x[i]>b.x[i];
        }
    }
        return true;
}

bool operator < (num  b){
    if(x[0]>=5 && b.x[0] < 5) return  true;
    if(x[0]<=5 && b.x[0] > 5) return  false;
    if(x[0]<=5 && b.x[0] < 5) {
        for(int i=0; i<2*M; i++){
            if(x[i] != b.x[i]){
                return x[i]<b.x[i];
            }
        }
        return false;
    }
    
    for(int i=0; i<2*M; i++){
        if(x[i] != b.x[i]){
            return x[i]>b.x[i];
        }
    }
        return false;
}
bool operator < (int n){
    if(!n) return x[0]>=5;
    if(x[0]>=5 && n>0) return  true;
    if(x[0]<=5 && n<0) return  false;
    if(x[0]<=5 && n>0) {
        num b(n);
        for(int i=0; i<2*M; i++){
            if(x[i] != b.x[i]){
                return x[i]<b.x[i];
            }
        }
        return false;
    }
    num b(n);
    for(int i=0; i<2*M; i++){
        if(x[i] != b.x[i]){
            return x[i]>b.x[i];
        }
    }
        return false;
}
bool operator < (double y){
    if(!y) return x[0] >= 5;
    if(x[0]>=5 && y>0) return  true;
    if(x[0]<=5 && y<0) return  false;
    if(x[0]<=5 && y>0) {
        num b(y);
        for(int i=0; i<2*M; i++){
            if(x[i] != b.x[i]){
                return x[i]<b.x[i];
            }
        }
        return false;
    }
    num b(y);
    for(int i=0; i<2*M; i++){
        if(x[i] != b.x[i]){
            return x[i]>b.x[i];
        }
    }
        return false;
}
bool operator < (const char k[]){
    num b(k);
    if(x[0]>=5 && b.x[0] < 5) return  true;
    if(x[0]<=5 && b.x[0] > 5) return  false;
    if(x[0]<=5 && b.x[0] < 5) {
        for(int i=0; i<2*M; i++){
            if(x[i] != b.x[i]){
                return x[i]<b.x[i];
            }
        }
        return false;
    }
    
    for(int i=0; i<2*M; i++){
        if(x[i] != b.x[i]){
            return x[i]>b.x[i];
        }
    }
        return false;
}

   // multiplication
num operator * (num b){
    if(x[0]<5 && b.x[0]<5){
        int ans[4*M-1];
        for(int i=0; i<4*M; i++) ans[i]=0;
        
        for(int i=2*M -1; i>=0; i--){
            if(!b.x[i]) continue;
            for(int j= 2*M-1; j>=0; j--){
                ans[i+j] += (x[j] * b.x[i]); 
            }
        }
        for(int i=4*M-2; i>0; i--){
            ans[i-1] += ans[i]/10;
            ans[i] = ans[i]%10;
        }
        int i=0;
        num k;
        for(;i<2*M; i++){
            k.x[i] = ans[M-1+i];
        }
        return k;
    }
    if(x[0]>=5 && b.x[0]<5){
        num  c = - (*this);
        int ans[4*M-1];
        for(int i=0; i<4*M; i++) ans[i]=0;
        for(int i=2*M -1; i>=0; i--){
            if(!c.x[i]) continue;
            for(int j= 2*M-1; j>=0; j--){
                ans[i+j] += (int)(b.x[j] * c.x[i]); 
            }
        }
        for(int i=4*M-2; i>0; i--){
            ans[i-1] += ans[i]/10;
            ans[i] = ans[i]%10;
        }
        int i=0;
        num k;
        for(;i<2*M; i++){
            k.x[i] = ans[M-1+i];
        }
        return -k;


    }
    if(x[0]<5 && b.x[0]>=5) {
        num  c = - b;
        int ans[4*M-1];
        for(int i=0; i<4*M; i++) ans[i]=0;
        for(int i=2*M -1; i>=0; i--){
            if(!c.x[i]) continue;
            for(int j= 2*M-1; j>=0; j--){
                ans[i+j] += (int)(x[j] * c.x[i]); 
            }
        }
        for(int i=4*M-2; i>0; i--){
            ans[i-1] += ans[i]/10;
            ans[i] = ans[i]%10;
        }
        int i=0;
        num k;
        for(;i<2*M; i++){
            k.x[i] = ans[M-1+i];
        }
        return -k;


    }
    else {
        num  c = - (*this);
        num d = - b;
        int ans[4*M-1];
        for(int i=0; i<4*M; i++) ans[i]=0;
        for(int i=2*M -1; i>=0; i--){
            if(!d.x[i]) continue;
            for(int j= 2*M-1; j>=0; j--){
                ans[i+j] += (int)(c.x[j] * d.x[i]); 
            }
        }
        for(int i=4*M-2; i>0; i--){
            ans[i-1] += ans[i]/10;
            ans[i] = ans[i]%10;
        }
        int i=0;
        num k;
        for(;i<2*M; i++){
            k.x[i] = ans[M-1+i];
        }
        return k;


    }
}
num operator * (int n) {
    if(n>10) {
        return  (*this) * num(n);
    }
    if(n< -9) {
        return - ((*this) * num(-n));
    }
    if(n>0){
        num ans;
        char carry  = 0;
        for(int i=2*M-1; i>=0; i--){
            ans.x[i] = (x[i]*n + carry)%10;
            carry = (x[i]*n+carry)/10;
        }
        return  ans;
    }
    if(n<0){
        num ans;
        n = -n;
        char carry  = 0;
        for(int i=2*M-1; i>=0; i--){
            ans.x[i] = (x[i]*n + carry)%10;
            carry = (x[i]*n+carry)/10;
        }
        return  -ans;
    }
    return num(0);
}\
num operator * (double y){
    return (*this) * num(y);
}

num abs(){
    if( (*this) >= 0) return *this;
    return -(*this);
}
    // division
num rec(){
    if(x[0]<5){
    num small(0);
    small.x[2*M-3] = 1;
    num guess(0);
    int r = 0;
    for(; !x[r] && r<2*M; r++);
    if(x[r]>1 ) guess.x[2*M-1-r] = 10/(x[r]);
    else guess.x[2*M-2-r] = 1; 
    
    num guess1; 
    num two(2);
    for(int i=0; i<2* log2(M); i++){ 
        guess.prt();
        cout<<endl;
        guess1=guess; 
        guess= guess1* (two - guess1*(*this)); 
        if((guess1-guess).abs() < small) break;
    }

    return guess;
    }

    else {
    num w = -(*this);
    num small(0);
    small.x[2*M-3] = 1;
    num guess(0);
    int r = 0;
    for(; !w.x[r] && r<2*M; r++);
    if(w.x[r]>1 ) guess.x[2*M-1-r] = (10/w.x[r]);
    else guess.x[2*M-2-r] = 1; 
    
    num guess1; 
    num two(2);
    for(int i=0; i<2*log2(M); i++){
        guess1=guess; 
        guess= guess1* (two - guess1*w);
        if((guess1-guess).abs() < small) break;
    }
    return -guess;
    }
}

num operator / (num b){

    if(x[0]<5 && b.x[0]<5){
        return (*this) * (b.rec());
    }
    if(x[0]<5 && b.x[0]>=5){
        return - ((*this) * ((-b).rec()));
    }
    if(x[0]>=5 && b.x[0]<5){
        return  ((*this) * (b.rec()));
    }
    return (-(*this))   *   ((-b).rec());
}
    // usefull functions
void prt(){
        if(x[0]<5){
            int s = 0;
            int i =0;
            while(!x[i] && i<M-1)i++;
            for(; i<M; i++) {
                if(!((i)%5)) printf(" ");
                printf("%d", x[i]);
            }
            int t=2*M-1;
            while(x[t]==0 && t>M-1) t--;
            if(t!=M-1){
                std:: cout<<'.';
                s = 0;
                for(int i=M; i<=t;i++) {
                    if(!(s%5) && s) cout<<" ";s++;
                    printf("%d", x[i]);
                }
            }
        }

        else{
            num temp(0);
            std:: cout<<'-';
            int i=2*M-1;
            while(!x[i])i--;
            temp.x[i] = 10-x[i];
            for(i--; i>=0; i--) temp.x[i] = 9 - x[i];
            i =0;
            while(temp.x[i]==0 && i<M-1) i++;
            for(; i<M; i++) {
                if(!((i)%5)) printf(" ");
                printf("%d", temp.x[i]);
            }
            int t=2*M-1;
            while(temp.x[t]==0 && t>M-1) t--;
            if(t!=M-1){
                std:: cout<<'.';
                int s=0;
                for(int i=M; i<=t;i++)  {
                    if(!(s%5) && s) cout<<" ";s++;
                    printf("%d", temp.x[i]);
                }
            }


            
        }
    }
};
void prt(num a){
    a.prt();
}
