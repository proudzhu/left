---
layout: post
---
### 字符串转为float/int

{% highlight python %}
>>> eval("544.2222")   
544.2222  
>>> eval("544")   
544  
{% endhighlight %}

### 字符串反向输出

{% highlight python %}
>>> 'hello'[::-1]  
'olleh'  
{% endhighlight %}

### 如何随机生成大写字母和数字组成的字符串  

{% highlight python %}
6UYFTG

>>>import string, random  
>>>''.join(random.choice(string.ascii_uppercase + string.digits) for x in range(6))  
'NYU71H'
{% endhighlight %}

### 如何填充0到数字字符串中保证统一长度

{% highlight python %}
>>>'4'.zfill(3)  
'004'  
>>>"{0:03d}".format(4)  
'004'  
{% endhighlight %}

### 检测列表是否为空

{% highlight python %}
if not a:
    print("List is empty")
{% endhighlight %}

### 合并两个dict

{% highlight python %}
z = dict(list(x.items()) + list(y.items()))
{% endhighlight %}
or   
{% highlight python %}
z = x.copy()
z.update(y)
{% endhighlight %}
