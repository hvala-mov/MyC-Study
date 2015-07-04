#ifndef _GAME_H_
#define _GAME_H_

#include"graph.h"
#include"rand.h"
#include"score.h"

class Game{
    private:
        int m_penal[24][17];
        Context *m_graph;
        int x;
        int y;//当前方块的位置，方块移动或者旋转成功后才可以设置这个值
        Score s;
        
        bool recoverPenal();
        bool isAttachBottom();
        bool isAttachLeft();
        bool isAttachRight();
        char getShape();
        bool setPenal();
        bool erasePenal();
    public:
        Game();
        void createCube();
        void move(const int &dir);
        void roll();
        void stop();
        void erase();
        void down(const int &level);
};

#endif
