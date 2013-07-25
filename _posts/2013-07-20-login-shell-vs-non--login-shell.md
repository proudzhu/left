---
layout: post
---

Now I start reading TLCL(The Linux Command Line), then I come across login shell and non-login shell.  

> A login shell session is one in which we are prompted for our username and password; when we start a virtual console session, for example.  
> A non-login shell session typically occurs when we launch a terminal session in the GUI.  

The differences between them is that login shells read one or more startup files as shown below:

* /etc/profile     
* ~/.bash_profile     
* ~/.bash_login     
* ~/.profile    

Non-login shell sessions read the following startup files:

* /etc/bash.bashrc    
* ~/.bashrc    


