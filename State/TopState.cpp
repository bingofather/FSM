#include "TopState.h"

void TopState::AddKids(shared_ptr<State> kid)
{
    if (kid)
        kids.push_back(kid);
}

void TopState::Feed(const Event& msg)
{
    for (const auto& kid : kids)
    {
        if (!kid.expired())
        {
            if (kid.lock()->IsInitial())
                kid.lock()->Feed(msg);
        }
    }
}