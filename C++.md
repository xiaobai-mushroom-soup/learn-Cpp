学习之前环境搭建请查看：[C++学习前注意事项](https://www.yuque.com/daidai-n9tou/iw3pax/xlg62lx2qhg43q9b?view=doc_embed)
# 开始
一个C++程序都包含至少一个甚至多个函数，并且其中一个必须命名为**main**。
操作系统通过调用main来运行C++程序。
```typescript
int main(){
  return 0;
}
```
:::info
由上述代码可知，一个函数定义包括四部分：**返回类型**、**函数名**、**一个括号包围的形参列表**、**函数体**
解析上述代码：
返回类型：`int`
函数名：`main`
一个括号包围的形参列表：`()`
函数体：`{ return 0;}`
:::
其中函数体返回的值要与前面的返回类型一致；
> 注意：return 语句末尾的分号。在C++中，大多数C++语句以分号表示结束！如果忘记写分号，就会导致莫名其妙的编译错误。

**重要的概念：类型**
:::info
类型是程序设计最基本概念之一，一种类型不仅定义了元素的内容，并且还定义了这一类数据上可以进行的运算。
程序处理所需要的数据都保存在变量中，而且每个变量都有自己的类型。eg：如果一个名为v的变量的类型为T，我们通常说“v具有类型T”，或者说“v是一个T类型的变量”。
:::
## 编译和运行 程序
本文集成的Mingw-w64,使用g++编译文件，编译成功后会生成exe文件。
指令：
```typescript
g++ -o 这里输入编译后的名字 这里输入你的文件
# eg:
g++ -o test captor01.cpp
# 运行直接输入文件名
test
```
## 输入输出
C++语言并未定义任何输入输出（IO）语句；
而是使用一个**标准库(standard library)**来提供IO机制（以及其他功能语句）。
> 标准库1：**iostream库**
> iostream库包含两个基础类型`istream`和`ostream`，分别表示输入流和输出流。
> 其中，一个流就是一个字符序列，是从IO设备读出或写入IO设备的。
> 术语：“流（stream）”所表达的是，随着时间的推移。字符是顺序生成或消耗的。

**接上方标准库拓展**
标准库定义了4个IO对象：

- 处理输入【标准输入(standard input)】:`**cin**`
- 处理输出【标准输出(standard output)】:`**cout**`
- 输出错误或警告【标准错误(standard error)】:`**cerr**`
- 输出程序运行时的一般性信息：`**clog**`
> 系统通常会将**程序所运行的窗口**与**这些对象**关联起来。

案例一：
> 注意：代码请编译后使用控制台运行。

```cpp
#include <iostream>

int main()
{
    std::cout << "请输入两个数字:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "数字" << v1 << "+" << v2 << "=" << v1 + v2 << std::endl;

    return 0;
}
```
![image.png](https://cdn.nlark.com/yuque/0/2023/png/27064455/1679157093323-419a92ec-92aa-4cec-b7fb-394e4bdd675b.png#averageHue=%231a1a1a&clientId=u847f3783-c759-4&from=paste&height=511&id=u1b74deb1&name=image.png&originHeight=639&originWidth=1094&originalType=binary&ratio=1.25&rotation=0&showTitle=false&size=29078&status=done&style=none&taskId=u32dd7bf9-b0c1-4849-b526-4f687f7a513&title=&width=875.2)
代码解读：（下方都围绕这上方代码解读学习。）
程序第一行：`#include <iostream>`：告诉编辑器，我们要使用iostream库
> 尖括号中的名字指出了一个头文件。每个使用标准库设施的程序都必须包含相关的头文件。
> `#include`指令和头文件的名字必须写在同一行中。
> 一般情况下`#include`指令必须出现在所有函数之外。我们一般将一个程序的所有`#include`指令都放在源文件的开始位置。

**向流写入数据**
在mian()函数里，第一句代码解读：`std::cout << "请输入两个数字:" << std::endl;`

第一句执行了一个**表达式（expression）**。
> C++中表达式会产生一个计算结果，它由一个或多个运算符对象和一个运算符组成。

:::info
新概念：输出运算符`<<`
`<<`运算符接受两个运算对象：

- 左侧的运算必须是一个`**ostream对象**`
- 右侧的运算对象是要打印的值。

作用：输出运算符的计算结果就是其左侧运算对象。
:::

当运行`std::cout << "xxxx"`，那么**双引号**之间的文本会被打印到标准输出。
:::info
新概念：操纵符（manipulator） 
表达式中的`endl`就是操纵符
而写入`endl`的作用是结束当前行；并将与设备关联的缓冲区中的内容刷到设别中。
缓冲刷新操作可以保证到目前为止程序所产生的所有输出都真正写入输出流中，而不仅停留在内存中等待写入流。
:::
**使用标准库中的名字**
在程序中使用到了`std::cout`和`std::endl`,而不是直接的cout和endl。前缀`std::`指出名字cout和endl是定义在名为`**std**`** **的**命名空间**中的。
:::info
新概念：命名空间(namespace)
作用：命名空间可以帮助我们避免不经意的名字定义冲突，以及使用库中相同名字导致的冲突。
标准库定义的所有名字都在命名空间`std`中
命名空间副作用：当时有标准库中的一个名字时，必须**显式说明**我们想使用来自命名空间`std`中的名字。
比如：需要写出`std::cout`,通过**作用运算符（**`**::**`**）**来指出我们想使用定义在命名空间std中的名字cout。
:::
**从流读取数据**
`int v1 = 0, v2 = 0;`：声明并初始化变量。
`std::cin >> v1 >> v2;`：它会读入数据。
:::info
新概念：输入运算符`>>`
它与输出运算符类似；它接受一个`istream`作为其左侧运算对象，接受一个对象作为其右侧运算对象。
作用：它会从给定的`istream`读入数据，并存入给定对象中。与输出运算符相似，输入运算符返回其左侧运算对象作为其运算结果。
:::
## 注释
C++有两种注释：`单行注释``界定符对注释`
单行注释：
```javascript
// 双引号进行注释
```
界定符对注释：
```javascript
/*
*
*
*
*/
```
## 流程控制
### 循环
**while语句**
```javascript

#include <iostream>

int main()
{
    int sum = 0, val = 1;
    while (val <= 10) {
        sum += val;
        ++val;
        std::cout << sum, val;
    }
    std::cout << "1+到10和为" << sum ;

    return 0;
}

```
**for语句**
```javascript
#include <iostream>

int main()
{
    for (int i = 0; i <= 10; i++) {
        std::cout << "i:" << i<<std::endl;
    }
    return 0;
}

```
**读取数量不定的输入数据**
```javascript
#include <iostream>

int main()
{
    int sum = 0, val = 0;
    while (std::cin >> val) 
        sum += val;
    
        std::cout << "sum is:" << sum <<std:: endl;
    return 0;
}

```
> 如果一直输入则一直执行，只有遇到异常输入，才会退出。
> 我们可以主动退出：Win下Ctrl+Z后回车；UNIX、mac中CTRL+D

### 常见错误
语法错误syntax error

- 漏掉分号
- 使用字符串但未加双引号
- 漏掉了输出运算符

类型错误type error

- C++中每个数据都有对应的类型，如果为一个int类型，赋予一个字符串类型会出现这个错误

声明错误declaration error
C++中变量都是先声明后使用。

- 意外使用未声明的变量
- 未声明命名空间直接使用命名空间的对象
### 流程控制
if
```javascript
int i=1;
if(i==1){
  // ...
}
```
> C++中用`=`赋值；用`==`进行判断













