#include "WebsocketManager.h"

namespace WebsocketManager {
    unsigned char CERT[] = {
        0x30, 0x82, 0x01, 0xa6, 0x30, 0x82, 0x01, 0x50, 0x02, 0x14, 0x14, 0x37,
        0xbe, 0x6a, 0x33, 0x60, 0x0a, 0x0a, 0xe3, 0x6e, 0x85, 0xa5, 0xcb, 0x70,
        0x20, 0x37, 0x08, 0x0a, 0x80, 0x07, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86,
        0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05, 0x00, 0x30, 0x54, 0x31,
        0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x44, 0x45,
        0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x08, 0x0c, 0x02, 0x42,
        0x45, 0x31, 0x0f, 0x30, 0x0d, 0x06, 0x03, 0x55, 0x04, 0x07, 0x0c, 0x06,
        0x42, 0x65, 0x72, 0x6c, 0x69, 0x6e, 0x31, 0x12, 0x30, 0x10, 0x06, 0x03,
        0x55, 0x04, 0x0a, 0x0c, 0x09, 0x4d, 0x79, 0x43, 0x6f, 0x6d, 0x70, 0x61,
        0x6e, 0x79, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c,
        0x0a, 0x6d, 0x79, 0x63, 0x61, 0x2e, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x30,
        0x1e, 0x17, 0x0d, 0x32, 0x33, 0x31, 0x30, 0x32, 0x36, 0x31, 0x39, 0x30,
        0x36, 0x32, 0x38, 0x5a, 0x17, 0x0d, 0x33, 0x33, 0x31, 0x30, 0x32, 0x33,
        0x31, 0x39, 0x30, 0x36, 0x32, 0x38, 0x5a, 0x30, 0x55, 0x31, 0x0b, 0x30,
        0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x44, 0x45, 0x31, 0x0b,
        0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x08, 0x0c, 0x02, 0x42, 0x45, 0x31,
        0x0f, 0x30, 0x0d, 0x06, 0x03, 0x55, 0x04, 0x07, 0x0c, 0x06, 0x42, 0x65,
        0x72, 0x6c, 0x69, 0x6e, 0x31, 0x12, 0x30, 0x10, 0x06, 0x03, 0x55, 0x04,
        0x0a, 0x0c, 0x09, 0x4d, 0x79, 0x43, 0x6f, 0x6d, 0x70, 0x61, 0x6e, 0x79,
        0x31, 0x14, 0x30, 0x12, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x0b, 0x65,
        0x73, 0x70, 0x33, 0x32, 0x2e, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x30, 0x5c,
        0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01,
        0x01, 0x05, 0x00, 0x03, 0x4b, 0x00, 0x30, 0x48, 0x02, 0x41, 0x00, 0xdd,
        0xc4, 0xed, 0xb9, 0xcc, 0x6c, 0x23, 0x0e, 0xd7, 0xeb, 0x34, 0x0c, 0x98,
        0x04, 0xaa, 0x67, 0x3a, 0x46, 0x25, 0x29, 0x67, 0xa3, 0x71, 0x04, 0xf3,
        0xcb, 0x62, 0x59, 0x01, 0xc0, 0x3b, 0x36, 0x90, 0x76, 0x61, 0x9f, 0x0e,
        0x26, 0xd1, 0x7c, 0xb6, 0xd1, 0xba, 0x2e, 0xdc, 0x1b, 0x77, 0xd0, 0x53,
        0x3d, 0x83, 0xc8, 0xb5, 0x0b, 0x25, 0xba, 0xe0, 0xc6, 0xbb, 0xcc, 0x19,
        0x11, 0xe3, 0xfd, 0x02, 0x03, 0x01, 0x00, 0x01, 0x30, 0x0d, 0x06, 0x09,
        0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05, 0x00, 0x03,
        0x41, 0x00, 0x68, 0x72, 0xe0, 0xca, 0x56, 0x48, 0x5a, 0x11, 0x49, 0x21,
        0x31, 0x5c, 0x7c, 0xe5, 0xc5, 0xe3, 0x7c, 0x04, 0x5b, 0x7f, 0x68, 0xea,
        0xf7, 0xd0, 0xb2, 0xab, 0x56, 0x50, 0xc5, 0x28, 0x43, 0xad, 0xb4, 0x36,
        0x52, 0x88, 0x93, 0x01, 0xe9, 0x47, 0xcb, 0xdc, 0xa0, 0xd6, 0x8f, 0x4f,
        0xd0, 0x11, 0x88, 0xc5, 0xac, 0x9f, 0x26, 0x62, 0x1c, 0x80, 0xcd, 0x86,
        0x80, 0x0b, 0xd8, 0xca, 0x37, 0xb2
    };
    unsigned int CERT_LEN = 426;
    
