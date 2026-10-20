#include "server.h"
#include <iostream>

namespace HTTP
{
    namespace Server
    {

        CServer::CServer(const std::string &address, const std::string &port)
            : m_ioContext(1),
              m_acceptor(m_ioContext)
        {
            Init(address, port);
        }

        void CServer::Run()
        {
            boost::asio::ip::tcp::socket socket(m_ioContext);
            m_acceptor.accept(socket);

            boost::beast::flat_buffer buffer;
            boost::beast::http::request<boost::beast::http::string_body> request;
            boost::system::error_code errorCode;
            boost::beast::http::read(socket, buffer, request, errorCode);

            if (errorCode)
            {
                std::cerr << "Failed to read HTTP request: "
                          << errorCode.message() << '\n';
                return;
            }

            std::cout << "Method: " << request.method_string() << std::endl;
            std::cout << "Target: " << request.target() << std::endl;
            std::cout << "Version: " << request.version() << std::endl;

            for (const auto &header : request.base())
            {
                std::cout << header.name_string() << ": " << header.value() << '\n';
            }
            std::cout << std::flush;
        }

        void CServer::Init(const std::string &address, const std::string &port)
        {
            boost::asio::ip::tcp::resolver resolver(m_ioContext);
            boost::asio::ip::tcp::endpoint endpoit = *resolver.resolve(address, port).begin();
            m_acceptor.open(endpoit.protocol());
            m_acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
            m_acceptor.bind(endpoit);
            m_acceptor.listen();
        }

    } // namespace Server
} // namespace HTTP