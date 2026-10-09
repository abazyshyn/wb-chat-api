#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <iostream>

int main()
{
    boost::asio::io_context io;
    std::cout << "Hello world!" << std::endl;

    return 0;
}
