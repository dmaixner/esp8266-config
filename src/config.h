#ifndef _Config_h
#define _Config_h

#include <Arduino.h>
#include <EEPROM.h>

typedef enum datatype_enum : byte {
    TEMPERATURE
} datatype_t;

typedef struct config_struct
{
    char wifiSsid[20];
    char wifiPass[20];
    char thingspeakChannelId[10];
    char thingspeakWriteKey[20];
    char dataField[10];
    datatype_t dataType;
    byte dataId;
} config_t;

class Config
{
  public:
    static void writeConfigEEPROM(config_t &config, int offset);
    static void readConfigEEPROM(config_t &config, int offset);
    static void printConfig(String label, config_t &config);
    static void printStats();
};

#endif