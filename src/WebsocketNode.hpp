#ifndef SRC_WEBSOCKETNODE_HPP_
#define SRC_WEBSOCKETNODE_HPP_

#include <string>

#include "HTTPNode.hpp"
#include "WebsocketHandler.hpp"

namespace httpsserver {

typedef WebsocketHandler* (WebsocketHandlerCreator)(const void* arg);

class WebsocketNode : public HTTPNode {
public:
  WebsocketNode(const std::string &path, const WebsocketHandlerCreator creatorFunction, void* creatorFunctionArg, const std::string &tag = "");
  virtual ~WebsocketNode();
  WebsocketHandler* newHandler();
  std::string getMethod() { return std::string("GET"); }
private:
  const WebsocketHandlerCreator * _creatorFunction;
  const void* _creatorFunctionArg;
};

} /* namespace httpsserver */

#endif /* SRC_WEBSOCKET_HPP_ */
