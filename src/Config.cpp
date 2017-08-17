#include "config.h"

void Config::writeConfigEEPROM(config_t &config, int offset)
{
    EEPROM.begin(offset + sizeof(config_t));
    EEPROM.put(offset, config);
    EEPROM.end();
}

void Config::readConfigEEPROM(config_t &config, int offset)
{
    EEPROM.begin(offset + sizeof(config_t));
    EEPROM.get(offset, config);
    EEPROM.end();
}

void Config::printConfig(String label, config_t &config)
{
    Serial.println(label);
#ifdef _config_option_wifi
    Serial.printf("- WiFi SSID: %s\n", config.wifiSsid);
    Serial.printf("- WiFi password: %s\n", config.wifiPass);
#endif
#ifdef _config_option_thingspeak
    Serial.printf("- Thingspeak channel ID: %s\n", config.thingspeakChannelId);
    Serial.printf("- Thingspeak write key: %s\n", config.thingspeakWriteKey);
    Serial.printf("- Thingspeak field: %d\n", config.thingspeakField);
#endif
#ifdef _config_option_sensors
    Serial.printf("- Dallas sensor count: %d\n", config.sensorCount[DALLAS]);
    Serial.printf("- DHT11 sensor count: %d\n", config.sensorCount[DHT11]);
#endif
    Serial.println("----------------------");
}

void Config::printStats()
{
    Serial.printf("Config size: %d\n", sizeof(config_t));
    Serial.println("Reset reason: " + ESP.getResetReason());
    Serial.printf("Free heap: %d\n", ESP.getFreeHeap());
    Serial.printf("Chip ID: %d\n", ESP.getChipId());
    Serial.printf("Sketch size: %d\n", ESP.getSketchSize());
    Serial.printf("Free sketch space: %d\n", ESP.getFreeSketchSpace());
    Serial.printf("Flash chip ID: %d\n", ESP.getFlashChipId());
    Serial.printf("Flash chip size: %d\n", ESP.getFlashChipSize());
    Serial.printf("Flash chip real size: %d\n", ESP.getFlashChipRealSize());
    Serial.println("----------------------");
}