    unsigned char KEY[] = {
        0x30, 0x82, 0x01, 0x55, 0x02, 0x01, 0x00, 0x30, 0x0d, 0x06, 0x09, 0x2a,
        0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04, 0x82,
        0x01, 0x3f, 0x30, 0x82, 0x01, 0x3b, 0x02, 0x01, 0x00, 0x02, 0x41, 0x00,
        0xdd, 0xc4, 0xed, 0xb9, 0xcc, 0x6c, 0x23, 0x0e, 0xd7, 0xeb, 0x34, 0x0c,
        0x98, 0x04, 0xaa, 0x67, 0x3a, 0x46, 0x25, 0x29, 0x67, 0xa3, 0x71, 0x04,
        0xf3, 0xcb, 0x62, 0x59, 0x01, 0xc0, 0x3b, 0x36, 0x90, 0x76, 0x61, 0x9f,
        0x0e, 0x26, 0xd1, 0x7c, 0xb6, 0xd1, 0xba, 0x2e, 0xdc, 0x1b, 0x77, 0xd0,
        0x53, 0x3d, 0x83, 0xc8, 0xb5, 0x0b, 0x25, 0xba, 0xe0, 0xc6, 0xbb, 0xcc,
        0x19, 0x11, 0xe3, 0xfd, 0x02, 0x03, 0x01, 0x00, 0x01, 0x02, 0x40, 0x74,
        0xee, 0xed, 0x5a, 0x56, 0x8b, 0x7e, 0x40, 0xc9, 0x60, 0xdf, 0x64, 0xf4,
        0x93, 0x21, 0x36, 0xa4, 0xe7, 0x6f, 0x98, 0xd1, 0x68, 0xc0, 0xa3, 0x17,
        0xd9, 0x59, 0xd6, 0x0c, 0xb2, 0x4b, 0x85, 0x92, 0x6e, 0xd7, 0xd0, 0xdb,
        0xca, 0x93, 0x24, 0xf0, 0xae, 0xf6, 0xc0, 0x31, 0x87, 0x4d, 0x17, 0x7c,
        0xd2, 0xf4, 0x2d, 0x1b, 0x41, 0xa3, 0xc8, 0x5c, 0xf1, 0xc0, 0x17, 0x63,
        0x3e, 0xb6, 0x91, 0x02, 0x21, 0x00, 0xf5, 0x28, 0x39, 0x43, 0xde, 0x1b,
        0xa4, 0xa9, 0x1d, 0x13, 0x86, 0x21, 0xf0, 0x2e, 0x3a, 0x6e, 0xf9, 0x72,
        0x77, 0x48, 0x80, 0xd3, 0xc7, 0x17, 0xf7, 0x07, 0xbc, 0x61, 0x46, 0x75,
        0x40, 0x2b, 0x02, 0x21, 0x00, 0xe7, 0x93, 0xe5, 0xaf, 0x1c, 0x85, 0x08,
        0xbc, 0xb2, 0x0a, 0xf5, 0x06, 0xf6, 0x99, 0x2e, 0x55, 0xed, 0x86, 0x87,
        0xa0, 0x2e, 0xa7, 0x91, 0x4b, 0x48, 0x60, 0xe0, 0x1d, 0xc8, 0x1b, 0x30,
        0x77, 0x02, 0x20, 0x6d, 0xfe, 0x2a, 0x13, 0x45, 0x27, 0xe9, 0xec, 0xe6,
        0x5a, 0xc8, 0x27, 0x99, 0xf7, 0x63, 0xc8, 0x3e, 0xab, 0x18, 0xd1, 0xb2,
        0xdb, 0x51, 0xcc, 0x72, 0xcd, 0x49, 0xbb, 0xeb, 0x3c, 0xd8, 0x19, 0x02,
        0x21, 0x00, 0xb4, 0x21, 0x1d, 0x7a, 0x9d, 0x43, 0x79, 0xad, 0x55, 0x0c,
        0x22, 0xd5, 0xdc, 0xc1, 0x00, 0x02, 0xc4, 0xb4, 0x6d, 0x10, 0x92, 0xd9,
        0xb2, 0xb1, 0x8d, 0x46, 0x15, 0x6d, 0xf4, 0xf5, 0xf9, 0x37, 0x02, 0x21,
        0x00, 0xbf, 0x88, 0xf2, 0x21, 0x58, 0xe5, 0x3f, 0x53, 0x16, 0xb3, 0x5d,
        0x29, 0xf7, 0x17, 0x65, 0xcb, 0x23, 0xcc, 0x58, 0xa9, 0x24, 0x49, 0x4c,
        0x2b, 0xc8, 0x8e, 0x2a, 0x7f, 0x8c, 0x94, 0x6b, 0x8b
    };
    unsigned int KEY_LEN = 345;
    
