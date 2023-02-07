#ifndef _FIFO_H
#define _FIFO_H

//*******************************************************************
// FIFO.h
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

class FIFO : public ReplacementAlgorithm {
public:
    FIFO(int numPageFrames);
    void insert(int pageNumber) override;

private:
    vector<int> frameList;
};

#endif