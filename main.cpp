#include <iostream>
#include "Server/Server.h"

int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;
    Port port(9080);

    int threadNumber = 2;

    if (argc >= 2) {
        port = static_cast<uint16_t>(std::stol(argv[1]));

        if (argc == 3)
            threadNumber = std::stoi(argv[2]);
    }

    Address address(Ipv4::any(), port);

    cout << "Cores = " << hardware_concurrency() << endl;
    cout << "Using " << threadNumber << " threads" << endl;

    Server server(address);

    server.init(threadNumber);
    server.start();
    return 0;
}
