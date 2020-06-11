//
// Created by tsijercic1 on 6/2/20.
//

#include "Log.h"

#include <utility>

Log::Log(std::string name, std::string message) : name(std::move(name)), message(std::move(message)) {}

const std::string &Log::getName() const {
    return name;
}

void Log::setName(const std::string &name) {
    Log::name = name;
}

const std::string &Log::getMessage() const {
    return message;
}

void Log::setMessage(const std::string &message) {
    Log::message = message;
}
