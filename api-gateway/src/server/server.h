#pragma once

#include <boost/asio.hpp>

namespace HTTP
{
    namespace Server
    {

        class CServer
        {
        public:
            explicit CServer(const std::string &address, const std::string &port);

            void Run();

        private:
            void Init(const std::string &address, const std::string &port);

        private:
            boost::asio::io_context m_ioContext;
            boost::asio::ip::tcp::acceptor m_acceptor;
        };

    } // namespace Server
} // namespace HTTP