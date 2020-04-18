
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
float RoutePlanner::CalculateHValue(const RouteModel::Node *node)
{
    return node->distance(*end_node);
}
RouteModel::Node *RoutePlanner::NextNode()
{
    // RouteModel::Node *next_node;
    // float f_value_min = std::numeric_limits<float>::max();
    // for (RouteModel::Node *node : open_list)
    // {
    //     if ((node->g_value + node->h_value) < f_value_min)
    //     {
    //         f_value_min = node->g_value + node->h_value;
    //         next_node = node;
    //     }
    // }

    // return next_node;

    std::sort(open_list.begin(), open_list.end(), [](const auto &a, const auto &b) {
        return a->h_value + a->g_value < b->h_value + b->g_value;
    });
    RouteModel::Node *next_node = open_list.front();
    open_list.erase(open_list.begin());
    return next_node;
}