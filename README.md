# CS252 OPERATING SYSTEM
## Individual Medium level assignment submission - Project 1 Chapter 2

####  **AIM OF THE PROJECT**
This project is about loading and unloading **kernel modules** after they are created and also modify the kernelmodule so that it creates an entry
in the /proc file system.

#### Need for creating a kernel module
- Modules are pieces of code that can be loaded and unloaded into the kernel upon demand. 
- They extend the functionality of the kernel without the need to reboot the system. For example, one type of module is the device driver, which allows the kernel to access hardware connected to the system. Without modules, we would have to build monolithic kernels and add new functionality directly into the kernel image.
- modules are already loaded into the kernel by running lsmod, which gets its information by reading the file /proc/modules.

![Interaction-of-Linux-kernel-modules-with-their-environment](https://user-images.githubusercontent.com/57564844/143457545-430d610b-82e4-4b2f-8fe5-af1428adc4d0.png)

**Source:** https://www.researchgate.net/figure/Interaction-of-Linux-kernel-modules-with-their-environment_fig1_277248477 
