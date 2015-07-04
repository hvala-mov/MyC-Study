#ifndef GRAPH_H_
#define GRAPH_H_

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include"cur.h"
#include"cubePoint.h"
#include"rand.h"
using namespace std;
enum class Control{
    DOWN=0,
    LEFT,
    RIGHT
};
//const int DOWN=0;
//const int LEFT=1;
//const int RIGHT=2;

class Gbase{
    protected:
        int x;
        int y;//address[0][0]的位置
        int round;//roll的次数,因为图形出现的时候,角度应该是随机的
        int address[4][4];
    public:
        Gbase(){
            /*for(int i=0;i<3;++i){
                for(int j=0;j<3;++j){
                    address[i][j]=0;
                }
            }*/
            x=Rand::creatRand()->normal_randNum(8,1,1,15)-1;//-1是因为是以a[0][1]作参照的,假设区域是0-16宽,8是中点
            y=0;
            round=Rand::creatRand()->uniform_randNum(0,3);
            memset(address,0,sizeof(address));//初始化
        }
        int move(const Control &dir);
        virtual bool roll();//旋转跳跃我闭着眼..啦啦啦
        virtual void draw(){}//***********这里需要注意**********要有实现
        void setLocate(const int &ax,const int &ay){x=ax;y=ay;}
        void getLocate(int &ax,int &ay) const {ax=x;ay=y;}
        void setRound(const int &ax){round=ax;}
        void printGraph(const Colors &GraphColor);//打印图形
        //获取数组首地址
        void* getArray() const {return (void*)address;}//?void*?在想为啥用void*????????????????
        virtual ~Gbase(){}//************注意************虚析构函数
};

class Zgraph:public Gbase{
    public:
        void draw(){
            address[0][0]=1;
            address[0][1]=1;
            address[1][1]=1;
            address[1][2]=1;
            for(int i=0;i<round;++i){
                roll();
            }
        } 
};
class Tgraph:public Gbase{
    public:
        void draw(){
            address[0][0]=1;
            address[0][1]=1;
            address[0][2]=1;
            address[1][1]=1;
            for(int i=0;i<round;++i){
                roll();
            }

        }
};
class Ograph:public Gbase{
    public:
        void draw(){
            address[0][0]=1;
            address[0][1]=1;
            address[1][0]=1;
            address[1][1]=1;
            for(int i=0;i<round;++i){
                roll();
            }            
        }
        virtual bool roll(){return 0;}//这里虚函数?需不需要实现?
};
class Lgraph:public Gbase{
    public:
        void draw(){
            address[0][0]=1;
            address[0][1]=1;
            address[1][1]=1;
            address[2][1]=1;
            for(int i=0;i<round;++i){
                roll();
            }
        }  
};
class Igraph:public Gbase{
    public:
        Igraph(){
            x=Rand::creatRand()->normal_randNum(8,1.0,1,14)-1;//I比较长...
        }
        void draw(){
            address[0][0]=1;
            address[1][0]=1;
            address[2][0]=1;
            address[3][0]=1;
            for(int i=0;i<round;++i){
                roll();
            }            
        }    
};

class Context{//传说中的工厂模式?????
    private:
        Gbase *gbase;
    public:
        Context(const char &cType){
            switch(cType){
                case 'Z':
                    gbase=new Zgraph();
                    break;
                case 'T':
                    gbase=new Tgraph();
                    break;
                case 'O':
                    gbase=new Ograph();
                    break;
                case 'L':
                    gbase=new Lgraph();
                    break;
                case 'I':
                    gbase=new Igraph();
                    break;
                default:
                    cout<<"Type error!"<<endl;
                    break;
            }
        }
        ~Context(){
            delete gbase;
        }
        int move(const Control &dir){return gbase->move(dir);}
        bool roll(){return gbase->roll();}
        void draw(){gbase->draw();}
        void setLocate(const int &ax,const int &ay) const {gbase->setLocate(ax,ay);}
        void getLocate(int &ax,int &ay){gbase->getLocate(ax,ay);}
        void* getArray() const {return gbase->getArray();}
        void printGraph(Colors &ContextColor){gbase->printGraph(ContextColor);}
};

#endif
