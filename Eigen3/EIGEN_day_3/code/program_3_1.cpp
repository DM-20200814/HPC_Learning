#include <Eigen/Dense>
#include <iostream>

void test01()
{
    Eigen::Matrix3f A;
    Eigen::Vector3f b;
    A << 1, 2, 3, 4, 5, 6, 7, 8, 10;
    b << 3, 3, 4;
    std::cout << "Here is the matrix A:\n" << A << std::endl;
    std::cout << "Here is the vector b:\n" << b << std::endl;
    Eigen::Vector3f x = A.colPivHouseholderQr().solve(b);
    std::cout << "The solution is:\n" << x << std::endl;
}
void test02()
{
    Eigen::Matrix2f             A, b;
    Eigen::LLT<Eigen::Matrix2f> llt;
    A << 2, -1, -1, 3;
    b << 1, 2, 3, 1;
    std::cout << "Here is the matrix A:\n" << A << std::endl;
    std::cout << "Here is the right hand side b:\n" << b << std::endl;
    std::cout << "Computing LLT decomposition..." << std::endl;
    llt.compute(A);
    std::cout << "The solution is:\n" << llt.solve(b) << std::endl;
    A(1, 1)++;
    std::cout << "The matrix A is now:\n" << A << std::endl;
    std::cout << "Computing LLT decomposition..." << std::endl;
    llt.compute(A);
    std::cout << "The solution is now:\n" << llt.solve(b) << std::endl;
}
void test03()
{
    Eigen::MatrixXf A = Eigen::MatrixXf::Random(3, 2);
    std::cout << "Here is the matrix A:\n" << A << std::endl;
    Eigen::VectorXf b = Eigen::VectorXf::Random(3);
    std::cout << "Here is the right hand side b:\n" << b << std::endl;
    Eigen::Vector2f x;
    x = A.bdcSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(b);
    std::cout << "The least-squares solution is:\n" << x << std::endl;
    std::cout << "The least-squares solution is:\n"
              << A.bdcSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(b)
              << std::endl;
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}