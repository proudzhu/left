---
layout: post
---

由于Arch的滚动特性, 导致有一些软件包经常更新, 并有时会有`soname bump`, 官方源里的软件包会有保障, 但是AUR里可能会由于打包者或自己的疏忽而没有更新,严重时可能导致系统崩溃之类的.  
因此google到了这个[aurebuildcheck](https://bbs.archlinux.org/viewtopic.php?id=162949), 是用bash写的, 很简单, 只实现了基本的功能, 因此在github上fork, 并加入了一些功能. 

* 去除了calc依赖, 使用awk来实现简单的时间差计算
* 加入自动跳过Architecture为"Any"的软件包(这些软件包都是一些脚本,不大可能出错)
* ~~加入config文件支持, 目前只有IgnoredPkgs选项~~(已取消, 个人觉得没有必要, 第二点已经处理了)
* 修正了原PKGBUILD

github项目地址: [aurebuildcheck](https://github.com/matthiaskrgr/aurebuildcheck)

