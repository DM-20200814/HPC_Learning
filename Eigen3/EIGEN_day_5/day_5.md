由于EIGEN网站崩了，一直没好，第五天的学习延迟了几天，等了几天还是没好，原因是tuxfamily服务器崩了，导致挂在这些服务器上面的网页无法访问。等了两三天，上一些论坛看看有什么动静，结果确实有一些人都提出了这个问题，不过确实得等两天才会有人聊起这个问题。那么解决问题的办法有哪些呢？
- 镜像网站：`https://eigen-docs.netlify.app/`，有人遇到了这个问题，自己动手解决了这个问题。eigen用的doxygen，也能自己做一个网站，然后挂在github上，最近我刚好也用doxygen做了一个库的在线文档。
- Internet Archive:互联网档案馆是美国的一个非营利性的、提供互联网多媒体资料文件阅览服务的数字图书馆，它会提供一些网站的历史版本，在主页输入eigen的网址，就可以看到一个时间表，选择一个时间点，就可以看到当时的网页了。`https://web.archive.org/web/20230706031120/https://eigen.tuxfamily.org/index.php?title=Main_Page`
# 稀疏矩阵的求解
> 内置求解器  

|Class|Solver kind|Matrix kind|Features related to performance|Notes|
| :----: | :----: | :----: | :----: | :----: |
|SimplicialLLT<br><span style="font-family: Times New Roman; font-size: 15px;">#include<Eigen/SparseCholesky></span> </br>|Direct LLt factorization|SPD|fill-in reducing| SimplicialLLT is often peferable|
这里只给个例子，其它的请看文档。求解器有内置的直接求解器、迭代求解器和外部求解器。
求解器的使用伪代码如下：
```cpp
#include <Eigen/RequiredModuleName>
// ...
SparseMatrix<double> A;
// fill A
VectorXd b, x;
// fill b
// solve Ax = b
SolverClassName<SparseMatrix<double> > solver;
solver.compute(A);
if(solver.info()!=Success) {
  // decomposition failed
  return;
}
x = solver.solve(b);
if(solver.info()!=Success) {
  // solving failed
  return;
}
// solve for another right hand side:
x1 = solver.solve(b1);
```
对于对称正定的矩阵，求解器模板的第二个参数可以指定使用哪一个三角块。例如：Eigen::Upper
`compute()`函数可以分为`analyzePattern()`和`factorize()`两部分，分析部分不受数值的影响，对于相同结构(非零元位置一致，只有值不同)，可以省去第一步。
```cpp
SolverClassName<SparseMatrix<double> > solver;
solver.analyzePattern(A);   // for this step the numerical values of A are not used
solver.factorize(A);
x1 = solver.solve(b1);
x2 = solver.solve(b2);
...
A = ...;           // modify the values of the nonzeros of A, the nonzeros pattern must stay unchanged
solver.factorize(A);
x1 = solver.solve(b1);
x2 = solver.solve(b2);
...
```
不同求解器的适用对象不同，cholseky分解需要是对称正定的矩阵，因此再例子1中，simplicialLDLT的结果与其它两个求解器不一致，例2重新设置好对称矩阵后使用不同的求解器，得到的结果就一致了。而SparseQR需要输入的矩阵是压缩矩阵，矩阵先要调用`makeCompressed()`函数，而`makeCompressed()`没有返回值，需要先调用再传入求解器。solve(A.makeCompressed())会报错。
# 迭代法
求解方法跟之前的求解器用法一样。迭代器可以设置误差和迭代次数。
求解器有一个信息状态参数，通过调用info()函数获取，作用是记录求解器当前是否正常。在compute()、solve()等函数调用后会更新这个参数。
# eigen的几何模块
这一块目前我还用不到，所以eigen库的基础知识学习就到这里。