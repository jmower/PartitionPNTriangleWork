//
//  main.cpp
//  PartitionPNTriangleWork
//
//  Created by Jim Mower on 7/12/16.
//  Copyright © 2016 Jim Mower. All rights reserved.
//

#include <iostream>
#include <glm/glm.hpp>

int main(int argc, const char * argv[]) {

    glm::uvec2 agDim(8,16); // Patch dimensions (cols, rows) for some arbgrid
    uint totalPatches = agDim.x * agDim.y;
    const uint PHYSICALPROCESSORS = 2034; // Total number of processors for NVIDIA GTX 780 GPU
    uint tessVertsPerPatch = 36; // This will be a variable in real application
    uint totalVerticesInAg = totalPatches * tessVertsPerPatch;
    uint maxConcurrentPatches = PHYSICALPROCESSORS / tessVertsPerPatch;
    uint fullConcurrentPasses = totalPatches / maxConcurrentPatches;
    uint leftoverPatches = totalPatches % maxConcurrentPatches;
   
    std::cout << "For a patch grid with " << agDim.x << " cols and " << agDim.y << " rows, " << std::endl;
    std::cout << "containing " << tessVertsPerPatch << " vertices per patch " << std::endl;
    std::cout << "for a total of " << totalVerticesInAg << " vertices overall, " << std::endl;
    std::cout << "you can process " << maxConcurrentPatches << " patches concurrently, " << std::endl;
    //std::cout << "with " << leftoverPatches << " patches leftover " << std::endl;
    std::cout << "covering " << totalPatches << " total patches on " << fullConcurrentPasses <<
        " full passes with " << std::endl;
    std::cout << "a final partial pass containing " << leftoverPatches << " leftovers." << std::endl;
    return 0;
}
