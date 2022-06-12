#include <stdio.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
int main()
{
    int pid = fork();
    if(pid < 0)
    {
        fprintf(stderr, "fork error\n");
        _exit(0);
    }
    else if(pid == 0)
    {
        printf("-----------------\n");
        printf("child PID = %d\n", getpid());
        // fork出的子进程 组id 是 父进程
        // 如果参数pid 为0, 则会取得目前进程的组识别码, 0本组
        printf("child group id is %d\n", getpgid(0));
        printf("child session id is %d\n", getsid(0));
        sleep(2);
        // 创建一个会话， 会长是创建者  
        setsid();
        printf("-----------------\n");
        printf("child PID = %d\n", getpid());
        printf("child group id is %d\n", getpgid(0));
        printf("child session id is %d\n", getsid(0));
        sleep(20);
// ps ajx
// tty： tty7文字终端，？是无终端，pts是虚拟终端
    }
    return 0;
}