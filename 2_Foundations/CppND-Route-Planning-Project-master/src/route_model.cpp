#include "route_model.h"
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

//========================================================
// RouteModel::Node Class

//---------------
// Public methods

//Distance computation from another Node
float RouteModel::Node::distance(const Model::Node &otherNode) const
{
    return std::sqrt(std::pow(this->x - otherNode.x, 2.f) + std::pow(this->y - otherNode.y, 2.f));
}

//Populate the neighbors vector of this node 
//   (closest nodes on all roads this node is on)
//
//Note : original course solution is buggy as it does not consider the "linear/ordered" nature
//       of the Nodes in a way: the only possible neigbors are the one just before and after the
//       current node in the list, distance is not relevant in the selection
void RouteModel::Node::FindNeighbors()
{
    //For each roads going through the node (from reverese map)
    for (const Model::Road *roadPtr : parent_model->GetNodeToRoadMap()[index])
    {
        //Find two connected neigbors to current node
        RouteModel::Node *prevNode = nullptr, *nextNode = nullptr;
        vector<int> nodeList = parent_model->Ways()[roadPtr->way].nodes;
        for (int currIndex = 0; currIndex < nodeList.size(); currIndex++)
        {
            //if current node is the one searched stop the search
            if (nodeList[currIndex] == index)
            {
                //check if there one after non visited and add it
                if (currIndex != nodeList.size() - 1)
                    if (parent_model->SNodes()[nodeList[currIndex + 1]].visited == false)
                        nextNode = &parent_model->SNodes()[nodeList[currIndex + 1]];
                break;
            }
            else
            {
                //keep that as the previous node if it was not visited (or clear it otherwise)
                if (parent_model->SNodes()[nodeList[currIndex]].visited == false)
                    prevNode = &parent_model->SNodes()[nodeList[currIndex]];
                else
                    prevNode = nullptr;
            }            
        } 

        //Add prev/next if available
        if (nextNode != nullptr)
            neighbors.push_back(nextNode);
        if (prevNode != nullptr)
            neighbors.push_back(prevNode);
    }
}

//----------------
// Private methods

//Find closest Node in a list from current
RouteModel::Node* RouteModel::Node::FindNeighbor(vector<int> node_indices)
{
    RouteModel::Node* closestNode = nullptr;
    float minDistance = std::numeric_limits<float>::max(); 

    // Reference list of all the nodes 
    vector<RouteModel::Node> &nodeList = parent_model->SNodes();

    //For each of the nodes in the argument vector, if it was not visited yet
    for (int nodeIdx : node_indices)
    {
        if (nodeList[nodeIdx].visited == false)
        {
            //record closer node and new min distance
            //    (check for non-null distance to avoid itself)
            float currDistance = distance(nodeList[nodeIdx]);
            if (currDistance < minDistance && currDistance != 0)
            {
                minDistance = currDistance;
                closestNode = &nodeList[nodeIdx];
            }
        }
    }

    return closestNode;
}

//========================================================
// RouteModel Class

RouteModel::RouteModel(const std::vector<std::byte> &xml) : Model(xml) 
{
    //Convert all OSM Nodes to RouteModel::Node to be able to perform A*
    //Then store them in RouteModel.m_Nodes
    int index = 0;
    for (Model::Node currNode : this->Nodes())
        this->m_Nodes.push_back(RouteModel::Node(index++, this, currNode));

    //Build the reverse map from NodeIdx to Road*
    CreateNodeToRoadHashmap();
}

//---------------
// Public methods

//Find closest valid node from user input
RouteModel::Node &RouteModel::FindClosestNode(float x, float y)
{
    //Create a temporary Node with user coo
    Model::Node userNode {x, y};

    //Current Node idx & min distance 
    float minDistance = std::numeric_limits<float>::max(); 
    int minNodeIdx = std::numeric_limits<int>::max();

    //Nodes Idx in reverse-map are valid 
    //  (avoids checking multiple times the same node from different streets)
    for(auto ite : node_to_road)
    {
        //When current Node is closer, record it
        float currDistance = SNodes()[ite.first].distance(userNode);
        if (currDistance < minDistance)
        {
            minNodeIdx = ite.first;
            minDistance = currDistance;
        }
    }

    return SNodes()[minNodeIdx];
}

//----------------
// Private methods

//Building of the reverse map
void RouteModel::CreateNodeToRoadHashmap(void)
{
    //For each roads of the model (Note: use reference to store address in map)
    for (const Model::Road &currRoad : Roads())
    {
        //Build reverse map only for non-footway roads
        if (currRoad.type != Model::Road::Type::Footway)
        {
            //Iterate over all nodes of current road's way
            for (int currNodeIdx : Ways()[currRoad.way].nodes)
            {
                //When node index is not yet present in list create an empty vector 
                if (node_to_road.find(currNodeIdx) == node_to_road.end())
                    node_to_road[currNodeIdx] = vector<const Model::Road *> ();

                //Add current Road pointer to node index entry
                node_to_road[currNodeIdx].push_back(&currRoad);
            }
        } 
    }
}
