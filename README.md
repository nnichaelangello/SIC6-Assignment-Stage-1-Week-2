# Integrasi ESP32 dengan MQTT Broker Menggunakan WokWi Simulator

Proyek ini merupakan simulasi integrasi antara mikrokontroler ESP32 dengan MQTT Broker menggunakan platform **WokWi**. Proyek ini juga merupakan bagian dari **Tugas Assignment Stage 1 Week 2** dalam program **Samsung Innovation Campus (SIC) Batch 6**.

## Daftar Isi
- [Gambaran Proyek](#gambaran-proyek)
- [Fitur](#fitur)
- [Perangkat Keras Yang Digunakan](#persyaratan-perangkat-keras)
- [Simulasi di WokWi](#simulasi-di-wokwi)
- [Langkah-Langkah Integrasi WokWi dengan MQTT Client dan Broker](#langkah-langkah-integrasi-wokwi-dengan-mqtt-client-dan-broker)
- [Hasil](#hasil)
- [Kontribusi](#kontribusi)

## Gambaran Proyek
Proyek ini adalah bagian dari **Tugas Assignment Stage 1 Week 2** dalam program **Samsung Innovation Campus (SIC) Batch 6**. Tujuan dari tugas ini adalah untuk mensimulasikan integrasi antara ESP32 dengan MQTT Broker menggunakan platform **WokWi**. ESP32 mempublikasikan data suhu dan kelembaban, juga mengontrol LED melalui MQTT.

Tugas ini berfokus pada:
- Memahami protokol MQTT dan implementasinya dalam sistem IoT.
- Mensimulasikan perangkat IoT menggunakan platform WokWi.
- Mengembangkan keterampilan dalam memprogram mikrokontroler ESP32 dan mengintegrasikan sensor.

## Fitur
- **Mempublikasikan Data Sensor**: ESP32 mempublikasikan data suhu dan kelembaban ke topik MQTT `/UNI282/Michael_Angello_Qadosy_Riyadi/data_sensor`.
- **Mengontrol LED**: ESP32 melakukan subscribe ke topik MQTT `/UNI282/Michael_Angello_Qadosy_Riyadi/aktuasi_led` untuk menerima perintah menyalakan atau mematikan LED.
- **Simulasi di WokWi**: Seluruh sistem disimulasikan menggunakan platform WokWi.

## Perangkat Keras Yang Digunakan
- Mikrokontroler ESP32
- Sensor suhu dan kelembaban DHT22
- LED
- Resistor 220 ohm
- kabel penghubung

## Simulasi di WokWi
Simulasi dilakukan sepenuhnya di platform **WokWi**. Berikut adalah langkah-langkah untuk menjalankan proyek ini:

1. **Buka Proyek WokWi**:
   - Akses proyek WokWi saya di:  
     [https://wokwi.com/projects/420397682118927361](https://wokwi.com/projects/420397682118927361).
     ![Cuplikan layar 2025-01-18 132804](https://github.com/user-attachments/assets/5487a229-823b-4e25-a169-8328e7767908)

2. **Jalankan Simulasi**:
   - Klik tombol **"Start"** (ikon segitiga) di WokWi untuk memulai simulasi.
3. **Periksa Serial Monitor**:
   - Buka **Serial Monitor** di WokWi untuk melihat log dari ESP32, seperti status koneksi WiFi, MQTT, dan data sensor yang dipublikasikan.
4. **Kontrol LED**:
   - Gunakan klien MQTT (disini saya menggunakan, HiveMQ WebSocket Client) untuk mempublikasikan pesan `ON` atau `OFF` ke topik `/UNI282/Michael_Angello_Qadosy_Riyadi/aktuasi_led`.

## Langkah-Langkah Integrasi WokWi dengan MQTT Client dan Broker
1. **Buka HiveMQ WebSocket Client**:
   - Kunjungi [HiveMQ WebSocket Client](http://www.hivemq.com/demos/websocket-client/).
   - Klik "Connect" untuk terhubung ke broker HiveMQ.
2. **Berlangganan ke Topik**:
   - Di bagian "Subscriptions", klik "Add New Topic Subscription".
   - Masukkan topik `/UNI282/Michael_Angello_Qadosy_Riyadi/data_sensor` dan klik "Subscribe".
3. **Publikasikan Pesan untuk Mengontrol LED**:
   - Di bagian "Publish", masukkan topik `/UNI282/Michael_Angello_Qadosy_Riyadi/aktuasi_led`.
   - Masukkan pesan `ON` atau `OFF` dan klik "Publish".
4. **Periksa Hasil**:
   - Data sensor akan muncul di bagian "Messages" di HiveMQ WebSocket Client.
   - LED di WokWi akan menyala atau mati sesuai dengan pesan yang dipublikasikan.
     
## Hasil
- ESP32 berhasil mempublikasikan data suhu dan kelembaban ke topik MQTT.
  ![Cuplikan layar 2025-01-18 134259](https://github.com/user-attachments/assets/d954e01c-a45a-461b-a1ff-132c7b89b569)

- LED dapat dikontrol melalui pesan MQTT, menyala atau mati sesuai perintah.
  
  `ON`
  ![Cuplikan layar 2025-01-18 134144](https://github.com/user-attachments/assets/0e1ea853-d744-45b3-8dcc-4a502fb05c6d)

  `OFF`
  ![Cuplikan layar 2025-01-18 134204](https://github.com/user-attachments/assets/c9c11893-160f-44b7-8d4e-6788319e66ca)

## Kontribusi
Kontribusi sangat diterima! Silakan fork repositori ini dan buat pull request dengan perubahan Anda.
