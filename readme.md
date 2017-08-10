# NodeMCU ESP8266 Configuration library
Configuration library used to read/write struct objects from/to EEPROM.

# Usage

This library provides data type `config_t`, which is generated according to dynamic build flags (use -D during compilation). Here are available options (see header file for details):

-D option name|generated fields in `config_t` type
--------------|-----------------------------------
_config_option_wifi|`char wifiSsid[20]`, `char wifiPass[20]`
_config_option_thingspeak|`char thingspeakChannelId[10]`, `char thingspeakWriteKey[20]`, `byte thingspeakField`
_config_option_sensors|`byte sensorCount[SENSOR_TYPE_COUNT]`

Library also provides static methods in `Config` class for read/write those data from/to EEPROM and print information to Serial:
```C
    static void writeConfigEEPROM(config_t &config, int offset);
    static void readConfigEEPROM(config_t &config, int offset);
    static void printConfig(String label, config_t &config);
    static void printStats();
```