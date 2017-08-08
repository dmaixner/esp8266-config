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
    Serial.printf("- WiFi SSID: %s\n", config.wifiSsid);
    Serial.printf("- WiFi password: %s\n", config.wifiPass);
    Serial.printf("- Thingspeak channel ID: %s\n", config.thingspeakChannelId);
    Serial.printf("- Thingspeak write key: %s\n", config.thingspeakWriteKey);
    Serial.printf("- Data field: %s\n", config.dataField);
    Serial.printf("- Data type: %d\n", config.dataType);
    Serial.printf("- Data ID: %d\n", config.dataId);
    Serial.println("----------------------");
}

void Config::printStats()
{
#ifdef WiFi_h
    Serial.printf("RSSI: %d dBm\n", WiFi.RSSI());
#endif
    Serial.printf("Config size: %d\n", sizeof(config_t));
    Serial.println("Reset reason: " + ESP.getResetReason());
    Serial.printf("Free heap: %d\n", ESP.getFreeHeap());
    Serial.printf("Chip ID: %d\n", ESP.getChipId());
    Serial.printf("Sketch size: %d\n", ESP.getSketchSize());
    Serial.printf("Free sketch space: %d\n", ESP.getFreeSketchSpace());
    Serial.printf("Flash chip ID: %d\n", ESP.getFlashChipId());
    Serial.printf("Flash chip size: %d\n", ESP.getFlashChipSize());
    Serial.printf("Flash chip real size: %d\n", ESP.getFlashChipRealSize());
}
