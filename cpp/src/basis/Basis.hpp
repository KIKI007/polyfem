#ifndef BASIS_HPP
#define BASIS_HPP

#include "Quadrature.hpp"

#include <Eigen/Dense>
#include <functional>

#include <vector>

namespace poly_fem
{
	class Local2Global
	{
	public:
		int index;
		double val;

		Eigen::MatrixXd node;
	};

	class Basis
	{

	public:
		typedef std::function<void(const Eigen::MatrixXd &uv, Eigen::MatrixXd &val)> Fun;


		Basis();

		void init(const int global_index, const int local_index, const Eigen::MatrixXd &node);


		void basis(const Eigen::MatrixXd &uv, Eigen::MatrixXd &val) const;
		void grad(const Eigen::MatrixXd &uv, Eigen::MatrixXd &val) const;

		inline const std::vector< Local2Global > &global() const { return global_; }
		inline std::vector< Local2Global > &global() { return global_; }
		// inline const Eigen::MatrixXd &node() const { return node_; }
		// inline void set_node(const Eigen::MatrixXd &v) { node_ = v; }

		inline void set_basis(const Fun &fun) { basis_ = fun; }
		inline void set_grad(const Fun &fun) { grad_ = fun; }
	private:
		std::vector< Local2Global > global_;
		int local_index_;


		Fun basis_;
		Fun grad_;
	};
}

#endif //BASIS_HPP
