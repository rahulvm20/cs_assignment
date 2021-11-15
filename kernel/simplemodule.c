#include <linux/module.h>
#include <linux/init.h>
#include <linux/hash.h>
#include <linux/gcd.h>
#include <linux/uaccess.h>
#include <linux/jiffies.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("RAHUL VM");
MODULE_DESCRIPTION("BASIC CODE FOR LOADING AND REMOVING KERNEL MODULES");

static int __init ModuleInit(void)
{
	printk("\nHello kernel, loading the current kernel..!\n");
	printk("Golden ratio prime: %llu\n",GOLDEN_RATIO_PRIME);
	printk("Jiffies: %lu HZ: %d\n\n",jiffies,HZ);
	return 0;
}

static void __exit ModuleExit(void)
{
	printk("\nGoodbye, Removing this current kernel\n");
	printk("GCD(3300,24): %lu\n",gcd(3300,24));
	printk("Jiffies: %lu\n\n",jiffies);
}

module_init(ModuleInit);
module_exit(ModuleExit);

