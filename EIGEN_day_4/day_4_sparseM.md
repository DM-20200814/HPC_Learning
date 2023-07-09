# sparse matrix
稀疏矩阵是最常用到的一类矩阵，简单来说就是矩阵中大部分元素都是0。
## 稀疏对象的创建
Eigen中使用SparseMatrix类和SparseVector来表示稀疏矩阵和稀疏向量，模板参数有三个：矩阵元素类型`int,double...`、行、列存储类型(`Rowmajor,Colmajor`)、索引类型(`int,long...`)。
构造函数需要传入对象的size，resize函数可以修改函数大小，不知道初始化大小，默认为0×0；
```cpp
SparseMatrix<double> sm1(1000,1000); 
SparseMatrix<std::complex<double>,RowMajor> sm2;
```
一些常用的函数：用于查看变量的一些属性
| 函数名 | 描述 |
| --- | --- |
| `sm1.rows()` | 行数 |
| `sm1.cols()` | 列数 |
| `sm1.nonZeros()` | 非零值的数量 |
| `sm1.outerSize()` | 列主序（column major）时的列数，行主序（row major）时的行数 |
| `sm1.innerSize()` | 行主序（row major）时的行数，列主序（column major）时的列数 |
| `sm1.norm()` | 矩阵的欧几里得范数 |
| `sm1.squaredNorm()` | 矩阵的平方范数 |
| `sm1.blueNorm()` | 矩阵的布洛赫范数 |
| `sm1.isVector()` | 检查 `sm1` 是否为稀疏向量或稀疏矩阵 |
| `sm1.isCompressed()` | 检查 `sm1` 是否已压缩 |
## 赋值
### Triplets
Triplets是一种数据结构，用于存储稀疏矩阵的非零元素，它包含三个元素：行、列、值。其包含两个模板参数：数据类型以及储存索引。第二个参数有默认值，因此一般只需要设置第一个参数即可。构造函数常用的是输入三个参数，分别是行、列以及数值。简单使用如下：
```cpp
std::vector<Triplet<double>> tripletList(m,n,value);
```
通过Triplet对象可以构造稀疏矩阵，如下：
```cpp
vector<Triplet<double>> tripletList;

for(int j = 1; j < n+1; j++)
{
    tripletList.push_back(Triplet<double>(j,j,value));
}

SparseMatrix<double> sm1(m,n);
sm1.setFromTriplets(tripletList.begin(),tripletList.end());

// 可以直接插入
sm1.insert(1,5) = 7.0;

sm1.block(0,0,2,2);// 返回一个稀疏矩阵的块，(起始行，起始列，行数，列数)
```
