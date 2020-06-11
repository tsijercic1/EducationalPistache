#pragma once

#include <string>

class Log {
    std::string name;
    std::string message;
public:
    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getMessage() const;

    void setMessage(const std::string &message);

    Log(std::string name, std::string message);
};
