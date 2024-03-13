#ifndef EVENT_H
#define EVENT_H

#include <algorithm>

using std::copy;


#define GENEVENTID(event) event,

typedef enum EventId
{
    #include "EventId.h"
    INVALID,
} EventId;

struct Event
{
    EventId id;
    uint8_t para[512];
    Event& operator=(const Event& ev)
    {
        id = ev.id;
        copy(ev.para, ev.para + sizeof(para), para);
        return *this;
    }
};

#endif // EVENT_H
