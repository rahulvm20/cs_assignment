# CS252 OPERATING SYSTEM
## Individual Medium level assignment submission - Project 1 Chapter 2

##  **AIM OF THE PROJECT**
This project is about loading and unloading **kernel modules** after they are created and also modifying the kernel module so that it creates an entry
in the /proc file system.

## Need for creating a kernel module
- Modules are pieces of code that can be loaded and unloaded into the kernel upon demand. 
- They extend the functionality of the kernel without the need to reboot the system. For example, one module type is the device driver, which allows the kernel to access hardware connected to the system. Without modules, we would have to build monolithic kernels and add new functionality directly into the kernel image.
- Modules are already loaded into the kernel by running lsmod, which gets its information by reading the file /proc/modules.<br/><br/>
**Source:** https://linux.die.net/lkmpg/x40.html <br/><br/>

![Interaction-of-Linux-kernel-modules-with-their-environment](https://user-images.githubusercontent.com/57564844/143457545-430d610b-82e4-4b2f-8fe5-af1428adc4d0.png)

**Image Source:** https://www.researchgate.net/figure/Interaction-of-Linux-kernel-modules-with-their-environment_fig1_277248477 <br/>


## Setting up the Environment
I used a Linux virtual machine that I had already installed while learning a course to carry out this project. The details of this course are https://www.coursera.org/learn/finite-element-method/home/welcome, where they explained how to install VM, which worked well in this project. This provided the Linux ubuntu version. Following the steps mentioned in the course made it easier to install the virtual machine. I used the Github desktop version to clone the folder present on my desktop, and any changes made in the folder could be easily pushed to the GitHub repository. I also used VS studio and gedit to edit codes in windows and Linux, respectively.


## Problems faced during the project
Although the installation was more manageable due to the steps mentioned in that course, it took time to understand the command used in Linux. Due to this, I had to use both user interfaces by mouse to select and do operations like it is done in windows and used command-line. During compiling using a makefile, there were some issues related to the module not being found, due to which I had to use sudo apt install module_name and similar commands. Some modules needed slightly different methods to solve where the name had to be changed from asm/access.h to Linux/access.h. Some of the links that helped me set up the codes and compile them are https://ubuntuforums.org/showthread.php?t=1555724 https://askubuntu.com/questions/530248/asm-errno-h-no-such-file-or-directory, https://forums.gentoo.org/viewtopic-t-614888-start-0.html.


## Description of the project
The project is being divided into three parts 
- **Part 1**
  - Loading and unloading of kernel modules
  - print GOLDEN RATIO PRIME, jiffies, HZ in init() function 
  - Print jiffies, HZ and Greatest Common Divisor (GCD) of 3300,24 in exit() function
  - **Description:** Import necessary modules to create kernel modules and those that help run functions during loading and unloading of the modules, access kernel space buffer, and access jiffies and GCD() function. Once this C file is made, save it and create a MakeFile as shown in the folder, which will create all required files for loading this as a kernel module. Once it is loaded, dmesg will examine the kernel ring buffer and print its message buffer. Also, there is a variable that stores jiffies values during loading and unloading the module and upon calculation gives the time elapsed and details of this is in part 3 below. Every time a kernel message is needed during loading or unloading the module, dmesg will display what happened during each of those processes based on the C code written.
  
 - **Part 2**
   - Modify the kernel modules to display **jiffies** value at the moment it read using proc file system
   - **Description:** Once the Kernel module is created, it is modified to print jiffies value whenever it is called using proc file system using cat /proc/jiffies command. To make this work first, we should modify the C file made before and include functions related to the proc file system that will get invokes when the file is loaded, removed, or read. After making, we get many files; one of them is the .ko file which should be inserted using the insmod command. Then call cat /proc/jiffies, which will read the proc file, and ssize_t proc_read() function is invoked where it accesses the jiffies variable and prints it in kernel buffer it is copied to user buffer by raw_copy_to_user() and displayed on the screen.

 - **Part 3**
   - Modify the kernel module to display **total time elapsed** from the loading till unloading the module in **seconds** using jiffies with help of the proc file system
   - **Description:** The changes made here are similar to those made of jiffies as in part 2, but some more things are to be added to store jiffies values at a different execution time, as stated in part 1. Here two-variable named stat_time and end_time, which stores values of jiffies during loading and reading of the file named seconds is taken. Each time this module is loaded, jiffies values during loading are stored in the start_time variable, and every time the seconds file is read, jiffies value is stored in the end_time variable. Then their difference is taken and divided by the HZ value. Since the difference in the number of ticks during the duration from loading the file to being read, and HZ is the number of ticks that happens in one second, their ratio will give the total time elapsed during that period. This message in kernel buffer is copied to user buffer by raw_copy_to_user() and displayed on the screen.<br/><br/>

## OUTPUT
- ### **Part 1**<br/><br/>
  - **dmesg when module is not yet loaded:** <br/>
   ![11](https://user-images.githubusercontent.com/57564844/143489417-e2f0a773-515a-49c3-ba47-f2df18918b4c.png)<br/><br/>
  - **dmesg when module is loaded first time:** <br/>
   ![22](https://user-images.githubusercontent.com/57564844/143489800-b39923fe-3e12-401a-a96d-d4d94dd68cd2.png)<br/><br/>
  - **dmesg when module is un-loaded first time:** <br/>
   ![33](https://user-images.githubusercontent.com/57564844/143489894-6b9c076d-843d-4134-82ec-1613c7e9617d.png)<br/><br/>
  - **dmesg when module is loaded second time:** <br/>
   ![44](https://user-images.githubusercontent.com/57564844/143490368-b4061a2d-a54a-4076-a610-f799da11a6b2.png)<br/><br/><br/>

- ### **Part 2**<br/><br/>
  - **cat /proc/jiffies when module is not yet loaded:** <br/>
   ![11](https://user-images.githubusercontent.com/57564844/143493138-de596f41-9530-49cb-b363-6daeae721609.png)<br/><br/>
  - **cat /proc/jiffies when module is loaded first time:** <br/>
   ![22](https://user-images.githubusercontent.com/57564844/143493151-2f69f9ec-4cfc-4f33-89ab-743b89bd8abc.png)<br/><br/>
  - **cat /proc/jiffies after sometime:** <br/>
   ![33](https://user-images.githubusercontent.com/57564844/143491201-027f2430-d102-452b-9815-b1fb598c646e.png)<br/><br/><br/>

- ### **Part 3**<br/><br/>
  - **cat /proc/second when module is not yet loaded:** <br/>
   ![11](https://user-images.githubusercontent.com/57564844/143492062-27affc70-08fa-4bef-890d-9848cb312cb8.png)<br/><br/>
  - **cat /proc/seconds when module is loaded first time:** <br/>
   ![22](https://user-images.githubusercontent.com/57564844/143492839-6a81f0b1-7d07-4e64-b852-49e988cad8fa.png)<br/><br/>
  - **cat /proc/seconds after successive time periods:** <br/>
   ![33](https://user-images.githubusercontent.com/57564844/143492083-8dc4cc84-fdc9-4622-b28f-6f8c1f9d6f9f.png)<br/><br/>
   ![44](https://user-images.githubusercontent.com/57564844/143492095-998b999d-2fba-4012-b2ee-f8380ae72979.png)<br/><br/>
   ![55](https://user-images.githubusercontent.com/57564844/143492110-69a5f339-9a3b-48f5-bb43-e6c7b473e6de.png)<br/><br/>
  - **cat /proc/seconds when module is un-loaded:** <br/>
   ![66](https://user-images.githubusercontent.com/57564844/143492195-26bff48e-e9da-4f09-a098-8fae471d9457.png)<br/><br/>
   
# Reference <br/>  
- Operating System Concepts - 10th Edition
