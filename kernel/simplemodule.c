/**
 * simplemodule.c
 *
 * Loading and un-loading of kernel modules
 * Operating System Concepts - 10th Edition
 * Authored by Rahul V M
 *
 */

#include <linux/module.h>  /*This is where module_init and module_exit are defined*/ 
#include <linux/init.h>    /*This header file includes all things related to __init part*/
#include <linux/hash.h>    /*Includes all the hashing functions which defines a constant value called GOLDEN_RATIO_PRIME*/
#include <linux/gcd.h>     /*This header file is used to access the gcd() function*/
#include <linux/uaccess.h> /*This header file contains copy_to_user() function to copy buffer messages from kernel space to user space*/
#include <linux/jiffies.h> /*To access jiffies variable which maintains the number of timer interrupts that have occurred since the system was booted*/


MODULE_LICENSE("GPL"); /*To use any other system libraries running under GPL license*/
MODULE_AUTHOR("RAHUL VM"); /*This macro represents the author of the present kernel code*/
MODULE_DESCRIPTION("BASIC CODE FOR LOADING AND REMOVING KERNEL MODULES"); /*This macro contains the description of the present working kernel code*/

unsigned long int start_time, end_time; /*To store value of jiffies during loading and unloading of module*/

/*this is the function that says what work must be done once module_init(func_name) is invoked during loading of the kernel taking this function name as its parameter*/
static int __init ModuleInit(void)
{
	start_time = jiffies;/*store jiffies time during loading module*/
	printk("\nHello kernel, loading the current kernel..!\n");
	printk("Golden ratio prime: %llu\n", GOLDEN_RATIO_PRIME);
	printk("Jiffies: %lu HZ: %d\n\n", jiffies, HZ);
	return 0;
}

/*This is the function that says what work must be done once module_exit(func_name) is invoked during unloading of the kernel taking this function name as its parameter*/
static void __exit ModuleExit(void)
{
	end_time = jiffies;/*store jiffies time during un-loading module*/
	printk("\nGoodbye, Removing this current kernel\n");
	printk("GCD(3300,24): %lu\n", gcd(3300, 24));
	printk("Jiffies: %lu\n", end_time);
	printk("total time elapsed: %lu\n\n", (end_time - start_time) * 4 / 1000);
}

module_init(ModuleInit);/*This is the entry point to the kernel module*/
module_exit(ModuleExit);/*This is the exit point to the kernel module where it unregisters the module functionality from the kernel*/