#ifndef _config_h
#define _config_h

#include <Arduino.h>

/**
* list of all config options:
*       _config_option_wifi -- wifiSsid, wifiPass
*       _config_option_dallas -- dallasCounter, dallasPin
*       _config_option_dallas && _config_option_thingspeak -- thingspeakWriteKey
*       _config_option_dallas && _config_option_post -- roomId
*       _config_option_chacha -- chaChaKey, chaChaAuth
*       _config_option_relay -- relayPin, relayId
*/

typedef struct config_struct
{
#ifdef _config_option_wifi
    char wifiSsid[20];
    char wifiPass[20];
#endif

#ifdef _config_option_dallas
    byte dallasCounter = _config_option_dallas;
    byte dallasPin;
#ifdef _config_option_thingspeak
    char thingspeakWriteKey[_config_option_dallas][20];
#endif
#ifdef _config_option_post
    byte roomId[_config_option_dallas];
#endif
#endif

#ifdef _config_option_chacha
    byte chaChaKey[32];
    byte chaChaAuth[16];
#endif

#ifdef _config_option_relay
    byte relayPin;
    byte relayId;
#endif

} config_t;

class Config
{
  public:
    static void writeConfigEEPROM(config_t &config, int offset);
    static void readConfigEEPROM(config_t &config, int offset);
    static void printConfig(String label, config_t &config);
    static void printStats();
};

#endif // _config_h
