#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using boost::asio::ip::tcp;
using namespace boost::asio;
enum
{
    max_length = 1024
};

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
//////////////////////////////////////////////
std::string serialize(const calculation &_calculation)
{
    std::ostringstream oss;
    boost::archive::text_oarchive oa(oss);
    oa << _calculation;
    return oss.str();
}
void deSerialize(std::istream &serialized_data, sum &_sum)
{
    boost::archive::text_iarchive ia(serialized_data);
    ia >> _sum;
}

int main(int argc, char *argv[])
{
    while (true)
    {

        float first_no, second_no;
        char operator_;
        std::cout << "enter first no" << std::endl;
        std::cin >> first_no;
        std::cout << "enter second no" << std::endl;
        std::cin >> second_no;
        std::cout << "enter the operator" << std::endl;
        std::cin >> operator_;

        calculation _calculation{first_no, second_no, operator_};

        // Serialize the struct to a string
        std::string serialized_data = serialize(_calculation);
        std::cout << serialized_data << std::endl;
        // io_context interface to plateform to make it abstracted
        boost::asio::io_context io_context;
        /*     boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::make_address("localhost"), 1234);
         */
        boost::asio::ip::tcp::resolver resolver(io_context);

        // Resolve the hostname to an endpoint
        auto endpoint = resolver.resolve("calculator_server", "1234");

        tcp::socket socket(io_context);
        connect(socket, endpoint); // blocked until connect to the server

        // socket.write_some(boost::asio::buffer("serialized_data")); // will return after 1 or bytes are successfly written vs write as it will bluck until all finish

        socket.write_some(boost::asio::buffer(serialized_data)); // will return after 1 or bytes are successfly written vs write as it will bluck until all finish
        char reply[max_length];

        socket.read_some(boost::asio::buffer(reply));
        std::istringstream serialized_sum = static_cast<std::istringstream>(reply);
        sum _sum;
        deSerialize(serialized_sum, _sum);

        std::cout
            << "result is: " << _sum.value << std::endl;
    }
}
