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

### `scanf()`与`cin`的注意事项

#### `scanf`以`"%d"`或其他形式读入不会读入换行符，**但以`%c`形式读入会读入`\n`**。`cin.get()`也会读入。

#### `cin`不会读入`\n`.

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

### 01背包

#### 01背包公式

$$
opt[i][v]=max(opt[i-1][v],opt[i-1][v-volume[i]]+value[i])
$$



| 体积 | 价值 |
| ---- | ---- |
| 2    | 1    |
| 3    | 3    |
| 4    | 5    |
| 7    | 9    |

> 背包二维数组

|      | v=0  | v=1  | v=2  | v=3  | v=4   | v=5  | v=6  | v=7   | v=8  | v=9  | v=10 |
| ---- | ---- | ---- | ---- | ---- | ----- | ---- | ---- | ----- | ---- | ---- | ---- |
| i=0  | 0    | 0    | 0    | 0    | 0     | 0    | 0    | 0     | 0    | 0    | 0    |
| i=1  | 0    | 0    | 1    | 1    | **1** | 1    | 1    | **1** | 1    | 1    | 1    |
| i=2  | 0    | 0    | 1    | 3    | 3     | 4    | 4    | **4** | 4    | 4    | 4    |
| i=3  | 0    | 0    | 1    | 3    | 5     | 5    | 6    | 8     | 8    | 9    | 9    |
| i=4  | 0    | 0    | 1    | 3    | 5     | 5    | 6    | 9     | 9    | 10   | 12   |

```cpp
int opt[max_kindbag][max_volumn] = { 0 };
void opt_dp_01() {
	for (int i = 1; i <= total_kindbag; i++) {
			for (int v = 1; v <= total_volumn; v++) {
			if (v >= volumn[i])
				opt[i][v] = max(opt[i - 1][v], opt[i - 1][v - volumn[i]] + value[i]);
			else
				opt[i][v] = opt[i - 1][v];
			}
	}
}
```

#### 一维优化

```cpp
for i=1....N
      v=V....1
         opt[v]=max(opt[v],opt[v-volume[i]]+value[i])
```



```cpp
int opt_1_dim[max_volumn] = {0};
void opt_dp_01_single_dimension() {
	for (int i = 1; i <= total_kindbag; i++) {
		for (int v = total_volumn; v >= 1; v--) {
			if (v >= volumn[i])
				opt_1_dim[v] = max(opt_1_dim[v], opt_1_dim[v - volumn[i]] + value[i]);
			else
				opt_1_dim[v] = opt_1_dim[v];
		}
	}
}
```

### 02背包

#### 公式

$$
opt[i][v]=max(opt[i-1][v],opt[i-1][v-k*volume[i]]+k*value[i])
$$



#### 代码

```cpp
void opt_dp_02() {
	for (int i = 1; i <= total_kindbag; i++) {
		for (int v = 1; v <= total_volumn; v++) {
			for (int k = 0;; k++) {
				if (v >= k * volumn[i]) {
					opt[i][v]=max(opt[i-1][v],opt[i-1][v-k*volumn[i]]+k*value[i]);
				}
				else {
					break;
				}
			}
		}
	}
}
```

#### 一维优化

```cpp
int opt_1_dim[max_volumn] = {0};
void opt_dp_02() {
	for (int i = 1; i <= total_kindbag; i++) {
		for (int v = total_volumn; v >= 1; v--) {
			for (int k = 0;; k++) {
				if (v >= k * volumn[i]) {
					opt[i][v]=max(opt[i-1][v],opt[i-1][v-k*volumn[i]]+k*value[i]);
				}
				else {
					break;
				}
			}
		}
	}
}
```

### 03背包

#### 代码：

```cpp
void dp_packpack_03() {
	for (int i = 1; i <= total_kindbag; i++) {
		for (int v = 1; v <= total_volumn; v++) {
			for (int k = 0; k<=num[i]; k++) {
				if (v >= k * volumn[i]) {
					int temp = max(opt[i - 1][v], opt[i - 1][v - k * volumn[i]] + k * value[i]);
					if (temp > opt[i][v])
						opt[i][v]=temp;
				}
				else {
					break;
				}
			}
		}
	}
}
```

#### 输入样例

```cpp
15 4
2 1 3
3 3 5
4 5 6
7 9 1
```

#### 输出样例

```cpp
19
```
### 最长公共子序列

#### 代码

```cpp
int main(){
	//freopen("lca.in","r",stdin);
	scanf("%s%s",&a,&b);
	//printf("a=%s b=%s\n",a,b);
	for(int i=0;i<strlen(a);i++){//记住从0开始，不让无法读入a[0],b[0]
		for(int j=0;j<strlen(b);j++){
			if(a[i]==b[j])
				opt[i+1][j+1]=opt[i][j]+1;
			else if(a[i]!=b[j])
				opt[i+1][j+1]=max(opt[i+1][j],opt[i][j+1]);	
			
		}
	}
	printf("%d",opt[strlen(a)][strlen(b)]);
	return 0;
}
```

```cpp
//从1开始的版本
int main(){
	freopen("lca.in","r",stdin);
/**/scanf("%s%s",a+1,b+1);
	printf("a=%s b=%s\n",a+1,b+1);
/**/for(int i=1;i<=strlen(a+1);i++){
/**/	for(int j=1;j<=strlen(b+1);j++){
			if(a[i]==b[j]){
/**/			opt[i][j]=opt[i-1][j-1]+1;	
			}
    		else if(a[i]!=b[j]){
/**/			opt[i][j]=max(opt[i][j-1],opt[i-1][j]);
			}
		}
	}
/**/printf("%d",opt[strlen(a+1)][strlen(b+1)]);
	return 0;
}
```

