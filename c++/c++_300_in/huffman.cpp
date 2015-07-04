#include<iostream>
#include<string>
using namespace std;
struct huffTree{
    int parent;
    int lchild;
    int rchild;
    int weight;
    string flag;
};
struct Lowest_Node{
    char ch;
    int ch_num;
};
void coding(int length,huffTree tree[],int n,int &a,int &b){
    int i;
    int r,s;
    r=s=length;
    for(i=0;i<n;++i){
        if((tree[i].weight<r)&&(tree[i].parent==-1)){
            r=tree[i].weight;
            a=i;
        }
    }
}
