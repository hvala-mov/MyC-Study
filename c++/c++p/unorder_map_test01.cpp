#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main (){
    unordered_map<string,size_t> word_count;
    string word;
    cout<<"fucking input here:"<<endl;
    while(cin>>word){
        ++word_count[word];
    }
    for(auto temp:word_count){
        cout<<temp.first<<" "<<((temp.second>1)?"times:":"time:")<<temp.second<<endl;
    }
    cout<<"fucking over!"<<endl;
    cout<<"buket_count:"<<word_count.bucket_count()<<endl;
    cout<<"buket_count_max:"<<word_count.max_bucket_count()<<endl;
    for(auto num=0;num<word_count.bucket_count();++num){
        cout<<"bucket_size:"<<word_count.bucket_size(num)<<endl;
    }
    cout<<word_count.bucket("hello")<<endl;
    return 0;
}
