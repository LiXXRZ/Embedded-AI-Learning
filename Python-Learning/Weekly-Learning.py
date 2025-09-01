"""
LIXXRZ的python学习路程记录
"""

#   Lesson 1

# 1.python是什么
#   python是面向对象的解释型高级编程语言
#   python是强类型的动态脚本语言
# 2.编写第一个程序
#   print("Hello World!")
#   运行文件选择Run
# 3.bug/debug
#   注意：python中符号用英文形式
#   print要顶格写，两个print不能在同一行，syntax说明语法错误
#   print中字符串加单引号或者双引号，不包括数字
#   debug调试观察执行顺序，灵活运用断点
# 4.注释
#   使用#，或者
"""
多行注释
"""
'''
单引号相同
'''
#   添加注释/取消注释：
#   ctrl + /
# 5.输出函数print()
#   print("1","2","3","4","5","6","7","8","9",sep='|')
#   *输出多个值或者多句话须用逗号隔开，tab快捷填充
#   sep用来间隔多个值(先写值，后使用sep)，默认是空格键隔开
#   end用来设定以...结尾，默认值是换行符\n，可以切换成其它字符串
"""
print('hello',end='1')
print('world')
"""
#   print(字符串，end=“后面拼接的值”)
#   最后输出的结果为：字符串+后面拼接的值+下一个print中的字符串

#   Lesson 2

# 1.变量
#   *变量的作用：
#   计算机中的存储空间，用于保存数据
#   *定义变量的格式：
#   变量名 = 值
#   注意：=是赋值运算符，左右两边打上空格是为了代码的规范性，美观性
"""
num1 = 3  #num1就是一个变量，保存可乐的价格
num2 = 10  #num2也是一个变量，保存冰淇淋的价格
total = num1 + num2  #total也是一个变量，保存总价格
print(total)
"""
#   *加上引号会打印引号里面的内容，没有引号就会被识别为变量名
#   如果该变量没有被赋值，就会报错
#   变量只有被赋值后才会被创建，使用变量之前必须赋值
#   a = 666
#   解释器做两件事：
#   (1) 在内存中创建了一个666的数据
#   (2) 创建了一i个变量a，把666这个数据保存到a变量中
#   b = a
#   print(b)
#   print(a) #666
#   a = 9.99  同一个变量可以反复赋值，并且可以是不同的数据类型
#   print(a) #999
#   *代码是从上到下运行的
# 2.标识符
#   含义：人为定义的变量名、函数名
#   注意：只能由数字、字母、下划线组成
#   (username) = 1
#   print((username))
#   标识符被包含在()对标识符本身没有影响
#   不能以数字开头
#   不能是关键字
#   严格区分大小写
# 3.数值类型
#   检测数据类型的方法 type()
#   print(type(num))
#   (1) int整形：任意大小整数
#   num = -5
#   (2) float浮点型：小数
#   num2 = 1.5
#   (3) bool布尔型（重点）：通常用于判断
#   有固定写法，一个为True（真），一个为False（假）
#   *注意：True和False必须严格区分大小写
#   布尔值可以当做整形对待，True相当于整数1，False相当于整数0
#   print(True + False) # 1 + 0 = 1
#   print(True + 1) # 1 + 1 = 2
#   (4) complex复数型（了解）
#   固定写法：z = a + bj ————a是实部，b是虚部，j是虚数单位
#   print(type(2+3j))
#   ma = 1 + 2j # j是固定的单位，不可改变
#   ma2 = 2 + 3j
#   print(ma+ma2)
# 4.字符串str
#   特点：需要加上引号，单引号双引号都乐意，包含多行内容的时候也可以使用三引号
#   name = 'LIXX'
#   name = """LIXX
#   nb"""
#   print(name)
# 5.格式化输出
#   (1) 占位符
#   生成一定格式的字符串
#   (2) %
#   1.%s 字符串
#   name = 'lip'
#   print("我的名字：%s" %name)
#   2.%d 整数
#   age = 18
#   name = 'lip'
#   print("我的名字：%s, 年龄：%d" %(name,age))
#   3.%4d 整数
#   数字设置位数，不足前面补空白
#   a = 123
#   print("%06d" %a) # 表示输出的整数显示位数，不足的话用0补全，超出当前位数则原样输出
#   4.%f浮点数
#   a = 1.23456789
#   print('%f' %a)
#   默认后六位小数，遵循四舍五入原则
#   5.%.4f 浮点数
#   数字设置小数位数,遵循四舍五入原则
#   b = 2.34567
#   print('.7%f' %b)
#   6.%%
#   print("我是%%的1%%" %())
#   (3) f格式化
#   格式：f"(表达式)"
#   name = 'lip'
#   age = 20
#   print(f"我的名字是{name}，我今年{age}岁了")

