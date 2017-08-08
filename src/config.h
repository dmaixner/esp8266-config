#ifndef _Config_h
#define _Config_h

#include <EEPROM.h>

typedef enum datatype_t : byte {
    TEMPERATURE
};

typedef struct
{
    char wifi_ssid[20];
    char wifi_pass[20];
    char thingspeak_channel_id[10];
    char thingspeak_write_key[20];
    char data_field[10];
    datatype data_type;
    byte data_id;
} config_t;

class Config
{
  public:
    static void write_config_eeprom(config_t &config, int offset);
    static void read_config_eeprom(config_t &config, int offset);
    static void print_config(String label, config_t &config);
    static void print_stats();
}

#endif