    void (*msgReceivedCallback)(String);

    SSLCert cert = SSLCert(
        CERT, CERT_LEN,
        KEY, KEY_LEN
    );
    HTTPSServer secureServer = HTTPSServer(&cert, 443, MAX_CLIENTS);

    // Simple array to store the active clients:
    MessageHandler* activeClients[MAX_CLIENTS];

    void setup(void (*msgReceivedCallback)(String)) {
        WebsocketManager::msgReceivedCallback = msgReceivedCallback;

        // Initialize the slots
        for(int i = 0; i < MAX_CLIENTS; i++) activeClients[i] = nullptr;

        // For every resource available on the server, we need to create a ResourceNode
        // The ResourceNode links URL and HTTP method to a handler function
        ResourceNode * nodeRoot    = new ResourceNode("/", "GET", &handleRoot);
        ResourceNode * node404     = new ResourceNode("", "GET", &handle404);

        // Add the root node to the server
        secureServer.registerNode(nodeRoot);

        // The websocket handler can be linked to the server by using a WebsocketNode:
        // (Note that the standard defines GET as the only allowed method here,
        // so you do not need to pass it explicitly)
        WebsocketNode * messageNode = new WebsocketNode("/", &MessageHandler::create);

        // Adding the node to the server works in the same way as for all other nodes
        secureServer.registerNode(messageNode);

        // Finally, add the 404 not found node to the server.
        // The path is ignored for the default node.
        secureServer.setDefaultNode(node404);

        Serial.println("Starting server...");
        secureServer.start();
        if (secureServer.isRunning()) {
            Serial.print("Server ready. URL: wss://");
            Serial.println(WiFi.localIP());
        }
    }

    void loop() {
        // This call will let the server do its work
        secureServer.loop();
    }

    void handle404(HTTPRequest * req, HTTPResponse * res) {
        // Discard request body, if we received any
        // We do this, as this is the default node and may also server POST/PUT requests
        req->discardRequestBody();

        // Set the response status
        res->setStatusCode(404);
        res->setStatusText("Not Found");
        res->setHeader("Content-Type", "text/plain");
        res->println("Nothing here");
    }

    // In the create function of the handler, we create a new Handler and keep track
    // of it using the activeClients array
    WebsocketHandler * MessageHandler::create() {
        Serial.println("Creating new client!");
        MessageHandler * handler = new MessageHandler();
        for(int i = 0; i < MAX_CLIENTS; i++) {
            if (activeClients[i] == nullptr) {
                activeClients[i] = handler;
                break;
            }
        }
        return handler;
    }

    // When the websocket is closing, we remove the client from the array
    void MessageHandler::onClose() {
        for(int i = 0; i < MAX_CLIENTS; i++) {
            if (activeClients[i] == this) {
            activeClients[i] = nullptr;
            }
        }
    }

    // Finally, passing messages around. If we receive something, we send it to all
    // other clients
    void MessageHandler::onMessage(WebsocketInputStreambuf * inbuf) {
        // Get the input message
        std::ostringstream ss;
        std::string msg;
        ss << inbuf;
        msg = ss.str();
        msgReceivedCallback(msg.c_str());
    }

    // The following HTML code will present the chat interface.
    void handleRoot(HTTPRequest * req, HTTPResponse * res) {
        res->setHeader("Content-Type", "text/plain");
        res->print("SSL cert accepted. You can now close this tab.");
    }

    void sendMessage(String msg) {
        for(int i = 0; i < MAX_CLIENTS; i++) {
            if (activeClients[i] != nullptr) {
                activeClients[i]->send(msg.c_str(), WebsocketHandler::SEND_TYPE_TEXT);
                break;
            }
        }
    }
}