#   Lesson 3

# 1.算术运算符
#   (1) +-*/
#   *注意：使用算术运算符/，商一定是浮点数
#   (2) // 取整除：取商的整数部分，向下取整，忽略小数
#   (3) % 取余数：只取余数部分
#   (4) ** 幂：m**n：m的n次方
# 2.赋值运算符
#   (1) =
#   (2) += 、-=
#   *注意：赋值运算符针对变量，纯数字无法使用
# 3.input()输入函数 默认输入字符串类型
#   input(prompt)  prompt是提示，会在控制台中显示
#   name = input("请输入姓名：")
#   print(name)
# 4.转义字符
#   (1) \t 制表符 通常表示四个空字符，也称缩进
#   print('姓名\t年龄\t电话')
#   (2) \n 换行符
#   print(end = '\n')
#   (3) \r 回车 表示将当前位置移到本行开头
#   print("985\r211")
#   (4) \\ 反斜杠符号
#   print('LI\\XX')
#   print('LI\\\tXX')
#   print(r'LI\\\tXX') # r原生字符，默认取消转义

#   Lesson 4

# 1.if判断基本格式
#   age = 12
#   if age >= 18:
#       print("你可以上网")
# Test1:
"""
score = input("请输入成绩：")
if score == '100':
    print('nb')
if score == '60':
    print('lj')
"""
# 2.比较（关系）运算符
#   == 比较的是两个变量的值是否相等，相等的话就返回为True（真），不相等返回False（假）
#   != 比较的是两个变量的值是否相等，不相等的话就返回为True（真），相等返回False（假）
#   a = 6
#   b = 9
#   print(a != b)
#   c = a > b
#   print(c)
# 3.逻辑运算符
#   and 左右两边都符合才为真
#   or 左右两边一边符合就为真
#   not 表示相反的结果
#   print(not 3 > 9)
# 4.三目运算
#   基本格式：为真结果 if 判断条件 else 为假结果
#   a = 1
#   b = 2
#   c = a if a > b else b
#   print('a小于等于b') if a <= b else print('a比b大')
# 5.if-else
#   c = 1
#   if c == 1:
#       print('a')
#   else:
#       print('b')
# 6.if-elif
#   if-else 二选一 if-elif 多选一
# 7.if嵌套
#   顾名思义if套if......

#   Lesson 5

# 1.while循环
#   i = 1 # 定义一个初始值，记录循环的次数，i=1表示从第一次开始
#   while i <= 100:
#       print(i)
#       i += 1
#   注意：条件为False和0外的常值导致死循环
# Test 2:
"""
i = 1
s = 0
while i <= 100:
    s += i
    i += 1
"""
# 2.while循环嵌套
#   顾名思义
# 3.for循环
#   (1)固定格式
#   for 临时变量 in 可迭代对象：
#     循环体
#   注意冒号和缩进
#   str = ("helloworld") # int不可遍历
#   可迭代对象就是要求遍历取值的整体
#   for i in str: # i是临时变量，可以随便写，i是常规写法
#       print(i)
#   (2)range()
#   用来记录循环次数，相当于一个计数器
#   for i in range(1,11): # 从1开始，到11结束，遵循包前不包后规则，[)
#      print(i)
#   for i in range(10): # 同样循环十次，默认从零开始
#      print(i)
# Test 3：
"""
s = 0
for i in range(1,101):
       s += i
print(s)
"""
# 4.break和continue
#   都是专门在循环中使用的关键字
#   (1) break
#   作用：某一条件满足时退出循环
#   (2) continue
#   作用：退出本次循环，下一次循环继续执行
#   i = 1
#   while i <= 10:
#       if i == 3:
#           print(f"第{i}个苹果不吃了")
#           # 在continue之前，一定要修改计数器，否则会陷入死循环
#           i += 1 # for不涉及计数器，故不需在意
#           continue
#       print(f"小明在吃第{i}个苹果")
#       i += 1

#   Lesson 6

