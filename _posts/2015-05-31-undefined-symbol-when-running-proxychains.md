---
layout: post
---

Last Firday, when I upgrade proxychains from 4.8.1 to 4.9 in my archlinux, it suddenly cannot work anymore.

When I run `proxychains ls`, it print out

```
[proxychains] config file found: /etc/proxychains.conf
[proxychains] preloading /usr/lib/libproxychains4.so
ls: symbol lookup error: /usr/lib/libproxychains4.so: undefined symbol: pthread_once
```

It is clearly that libproxychains4.so does not link against pthread.

Then I googled this error, finally I found this https://github.com/rofl0r/proxychains-ng/issues/53#issuecomment-107180938
on github.

It seems that jackyzy823 solved this issuse by changing
`$(CC) -shared -lpthread $(LIBDL) $(LDFLAGS) $(LD_SET_SONAME)$(LDSO_PATHNAME) -o $@ $(LOBJS)`
to
`$(CC) -shared $(LDFLAGS) $(LD_SET_SONAME)$(LDSO_PATHNAME) -lpthread $(LIBDL) -o $@ $(LOBJS)`,
also it is introduced in commit [fix makefile link order](https://github.com/rofl0r/proxychains-ng/commit/377b474b40bb34fde018301294e02850dac928fe).

I tried to revert it, and everything works fine now.

I posted in this issue above, and got replay from the owner rofl0r
> @proudzhu try to revert e79e05a as well. does that work ? this commit seems to be the original cause of the regression

Finally I found that I have "--as-needed" in my local LDFLAGS, it is set in the default makepkg.conf which will be loaded when building a package in archlinux.

Then I found this [wiki](https://wiki.gentoo.org/wiki/Project:Quality_Assurance/As-needed),
in section "Fixing problems with --as-needed", it says "libraries don't create problems, because they are allowed to have undefined symbols".

So in my system, when building a shared library, every -llibs after $(LDFLAGS) will be ignored, so
`$(CC) -shared -lpthread $(LIBDL) $(LDFLAGS) $(LD_SET_SONAME)$(LDSO_PATHNAME) -o $@ $(LOBJS)` works,
but `$(CC) -shared $(LDFLAGS) $(LD_SET_SONAME)$(LDSO_PATHNAME) -lpthread $(LIBDL) -o $@ $(LOBJS)` fails.

Maybe we should move  "-lpthread $(LIBDL)" before $(LDFLAGS).

But I cannot figure out why the other users in the post failed to link against libpthread.
If it is a gcc link order issue as @jackyzy823 says ( but I'm confused as there is not other library in the argument), maybe we could change to
`$(CC) -shared  $(LD_SET_SONAME)$(LDSO_PATHNAME) -lpthread $(LIBDL) $(LDFLAGS) -o $@ $(LOBJS)`?

Think in more depth, it is also related with the structure of `proxychains`.
The program `proxychains` does not link against `libproxychains4.so`, it just load the library and do the other things.

Conclusion:
Remember to add -llibs before $(LDFLAGS) when building shared libraries.
