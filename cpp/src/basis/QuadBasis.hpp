#ifndef QUAD_BASIS_HPP
#define QUAD_BASIS_HPP

#include "ElementBases.hpp"
#include "Mesh2D.hpp"
#include "LocalBoundary.hpp"

#include <Eigen/Dense>
#include <vector>

namespace poly_fem
{
	class QuadBasis
	{
	public:
		static int build_bases(const Mesh2D &mesh, const int quadrature_order, std::vector< ElementBases > &bases, std::vector< LocalBoundary > &local_boundary, std::vector< int > &bounday_nodes);

		static void basis(const int disc_order, const int local_index, const Eigen::MatrixXd &uv, Eigen::MatrixXd &val);
		static void grad(const int disc_order, const int local_index, const Eigen::MatrixXd &uv, Eigen::MatrixXd &val);
	};
}

#endif //QUAD_BASIS_HPP
