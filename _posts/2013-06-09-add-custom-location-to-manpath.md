---
layout: post
---

一直喜欢autojum类的快速跳转工具,但是自己又不会python.最近在github上找到了一个替代品[z](https://github.com/rupa/z/), 是使用bash写的, 只有一个文件.在作者的源里提供了在z.1这个manpage,使用时需要使用`man path/to/z.1`来查看,很不方便,虽然有`/usr/local/man`这个提供给用户自己放置man文件的地方,但是本人不想touch 非$HOME文件夹,便google了加入自动义文件夹到manpath中去的方法.

* 在$HOME下新建.manpath,并加入自定义的文件夹即可

`echo "MANDATORY_MANPATH   /home/proudzhu/.man" > ~/.manpath`
    
* 再将z.1复制到增加的文件夹中

`mkdir ~/.man/man1`
`cp path/to/z.1 ~/.man/man1/`

* 最后转换格式

` gzip ~/.man/man1/z.1`

* Over
