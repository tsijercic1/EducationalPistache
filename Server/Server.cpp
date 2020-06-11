#include "Server.h"

namespace Generic {
    void handleReady(const Rest::Request&, Http::ResponseWriter response) {
        response.send(Http::Code::Ok, R"({"message":"This is the generic response. Hi!"})");
    }
}

Server::Server(Address address):
        description("Server", "0.1"),
        httpEndpoint(std::make_shared<Http::Endpoint>(address))
    {}

void Server::init(size_t threadNumber = 2) {
    auto opts = Http::Endpoint::options()
            .threads(static_cast<int>(threadNumber));
    httpEndpoint->init(opts);
    createDescription();
}

void Server::start() {
    router.initFromDescription(description);
    httpEndpoint->setHandler(router.handler());
    httpEndpoint->serve();
}

void Server::createDescription() {
    description
            .info()
            .license("Apache", "http://www.apache.org/licenses/LICENSE-2.0");

    auto backendErrorResponse =
            description.response(Http::Code::Internal_Server_Error, "An error occured with the backend");

    description
            .schemes(Rest::Scheme::Http)
            .basePath("/v1")
            .produces(MIME(Application, Json))
            .consumes(MIME(Application, Json));

    description
            .route(description.get("/ready"))
            .bind(&Generic::handleReady)
            .response(Http::Code::Ok, "Response to the /ready call")
            .hide();

    auto versionPath = description.path("/v1");

    auto logsPath = versionPath.path("/logs");

    logsPath
            .route(description.get("/all"))
            .bind(&Server::retrieveAllLogs, this)
            .produces(MIME(Application, Json), MIME(Application, Xml))
            .response(Http::Code::Ok, "The list of all account");

//    logsPath
//            .route(description.get("/:name"), "Retrieve an account")
//            .bind(&Server::retrieveAccount, this)
//            .produces(MIME(Application, Json))
//            .parameter<Rest::Type::String>("name", "The name of the account to retrieve")
//            .response(Http::Code::Ok, "The requested account")
//            .response(backendErrorResponse);
//
//    logsPath
//            .route(description.post("/:name"), "Create an account")
//            .bind(&Server::createAccount, this)
//            .produces(MIME(Application, Json))
//            .consumes(MIME(Application, Json))
//            .parameter<Rest::Type::String>("name", "The name of the account to create")
//            .response(Http::Code::Ok, "The initial state of the account")
//            .response(backendErrorResponse);
//
//    auto accountPath = logsPath.path("/:name");
//    accountPath.parameter<Rest::Type::String>("name", "The name of the account to operate on");
//
//    accountPath
//            .route(description.post("/budget"), "Add budget to the account")
//            .bind(&Server::creditAccount, this)
//            .produces(MIME(Application, Json))
//            .response(Http::Code::Ok, "Budget has been added to the account")
//            .response(backendErrorResponse);

}

void Server::retrieveAllLogs(const Rest::Request &, Http::ResponseWriter response) {
    response.send(Http::Code::Ok, R"({"name":"MyAccount"})");
}

void Server::retrieveAccount(const Rest::Request&, Http::ResponseWriter response) {
    response.send(Http::Code::Ok, "The bank is closed, come back later");
}

void Server::createAccount(const Rest::Request&, Http::ResponseWriter response) {
    response.send(Http::Code::Ok, "The bank is closed, come back later");
}

void Server::creditAccount(const Rest::Request&, Http::ResponseWriter response) {
    response.send(Http::Code::Ok, "The bank is closed, come back later");
}
