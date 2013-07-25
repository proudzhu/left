---
layout: post
---
使用了arch快一年,由于rolling release,对于pacman这个包管理器使用也是相当的多,下面是一些在arch bbs上淘到的一些pacman相关的scripts.

* aurdiff: diff between local PKGBUILD and the one on AUR 
{% highlight bash %}
DIFF=${DIFF:-diff}
if [[ ! -f PKGBUILD ]]; then
    echo "error: No PKGBUILD found in working directory."
    exit 1
fi >&2
eval $(grep '^pkgname=' PKGBUILD)
if [[ -z $pkgname ]]; then
    echo "error: pkgname not found in PKGBUILD"
    exit 1
fi >&2
diff ${@:--u} PKGBUILD <(curl -s "https://aur.archlinux.org/packages/${pkgname:0:2}/$pkgname/PKGBUILD")
{% endhighlight %}
* absdiff: diff between local PKGBUILD and the one in abs tree   
{% highlight bash %}
DIFF=${DIFF:-diff}
if [[ ! -f PKGBUILD ]]; then
    echo "error: No PKGBUILD found in working directory."
    exit 1
fi >&2
eval $(grep '^pkgname=' PKGBUILD)
if [[ -z $pkgname ]]; then
    echo "error: pkgname not found in PKGBUILD"
    exit 1
fi >&2
repo=$(pacman -Si $pkgname | awk ' BEGIN {FS=" "}/^Repository/{printf $1}')          
diff ${@:--u} PKGBUILD "/var/abs/$repo/$pkgname/PKGBUILD"
{% endhighlight %}
