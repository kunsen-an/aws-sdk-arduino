#ifndef AWSESP32MPLEMENTATIONS_H_
#define AWSESP32IMPLEMENTATIONS_H_
#ifdef ESP32
#include "DeviceIndependentInterfaces.h"
/* application.h is Esp32's standard library. Define TCPClient. */
//#include <ESP8266WiFi.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>

/* HttpClient implementation to be used on the Esp32 Core device. */
class Esp32HttpClient: public IHttpClient {
    WiFiClientSecure sclient;
    //TCPClient client;
public:
    Esp32HttpClient();
    /* Send http request and return the response. */
    char* send(const char *request, const char* serverUrl, int port);
    /* Returns false. Client uses raw http/https. */
    bool usesCurl(void);
};

class Esp32DateTimeProvider: public IDateTimeProvider {
    /* The time as a cstring in yyyyMMddHHmmss format. Is written to within and
     * returned by getDateTime(). */
    WiFiClient client;
    //char dateTime[15];
public:
    char dateTime[15];
    Esp32DateTimeProvider();
    /* Retrieve the current GMT date and time in yyyyMMddHHmmss format. */
    const char* getDateTime(void);
    /* Returns false because Esp32 has it's own mechanism for syncing that does
     * not require an argument. */
    bool syncTakesArg(void);
    /* Synchronizes Esp32's date and time with Esp32's servers. The dateTime
     * argument is ignored. */
    void sync(const char* dateTime);
};

#endif /* ESP32 */
#endif /* AWSESP32IMPLEMENTATIONS_H_ */
