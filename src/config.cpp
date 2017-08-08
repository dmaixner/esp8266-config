#include "config.h"

void Config::write_config_eeprom(config_t &config, int offset)
{
    EEPROM.begin(offset + sizeof(config_t));
    EEPROM.put(offset, config);
    EEPROM.end();
}

void Config::read_config_eeprom(config_t &config, int offset)
{
    EEPROM.begin(offset + sizeof(config_t));
    EEPROM.get(offset, config);
    EEPROM.end();
}

void Config::print_config(String label, config_t &config)
{
    Serial.println(label);
    Serial.printf("- WiFi SSID: %s\n", config.wifi_ssid);
    Serial.printf("- WiFi password: %s\n", config.wifi_pass);
    Serial.printf("- ThingSpeak channel ID: %s\n", config.thingspeak_channel_id);
    Serial.printf("- ThingSpeak write key: %s\n", config.thingspeak_write_key);
    Serial.printf("- Data field: %s\n", config.data_field);
    Serial.printf("- Data type: %d\n", config.data_type);
    Serial.printf("- Data ID: %d\n", config.data_id);
    Serial.println("----------------------");
}

void Config::print_stats()
{
#ifdef WiFi_h
    Serial.printf("RSSI: %d dBm\n", WiFi.RSSI());
#endif
    Serial.printf("Config size: %d\n", sizeof(config_t));
    Serial.printf("Reset reason: %s\n" + ESP.getResetReason());
    Serial.printf("Free heap: %d\n", ESP.getFreeHeap());
    Serial.printf("Chip ID: %d\n", ESP.getChipId());
    Serial.printf("Sketch size: %d\n", ESP.getSketchSize());
    Serial.printf("Free sketch space: %d\n", ESP.getFreeSketchSpace());
    Serial.printf("Flash chip ID: %d\n", ESP.getFlashChipId());
    Serial.printf("Flash chip size: %d\n", ESP.getFlashChipSize());
    Serial.printf("Flash chip real size: %d\n", ESP.getFlashChipRealSize());
}
