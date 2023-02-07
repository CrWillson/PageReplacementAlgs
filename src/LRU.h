#ifndef _LRU_H
#define _LRU_H

//*******************************************************************
// LRU.h
// 
// Original by: Patrick P. Dudenhofer
// Edited by: Caleb Willson
// Date: 10/26/22
//
// Edits: Added private data members
//*******************************************************************

#include <iostream>
#include "ReplacementAlgorithm.h"
#include <vector>

using namespace std;

class LRU : public ReplacementAlgorithm {
public:
    LRU(int numPageFrames);
    void insert(int pageNumber) override;

private:
    vector<int> frameList;
};

#endif