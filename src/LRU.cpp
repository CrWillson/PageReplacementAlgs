//*******************************************************************
// LRU.cpp
// 
// Original by: Patrick P. Dudenhofer
// Edited by: Caleb Willson
// Date: 10/26/22
//
// Edits: Added LRU algorithm implementation
//*******************************************************************

#include "LRU.h"

LRU::LRU(int numPageFrames) : ReplacementAlgorithm(numPageFrames) {
    pageFaultCount = 0;
}

void LRU::insert(int pageNumber)
{
    // check if the page is already loaded
    for (int i = 0; i < frameList.size(); i++) {
        if (frameList.at(i) == pageNumber) { 
            frameList.erase(frameList.begin() + i);
            frameList.insert(frameList.begin(), pageNumber);
            return;
        }
    }

    // remove the last page in the list
    if (frameList.size() >= pageFrameCount) {
        frameList.pop_back();
    }
    // load the new page
    frameList.insert(frameList.begin(), pageNumber);
    pageFaultCount++;
}

