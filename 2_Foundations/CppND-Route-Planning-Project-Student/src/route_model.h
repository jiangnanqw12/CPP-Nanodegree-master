#pragma once
/*
route_model.h and route_model.cpp
These files contain class stubs which will be used to extend the Model and Node data structures
from model.h and model.cpp using "class inheritance".

Remember that inheritance in this case will you
to use all of the PUBLIC methods and attributes of the Model and Node classes in the derived classes.
You will be filling out the classes in route_model.h and route_model.cpp over the course of your project.

*/
#include <limits>
#include <cmath>
#include <unordered_map>
#include "model.h"
#include <iostream>
#include <vector>

class RouteModel : public Model
{

public:
  class Node : public Model::Node
  {
  public:
    // Add public Node variables and methods here.

    Node() {}
    Node(int idx, RouteModel *search_model, Model::Node node) : Model::Node(node), parent_model(search_model), index(idx) {}
    Node *parent = nullptr;
    float h_value = std::numeric_limits<float>::max();
    float g_value = 0.0;
    bool visited = false;
    std::vector<Node *> neighbors;
    float distance(Node node) const;
    RouteModel::Node *FindNeighbor(std::vector<int> node_indices);

  private:
    // Add private Node variables and methods here.
    int index;
    RouteModel *parent_model = nullptr;
  };

  // Add public RouteModel variables and methods here.
  RouteModel(const std::vector<std::byte> &xml);
  std::vector<Node> path; // This variable will eventually store the path that is found by the A* search.
  std::vector<Node> &SNodes()
  {
    return m_Nodes;
  }
  std::unordered_map<int, std::vector<const Model::Road *>> &GetNodeToRoadMap()
  {
    return node_to_road;
  }

private:
  // Add private RouteModel variables and methods here.
  std::vector<Node> m_Nodes;
  std::unordered_map<int, std::vector<const Model::Road *>> node_to_road;
  void CreateNodeToRoadHashmap();
};
