#include "route_model.h"
#include <iostream>

RouteModel::RouteModel(const std::vector<std::byte> &xml) : Model(xml)
{
    int count = 0;
    for (auto i : this->Nodes())
    {
        Node n1(count, this, i);
        count++;
        this->m_Nodes.emplace_back(n1);
    }
    CreateNodeToRoadHashmap();
}
float RouteModel::Node::distance(Node node) const
{
    return std::sqrt(std::pow((node.x - x), 2) + std::pow((node.y - y), 2));
}

void RouteModel::CreateNodeToRoadHashmap()
{
    for (const Model::Road &road : Roads())
    {
        if (road.type != Model::Road::Type::Footway)
        {
            for (int nodeIDX : Ways()[road.way].nodes)
            {
                if (this->node_to_road.find(nodeIDX) == this->node_to_road.end())
                {
                    this->node_to_road[nodeIDX] = std::vector<const Model::Road *>{};
                }
                this->node_to_road[nodeIDX].push_back(&road);
            }
        }
    }
}
RouteModel::Node *RouteModel::Node::FindNeighbor(std::vector<int> node_indices)
{
    Node *closet_node = nullptr;
    //這裡不能單純用 this->SNodes() 因為現在 FindNeighbor() 是定義在在 Node class 理
    //因此 this 指的是Node, 此時this 不是 RouteModel address
    Node node;

    for (int node_indix : node_indices)
    {
        node = parent_model->SNodes()[node_indix];
        if (distance(node) != 0.0 && visited == false)
        {
            if (closet_node == nullptr || distance(node) < distance(*closet_node))
            {
                closet_node = &(parent_model->SNodes()[node_indix]);
            }
        }
    }
    return closet_node;
}

void RouteModel::Node::FindNeighbor()
{
    
}