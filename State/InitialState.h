#ifndef INITIALSTATE_H
#define INITIALSTATE_H

#include <memory>
#include <vector>

#include "PseudoState.h"
#include "Event.h"

using std::shared_ptr;
using std::vector;

class InitialState : public PseudoState
{
public:
    InitialState(string stateName,
          shared_ptr<State> p) : PseudoState(stateName, p) {}
    virtual ~InitialState() = default;

public:
    bool IsInitial() override { return true; }
}; 

#endif