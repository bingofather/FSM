#ifndef TOPSTATE_H
#define TOPSTATE_H

#include <vector>
#include <memory>

#include "State.h"

using std::vector;
using std::weak_ptr;

class TopState : public State
{
public:
    TopState(string stateName,
               shared_ptr<State> p) : State(stateName, p) {}

    virtual ~TopState() = default;

public:
    bool IsTop() override { return true; }
    void Feed(const Event& msg) override;
    void AddKids(shared_ptr<State> kid);

private:
    vector<weak_ptr<State> > kids;
};

#endif // TOPSTATE_H
