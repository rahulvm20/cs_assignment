/**
 * jiffies.c
 *
 * Show the value of jiffies by help of kernel module by communicating through proc file system
 * Operating System Concepts - 10th Edition
 * Authored by Rahul V M
 *
 */


#include <linux/init.h>    /*This header file includes all things related to __init part*/
#include <linux/module.h>  /*This is where module_init and module_exit are defined*/ 
#include <linux/proc_fs.h> /*This header file is mainly used to invoke the function such as proc_create(), proc_read(), proc_init(), proc_exit() etc.,*/
#include <linux/uaccess.h> /*This header file contains copy_to_user() function to copy buffer messages from kernel space to user space*/
#include <asm/param.h>     /*This header file use to access the HZ determine the frequency of time interrupt*/
#include <linux/jiffies.h> /*To access jiffies variable which maintains the number of timer interrupts that have occurred since the system was booted*/

MODULE_LICENSE("GPL"); /*To use any other system libraries running under GPL license*/
MODULE_AUTHOR("RAHUL VM"); /*This macro represents the author of the present kernel code*/
MODULE_DESCRIPTION("PROC FILE FOR JIFFIES"); /*This macro contains the description of the present working kernel code*/

#define BUFFER_SIZE 128 /*defines a buffer of size 128 bytes that is used by this program*/
#define PROC_NAME "jiffies" /*This is where the module gets its name*/

/**
 *  This function is called, when the module is loaded into the kernel
 * 
 * This function is called repeatedly until it returns 0, so
 * there must be logic that ensures it ultimately returns 0
 * once it has collected the data that is to go into the 
 * corresponding /proc file.
 * 
 */

ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos);

static struct file_operations proc_ops = /* process file operations are being done*/
{

	.owner = THIS_MODULE,
	.read = proc_read,
};

/* This function is called, when the module is loaded to the kernel */
int proc_init(void) 
{
	proc_create(PROC_NAME, 0666, NULL, &proc_ops); /* it will create the /proc/jiffies entry  */
	return 0;
}

/* This function is called, when the module is removed from the kernel */
void proc_exit(void)  
{
	remove_proc_entry(PROC_NAME, NULL); /* it will remove the /proc/jiffies entry */
}

/* Here in  this function is called each time /proc/jiffies is read */
ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos)
{
	int rv = 0;
	char buffer[BUFFER_SIZE]; // defining buffer of size 128 bytes
	static int completed = 0;

	if (completed) /*To make sure this function is called repeatedly until this returns 1*/
	{
		completed = 0;
		return 0;
	}

	completed = 1;

	rv = sprintf(buffer, "JIFFIES: %lu\n", jiffies); /*Value of jiffies stored in jiffies variable that is a part of kernel buffer space*/
	raw_copy_to_user(usr_buf, buffer, rv); /* copies kernel space buffer to user space usr buf */
	return rv;
}

/*module entry and exit points*/
module_init(proc_init); /*This is the entry point to the kernel module*/
module_exit(proc_exit); /*This is the exit point to the kernel module where it unregisters the module functionality from the kernel*/



