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
        // 如果参数pid 为0, 则会取得目前进程的组识别码
        printf("child group id is %d\n", getpgid(0));
        printf("child session id is %d\n", getsid(0));
        sleep(2);
        // 设置为组长进程
        setsid();
        printf("-----------------\n");
        printf("child PID = %d\n", getpid());
        printf("child group id is %d\n", getpgid(0));
        printf("child session id is %d\n", getsid(0));
        sleep(5);

    }
    return 0;
}