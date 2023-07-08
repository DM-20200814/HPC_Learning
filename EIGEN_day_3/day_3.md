# 方程组的求解
[Eigen文档](https://eigen.tuxfamily.org/dox/group__TutorialLinearAlgebra.html)
$$
\left\{\begin{matrix} 
1x_1+2x_2+3x_3 = 3\\
4x_1+5x_2+6x_3 = 3\\
7x_1+8x_2+10x_3 = 4
\end{matrix}\right. 
$$
分为系数矩阵A和RHS右端向量b
不同分解方法的求解速度和精度略有不同，很不幸，官网给出的结$(-2,1,1)^T$，但是我电脑上并不是完全精确的解$(-2,0.9997,1)^T$。
求解过程是先调用分解方法把A分解，返回值一般是分解后的结果，再利用这个结果的求解函数求解。
> A.分解方法.solver(b)

奇怪矩阵方程的求解
$$
\left(\begin{array}{cc}
1 & 2 \\
3 & 1
\end{array}\right)=\left(\begin{array}{cc}
2 & -1 \\
-1 & 3
\end{array}\right)\left(\begin{array}{ll}
x_{1} & x_{2} \\
x_{3} & x_{4}
\end{array}\right)
$$
这个倒是很像地球电磁学求阻抗的形式
# 最小二乘求解
需要用到SVD分解，官网给的例子，在我这里代码编译失败，
```cpp
// 官网
A.template bdcSvd<Eigen::ComputeThinU | Eigen::ComputeThinV>().solve(b);
// 修改后
A.bdcSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(b);
```
最小二乘问题是许多优化问题的开端，即使是非线性问题，最小二乘会带来很多问题，它的解不精确，预测结果的不稳定balabala，苏联伟大科学家吉洪诺夫(时间可能不准确，可能是1940-1960)在研究微分方程不适定问题时，提出了正则化思想，他是用数学分析的语言和手段来研究正则化理论，在此之前或者之后，在回归问题中，也有相同的思路，比如岭回归、Lasso回归，后来的压缩感知，思路可以概括为，在缺观测数据和不知道具体响应方程的情况下，通过限制参数空间，来求得更稳定、更靠近正解的解，1978年，Constable把正则化概念引入到地球物理反演中，当然这个限制不一定是直接对参数值的约束，更多的是限制参数模型在整个空间的变化幅度。在此之前也有用“回归”这个词来谈反演，后来也就统一使用“正则化”这个概念了。
# 矩阵分解
矩阵分解具体见[https://eigen.tuxfamily.org/dox/group__TopicLinearAlgebraDecompositions.html](https://eigen.tuxfamily.org/dox/group__TopicLinearAlgebraDecompositions.html)
暂时没什么好说的，内容也很多，矩阵分解首先明白自己的分解对象有什么特征，然后去找合适的分解方法，具体情况具体分析。
