#ifndef COMPOSITESTATE_H
#define COMPOSITESTATE_H

#include <memory>
#include <vector>

#include "State.h"
#include "Event.h"

using std::shared_ptr;
using std::vector;

class CompositeState : public State
{
public:
    CompositeState(string stateName,
          shared_ptr<State> p) : State(stateName, p) {}
    virtual ~CompositeState() = default;

public:
    bool IsComposite() override { return true; }
    void AddKid(shared_ptr<State> kid);
    void OnEnter() override;
    void OnExit() override;
    virtual bool LookUpCompleteTransition();

private:
    vector<weak_ptr<State> > kids;
}; 

#endif
