//*******************************************************************
// Original by: Patrick P. Dudenhofer
// Edited by: Caleb Willson
// Date: 10/26/22
//
// Edits: Added Optimal algorithm
//        Reworked to only take one command line argument, <file name>,
//           and automatically test multiple number of page frames
//*******************************************************************

// testPR.cpp
// Patrick P. Dudenhofer
// CS3310 - Operating System
// Page Replacement
// 2015 October 12
//
// Testing program for the page replacement algorithms.
//

#include <cstdlib>
#include <time.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#include "ReplacementAlgorithm.h"
#include "LRU.h"
#include "FIFO.h"
#include "OPT.h"

std::vector<int> referenceString;

const int MAX_PAGE_NUMBER = 100;

// testPR <reference string size> <number of page frames> [fileName]
// The "reference string size" parameter is ignored if a filename is provided.
int main(int argc, char **argv)
{
    int minPageFrames = 1;
    int maxPageFrames = 5;

    bool useRefFile = false;
    std::string fileName = "";
    std::ifstream in;

    srand((unsigned int)time(0));

    if (argc != 2){
        std::cerr << "Usage: " << argv[0]
                  << " <reference string filename>"
                  << std::endl;
        exit(1);
    }

    fileName = "../resources/" + fileName;

    //open the input file
    in.open(argv[1]);
    if (!in.is_open()){
        std::cerr << "Error opening file " << fileName
                    << ". Exiting..." << std::endl;
        exit(1);
    }

    int n;
    while (!in.eof())
    {
        in >> n;
        if (n >= 0 && n < MAX_PAGE_NUMBER){
            referenceString.push_back(n);
        }
    }
    in.close();


    for (int i = minPageFrames; i <= maxPageFrames; i++) {
        ReplacementAlgorithm* lru = new LRU(i);
        ReplacementAlgorithm* fifo = new FIFO(i);
        // new optimal replacement alg
        ReplacementAlgorithm* opt = new OPT(i, referenceString);

        for (int j : referenceString) {
            lru->insert(j);
            fifo->insert(j);
            opt->insert(j);
        }

        std::cout << i << " Page Frames:" << std::endl;
        std::cout << "LRU faults  = " << lru->getPageFaultCount() << std::endl;
        std::cout << "FIFO faults = " << fifo->getPageFaultCount() << std::endl;
        std::cout << "OPT faults = " << opt->getPageFaultCount() << "\n" << std::endl;
    }
    return 0;
}