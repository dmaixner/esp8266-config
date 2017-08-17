#ifndef _config_h
#define _config_h

#include <Arduino.h>

/**
* list of all config options:
*       _config_option_wifi -- wifiSsid, wifiPass
*       _config_option_thingspeak -- thingspeakChannelId, thingspeakWriteKey, thingspeakField
*       _config_option_sensors -- sensorCount
*/

#ifdef _config_option_sensors
#define SENSOR_TYPE_COUNT 2
typedef enum sensor_type_enum : byte {
    DALLAS,
    DHT11
} sensor_type_t;
#endif

typedef struct config_struct
{
#ifdef _config_option_wifi
    char wifiSsid[20];
    char wifiPass[20];
#endif

#ifdef _config_option_thingspeak
    char thingspeakChannelId[10];
    char thingspeakWriteKey[20];
    byte thingspeakField;
#endif

#ifdef _config_option_sensors
    byte sensorCount[SENSOR_TYPE_COUNT];
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
