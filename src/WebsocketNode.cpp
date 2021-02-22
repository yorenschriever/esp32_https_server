#include "WebsocketNode.hpp"

namespace httpsserver {

WebsocketNode::WebsocketNode(const std::string &path, const WebsocketHandlerCreator * creatorFunction, void* creatorFunctionArg, const std::string &tag):
  HTTPNode(path, WEBSOCKET, tag),
  _creatorFunction(creatorFunction),
  _creatorFunctionArg(creatorFunctionArg) {

}

WebsocketNode::~WebsocketNode() {

}

WebsocketHandler* WebsocketNode::newHandler() {
  WebsocketHandler * handler = _creatorFunction(_creatorFunctionArg);
  return handler;
}

} /* namespace httpsserver */
