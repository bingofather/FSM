#ifndef PSEUDOSTATE_H
#define PSEUDOSTATE_H

#include "State.h"

class PseudoState : public State
{
public:
    PseudoState(string stateName,
                 shared_ptr<State> p) : State(stateName, p) {}

    virtual ~PseudoState() = default;

public:
    bool IsPseudo() { return true; }
    void OnEnter() override;
};

#endif // PSEUDOSTATE_H
