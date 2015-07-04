#include<iostream>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
class huffmanTree_node{//树节点
    friend class huffmanTree;//树类 作为友源 通过静态函数调用  
    private://全部是私有只能通过友元类访问
        char data;
        huffmanTree_node *lchild,*rchild;
        int weight;
        string huffmancode;//生成霍夫曼编码 更好的解决方式?
        static void delete_node(huffmanTree_node *child);
        static void coding_node(huffmanTree_node *child,const string &code);
        static void print_node(huffmanTree_node *child);
        huffmanTree_node(const char &c,const int &w,huffmanTree_node *left=nullptr,huffmanTree_node *right=nullptr):data(c),weight(w),lchild(left),rchild(right){}
        //huffmanTree(const string &str);
        //~huffmanTree();
};
class huffmanTree{
    private:
        huffmanTree_node *node;
    public:
        huffmanTree(const string &str);
        void print_huffmanTree();
        ~huffmanTree();
};
huffmanTree::huffmanTree(const string &str){
    unordered_map<char,int> char_count;
    for(const auto &c:str){//记录字符出现的个数
        ++char_count[c];
    }
    vector<pair<int,huffmanTree_node*>> tree_set;//用vector有利于排序 注意这里的pair
    for(const auto &elem:char_count){
        pair<int,huffmanTree_node*> temp;
        temp.first=elem.second;
        temp.second=new huffmanTree_node(elem.first,elem.second);
        tree_set.push_back(temp);
    }
    sort(tree_set.begin(),tree_set.end(),[](const pair<int,huffmanTree_node*> &x,const pair<int,huffmanTree_node*> &y)->bool{return x.first<y.first;});//sort 第三个参数 lambda
    while(tree_set.size()>1){//建立霍夫曼树的过程
        auto new_node=new huffmanTree_node(0,tree_set[0].first+tree_set[1].first,tree_set[0].second,tree_set[1].second);
        pair<int,huffmanTree_node*> new_pair(tree_set[0].first+tree_set[1].first,new_node);
        tree_set.push_back(new_pair);
        tree_set.erase(tree_set.begin(),tree_set.begin()+2);//注意这里的erase 删除2个元素 为啥是+2 不是+1
        sort(tree_set.begin(),tree_set.end(),[](const pair<int,huffmanTree_node*> &x,const pair<int,huffmanTree_node*> &y)->bool{return x.first<y.first;});
    }
    this->node=tree_set[0].second;
    huffmanTree_node::coding_node(this->node,"");
}
huffmanTree::~huffmanTree(){
    huffmanTree_node::delete_node(node);
}
void huffmanTree::print_huffmanTree(){
    huffmanTree_node::print_node(node);
}
void huffmanTree_node::delete_node(huffmanTree_node *child){
    if(child!=nullptr){
        delete_node(child->lchild);
        delete_node(child->rchild);
        delete child;
    }
}
void huffmanTree_node::coding_node(huffmanTree_node *child,const string &code){
    if(child!=nullptr){
        child->huffmancode=code;
        coding_node(child->lchild,child->huffmancode+"0");
        coding_node(child->rchild,child->huffmancode+"1");
    }
}
void huffmanTree_node::print_node(huffmanTree_node *child){
    if(child!=nullptr){
        if(child->lchild!=nullptr||child->rchild!=nullptr){
            print_node(child->lchild);
            print_node(child->rchild);
        }else{
            cout<<child->data<<" weight:"<<child->weight<<" huffmancode:"<<child->huffmancode<<endl;
        }
    }
}
int main (){
    /*fuck everthing here!*/
    string s1;
    cin>>s1;
    huffmanTree tree1(s1);
    tree1.print_huffmanTree();
	//system("pause");
    return 0;
}
