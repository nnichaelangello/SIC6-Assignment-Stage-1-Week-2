#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#define LED_PIN 15
#define DHT_PIN 2

const char* MQTT_CLIENT_ID = "demoErick";
const char* MQTT_BROKER = "broker.hivemq.com";
const char* MQTT_USER = "";
const char* MQTT_PASSWORD = "";
const char* MQTT_PUBLISH_TOPIC = "/UNI282/Michael_Angello_Qadosy_Riyadi/data_sensor";
const char* MQTT_SUBSCRIBE_TOPIC = "/UNI282/Michael_Angello_Qadosy_Riyadi/aktuasi_led";

DHT dht(DHT_PIN, DHT22);
WiFiClient espClient;
PubSubClient client(espClient);

void connectWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin("Wokwi-GUEST", "");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Connected!");
}

void connectMQTT() {
  Serial.print("Connecting to MQTT server... ");
  while (!client.connected()) {
    if (client.connect(MQTT_CLIENT_ID, MQTT_USER, MQTT_PASSWORD)) {
      Serial.println("Connected!");
      client.subscribe(MQTT_SUBSCRIBE_TOPIC);
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Retrying in 5 seconds...");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Received message on topic ");
  Serial.print(topic);
  Serial.print(": ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  if (strcmp(topic, MQTT_SUBSCRIBE_TOPIC) == 0) {
    if ((char)payload[0] == 'O' && (char)payload[1] == 'N') {
      digitalWrite(LED_PIN, HIGH); 
      Serial.println("LED turned ON");
    } else if ((char)payload[0] == 'O' && (char)payload[1] == 'F' && (char)payload[2] == 'F') {
      digitalWrite(LED_PIN, LOW); 
      Serial.println("LED turned OFF");
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  dht.begin();

  connectWiFi();

  client.setServer(MQTT_BROKER, 1883);
  client.setCallback(callback);

  connectMQTT();
}

void loop() {
  if (!client.connected()) {
    connectMQTT();
  }
  client.loop();

  static unsigned long lastPublish = 0;
  if (millis() - lastPublish >= 5000) {  
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (!isnan(temperature) && !isnan(humidity)) {
      char message[50];
      snprintf(message, sizeof(message), "{\"temperature\":%.2f,\"humidity\":%.2f}", temperature, humidity);
      Serial.print("Publishing message: ");
      Serial.println(message);
      client.publish(MQTT_PUBLISH_TOPIC, message);
    } else {
      Serial.println("Failed to read from DHT sensor!");
    }

    lastPublish = millis();
  }
}