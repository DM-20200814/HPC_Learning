#include <iostream>
#include <Eigen/Core>

int main()
{
    // 这是Eigen的一个宏，用于输出当前Eigen的版本
    std::cout << "Eigen version is:\n";
    std::cout << EIGEN_WORLD_VERSION << "." << EIGEN_MAJOR_VERSION << "." << EIGEN_MINOR_VERSION << std::endl;
    return 0;
}