#include <iostream>

#include <Eigen/Dense>

using namespace Eigen;

// 使用Eigen::Matrix类定义一个2行3列的矩阵，赋值为1~6
void test01()
{
    Matrix<float, 2, 3> matrix_2_3;
    matrix_2_3 << 1, 2, 3, 4, 5, 6;
    std::cout << "matrix_2_3 is:\n" << matrix_2_3 << std::endl;
}
// 两种改变动态矩阵的方式，resize和conservativeResize
void test02()
{
    Matrix<float, -1, -1> matrix_3_2;
    matrix_3_2.resize(2, 3);
    matrix_3_2 << 1, 2, 3, 4, 5, 6;
    std::cout << "matrix_3_2 is:\n" << matrix_3_2 << std::endl;
    matrix_3_2.resize(3, 2);
    std::cout << "resized matrix_3_2 is:\n" << matrix_3_2 << std::endl;
    matrix_3_2.conservativeResize(2, 2);
    std::cout << "conservatively resized matrix_3_2 is:\n"
              << matrix_3_2 << std::endl;
}

// 常见的一些矩阵函数
void test03()
{
    int m{3}, n{4};
    // random
    auto matrix_random = MatrixXd::Random(m, n);
    std::cout << "matrix_random is:\n" << matrix_random << std::endl;
    // zero
    auto matrix_zero = MatrixXd::Zero(m, n);
    std::cout << "matrix_zero is:\n" << matrix_zero << std::endl;
    // ones
    auto matrix_ones = MatrixXd::Ones(m, n);
    std::cout << "matrix_ones is:\n" << matrix_ones << std::endl;
    // identity
    auto matrix_identity = MatrixXd::Identity(m, m);
    std::cout << "matrix_identity is:\n" << matrix_identity << std::endl;
    // constant
    auto matrix_constant = MatrixXd::Constant(m, n, 1.2);
    std::cout << "matrix_constant is:\n" << matrix_constant << std::endl;
    // linspace vector
    auto matrix_linspace = VectorXf::LinSpaced(m, 0, 10);
    std::cout << "matrix_linspace is:\n" << matrix_linspace << std::endl;
    // no logspace vector
}
// 矩阵的基本运算
void test04()
{
    Matrix<double, 3, 3> A_mat_3_3;
    A_mat_3_3 << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    Matrix<double, 3, 3> B_mat_3_3;
    B_mat_3_3 << 9, 8, 7, 6, 5, 4, 3, 2, 1;
    Matrix<double, 1, 3> C_mat_1_3;
    C_mat_1_3 << 1, 2, 3;
    // 矩阵的加减乘,除
    std::cout << "A_mat_3_3 + B_mat_3_3 is:\n"
              << A_mat_3_3 + B_mat_3_3 << std::endl;
    std::cout << "A_mat_3_3 - B_mat_3_3 is:\n"
              << A_mat_3_3 - B_mat_3_3 << std::endl;
    std::cout << "A_mat_3_3 * B_mat_3_3 is:\n"
              << A_mat_3_3 * B_mat_3_3 << std::endl;
    std::cout << "B_mat_3_3 inverse:\n" << B_mat_3_3.inverse() << std::endl;
    std::cout << "A_mat_3_3 / B_mat_3_3 is:\n"
              << A_mat_3_3 * B_mat_3_3.inverse() << std::endl;
    std::cout << "A_mat_3_3 * C_mat_1_3 is:\n"
              << A_mat_3_3 * C_mat_1_3.transpose() << std::endl;
}

// 矩阵本身的操作
void test05()
{
    // ...见文档
}

// broadcasting
void test06()
{
    Matrix<double, 2, 4> A_mat_2_4;
    A_mat_2_4 << 1, 2, 3, 4, 5, 6, 7, 8;
    Vector2d B_vec_2_1;
    B_vec_2_1 << 1, 2;
    std::cout << "A_mat_2_4 + B_vec_2_1 is:\n"
              << A_mat_2_4.colwise() + B_vec_2_1 << std::endl;
}


int main()
{
    // test01();
    // test02();
    test03();
    // test04();
    // test05();
    // test06();
    return 0;
}