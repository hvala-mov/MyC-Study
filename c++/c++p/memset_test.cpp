#include<iostream>
#include<cstring>
using namespace std;
int main (){
    int a[3][3];
    memset(a,0,sizeof(a));
    a[0][0]=1;
    a[1][1]=1;
    a[2][2]=1;
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            cout<<a[i][j]<<endl;
        }
    }
    return 0;
}
