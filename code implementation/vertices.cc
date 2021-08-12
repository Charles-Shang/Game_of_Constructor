#include "vertices.h"
#include <iostream>

Vertices::Vertices(int _location, bool _canBuildResidence, int _whichBuilder)
    : location{_location},
      canBuildResidence{_canBuildResidence},
      whichBuilder{_whichBuilder} {}

void Vertices::addResidence(int builder) {
    if (!canBuildResidence) {
        canBuildResidence = false;
    } else {
        std::cout << "cannot build residence at this location" << std::endl;
        return;
    }
    whichBuilder = builder;
}

void Vertices::addEdgeNeighbour(const std::shared_ptr<Edge> &edge) {
    connectedEdges.emplace_back(edge);
}

int Vertices::getLocation() { return location; }

void Vertices::displayNeighbourEdges() {
    std::cout << "Vertice: |" << location << "|" << std::endl;
    std::cout << "Connected edges are: " << std::endl;
    for (size_t i = 0; i < connectedEdges.size(); i++) {
        std::cout << connectedEdges[i]->getLocation() << " ";
    }

    std::cout << std::endl;
}

bool Vertices::getCanBuildResidence() {
    return canBuildResidence;
}