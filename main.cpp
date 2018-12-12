#include <iostream>
#include <string>
using namespace std;
#include "P.h"

int M[26][26];

int main(){
cout<<"Please enter your message\r\n>";
string mess = GetStr();
int len = GetLen(mess);
int in = 0;
for(int i = 0;i<26;i++){
    for(int j = 0;j<26;j++){
        M[i][j]=in;
        in++;
    }
}
if(len%2!=0){
    mess+='a';
    len++;
}
int num = len/2;
int R[num][2];
int ind = 0;
for(int i = 0;i<num;i++){
    for(int j = 0;j<2;j++){
        char chm = mess[ind];
        chm-=97;
        R[i][j]=chm;
        ind++;
    }
}


int Enc[num]={0};
ind = 0;
for(int i = 0;i<num;i++){
    for(int j = 0;j<2;j++){
        Enc[ind]=M[R[i][j]][R[i][j+1]];
        ind++;
        break;
    }
}
cout<<"Your encrypted message is:\r\n";
for(int i = 0;i<num;i++){
    cout<<Enc[i]<<endl;
}
//Decryption
ind = 0;
string decr;
for(int z = 0;z<num;z++){
for(int i = 0;i<26;i++){
    for(int j = 0;j<26;j++){
        if(Enc[z]==M[i][j]){
            decr+=(char)i+97;
            decr+=(char)j+97;
        }
    }
}
}
cout<<"\r\nYour decrypted message is : ";
cout<<decr;
return 0;
}
