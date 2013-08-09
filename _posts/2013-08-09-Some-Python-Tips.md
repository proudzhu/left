---
layout: post
---
###字符串转为float/int
    >>> eval("544.2222")   
    544.2222  
    >>> eval("544")   
    544  

###字符串反向输出
    >>> 'hello'[::-1]  
    'olleh'  

###如何随机生成大写字母和数字组成的字符串  
    6UYFTG  

    >>>import string, random  
    >>>''.join(random.choice(string.ascii_uppercase + string.digits) for x in range(6))  
    'NYU71H'

###如何填充0到数字字符串中保证统一长度
    >>>'4'.zfill(3)  
    '004'  
    >>>"{0:03d}".format(4)  
    '004'  