# 1.字符串编码
#   (1) 本质上就是二进制语言文字的一一对应关系
#   (2) Unicode：所有字符都是两个字节
#   好处：字符与数字之间转换速度更快一些
#   坏处：占用空间大
#   (3) 1.3UTF-8：精准，对不同的字符用不同的长度表示
#   优点：节省空间
#   缺点：字符与数字的转换速度较慢，每次都需要计算字符要用多少字节来表示
#   (4) 字符串编码转换
#   a = 'hello'
#   print(a,type(a)) # str,字符串是以字符为单位处理
#   a1 = a.encode() # 编码
#   print('编码后：',a1)
#   print(type(a1)) # bytes, 以字节为单位进行处理的
#   a2 = a1.decode() # 解码
#   print('解码后',a2)
#   print(a2,type(a2))
#   注意：对于bytes，只需要知道他跟字符串之间的相互转换
#   st = "这里是BJTU"
#   str1 = st.encode("utf-8")
#   print(str1,type(str1))
#   str2 = str1.decode("utf-8")
#   print(str2,type(str2))
# 2.字符串常见操作1
#   (1) + 字符串拼接
#   print(1+1) # 2
#   print('1'+'1') # 11
#   name1 = 'LIXX'
#   name2 = 'BJTU'
#   print(name1+name2)
#   print(name1,name2,sep="")
#   (2) * 重复输出
#   print('好好学习天天向上\n'*5)
#   注意：需要重复多少次*后面就写多少
#   print('&\t'*10)
#   (3) 成员运算符
#   作用：检查字符串中是否包含某个子字符串（即某个字符或者多个字符）
#   in：如果包含的话，返回True，不包含返回False
#   not in：如果不包含的话，返回True，包含返回False
#   name = 'LIXX'
#   print('L' in name)
#   print('L' not in name)
#   print('XX' in name)
#   print('XX' not in name)
#   (4) 下标
#   Python中下标从0开始
#   作用：通过下标能够快速找到对应的数据
#   格式：字符串名[下标值]
#   name = 'LIXX'
#   从左往右数，下标从零开始
#   print(name[0])
#   print(name[1])
#   从右往左数，下标从-1开始
#   (5) 切片
#   含义：指对操作的对象截取其中一部分的操作
#   语法：[开始位置:结束位置:步长]
#   包前不包后：即从起始位置开始，到结束位置前的一位结束（不包含结束位置本身）
#   st = 'abcdefg'
#   从左往右
#   print(st[0:4]) # abcd
#   print(st[:5]) # abcde
#   print(st[3:]) # defg
#   从右往左
#   print(st[-1:]) # g
#   print(st[:-1]) # abcdef
#   print(st[-1:-5])
#   步长：表示选取间隔，不写步长默认是1
#   步长的绝对值大小决定切取的间隔，正负号决定切取方向
#   正数表示从左往右取值，负数表示从右往左取值
#   print(st[-1::-1]) # gfedcba
#   print(st[-1:-5:-1]) # gfed
#   print(st[0:7:2]) # aceg
# 3.字符串常见操作2
#   **查找**
#   (1) find()：检查某个子字符串是否包含在字符串中，如果在就返回这个子字符串开始位置的下标，否则就返回-1
#   find(子字符串，开始位置下标，结束位置下标) # 包前不包后
#   注意：开始和结束位置下标可以省略，表示在整个字符串中查找
#   name = 'LIXX'
#   print(name.find('L')) # 0
#   print(name.find('XX')) # 2
#   print(name.find('X',2)) # 只返回第一个
#   print(name.find('L',4)) # 超出范围/不包含，返回-1
#   (2) index():检测某个子字符串是否包含在字符串中，如果在就返回这个子字符串开始位置的下标，否则就报错
#   index(子字符串，开始位置下标，结束位置下标)
#   注意：开始和结束位置下标可以省略，表示在整个字符串中查找
#   同样遵循包前不包后原则
#   和find区别：find没有找到，返回-1，index没有找到就会报错
#   (3) count():返回某个子字符串在字符串中出现的次数，没有就返回0
#   count(子字符串，开始位置下标，结束位置下标)
#   name = 'deepseek'
#   print(name.count('e'))
#   注意：开始和结束位置下标可以省略，表示在整个字符串中查找
#   同样遵循包前不包后原则
#   **判断**
#   (1) startswith():是否以某个子字符串开头，是的话就返回True，不是的话就返回False
#   startswith(子字符串，开始位置下标，结束位置下标)
#   (2) endswith():是否以某个字符串结尾，同上
#   (3) isupper():检测字符串中所有字母是否都为大写，同上
#   ......
#   **修改元素**
#   (1) replace():替换
#   replace(旧内容，新内容，替换次数)
#   注意：替换次数可以省略，默认全部替换
#   (2) spilt():指定分隔符来切字符串
#   st = 'hello,python'
#   print(st.split(',')) # ['hello', 'python'] 以列表形式返回
#   如果字符串中不包含分割内容，就不会进行分割，会作为一个整体
#   print(st.split('a')) # ['hello,python']
#   print(st.split('o')) # ['hell', ',pyth', 'n']
#   print(st.split('o',1)) # ['hell', ',python']
#   (3) capitalized():第一个字符大写，其他都小写
#   (4) lower():大写字母转为小写
#   (5) upper():小写字母转为大写
# 4.列表
#   基本格式：
#   列表名 = [元素1，元素2，元素3，...]
#   注意：
#   所有元素放在[]内，元素之间用逗号隔开
#   元素之间的数据类型可以各不相同
#   li = [1,2,'a',4]
#   print(li,type(li))
#   print(li[2])
#   列表也可以进行切片操作
#   print(li[0:3])
#   列表是可迭代对象，可以for循环遍历取值
#   for i in li:
#       print(i,end=' ')
# 5.列表的常见操作
#   **添加元素**
#   append() extend() insert()
#   li = ['one','two','three']
#   li.append("four") # append整体添加
#   li.extend("four") # extend分散添加，将另外一个类型中的元素逐一添加
#   需要可迭代，不然会报错
#   li.insert(3,'four') # 在指定位置插入元素
#   li.insert(1,'five') # 指定位置如果有元素，原有元素会后移
#   insert需要指定下标，不然会报错
#   print(li)
#   **修改元素**
#   直接通过下标就可以修改
#   li = [1,2,3]
#   li[2] = 'a'
#   print(li)
#   **查找元素**
#   in：判断指定元素是否存在列表中，如果存在返回True，不存在就返回False
#   not in：：判断指定元素是否存在列表中，如果存在不返回True，存在就返回False
#   li = ['a','b','c','d']
#   print('b' in li)
# Test 4:
"""
# 用户输入昵称，昵称重复则不能使用
# 定义一个列表，保存已经存在的昵称
name_list = ['LIXX','YSY']
name = input("请输入你的昵称")
if name in name_list:
    print(f"您输入的昵称{name}已经存在了哦")
else:
    print(f"昵称{name}已经被您使用")
    name_list.append(name)
    print(name_list)
    break
"""
#   index：返回指定数据所在位置的下标，不存在则报错
#   count：统计指定数据在当前列表的出现次数
#   跟字符串中用法相同
#   **删除元素***
#   (1) del
#   li = ['a','b','c']
#   del li[0]
#   del li
#   (2) pop：删除指定下标的数据
#   li.pop() # python3版本默认删除最后一个元素
#   li.pop(2) # 不能指定元素删除，只能指定下标删除，下标超出范围报错
#   (3) remove：根据元素的值进行删除
#   li.remove('a') # 指定不存在的值报错
#   注意：默认删除最开始出现的元素
#   **排序**
#   sort：将列表按特定顺序重新排列，默认从小到大
#   reverse：倒叙，将列表倒置
#   li = [1,4,2,6,5]
#   li.sort()
#   li.reverse()
#   print(li)
# 6.列表推导式
#   格式一：[表达式 for 变量 in 列表]
#   注意：in后面不仅可以放列表，还可以放range()、可迭代列表
#   [print(i) for i in li]
#   li = []
#   [li.attend(i) for i in range(1,6)]
#   格式二：[表达式 for 变量 in 列表 if 条件]
#   li = []
#   [li.append(i) for i in range(1,11) if i % 2 == 1]
# 7.列表嵌套
#   含义：一个列表里面又有一个列表
#   li = [1,2,3,[4,5,6]]
#   print(li[3]) # 取出里面的列表
#   print(li[3][2]) # 取出内列表中的元素

