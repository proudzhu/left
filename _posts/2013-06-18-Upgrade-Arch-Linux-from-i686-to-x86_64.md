---
 layout: post
---

用arch快一年了, 之前一直用的是i686, 换到`x86_64`的原因:  

* arch i686使用的人数过少, 貌似有些软件包都不测试i686的
* 机器虽然只有2G的内存, 但使用kde时一直50%都达不到
* i686迟早要被淘汰的

下面是[升级方法](https://wiki.archlinux.org/index.php/Upgrade_Arch_Linux_from_i686_to_x86_64_HOWTO)

* 查看CPU是否支持`X86_64`  
	grep --color '\<lm\>' /proc/cpuinfo
* 下载, 做好arch的liveCD
* 挂载好原系统所有分区  
	mount /dev/sda7 /mnt
	mount /dev/sda5 /mnt/home
	mount /dev/sda8 /mnt/opt
* 使用下面的bash脚本来安装`X86_64`软件包
```bash
MOUNTED_INSTALL='/mnt'
TEMP_FILE='/tmp/packages.list'
pacman --root $MOUNTED_INSTALL -Sy
pacman --root $MOUNTED_INSTALL --cachedir $MOUNTED_INSTALL/var/cache/pacman/pkg --noconfirm -Sg base base-devel
pacman --root $MOUNTED_INSTALL -Qq > $TEMP_FILE
for PKG in $(cat $TEMP_FILE) ; do
   pacman --root $MOUNTED_INSTALL --cachedir $MOUNTED_INSTALL/var/cache/pacman/pkg --noconfirm -S $PKG
done
```
* 运行上面的脚本多次
* 最后编译aur软件, 并`mkinitcpio`和`grub-mkconfig`
* 最后清理缓存的i686软件包
