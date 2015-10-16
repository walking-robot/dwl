#ifndef DWL__LOCOMOTION__WHOLE_BODY_TRAJECTORY_OPTIMIZATION__H
#define DWL__LOCOMOTION__WHOLE_BODY_TRAJECTORY_OPTIMIZATION__H

#include <dwl/solver/OptimizationSolver.h>
#include <dwl/model/DynamicalSystem.h>
#include <dwl/model/Constraint.h>
#include <dwl/model/Cost.h>
#include <dwl/utils/SplineInterpolation.h>


namespace dwl
{

namespace locomotion
{

typedef std::vector<LocomotionState> LocomotionTrajectory;

/**
 * @class WholeBodyTrajectoryOptimization
 * @brief This class solves whole-body trajectory optimization problem given dynamical system
 * constraint and set of constraints and cost function.
 */
class WholeBodyTrajectoryOptimization
{
	public:
		/** @brief Constructor function */
		WholeBodyTrajectoryOptimization();

		/** @brief Destructor function */
		~WholeBodyTrajectoryOptimization();

		/**
		 * @brief Initializes the whole-body trajectory optimizer
		 * @param solver::OptimizationSolver* Pointer to the optimization solver
		 */
		void init(solver::OptimizationSolver* solver);

		/**
		 * @brief Adds the dynamical system constraint
		 * @param model::DynamicalSystem* Pointer to the dynamical system constraint
		 */
		void addDynamicalSystem(model::DynamicalSystem* system);

		/** @brief Removes the current dynamical system */
		void removeDynamicalSystem();

		/**
		 * @brief Adds the constraint
		 * @param model::Constraint* Pointer to the constraint
		 */
		void addConstraint(model::Constraint* constraint);

		/**
		 * @brief Removes the current dynamical system
		 * @param std::string Name constraint
		 */
		void removeConstraint(std::string name);

		/**
		 * @brief Adds the cost function
		 * @param model::Cost* Pointer to the cost function
		 */
		void addCost(model::Cost* cost);

		/**
		 * @brief Removes the cost function
		 * @param std::string Name cost
		 */
		void removeCost(std::string name);

		/**
		 * @brief Sets the horizon
		 * @param unsigned int Horizon value
		 */
		void setHorizon(unsigned int horizon);

		/**
		 * @brief Sets the initial state of the dynamical constraint
		 * @param const LocomotionState& Initial state
		 */
		void setStepIntegrationTime(const double& step_time);

		/**
		 * @brief Sets the nominal trajectory
		 * @param std::vector<LocomotionState>& Nominal trajectory
		 */
		void setNominalTrajectory(std::vector<LocomotionState>& nom_trajectory);

		/**
		 * @brief Computes a whole-body trajectory
		 * @param const LocomotionState& Current whole-body state
		 * @param const LocomotionState& Desired whole-body state
		 * @param double Allowed computation time
		 */
		bool compute(const LocomotionState& current_state,
					 const LocomotionState& desired_state,
					 double computation_time);

		/** @brief Gets the dynamical system constraint */
		model::DynamicalSystem* getDynamicalSystem();

		/**
		 * @brief Gets the whole-body trajectory
		 * @return LocomotionTrajectory& Whole-body trajectory
		 */
		const LocomotionTrajectory& getWholeBodyTrajectory();

		/**
		 * @brief Gets the interpolated whole-body trajectory
		 * @param const double Time of interpolation
		 * @return LocomotionTrajectory& Whole-body trajectory
		 */
		const LocomotionTrajectory& getInterpolatedWholeBodyTrajectory(const double& interpolation_time);


	private:
		/** @brief Optimization solver */
		solver::OptimizationSolver* solver_;

		/** @brief Interpolated locomotion trajectory */
		LocomotionTrajectory interpolated_trajectory_;
};

} //@namespace locomotion
} //@namespace dwl

#endif