#   Lesson 7

# 1.元组
#   基本格式：元组名 = (元素一，元素二，元素三...)
#   所有元素包含在小括号内，元素之间逗号隔开，不同元素可以是不同数据类型
#   tua = (1,2,3,'a','b')
#   print(type(tua))
#   tua = ()
#   print(type(tua))
#   tua = ('a',) # 只有一个元素时，末尾必须加上逗号，否则返回唯一的值的数据类型
# 2.元组与列表的区别
#   (1) 元组只有一个元素末尾必须加逗号，列表不需要
#   (2) 元组只支持查询操作，不支持增删改操作
#   (3) count()、index()、len()跟列表用法相同
# 3.应用场景
#   函数的参数和返回值
#   格式化输出后面的()本质上就是一个元组
#   name = 'LIXX'
#   age = 20
#   print("%s年龄是%d" %(name,age))
#   info = (name,age)
#   print(type(info))
#   print("%s年龄是%d" %info)
#   数据不可以修改，保护数据安全
# 4.字典
#   基本格式：字典名 = {键1：值1，键2：值2...}
#   键值对形式保存，键和值之间用：隔开，每个键值对之间用，隔开
#   dicc = {'name':'LIXX','age':18}
#   print(type(dicc))
#   字典中的键具备唯一性，但是值可以重复
#   dicc = {'age':'20','age':18}
#   若键名重复，前面的值会被后面的值覆盖
# 5.字典常见操作1
#   **查看元素**
#   (1) 变量名[键名]
#   print(dicc['age'])
#   若键名不存在则报错
#   注意：字典中没有下标
#   (2) 变量名.get(键名)
#   print(dicc.get('age'))
#   若键名不存在，返回None
#   print(dicc.get('tel','不存在')) # 如果没有这个键名，返回自己设置的默认值
#   **修改元素**
#   变量名[键名] = 值
#   dic['age'] = 20 # 列表通过下标修改，字典通过键名修改
#   **添加元素**
#   变量名[键名] = 值
#   注意：键名存在就修改，不存在就新增
#   **删除元素**
#   (1) del
#   del 字典名 ：删除整个字典
#   del dic
#   print(dic) # 报错，dic已被删除，找不到
#   del 字典名[键名] ：删除指定键值对
#   del dic['tel'] # 键名不存在就报错
#   print(dic)
#   (2) clear()：清空整个字典里面的东西，但保留了这个字典
#   dic.clear()
#   (3) pop()：删除指定键值对
#   dic.pop('age') # 不存在或不指定键名会报错
#   dic.popitem() # 3.7之前版本随机删除键值对，3.7后默认删除最后一个
# 6.字典常见操作2
#   (1) len()：求长度
#   len(li)
#   (2) keys()：返回字典里面包含的所有键名
#   li.keys() 只取出键名
#   for i in li:
#       print(i)
#   (3) values()：返回字典里面包含的所有值
#   类似于keys()
#   (4) item()：返回字典里面包含的所有键值对，键值对以元组形式
# 7.集合
#   (1) 基本格式：集合名 = {元素1，元素2...}
#   s1 = {} # 定义空字典
#   s1 = set() # 定义空集合
#   (2) 集合具有无序性
#   s1 = {1,2,3,4,5} # 数字结果相同
#   s2 = {'a','b','c','d'} # 字符不同
#   print(s1,s2)
#   (3) 集合具有唯一性，可自动去重
# 8.集合常见操作
#   **添加元素**
#   (1) add 添加的是一个整体
#   s1.add(值) # 一次只能添加一个元素
#   (2) update 把传入的积分拆分，一个个放进集合中
#   s1.update(可迭代对象) 字符串、列表、元组
#   **删除元素**
#   (1) remove：如果集合中没有选择删除的元素，报错
#   s1.remove(值)
#   (2) pop()
#   s1.pop(值)
#   默认删除排序后的第一个元素
#   (3) discard：选择要删除的元素，有就删，没有不变
#   同remove
# 9.交集和并集
#   (1) 交集 &
#   a = [1,2,3,4]
#   b = [4,5,6,7]
#   print(a & b)
#   没有共有的部分，返回空集set()
#   (2) 并集 |
#   a = [1,2,3,4]
#   b = [4,5,6,7]
#   print(a | b)
#   重复的部分不算（集合的唯一性）

