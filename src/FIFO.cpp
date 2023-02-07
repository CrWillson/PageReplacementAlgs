//*******************************************************************
// FIFO.cpp
// 
// Original by: Patrick P. Dudenhofer
// Edited by: Caleb Willson
// Date: 10/26/22
//
// Edits: Added FIFO algorithm implementation
//*******************************************************************

#include "FIFO.h"

FIFO::FIFO(int numPageFrames) : ReplacementAlgorithm(numPageFrames) {
    pageFaultCount = 0;
}

void FIFO::insert(int pageNumber)
{
    // check if the page is already loaded
    for (int i = 0; i < frameList.size(); i++) {
        if (frameList.at(i) == pageNumber) { return; }
    }

    // remove the last page in the list
    if (frameList.size() >= pageFrameCount) {
        frameList.pop_back();
    }
    // load the new page
    frameList.insert(frameList.begin(), pageNumber);
    pageFaultCount++;

}

