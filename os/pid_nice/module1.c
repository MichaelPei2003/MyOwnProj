#include <linux/init.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/moduleparam.h>


static pid_t pid = 1;
static int nice;

module_param(pid, int, 0644);
module_param(nice, int, 0644);
static int setnice_init(void)
{
    struct task_struct *ppid;
    int n;
    ppid = pid_task(find_get_pid(pid), PIDTYPE_PID);
    if (ppid == NULL)
    {
        printk(KERN_ALERT "pid not found\n");
        return 0;
    }
    n = task_nice(ppid);
    printk("pid: %d, nice: %d, prio: %d\n", ppid->pid, n, ppid->static_prio);
    if (nice < -20 || nice > 19)
    {
        printk(KERN_ALERT "nice erro\n");
        return 0;
    }
    else
    {
        set_user_nice(ppid, nice);
        n = task_nice(ppid);
        printk("changed nice: %d, changed prio: %d \n", n, ppid->static_prio);
    }
    return 0;
}
static void setnice_exit(void)
{
    printk(KERN_ALERT "bye\n");
}
module_init(setnice_init);
module_exit(setnice_exit);
MODULE_LICENSE("GPL");