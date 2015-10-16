#ifndef DWL__MODEL__HS071_COST__H
#define DWL__MODEL__HS071_COST__H


#include <dwl/model/Cost.h>


namespace dwl
{

namespace model
{

class HS071Cost : public Cost
{
	public:
		HS071Cost() {name_ = "HS071";}
		~HS071Cost() {}

		void compute(double& cost,
					 const LocomotionState& state)
		{
//			assert(n == 4);

			cost = state.joint_pos(0) * state.joint_pos(3) * (state.joint_pos(0) +
					state.joint_pos(1) + state.joint_pos(2)) + state.joint_pos(2);
		}
};

} //@namespace model
} //@namespace dwl

#endif