# CS252 OPERATING SYSTEM
## Individual Medium level assignment submission - Project 1 Chapter 2

####  **AIM OF THE PROJECT**
This project is about loading and unloading **kernel modules** after they are created and also modify the kernel module so that it creates an entry
in the /proc file system.

#### Need for creating a kernel module
- Modules are pieces of code that can be loaded and unloaded into the kernel upon demand. 
- They extend the functionality of the kernel without the need to reboot the system. For example, one type of module is the device driver, which allows the kernel to access hardware connected to the system. Without modules, we would have to build monolithic kernels and add new functionality directly into the kernel image.
- modules are already loaded into the kernel by running lsmod, which gets its information by reading the file /proc/modules.

![Interaction-of-Linux-kernel-modules-with-their-environment](https://user-images.githubusercontent.com/57564844/143457545-430d610b-82e4-4b2f-8fe5-af1428adc4d0.png)

**Image Source:** https://www.researchgate.net/figure/Interaction-of-Linux-kernel-modules-with-their-environment_fig1_277248477 


#### Seting up the Environment
To carryout this project, i used linux virtual machine that i had already installed while learning a course on coursera. details of this course is https://www.coursera.org/learn/finite-element-method/home/welcome where they explained how to install VM which worked well in this project too. This provided linux ubuntu version. Following the steps mentioned in the course made it easier to install the virtual machine.I used Github desktop version to clone the folder present in my desktop and any changes made in the folder could be easily pushed to github repositry. I also used VS studio and gedit to edit codes in windows and linux respectively.


#### Problems faced during the project
Although installation was easier due to steps mentioned in that course, it was taking time to understand the command used in linux. Due to this i had to use both user interface by mouse to select and do operations like it's done in windows and along with that used command-line. During compiling using makefile, there were some issues related to module not being found due to which i had to use **sudo apt install _module_name_** and similar commands. Some modules needed slightly different methods to solve where the name had to be changed from **asm/uaccess.h** to **linux/uaccess.h**. some of the links that helped me dueing seting up the codes and compiling them are https://ubuntuforums.org/showthread.php?t=1555724, https://askubuntu.com/questions/530248/asm-errno-h-no-such-file-or-directory, https://forums.gentoo.org/viewtopic-t-614888-start-0.html.


#### Problems faced during the project
The project is being divided into 3 parts 
-1 Loading and unloading of kernel modules and print 
  - GOLDEN RATIO PRIME, jiffies, HZ in init() function
  - Print jiffies, HZ and Greatest Common Divisor (GCD) of 3300,24 in exit() function
- Modify the kernel modules to display **jiffies** value at the moment its read using proc file system
- Modify the kernel module to display **total time elapsed** from loading till unloading the module in **seconds** using jiffies by help of proc file system



**Part 1**
  - ldaf





