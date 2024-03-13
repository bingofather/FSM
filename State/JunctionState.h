#ifndef JUNCTIONSTATE_H
#define JUNCTIONSTATE_H

#include "PseudoState.h"

class JunctionState : public PseudoState
{
public:
    JunctionState(string stateName,
          shared_ptr<State> p) : PseudoState(stateName, p) {}
    virtual ~JunctionState() = default;

public:
    bool IsJunction() override { return true; }    
};

#endif