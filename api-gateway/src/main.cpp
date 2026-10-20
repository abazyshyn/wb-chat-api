#include "server/server.h"

int main()
{
    HTTP::Server::CServer Server("127.0.0.1", "8080");
    Server.Run();

    return EXIT_SUCCESS;
}
