## C++ 编程备忘录

### string 注意事项

1. string尾部添加字符串

   ```
   string a("Hello");
   a.append("World");
   ```

   

2. string尾部添加单个字符

   ```c++
   string a("Hello");
   a.append(1,'A');
   a.push_back('B');
   a+='A';
   ```

3. string使用**at**或者**[]**时，需要保证目前**下标**小于string的**size()**

   ```c++
   string a("Hello");
   a.at[0]='W';//OK
   a.at[10]='t';//NOK,目前没有具体的行为
   ```

4. string和char* 互转

   ```c++
   string a("hello");
   const char *p=a.c_str();//c_str返回是只读指针，不能通过p去修改string的值
   char buf[1024]={0};
   sprintf(buf,"%s",a.c_str());
   ```

### char*尾部添加字符
* 使用strcat
 ```cpp
  char str[100]="Hello";
  strcat(str,"world");
 ```

* 使用sprintf
 ```cpp
  char str[100]="Hello";
  sprintf(str,"%s%s",str,"world");
 ```
* 使用strcpy
 ```cpp
  char str[100]="Hello";
  strcpy(str+strlen(str),"world");
 ```

### char*与char[]区别

```cpp
char* p="Hello";//p指向的地方是以全局只读内存，所以不能更改如strcpy(p,"12345")
char  m[16]="Hello";//m指向的地方是可写，所以可以更改
```

### char[] 初始化

```cpp
char p[16]={0};//只有初始化为0，才是全部初始化。所以这个会p的16个byte都会被置0
char m[16]={1};//这个只有m[0]=1,其它undefined
```



### 从console读取字符

1. 使用getchar，注意判断结束标志是**EOF（-1）**

   ```c++
   	while((t=getchar())!=EOF){
   		printf("%c",t);
   	}	
   ```

2. 使用cin时，注意判断方式，因为cin读取文件结束时，会置failbit与eofbit，此时cin的判断重载会读取failbit从而判断为非

   ```c++
   char c;
   while(cin>>c){
   ...		
   }	
   ```

***

### C++中自定义类型判断与指针判断区别

```c++
struct Point{
    int x;
    int y;
    operator bool() const  {
		return x+y;
	}
};
Point a;
Point *b;
```

> if(a)---里面的具体类型变量，这个会触发bool重载
>
> if(b)--b为指针，就是单纯的判断b是否为空，不需要触发任何重载

### 字符0与数字0之间的区别

> 字符0存在内存实际是其ASCII码，即0x30
>
> 数字0存在内存实际为0

### const指针的注意[就近原则]

```cpp
const char *p;//表示const char,即指针指向的区域不可修改，但是指针是可以指向别人
strcpy(p,"Hello");//试图修改p为Hello，编译报错

char * const p="Hello";//表示const p，即这个指针是不可修改，即指针只能指向固定的地址，
p=&A;//试图指向另一个变量，报错
```

