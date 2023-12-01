#pragma once
#include <functional>

class Receiver {
public:
    void ExecuteCommand(const std::function<void>& PayLoad) {
        //PayLoad();
    }
};

class Command {
public:
    virtual ~Command() {  }
    virtual void Execute() const = 0;
};

// class MoveCommand : public Command {
// private:
//     std::function<void> _PayLoad;
//     Receiver* receiver_;
//     
// public:
//     MoveCommand(const std::function<void>& PayLoad, Receiver* receiver) : _PayLoad(PayLoad), receiver_(receiver) {}
//     void Execute() const override {
//         receiver_->ExecuteCommand(_PayLoad);
//     }
// };


