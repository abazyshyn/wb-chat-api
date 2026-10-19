#include "server.h"

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
            const std::string response =
                "HTTP/1.1 200 OK\r\n"
                "Content-Length: 5\r\n"
                "Connection: close\r\n"
                "\r\n"
                "Hello";
            boost::asio::write(socket, boost::asio::buffer(response));
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