
#include "route_planner.h"
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y) : m_Model(model)
{
    start_x *= 0.01;
    start_y *= 0.01;
    end_x *= 0.01;
    end_y *= 0.01;
    *start_node = m_Model.FindClosestNode(start_x, start_y);
    *end_node = m_Model.FindClosestNode(end_x, end_y);
}

std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node)
{
    std::vector<RouteModel::Node> path_found;
    RouteModel::Node t;

    total_dist = 0;
    while (current_node->parent != nullptr)
    {
        RouteModel::Node *temNode = current_node->parent;
        path_found.push_back(*current_node);
        total_dist += current_node->distance(*temNode);
        current_node = current_node->parent;
    }
    path_found.push_back(*current_node);
    total_dist *= m_Model.MetricScale();
    return path_found;
}
void RoutePlanner::AStarSearch()
{
    end_node->parent = start_node;
    m_Model.path = ConstructFinalPath(end_node);
}
