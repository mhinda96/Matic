
#ifndef _XMLRPCSERVER_H_
#define _XMLRPCSERVER_H_
//
// XmlRpc++ Copyright (c) 2002-2003 by Chris Morley
//

/* changed by eQ-3 Entwicklung GmbH 2006 */

#if defined(_MSC_VER)
# pragma warning(disable:4786)    // identifier was truncated in debug info
#endif

#ifndef MAKEDEPEND
# include <map>
# include <string>
#endif

#include "dllexport.h"
#include "XmlRpcDispatch.h"
#include "XmlRpcSource.h"

#include <asm/bitsperlong.h>

namespace XmlRpc {


  // An abstract class supporting XML RPC methods
  class XmlRpcServerMethod;

  // Class representing connections to specific clients
  class XmlRpcServerConnection;

  // Class representing argument and result values
  class XmlRpcValue;


  //! A class to handle XML RPC requests
  class XMLRPC_DLLEXPORT XmlRpcServer : public XmlRpcSource {
  public:
    //! Create a server object.
    XmlRpcServer();
    //! Destructor.
    virtual ~XmlRpcServer();

    //! Specify whether introspection is enabled or not. Default is not enabled.
    void enableIntrospection(bool enabled=true);

    //! Add a command to the RPC server
    void addMethod(XmlRpcServerMethod* method);

    //! Remove a command from the RPC server
    void removeMethod(XmlRpcServerMethod* method);

    //! Remove a command from the RPC server by name
    void removeMethod(const std::string& methodName);

    //! Look up a method by name
    XmlRpcServerMethod* findMethod(const std::string& name) const;

    //! Create a socket, bind to the specified port, and
    //! set it in listen mode to make it available for clients.
    bool bindAndListen(const char* ip, int port, int backlog = 5);
		
    //! Create a socket, bind to the specified port, and
    //! set it in listen mode to make it available for clients.
    bool bindAndListen(int port, int backlog = 5);

    //! Process client requests for the specified time
    #if __BITS_PER_LONG == 32
    void work(long msTime);
    #else
    void work(int32_t msTime);
    #endif

    //! Temporarily stop processing client requests and exit the work() method.
    void exit();

    //! Close all connections with clients and the socket file descriptor
    void shutdown();

    //! Introspection support
    void listMethods(XmlRpcValue& result);

    // XmlRpcSource interface implementation

    //! Handle client connection requests
    virtual unsigned handleEvent(unsigned eventType);

    //! Remove a connection from the dispatcher
    virtual void removeConnection(XmlRpcServerConnection*);

	//! Return a pointer to the dispatcher
	XmlRpcDispatch* getDispatcher();

    //! Return the port the server listens on. -1 for error
    int getListenPort();

  protected:

    //! Accept a client connection request
    virtual void acceptConnection();

    //! Create a new connection object for processing requests from a specific client.
    virtual XmlRpcServerConnection* createConnection(int socket);

    // Whether the introspection API is supported by this server
    bool _introspectionEnabled;

    // Event dispatcher
    XmlRpcDispatch _disp;

    // Collection of methods. This could be a set keyed on method name if we wanted...
    typedef std::map< std::string, XmlRpcServerMethod* > MethodMap;
    MethodMap _methods;

    // system methods
    XmlRpcServerMethod* _listMethods;
    XmlRpcServerMethod* _methodHelp;

  };
} // namespace XmlRpc

#endif //_XMLRPCSERVER_H_
