#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<utility>
using namespace std;
class huffmanTree{
    private:
        char data;
        huffmanTree *parent,*left,*right;
        int weight;
    public:
        huffmanTree():data(0),parent(nullptr),left(nullptr),right(nullptr),int(0){}
        huffmanTree(const char &c,const int &w):data(c),parent(nullptr),left(nullptr),right(nullptr),weight(w){}
        huffmanTree(const char &c,const int &w,const huffmanTree *p){}
        void build_huffmanTree(const string &str){
            unordered_map<char,size_t> c_count;
            /*for(const auto &c:str){
                ++c_count[c];
            }*/
            //记录字符串中每个字符的出现次数
            for_each(str.begin(),str.end(),[&c_count](const auto &c){++c_count[c];});//c++11 tryout
            vectoe<pair<int,huffmanTree*>> tree_count;
            for_each(c_count.begin(),c_count.end(),[&tree_count](const auto &temp){});
            sort(tree_count.begin(),tree.end(),[](const auto &tree1,const auto &tree2)->bool{return tree1->first<tree2->first;});
            while(tree_count.size()!=1){
                auto new=make_huffman_node(tree_count[0],tree_count[1]);
                tree_count.erase(tree_count.begin(),tree_count.begin()+1);
                tree_count.insert(new,tree_count.begin());
                sort(tree_count.begin(),tree.end(),[](const auto &tree1,const auto &tree2)->bool{return tree1->first<tree2->first;});
            }
            tree_count[0]->second->travel_print();
        }
};
