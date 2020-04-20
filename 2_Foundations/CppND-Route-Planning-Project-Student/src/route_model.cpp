#include "route_model.h"
#include <iostream>
//student
RouteModel::RouteModel(const std::vector<std::byte> &xml) : Model(xml)
{
    int counter = 0;

    for (Model::Node node : this->Nodes())
    {
        Node n1(counter, this, node);
        counter++;
        this->SNodes().push_back(n1);
    }

    // int counter = 0;
    // auto &con_m_Nodes = this->SNodes();
    // for (auto node : this->Nodes())
    // {
    //     con_m_Nodes.emplace_back(Node(counter, this, node));
    //     counter++;
    // }
    CreateNodeToRoadHashmap();
}

void RouteModel::CreateNodeToRoadHashmap()
{
    for (const Model::Road &road : Roads())
    {
        if (road.type != Model::Road::Type::Footway)
        {
            for (int node_idx : Ways()[road.way].nodes)
            {
                if (node_to_road.find(node_idx) == node_to_road.end())
                {
                    node_to_road[node_idx] = std::vector<const Model::Road *>();
                }
                node_to_road[node_idx].push_back(&road);
            }
        }
    }
}
RouteModel::Node *RouteModel::Node::FindNeighbor(std::vector<int> node_indices)
{
    Node *closest_node = nullptr;
    //這裡不能單純用 this->SNodes() 因為現在 FindNeighbor() 是定義在在 Node class 理
    //因此 this 指的是Node, 此時this 不是 RouteModel address
    Node node;

    for (int node_idx : node_indices)
    {
        node = parent_model->SNodes()[node_idx];
        if (distance(node) != 0.0 && visited == false)
        {
            if (closest_node == nullptr || distance(node) < distance(*closest_node))
            {
                closest_node = &(parent_model->SNodes()[node_idx]);
            }
        }
    }
    return closest_node;
}

void RouteModel::Node::FindNeighbors()
{
    Node *neighbor;
    for (auto &road : parent_model->node_to_road[this->index])
    {
        neighbor = FindNeighbor(parent_model->Ways()[road->way].nodes);
        if (neighbor != nullptr)
        {
            this->neighbors.push_back(neighbor);
        }
    }
}

RouteModel::Node &RouteModel::FindClosestNode(float x, float y)
{
    Node node;
    node.x = x;
    node.y = y;
    float min_dist = std::numeric_limits<float>::max();
    int closest_idx;
    for (const Model::Road &road : Roads())
    {
        if (road.type != Model::Road::Type::Footway)
        {
            for (int node_idx : Ways()[road.way].nodes)
            {
                float dist = node.distance(SNodes()[node_idx]);
                if (dist < min_dist)
                {
                    min_dist = dist;
                    closest_idx = node_idx;
                }
            }
        }
    }
    return RouteModel::SNodes()[closest_idx];
}
