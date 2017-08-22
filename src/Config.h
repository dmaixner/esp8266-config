#ifndef _config_h
#define _config_h

#include <Arduino.h>

/**
* list of all config options:
*       _config_option_wifi -- wifiSsid, wifiPass
*       _config_option_thingspeak -- thingspeakChannelId, thingspeakWriteKey
*       _config_option_dallas -- dallasPin
*       _config_option_chacha -- chaChaKey, chaChaAuth
*/

typedef struct config_struct
{
#ifdef _config_option_wifi
    char wifiSsid[20];
    char wifiPass[20];
#endif

#ifdef _config_option_thingspeak
    char thingspeakChannelId[10];
    char thingspeakWriteKey[20];
#endif

#ifdef _config_option_dallas
    byte dallasPin;
#endif

#ifdef _config_option_chacha
    byte chaChaKey[32];
    byte chaChaAuth[16];
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
