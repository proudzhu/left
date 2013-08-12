---
layout: post
---

前几天发现有几个包的Validated By项是None, 感到很疑惑, 在wiki上找到了重装所有包的方法[Reinstalling_all_installed_packages](https://wiki.archlinux.org/index.php/Pacman_Tips#Reinstalling_all_installed_packages)
```bash
comm -23 <(pacman -Qeq|sort) <(pacman -Qmq|sort) | pacman -S -
```

看到了comm这个工具, 在manpage上了解到

>  Compare sorted files FILE1 and FILE2 line by line.
	
为此自己也写了些用comm的one-line-bash 

* `paclist`: 列出当前系统不依赖于其他包, 且不包含在base和base-devel组中的包 

{% highlight bash %}
function paclist() {
    sudo pacman -Qei $(comm -23 <(pacman -Qtq|sort) <(pacman -Qqg base base-devel|sort)) |
    awk '  BEGIN {FS=":"}/^Name/{printf("\033[1;36m%s\033[1;37m", $2)}/^Description/{print $2}'  
}
{% endhighlight %}

* `aurneeds $package`: 列出依赖$package的AUR包(使用了pkg-tools中的whoneeds脚本) 

{% highlight bash %}
function aurneeds() {
    comm -12 <(pacman -Qqm | sort) <(whoneeds $1 | sed -e '1d; s|^\s*||' | sort)
}
{% endhighlight %}
