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
}
float RouteModel::Node::distance(Node node) const
{
    return std::sqrt(std::pow((node.x - x), 2) + std::pow((node.y - y), 2));
}

void RouteModel::CreateNodeToRoadHashmap()
{
    for (const Model::Road &road : this->Roads())
    {
        if (road.type != Modle::Road::Type::Footway)
        {
        }
    }
}