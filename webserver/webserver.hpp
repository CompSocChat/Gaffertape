#pragma once

#include <boost/asio.hpp>
#include <string>

#include "../common.hpp"

namespace webserver {
  class InvalidRequest : public std::exception {};

  class HeaderField {
  public:
    std::string name;
    std::string value;
  };

  class Header {
  public:
    std::string version = "HTTP/1.1";
    virtual std::string build() const = 0;
    std::vector<HeaderField> headers;
  };

  class RequestHeader : public Header {
  public:
    std::string verb;
    std::string path;
    std::string build() const;
  };

  enum ResponseCode {
    // 1xx: Informational
    Continue = 100,
    // 2xx: Success
    Ok = 200,
    // 4xx: Error
    Bad_Request = 400,
    Not_Found = 404
  };

  std::ostream & operator<<(std::ostream & s, ResponseCode rc);

  class ResponseHeader : public Header {
  public:
    ResponseCode code;
    std::string build() const;
  };

  class Server;

  class Response {
  private:
  public:
    ResponseHeader header;
    std::string body;
    std::string build() const;
  };

  class Request {
    friend Server;
  private:
    boost::asio::ip::tcp::socket * socket;
  public:
    RequestHeader header;
    std::string build() const;
    void respond(const Response * response);
  };


  class Server {
  private:
    boost::asio::ip::tcp::acceptor * socket;
    boost::asio::io_service * service;
  public:
    Request * receive();
    USER_ID name;
    Server(USER_ID * name, boost::asio::ip::tcp::endpoint ep);
  };


}
