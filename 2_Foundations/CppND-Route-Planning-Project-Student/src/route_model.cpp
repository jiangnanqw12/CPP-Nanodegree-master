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