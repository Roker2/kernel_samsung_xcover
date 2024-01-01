HOW TO BUILD KERNEL 2.6.35.7 FOR GT-S5690

1. How to Build
	(1) get Toolchain
	Visit http://www.codesourcery.com/, download and install Sourcery G++ Lite 2009q3-68 toolchain for ARM EABI.
	(2) Extract kernel source and move into the top directory.
	$ cd kernel
	$ make alkon_03_defconfig
	$ make all

2. Output files
	- Kernel : kernel/common/arch/arm/boot/zImage
	
3. How to make .tar binary for downloading into target.
	- change current directory to kernel/common/arch/arm/boot
	- type following command
	$ tar cvf GT-S5690_Kernel_Gingerbread.tar zImage
