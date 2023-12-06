#pragma once
#include <queue>
#include "Command.h"


class EventHandler {
public:
    static inline std::queue<std::shared_ptr<Command>> CommandQueue;
    EventHandler() {  }
    static void Enqueue(std::shared_ptr<Command> Command) {
        CommandQueue.push(Command);
    }

    static void Dequeue(const bool override = false) {
        // how is this called?
        if (!override) {
            while (CommandQueue.back()->Execute()) {
                return;
            }
            CommandQueue.pop();
        }
        else {
            CommandQueue.back()->Execute();
            CommandQueue.pop();
        }
    }
};
