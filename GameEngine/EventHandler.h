#pragma once
#include <queue>
#include "Command.h"

class EventHandler {
    static inline std::queue<std::shared_ptr<Command>> CommandQueue;

public:
    static std::shared_ptr<Command> TryPop() {
        std::shared_ptr<Command> item = CommandQueue.front();
        if (!item->Execute()) CommandQueue.pop();
        return item;
    }

    static void Push(const std::shared_ptr<Command>& command) {
        CommandQueue.push(command);
    }

    bool Empty() const {
        return CommandQueue.empty();
    }
};
