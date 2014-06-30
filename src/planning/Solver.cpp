#include <planning/Solver.h>


namespace dwl
{

namespace planning
{


Solver::Solver() : adjacency_(NULL), is_graph_searching_algorithm_(false), total_cost_(0), is_settep_adjacency_model_(false)
{

}


Solver::~Solver()
{
	delete adjacency_;
}


void Solver::reset(environment::EnvironmentInformation* environment)
{
	adjacency_->reset(environment);
}


void Solver::setAdjacencyModel(environment::AdjacencyEnvironment* adjacency_model)
{
	printf(BLUE "Setting the %s adjacency model \n" COLOR_RESET, adjacency_model->getName().c_str());
	is_settep_adjacency_model_ = true;
	adjacency_ = adjacency_model;
}


bool Solver::compute(Vertex source, Vertex target, double orientation)
{
	if (is_graph_searching_algorithm_)
		printf(YELLOW "Could not compute the shortest-path because the %s is not defined an algorithm\n" COLOR_RESET, name_.c_str());
	else
		printf(YELLOW "Could not compute the shortest-path because the %s is not a graph-searchin algorithm\n" COLOR_RESET, name_.c_str());

	return false;
}


std::list<Vertex> Solver::getShortestPath(Vertex target)
{
	std::list<Vertex> path;
	if (is_graph_searching_algorithm_) {
		PreviousVertex::iterator prev;
		Vertex vertex = target;
		path.push_front(vertex);
		while((prev = previous_.find(vertex)) != previous_.end()) {
			vertex = prev->second;
			path.push_front(vertex);
		}
	} else {
		printf(YELLOW "Could not get the shortest path because the %s is not a graph-searchin algorithm\n" COLOR_RESET, name_.c_str());
	}

	return path;
}


double Solver::getMinimumCost()
{
	return total_cost_;
}


std::string dwl::planning::Solver::getName()
{
	return name_;
}


} //@namespace planning
} //@namespace dwl
