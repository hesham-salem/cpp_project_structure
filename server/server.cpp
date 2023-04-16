#include <cstdlib>
#include <iostream>
#include <boost/bind/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <fmt/core.h>
#include "calculator.h"

calculator<float> _calculator;

using boost::asio::ip::tcp;

const int max_length = 1024;
using namespace boost::asio;

struct calculation
{
    float firstNo;
    float secondNo;
    char operator_;
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar &firstNo;
        ar &secondNo;
        ar &operator_;
    }
};
struct sum
{
    float value;

    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar &value;
    }
};
void deSerialize(std::istream &serialized_data, calculation &_calculation)
{
    boost::archive::text_iarchive ia(serialized_data);
    ia >> _calculation;
}
std::string serialize(const sum &_sum)
{
    std::ostringstream oss;
    boost::archive::text_oarchive oa(oss);
    oa << _sum;
    return oss.str();
}
int main()
{

    boost::asio::io_context io_context;
    /*     boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::make_address("localhost"), 1234);
     */
    boost::asio::ip::tcp::resolver resolver(io_context);

    // Resolve the hostname to an endpoint
    auto endpoints = resolver.resolve("calculator_server", "1234");

    // Bind the acceptor to the first endpoint in the list
    boost::asio::ip::tcp::endpoint endpoint = *endpoints.begin();
    tcp::acceptor _acceptor(io_context, endpoint);
    // aceptor constructor equal this
    /* tcp::acceptor _acceptor(io_context);
    _acceptor.open(endpoint.protocol());
    _acceptor.bind(endpoint);
    _acceptor.listen(); */
    for (;;)
    {
        tcp::socket socket(io_context);
        _acceptor.accept(socket);
        std::cout << "connected" << std::endl;
        char data[max_length];

        socket.read_some(boost::asio::buffer(data));
        std::istringstream serialized_data = static_cast<std::istringstream>(data);

        // Deserialize the data
        calculation _calculation;
        deSerialize(serialized_data, _calculation);
        switch (_calculation.operator_)
        {
        case '+':
            _calculator.add(_calculation.firstNo, _calculation.secondNo);
            break;
        case '*':
            _calculator.product(_calculation.firstNo, _calculation.secondNo);
            break;
                }

        sum _sum = {_calculator.get_result()};

        socket.write_some(boost::asio::buffer(serialize(_sum)));
    }
}
