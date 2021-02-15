#include <iostream>
#include <Eigen/Dense>
#include <Eigen/LU>
#include <Eigen/Cholesky>


using namespace Eigen;

int main()
{
  Vector3d a(1, 1, 0);
  Vector3d b(-1, 2, 5);
  MatrixXd M(3, 3);

  M << 2, -1, 0,
       -1, 2, -1,
       0,  -1, 2;

  std::cout << "Inner product between a and b: " << a.adjoint() * b << '\n';
  std::cout << "Matrix product between M and b: \n" << M * b << '\n';
  std::cout << "L2 norm of b: " << b.norm() << '\n';
  std::cout << "Mx = b solution using LU: \n" << M.fullPivLu().solve(b)  << '\n';
  std::cout << "Mx = b solution using Cholesky \n: \n" << M.ldlt().solve(b) << '\n';
}
