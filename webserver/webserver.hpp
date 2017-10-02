#pragma once

#include <string>
#include <functional>

#include <boost/asio.hpp>

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

  enum StatusCode {
    // 1xx: Informational
    Continue = 100,
    // 2xx: Success
    Ok = 200,
    // 4xx: Error
    Bad_Request = 400,
    Not_Found = 404,
    // 5xx: Server Error
    Internal_Server_Error = 500
  };

  std::ostream & operator<<(std::ostream & s, StatusCode rc);

  class ResponseHeader : public Header {
  public:
    StatusCode code;
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
    void respond(const Response& response);
    ~Request();
  };


  class Server {
  private:
    boost::asio::ip::tcp::acceptor * socket;
    boost::asio::io_service * service;
  public:
    USER_ID name;

    Request * receive();
    Server(USER_ID * name, boost::asio::ip::tcp::endpoint ep);
    ~Server();
  };

  class RequestHandler {
  public:
    // Should return false when request could not be handled
    // (i.e. a GET handler on a POST request)
    // NOTE: Should send an error to the client for a bad request
    virtual bool handle(Request& request) = 0;
  };

  class FileRequestHandler : RequestHandler {
  protected:
    // The path to the root directory of the webserver
    bool resolve(std::string& path);
    FileRequestHandler(std::string root) : root(root) {};
  public:
    std::string root;
  };

  class FileGetRequestHandler : FileRequestHandler {
  public:
    bool handle(Request& request);
    FileGetRequestHandler(std::string root) : FileRequestHandler(root) {};
  };

  typedef std::function<std::map<std::string, std::string>(std::string)> post_handler;
  class FilePostRequestHandler : FileRequestHandler {
  public:
    bool handle(Request& request);
    FilePostRequestHandler(std::string root) : FileRequestHandler(root) {};
  };

}
