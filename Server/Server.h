#pragma once
#include <pistache/http.h>
#include <pistache/description.h>
#include <pistache/endpoint.h>

//#include <pistache/serializer/rapidjson.h>

using namespace std;
using namespace Pistache;

class Server {
    std::shared_ptr<Http::Endpoint> httpEndpoint;
    Rest::Description description;
    Rest::Router router;

public:
    explicit Server(Address address);

    void init(size_t threadNumber);
    void start();
private:
    void createDescription();

    void retrieveAllLogs(const Rest::Request &, Http::ResponseWriter response);

    void retrieveAccount(const Rest::Request &, Http::ResponseWriter response);

    void createAccount(const Rest::Request &, Http::ResponseWriter response);

    void creditAccount(const Rest::Request &, Http::ResponseWriter response);
};
