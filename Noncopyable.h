#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

class NonCopyableForAll
{
protected:
    NonCopyableForAll() = default;
    ~NonCopyableForAll() = default;

    NonCopyableForAll(const NonCopyableForAll&) = delete;
    NonCopyableForAll& operator=(const NonCopyableForAll&) = delete;

    NonCopyableForAll(NonCopyableForAll&&) = delete;
    NonCopyableForAll& operator=(NonCopyableForAll&&) = delete;
};

#endif // NONCOPYABLE_H
