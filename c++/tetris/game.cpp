#include"game.h"
#include"rand.h"
#include"graph.h"
#include"cubePoint.h"
#include<cstring>
#include<cstdio>
#include<pthread.h>
#include<unistd.h>
//#include<iostream>

const int SPEED=200000;
const int PENAL_SIZE=(17*24*sizeof(int));
const int CUBE_SIZE=(3*3*sizeof(int));

static int stop_flag;

static Rand r;//????????????

Game::Game(){
    m_graph=nullptr;
    x=1;
    y=7;
    CubePoint p;
    s.printMessage();
    memset((void*)m_penal,0,PENAL_SIZE);
    for(int i=0;i<24;++i){
        p.setLocate(i,0);
        p.setColor(BLUE);
        p.printPoint();
        p.setLocate(i,16);
        p.setColor(BLUE);
        p.printPoint();
        m_penal[i][0]=1;
        m_penal[i][16]=1;
    }
    for(int i=0;i<17;++i){
        p.setLocate(23,i);
        p.setColor(BLUE);
        p.printPoint();
        p.setLocate(0,i);
        p.setColor(BLUE);
        p.printPoint();
        m_penal[23][i]=1;
        m_penal[0][i]=1;
    }
}

char Game::getShape(){
    char ch;
    switch(r.randNum(1,5)){
        case 1:
            ch='Z';
            break;
        case 2:
            ch='T';
            break;
        case 3:
            ch='O';
            break;
        case 4:
            ch='I';
            break;
        case 5:
            ch='L';
            break;
        default:
            cout<<"There is no this shape type!"<<endl;
            ch='\0';
            break;
    }
    return ch;
}

/*
    }
    for(int i=0;i<17;++i){
        p.setLocate(23,i);
        p.setColor(BLUE);
        p.printPoint();
        p.setLocate(0,i);
        p.setColor(BLUE);
        p.printPoint();
        m_penal[23][i]=1;
        m_penal[0][i]=1;
    }
}
*/
//void Context::printGraph(Colors &color);

bool Game::erasePenal(){
    int temp[3][3]={0};
    m_graph->printGraph(CLEAR);
    memcpy(temp,m_graph->getArray(),CUBE_SIZE);
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            m_penal[i+x][j+y]-=temp[i][j];
        }
        return true;
    }
    return false;
}

bool Game::recoverPenal(){
    int temp[3][3]={0};
    memcpy(temp,m_graph->getArray(),CUBE_SIZE);
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            m_penal[i+x][j+y]+=temp[i][j];
        }
    }
    return true;
}

bool Game::setPenal(){
    int temp[3][3]={0};
    m_graph->getLocate(x,y);
    memcpy(temp,m_graph->getArray(),CUBE_SIZE);
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            m_penal[i+x][j+y]+=temp[i][j];
            if(m_penal[i][j]>1){
                cout<<"game over!"<<endl;
                system("sttyicanon echo");
                exit(0);
            }
        }
    }
    return true;
}

void Game::createCube(){
    m_graph=new Context(getShape());
    m_graph->draw();
    m_graph->setLocate(1,7);
    setPenal();
    m_graph->printGraph(YELLOW);
}

void Game::move(const int &dir){
    erasePenal();
    switch(dir){
        case DOWN:
            if(false==isAttachBottom()){
                m_graph->move(DOWN);
                setPenal();
                m_graph->printGraph(YELLOW);
            }else{
                recoverPenal();
                m_graph->printGraph(YELLOW);
                erase();
                stop();
            }
            break;
        case LEFT:
            if(false==isAttachBottom()){
                m_graph->move(LEFT);
                setPenal();
                m_graph->printGraph(YELLOW);
            }else{
                recoverPenal();
                m_graph->printGraph(YELLOW);
                erase();
                stop();
            }
            break;
        case RIGHT:
            if(false==isAttachBottom()){
                m_graph->move(RIGHT);
                setPenal();
                m_graph->printGraph(YELLOW);
            }else{
                recoverPenal();
                m_graph->printGraph(YELLOW);
                erase();
                stop();
            }
            break;
        default:
            break;
    }
}

