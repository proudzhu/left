---
layout: post
category: linux
tags: [linux, aur, doubanfm]
---

doubanfm作为上网听音乐的好去处, 但一直没有找到比较好用的客户端, 只能一直用浏览器, 但浏览器的内存占用是不可忽视的.

在aur上只找到如下方案:

* banshee-extension-doubanfm-hg
* exaile-doubanfm-plugin
* kdoubanfm
* qdoubanfm-git
* rhythmbox-doubanfm

由于使用KDE, 因此1, 2, 5直接不考虑. 

###kdoubanfm
这个是很久之前的了, 大概2011年的, 至今还能用不得不说是个奇迹, 但是只能收听默认的频道, 切换频道就会崩溃, 并且已经无法登陆了, **PASS**

###qdoubanfm-git
是个在gitcafe上的项目, 貌似github上作者也创建了该项目.   但是编译运行会导致段错误.      
> "Load Language: UnitedStates_English"   

> QLayout: Attempting to add QLayout "" to UserLoginWidget "userLoginWidget", which already has a layout   

> [0x9e257e0] main services discovery error: no suitable services discovery module   

> [1]    18398 segmentation fault (core dumped)  doubanfm-qt
	
客户端方案基本没有好的了, 转而寻找CLI的, 在github上找到了给予ruby的douban.fm, 基本的功能已经实现,但是无法标记红星(也就是标记为喜欢)   

PS: 其实github上doubanfm的相关项目不少, 但是估计大部分都是个人的自娱自乐之作, 根本没有相关的使用文档或README之类的
