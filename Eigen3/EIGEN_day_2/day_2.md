# Array的一些函数
- arr.abs()：逐元素取绝对值
- arr.sqrt()：逐元素开根号
- arr.pow()：逐元素乘方
- arr.matrix()：将Array转换为Matrix
- arr1.min(arr2)：将两个Array中相应位置的最小值组成一个新Array
- arr1.max(arr2)：将两个Array中相应位置的最大值组成一个新Array
# Matrix的块操作
- mat.row()：用于单独取出某一行(可修改)
- mat.col()：用于单独取出某一列(可修改)
- mat.topLeftCorner()：用于取出左上角元素
- mat.block<p,q>(i,j)：用于取出从(i,j)开始的p行q列的子矩阵
- mat.block(i,j,p,q)：用于取出从(i,j)开始的p行q列的子矩阵,动态大小，非固定大小
# Eigen的map函数
将c++原生数组转换成Map类型
```
// 用法
double data[8];
Map<Matrix<...>> map(data,m,n);
```
Map也可以转换成Matrix类型，但是无法使用auto自动判断类型，显示不可访问。
Map默认列优先，从左至右。关键字：`ColMajor = 0`，`RowMajor = 1`,Map很多操作都很神奇，以后慢慢补充。
# Random 的坑点
多次生成的随机矩阵是一样的，因为随机数种子是固定的，需要手动设置随机数种子。
而且矩阵数据类型是整形时，随机数的范围也是特别大，覆盖整个整形范围，浮点形的范围是[-1,1]。官网给的例子似乎存在一些问题
``` 
cout << 100 * Matrix2i::Random () << endl;
// 输出结果不是几百几百，数值有点夸张
Eigen::MatrixXi m = (Eigen::MatrixXf::Random(3, 3) * 10).cast<int>();
std::cout << "Here is the matrix m:" << std::endl << m << std::endl;
// 这个结果是先生成浮点形的，乘以10，然后转换成整形，所以结果是[-10,10]之间的整数
```