void Game::roll(){
    //取出方块的值，先放到一个数组中
    bool flag=false;
    int temp[3][3]={0};
    int rolled_temp[3][3]={0};
    m_graph->getLocate(x,y);
    memcpy(temp,m_graph->getArray(),CUBE_SIZE);
    erasePenal();
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            rolled_temp[2-j][i]=temp[i][j];
        }
    }
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(1==rolled_temp[i][j]&&1==m_penal[x+i][y+j]){
                flag=true;
                break;
            }
        }
    }
    if(false==flag){
        m_graph->roll();
    }
    setPenal();
    m_graph->printGraph(YELLOW);
}

void Game::stop(){
    delete m_graph;
    stop_flag=1;
    createCube();
}

bool Game::isAttachBottom(){
    int cube_x,cube_y;
    int temp[3][3]={0};
    bool flag=false;
    m_graph->getLocate(cube_x,cube_y);
    memcpy(temp,m_graph->getArray(),CUBE_SIZE);
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(1==temp[i][j]&&1==m_penal[cube_x+i+1][cube_y+j]){
                flag=true;
                break;
            }
        }
        if(true==flag){
            break;
        }
    }
    return flag;
}

bool Game::isAttachLeft(){
    int cube_x,cube_y;
    int temp[3][3]={0};
    bool flag=false;
    m_graph->getLocate(cube_x,cube_y);
    memcpy(temp,m_graph->getArray(),CUBE_SIZE);
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(1==temp[i][j]&&1==m_penal[cube_x+i][cube_y+j-1]){
                flag=true;
                break;
            }
        }
        if(true==flag){
            break;
        }
    }
    return flag;
}

bool Game::isAttachRight(){
    int cube_x,cube_y;
    int temp[3][3]={0};
    bool flag=false;
    m_graph->getLocate(cube_x,cube_y);
    memcpy(temp,m_graph->getArray(),CUBE_SIZE);
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(1==temp[i][j]&&1==m_penal[cube_x+i][cube_y+j+1]){
                flag=true;
                break;
            }
        }
        if(true==flag){
            break;
        }
    }
    return flag;
}

void Game::erase(){
    bool flag=false;
    static int count=0;
    for(int i=22;i>0;--i){
        for(int j=1;j<16;++j){
            if(0==m_penal[i][j]){
                flag=true;
            }
        }
        if(0==flag){
            //加分
            ++count;
            s.setScore(count);
            s.printMessage();
            down(i);
            ++i;
        }
        flag=false;
    }
}

void Game::down(const int &level){
    //bool flag=true;
    for(int i=level;i>1;--i){
        for(int j=1;j<16;++j){
            m_penal[i][j]=m_penal[i-1][j];
        }
    }
    CubePoint p;
    for(int i=1;i<23;++i){
        for(int j=1;j<16;++j){
            if(1==m_penal[i][j]){
                p.setLocate(i,j);
                p.setColor(YELLOW);
                p.printPoint();
            }
            if(0==m_penal[i][j]){
                p.setLocate(i,j);
                p.setColor(CLEAR);
                p.printPoint();
            }
        }
    }
}

void* listenKey(void *ptr){
    Game *ptrg=(Game*)ptr;
    char key;
    while(true){
        system("stty -icanon -echo");
        key=getchar();
        system("stty -icanon -echo");
        switch(key){
            case 'a':
                ptrg->move(LEFT);
                break;
            case 'd':
                ptrg->move(RIGHT);
                break;
            case 'w':
                ptrg->roll();
                break;
            case 's':
                while(true){
                    if(1==stop_flag){
                        stop_flag=false;
                        break;
                    }
                    ptrg->move(DOWN);
                }
                break;
            default:
                break;
        }
    }
    return nullptr;
}

int main (){
    pthread_t t1;
    system("clear");
    Game g;
    g.createCube();
    pthread_create(&t1,NULL,listenKey,(void*)(&g));
    while(true){
        fflush(stdout);
        usleep(SPEED);
        g.move(DOWN);
    }
    return 0;
}
