#include <unistd.h>
#include <sys/syscall.h>
#include <sys/prctl.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

char process_name[16];

/*548 pidsyscall asmlinkage long sys_pidsyscall(pid_t pid,int flag,int nicevalue,void __user *prio,void __user *nice);*/

int main()
{
	pid_t pid;
	char strin[100];
	int nicevalue = 3100;
	int flag = 2;
	int p = 0;
	int n = 0;
	int *prio;
	int *nice;
	prio = &p;
	nice = &n;
	pid_t cPID = getpid();
	while (1)
	{
		printf("Current Thread PID: %d\n", cPID);
		printf("Input 0 to show current nice & prio, 1 to change nice, -1 to exit.\n");
		scanf("%d", &flag);
		if (flag != 0 && flag != 1 && flag != -1)
		{
			printf("Invalid Input!");
			continue;
		}
		if (flag == -1)
		{
			exit(0);
		}
		printf("Please input PID:\n");
		// get target pid
		scanf("%d", &pid);


		if (kill(pid, 0) == 0)
		{
			printf("Process with PID %d exists.\n", pid);
		}
		else
		{
			perror("kill");
			printf("Process with PID %d does not exist or you don't have permission to signal it.\n", pid);
			continue;
		}

		syscall(548, pid, flag, nicevalue, prio, nice);
		if (flag == 1)
		{
			printf("PID:%d nice:%d prio:%d \n", pid, n, p);
			printf("Please input nice:\n");
			// read nice
			scanf("%d", &nicevalue);
			while (nicevalue < -20 || nicevalue > 19)
			{
				printf("Invalid nice value!\n");
				scanf("Please input nice:%d", &nicevalue);
			}
			syscall(548, pid, flag, nicevalue, prio, nice);
		}

		printf("Current nice:%d\nCurrent prio:%d\nPress any ket to continue...\n", n, p);
		getchar();
		fgets(strin, 100, stdin);
		system("clear");
	}
}
