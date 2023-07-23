#include <cmath>
#include <iostream>

#include "httplib.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

double add(double a, double b)
{
  return a + b;
}

double subtract(double a, double b)
{
  return a - b;
}

double multiply(double a, double b)
{
  return a * b;
}

double divide(double a, double b)
{
  if ((int)b != 0) {
    return a / b;
  } else {
    throw std::runtime_error("Division by zero!");
  }
}

int main()
{
  httplib::Server server;
  // server.set_base_dir("./public");  // Set the base directory to serve static
  // files, e.g., HTML, JS, CSS

  server.set_base_dir("./public");  // Set the base directory to serve static
                                    // files, e.g., HTML, JS, CSS

  // Define a route to serve index.html at the root URL ("/")
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
                std::cout << "hello " << std::endl;
                // Parse JSON payload
                json request = json::parse(req.body);
                std::cout << "req.body" << req.body << std::endl;

                // Extract operation and operands from JSON
                std::string operation = request["operation"];

                double operand1 = request["operand1"];
                double operand2 = request["operand2"];
                //////////////////////////////////////////////////////////////////
                // Perform the requested operation
                double result;

                if (operation == "add") {
                  result = add(operand1, operand2);
                } else if (operation == "subtract") {
                  result = subtract(operand1, operand2);
                } else if (operation == "multiply") {
                  result = multiply(operand1, operand2);
                } else if (operation == "divide") {
                  result = divide(operand1, operand2);
                } else {
                  throw std::runtime_error("Invalid operation!");
                }

                // Prepare JSON response
                json response;
                response["result"] = result;

                // Set response content type to JSON
                res.set_content(response.dump(), "application/json");
              });

  server.listen("localhost", 8080);

  return 0;
}
