#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/asio.hpp>

#include "httplib.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;
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
  std::string operator_;
  template<class Archive>
  void serialize(Archive& ar, const unsigned int version)
  {
    ar& firstNo;
    ar& secondNo;
    ar& operator_;
  }
};
struct sum
{
  float value;

  template<class Archive>
  void serialize(Archive& ar, const unsigned int version)
  {
    ar& value;
  }
};
//////////////////////////////////////////////
std::string serialize(const calculation& _calculation)
{
  std::ostringstream oss;
  boost::archive::text_oarchive oa(oss);
  oa << _calculation;
  return oss.str();
}
void deSerialize(std::istream& serialized_data, sum& _sum)
{
  boost::archive::text_iarchive ia(serialized_data);
  ia >> _sum;
}

int main(int argc, char* argv[])
{
  httplib::Server server;

  server.set_base_dir("./public");
  server.Get("/",
             [](const httplib::Request& /*req*/, httplib::Response& res)
             {
               // Read the index.html file and send it as the response
               std::ifstream file("./public/index.html");
               if (file.is_open()) {
                 std::stringstream buffer;
                 buffer << file.rdbuf();
                 res.set_content(buffer.str(), "text/html");
               } else {
                 res.status = 404;  // Not Found
               }
             });

  server.Post("/calculate",
              [&](const httplib::Request& req, httplib::Response& res)
              {
                // Parse JSON payload
                json request = json::parse(req.body);
                std::cout << "req.body" << req.body << std::endl;

                // Extract operation and operands from JSON
                std::string operation = request["operation"];
                double operand1 = request["operand1"];
                double operand2 = request["operand2"];

                calculation _calculation {operand1, operand2, operation};

                // Serialize the struct to a string
                std::string serialized_data = serialize(_calculation);

                boost::asio::io_context io_context;

                boost::asio::ip::tcp::resolver resolver(io_context);

                // Resolve the hostname to an endpoint
                auto endpoint = resolver.resolve("localhost", "1234");

                tcp::socket socket(io_context);

                connect(socket,
                        endpoint);  // blocked until connect to the server

                socket.write_some(boost::asio::buffer(
                    serialized_data));  // will return after 1 or bytes are
                                        // successfly written vs write as it
                                        // will bluck until all finish

                char reply[max_length];

                socket.read_some(boost::asio::buffer(reply));
                std::istringstream serialized_sum =
                    static_cast<std::istringstream>(reply);
                sum _sum;
                deSerialize(serialized_sum, _sum);

                // Prepare JSON response
                json response;
                response["result"] = _sum.value;
                std::cout << " response[ result ] : " << response["result"]
                          << std::endl;
                // Set response content type to JSON
                res.set_content(response.dump(), "application/json");
              });

  server.listen("localhost", 8080);
}