#   Lesson 8

# 1.类型转换
#   (1) int()：转换为一个整数，只能转换由纯数字组成的字符串，可含+-
#   float ——> int 只保留整数部分
#   str ——> int
# Test 5：
"""
age = int(input("请输入您的年龄")) # input默认输入字符串类型
if age >= 18:
    print("成年了")
"""
#   (2) float()：转换为一个小数
#   整数转换为浮点型，会自动添加一位小数
#   (3) str()：转换为字符串类型，任何类型都可以转换为字符串类型
#   float转换成str会取出末位为0的小数部分
#   (4) eval()：用来执行一个字符串表达式，并返回表达式的值
#   print(10+10) # 20
#   print('10'+'10') # 1010
#   print(eval('10+10')) # 20，执行运算，并返回运算值
#   print(eval('‘10’+10'))# 报错，整形与字符串不可以相加
#   *eval()可以实现list、dict、tuple和str之间的转换
#   str = [[1,2],[3,4],[5,6]]
#   li = eval(str)
#   注意：eval()非常强大，但是并不安全，容易被恶意修改数据，不建议使用
#   (5) list()：将可迭代对象转换成列表
#   支持转换为list的类型：str、tuple、dict、set
#   字典转换成列表，会取键名作为列表的值
#   集合转换时会先去重
# 2.深浅拷贝
#   (1) 赋值:等于完全共享资源，一个值的改变会完全改变另一个值共享
#   li = [1,2,3,4]
#   li2 = li # 将li直接赋值给li2
#   li.append(5)
#   print(li,li2)
#   (2) 浅拷贝（数据办共享）
#   会创建新的对象，拷贝第一层的数据，嵌套层会指向原来的内存地址
#   import copy
li = [1,2,3,[4,5,6]]
#   li2 = copy.copy(li)
#   print(li)
#   print(li2)
#   查看内存地址id()
#   print(id(li))
#   print(id(li2))
#   内存地址不一样，说明不是同一个对象
#   li.append(7)
#   print(li)
#   print(li2)
#   往嵌套列表里添加元素
#   li[3].append(7)
#   print(li)
#   print(li2)
#   内层的内存地址相同
#   (3) 深拷贝（数据完全不共享）
#   外层对象和内部元素都拷贝了一遍
#   import copy
#   li2 = copy.deepcopy(li)
#   print(li2)
#   print(id(li))
#   print(id(li2))
#   li.append(7)
#   print(li)
#   print(li2)
#   在嵌套列表添加元素
#   li[3].append(7)
#   print(li)
#   print(li2)
#   print(id(li))
#   print(id(li2))
#   内层地址也不一样
# 3.可变类型
#   含义：变量对应的值可以修改，但是内存地址不会改变
#   常见的可变类型：list、dict、set
# 4.不可变对象
#   含义：变量对应的值不能被修改，如果修改就会生成一个新的值从而分配新的内存空间
#   注意：深浅拷贝只支持可变对象

