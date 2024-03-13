#include "HistoryState.h"

#include "Transition.h"

void HistoryState::UpdateRecord(shared_ptr<State> s)
{
    if (s)
        record = s;
}

weak_ptr<State> HistoryState::ReportRecord()
{
    if (record.expired())
    {
        for (const auto& iter : transitions)
            return iter->ReportDest();
        
        return record;
    }
    else
        return record;
}






