#include<iostream>
using namespace std;
void fun1(const int &a){
    cout<<a<<endl;
}
void fun2(int &a){
    cout<<a<<endl;
}
void fun3(const int a){
    cout<<a<<endl;
}
int main (){
    int a=10;
    fun1(10);
    fun2(a);
    fun3(10);
    return 0;
}
