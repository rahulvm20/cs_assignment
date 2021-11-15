obj-m += jiffies___.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell name -r)/build M=$(PWD) clean