#### 另一种DP

##### **这种dp不再是简单的取或不取，而是要考虑其对整体的最优解**

##### 题干

```cpp
从n个数中去除任意个，要求他们的和最大且分布不连续。
```

##### 方程

```cpp

```



### 回溯算法

#### 排列，类似于不停的进入同一房间，所见都一样，只能通过vis来区分是否曾经用过

##### 题干

```cpp
从m个数中取出n个数，求出这些数的全排列，要求是按照大小输出。
```

##### 输入样例

```cpp
9 5
```

##### 输出样例

````cpp
0 1 2 3 4
0 1 2 3 5
...
4 5 6 7 8

````

##### 代码

```cpp
void search(int t){
	for(int i=0;i<m;i++){
		if(tot<n&&!vis[i]){
			if(!v.empty()&&i<v.back()){
				continue;
			}
			tot++;
			vis[i]=1;
			v.push_back(i);
			if(tot==n){
				print();
			//	return; 不可在此退出，不然无法继续搜索。
			}else{
				search(t+1);
			}
			v.pop_back();
			tot--;
			vis[i]=0;
		}
	}
}
```

### prim最小生成树

![1565580582465](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1565580582465.png)

0.由上图建立node_distance表

1.建立vis数组，用来保存访问的状态

2.建立dis数组，用来选择最短路径

```cpp
int nd[5][5] = {
	{0,3,1,MAX,MAX},
	{3,0,MAX,4,6},
	{1,MAX,0,2,7},
	{MAX,4,2,0,5},
	{MAX,6,7,5,0},
};
int vis[MAXN] = { 0 };
int dis[MAXN] = { 0 };
int nodeNum = 5;
```

3.思路：从2类中寻找最短路径

​	0.所有节点分为2类，用vis数组来区分；

​	1.从所有被访问过的节点，选择他们衍生出来的最短路径；

​	2.判断他通向的节点有没有被访问过，这样才可以保证不成环；

```cpp
int order = 1;
int ans = 0;
//init dis
for (int i = 0; i < nodeNum; i++) {
	dis[i] = nd[0][i];
}
for (int i = 0; i < nodeNum; i++) {	
	int min = MAXN;
	int pos = -1;
	int min_idx = -1;
	//find the shortest distance
	for (int j = 0; j < nodeNum; j++) {
		if (!vis[j] && min > dis[j]) {//未被访问+短一些
			min = dis[j];
			min_idx = j;//比较最短路径
    }
}
```



4.演示：
	1.如图，从节点1开始，选择最短路径1通向3，判断3未访问过，并将1，3置为访问过；

​	2.从当前已选的里面选取最短路径，选取通向4的2，判断其未被访问过，并将他设为访问过；

​	以此类推。更新所有已访问到未访问节点的最小值（2维for遍历）。

```cpp
int main() {
		//把最小距离加入vis
		vis[min_idx] = order;
		order++;
		ans += min;//加上
		//更新distance
		for (int unvisit_j = 0; unvisit_j < nodeNum; unvisit_j++) {

			if (!vis[unvisit_j]) {//未访问+不成环

				for (int visit_i = 0; visit_i < nodeNum; visit_i++) {

					if (vis[visit_i]&& visit_i != unvisit_j) {

						if (nd[visit_i][unvisit_j] < dis[unvisit_j]) {

							dis[unvisit_j] = nd[visit_i][unvisit_j];
						
						}
					}
				}
			}
		}
	}
	copy(vis, vis + nodeNum, ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "ans=" << ans << endl;
}
```

### Algorithm几种function

``` cpp
struct student{
    char name[32];
    int age;
    int chinese;
    int math;
    int english;
}
vector<student> sv;
vector<int> iv;
```





0. UnaryFunction

   ```cpp
   UnaryFunction for_each( iterator start, iterator end, UnaryFunction f );
   
   
   void myfunction (int i) {  // function:
     std::cout << ' ' << i;
   }
   for_each (iv.begin(), iv.end(), myfunction);
   
   struct myclass {           // function object type:
     void operator() (student i) {std::cout << i.name<<" "<<i.age<<" "<<endl;}
   } myobject;
   
   for_each (sv.begin(), sv.end(), myobject);
   
   ```

   

1. BinaryFunction 

   ```cpp
   TYPE accumulate( iterator start, iterator end, TYPE val, BinaryFunction f );
   ```

   

2. Unpred

   ```cpp
   iterator find_if( iterator start, iterator end, UnPred up );
   ```

   

3. BinPred

   ```cpp
   const TYPE& max( const TYPE& x, const TYPE& y, BinPred p );
   iterator search( iterator start1, iterator end1, iterator start2, iterator end2, BinPred p );
   const TYPE& min( const TYPE& x, const TYPE& y, BinPred p );
   ```

   

4. UnaryPred

   ```cpp
   size_t count_if( iterator start, iterator end, UnaryPred p );
   ```

   

5. StrictWeakOrdering 

   ```cpp
   void stable_sort( iterator start, iterator end, StrictWeakOrdering cmp );
   ```

   

6. BinOp 

   ```cpp
   iterator partial_sum( iterator start, iterator end, iterator result, BinOp p );
   ```

   

7. Predicate

   ```cpp
   iterator remove_if( iterator start, iterator end, Predicate p );
   ```

   

8. xx

9. xx

 ```cpp
size_t count_if( iterator start, iterator end, UnaryPred p );
 ```

 