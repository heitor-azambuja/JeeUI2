#ifndef JeeUI2_h
#define JeeUI2_h

#include "Arduino.h"

#ifdef ESP8266
#include <ESPAsyncTCP.h>
#include <FS.h>
#else
#include <AsyncTCP.h>
#include "SPIFFS.h"
#endif

#include <ESPAsyncWebServer.h>
#include "ArduinoJson.h"

#define BUTTON 0

class jeeui2
{
    typedef void (*buttonCallback) ();
    typedef void (*uiCallback) ();
    typedef void (*updateCallback) ();
    typedef void (*mqttCallback) ();

  public:
    void var(String key, String value);
    String param(String key);
    void led(uint8_t pin, bool invert);
    void deb();
    void ap(unsigned long interval);
    void begin();
    void begin(bool debug);
    void handle();
    void btnCallback(String name ,buttonCallback response);

    void app(String name);
    void menu(String name);
    void page();

    void text(String id, String label);
    void password(String id, String label);
    void number(String id, String label);
    void time(String id, String label);
    void date(String id, String label);
    void datetime(String id, String label);
    void email(String id, String label);
    void range(String id, int min, int max, float step, String label);
    void select(String id, String label);
    void option(String value, String label);
    void checkbox(String id, String label);
    void color(String id, String label);
    void button(String id, String color, String label);
    void button(String id, String color, String label, int column);
    void textarea(String id, String label);
    void save();
    void udp(String message);
    void udp();
    void pubMQTT(String id);
    void pub(String id, String label);
    void pub(String id, String label, String unit);
    void pub(String id, String label, String unit, String bg_color);
    void pub(String id, String label, String unit, String bg_color, String text_color);
    void pub_mqtt(String key, String value);

    void formWifi();
    void formMqtt();

    uiCallback foo;
    void ui(void (*uiFunction) ());

    void mqtt(String pref, String host, int port, String user, String pass, void (*mqttFunction) (String topic, String payload), bool remotecontrol);
    void mqtt(String pref, String host, int port, String user, String pass, void (*mqttFunction) (String topic, String payload));
    void mqtt(String host, int port, String user, String pass, void (*mqttFunction) (String topic, String payload));
    void mqtt(String host, int port, String user, String pass, void (*mqttFunction) (String topic, String payload), bool remotecontrol);
    void mqtt(String host, int port, String user, String pass, bool remotecontrol);
    void mqtt(String pref, String host, int port, String user, String pass, bool remotecontrol);

    mqttCallback onConnect;

    void mqtt(String pref, String host, int port, String user, String pass, void (*mqttFunction) (String topic, String payload), void (*mqttConnect) (), bool remotecontrol);
    void mqtt(String pref, String host, int port, String user, String pass, void (*mqttFunction) (String topic, String payload), void (*mqttConnect) ());
    void mqtt(String host, int port, String user, String pass, void (*mqttFunction) (String topic, String payload), void (*mqttConnect) ());
    void mqtt(String host, int port, String user, String pass, void (*mqttFunction) (String topic, String payload), void (*mqttConnect) (), bool remotecontrol);

    void subscribe(String topic);
    void publish(String topic, String payload);
    void publish(String topic, String payload, bool retained);

    void remControl();

    updateCallback upd;
    void update(void (*updateFunction) ());

    String ip;
    String buf;
    String mc;
    String mac;
    bool connected = false;
    

    String id(String tpoic);
    String m_pref;
    String config = "{}";

  private:
    void arr(String key, String value);
    void wifi_connect();
    void button_handle();
    void led_handle();
    void nonWifiVar();
    void led_on();
    void led_off();
    void led_inv();
    void load();
    void autosave();
    void as();
    void prntmac();
    void udpBegin();
    void udpLoop();
    void btn();
    void getAPmac();

    void mqtt_update();
    void mqtt_handle();
    void mqtt_send();
    void mqtt_reconnect();
    bool mqtt_ok = false;
    bool mqtt_enable = false;

    void subscribeAll();
   
    String m_host;
    int m_port;
    String m_user;
    String m_pass;
    bool m_params;

    int sendConfig = 0;

    bool pub_enable;
    int pub_num = 0;
    String pub_id[512];

    String udpRemoteIP;
    unsigned int localUdpPort = 4243;
    char incomingPacket[64];

    unsigned int asave = 1000;
    bool sv = false;
    unsigned long astimer;

    
    String op = "";
    uint8_t wifi_mode;
    int LED_PIN = -1;
    bool LED_INVERT = false;
    uint8_t mn = 0;
    unsigned long a_ap = 0;
    bool wf = false;
    uint8_t pg = 0;
    String btnui = "";
    String udpMessage;
    
    bool dbg = false;
    
};

#endif