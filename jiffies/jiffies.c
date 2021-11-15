#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Hello world!\n");
	return 0;
}
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <asm/param.h>
#include <linux/jiffies.h>

/**
 *  This function is called, when the module is loaded into the kernel
 */
#define BUFFER_SIZE 128
#define PROC_NAME "jiffies"

ssize_t proc_read(struct file *file, char __user *usr_buf,
	size_t count, loff_t *pos);

static struct file_operations proc_ops =
{

	.owner = THIS_MODULE,
	.read = proc_read,
};

int proc_init(void)
{
	/* it will create the /proc/jiffies entry  */
	proc_create(PROC_NAME, 0666, NULL, &proc_ops);
	return 0;
}

/**
 * @brief This function is called, when the module is removed from the kernel
 */
void proc_exit(void)
{

	/* it will remove the /proc/jiffies entry */
	remove_proc_entry(PROC_NAME, NULL);
}

/* Here in  this function is called each time /proc/jiffies is read */
ssize_t proc_read(struct file *file, char __user *usr_buf,
	size_t count, loff_t *pos)
{
	int rv = 0;
	char buffer[BUFFER_SIZE];
	static int completed = 0;

	if (completed)
	{
		completed = 0;
		return 0;
	}

	completed = 1;

	rv = sprintf(buffer, "JIFFIES: %lu\n", jiffies);
	/* copies kernel space buffer to user space usr buf */
	raw_copy_to_user(usr_buf, buffer, rv);
	return rv;
}

/*module entry and exit points*/
module_init(proc_init);
module_exit(proc_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("RAHUL V M");
MODULE_DESCRIPTION("PROC FILE FOR JIFFIES");

