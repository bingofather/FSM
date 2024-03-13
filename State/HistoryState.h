#ifndef HISTORYSTATE_H
#define HISTORYSTATE_H

#include <memory>

#include "PseudoState.h"

using std::weak_ptr;

class HistoryState : public PseudoState
{
public:
    HistoryState(string stateName,
                 shared_ptr<State> p) : PseudoState(stateName, p) {}
    
    virtual ~HistoryState() = default;

public:
    bool IsHistory() override { return true; }
    void Feed(const Event& /*unused*/) override {}
    void UpdateRecord(shared_ptr<State> s);
    weak_ptr<State> ReportRecord();

private:
    weak_ptr<State> record;
};

#endif // HISTORYSTATE_H
