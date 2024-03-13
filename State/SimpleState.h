#ifndef SIMLESTATE_H
#define SIMLESTATE_H

#include "State.h"

class SimpleState : public State
{
public:
    SimpleState(string stateName,
                 shared_ptr<State> p) : State(stateName, p) {}
    
    virtual ~SimpleState() = default;

public:
    bool IsSimple() override { return true; }
};

#endif