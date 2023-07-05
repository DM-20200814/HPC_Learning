#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

int main()
{
    // 以Xd方式声明一个3x3的矩阵
    MatrixXd mat(3, 3);
    // 将矩阵(0,0)位置元素赋为1.5
    mat(0, 0) = 1.3;
    // 将矩阵(1,1)位置元素赋为2.4
    mat(1, 1) = 2.4;
    // 将矩阵(2,2)位置元素赋为3.5
    mat(2, 2) = 3.5;
    // 输出矩阵
    std::cout << mat << std::endl;
    return 0;
}