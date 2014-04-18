#ifndef DWL_Solver_H
#define DWL_Solver_H

#include <planning/Constraint.h>
#include <planning/Cost.h>
//#include <iostream>
#include <Eigen/Dense>
#include <vector>
#include <utils/macros.h>


namespace dwl
{

namespace planning
{

class Solver
{
	public:
		/** @brief Constructor function */
		Solver() {};

		/** @brief Destructor function */
		virtual ~Solver() {};

		virtual bool init() = 0;
		virtual bool compute(Eigen::MatrixXd& solution) = 0;

		void addConstraint(Constraint* constraint);
		void addCost(Cost* cost);

		std::string getName();

	private:

	protected:
		std::string name_;
		std::vector<Constraint*> active_constraints_;
		std::vector<Constraint*> inactive_constraints_;
		std::vector<Cost*> costs_;
};

} //@namespace planning

} //@namespace dwl


inline std::string dwl::planning::Solver::getName()
{
	return name_;
}


#endif
