#ifndef FINALSTATE_H
#define FINALSTATE_H

#include "State.h"

#include <string>

class FinalState : public State
{
public:
    FinalState(string stateName,
                 shared_ptr<State> p) : State(stateName, p) {}

    virtual ~FinalState() = default;

public:
    bool IsFinal() override { return true; }
    void OnEnter() override;

private:
    string LookUpCompleteTransition();
    void MakeCompleteTransition();
};

#endif // FINALSTATE_H