#   Lesson 9

# 1.函数
#   格式：
#   def 函数名():
#       函数体
#   调用函数前，需保证函数已存在
# 2.返回值 return
#   需要打印才会出现值，以元组的形式返回多个值，无返回值为None
#   return表示此函数结束，不再运行，以下代码不再执行
# 3.参数
#   (1) 形参和实参
#   def 函数名(形参a,形参b):
#       函数体
#   函数名(实参1,实参2)
#   (2) 函数参数
#   **必备参数（位置参数）**
#   传递和定义参数的顺序及个数必须一致
#   **默认参数**
#   注意：位置参数要出现在默认参数前
#   def func(a=1):
#       print(a)
#   func()
#   func(2)
#   设置默认值，没有传值会根据默认值来执行代码，传了值根据传的值来执行代码
#   **可变参数**
#   def func(*args): # 可以把args改成其他参数名，但是args更规范
#       print(args)
#   func(1,2,3) # 以元组形式接收
#   **关键字参数**
#   格式：def func(**kwargs)
#   def func(**kwargs):
#       print(kwargs) # 以字典形式接收
#   func() # 空字典
#   func(name='LIXX',age=18) # 传值时，采用键=值的形式
#   (3) 函数嵌套
#   **嵌套调用**
#   含义：在一个函数里调用另一个函数
#   **嵌套定义**
#   含义：在一个函数里定义另一个函数
#   注意：不要再内层函数调用外层函数

#   Lesson 10

# 1.作用域
#   (1) 全局变量
#   (2) 局部变量
#   global：可以对全局变量进行修改，也可在局部变量声明一个全局变量
#   nonlocal：只能对上一级进行修改
# 2.匿名函数
#   (1) 基本语法
#   函数名 = lambda 形参 : 返回值（表达式）
#   调用：结果 = 函数名（实参）
#   def add(a,b):
#       return a+b
#   print(add(1,3))
#   add = lambda a,b : a+b
#   print(add(1,3))
#   (2) lambda的参数形式
#   **无参数**
#   funa = lambda : "LIXX"
#   **一个参数**
#   funb = lambda name : name
#   **默认参数**
#   func = lambda name,age=18 : (name,age)
#   **关键字参数**
#   fund = lambda **kwargs : kwargs