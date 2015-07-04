#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    pid_t pid;
    pid=fork();
    if(pid<0){
        fprintf(stderr,"fork failed");
        exit(-1);
    }else if(0==pid){
        execlp("/bin/ls","ls",NULL);
    }else{
        wait(NULL);
        printf("child complete");
        exit(0);
    }
    return 0;
}
