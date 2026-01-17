*Bu proje, 42 müfredatının bir parçası olarak **bsevigen** tarafından oluşturulmuştur.*

# Minitalk

##  Açıklama (Description)

Minitalk, **UNIX sinyallerini kullanarak** (SIGUSR1 ve SIGUSR2) bir sunucu ve istemci arasında veri iletimi gerçekleştiren küçük bir iletişim programıdır.
Amaç, düşük seviyeli proses haberleşmesini anlamak ve ASCII karakterlerin sinyaller aracılığıyla nasıl kodlanıp gönderilebileceğini uygulamaktır.

Proje iki ana programdan oluşur:

* **server**: İstemciden gelen sinyalleri alır, çözümleyerek ekrana yazdırır.
* **client**: Göndermek istenen metni bit karşılığına çevirerek sunucuya sinyaller ile iletir.

---

##  Kurulum ve Çalıştırma Talimatları (Instructions)

### 1. Derleme

Aşağıdaki komut ile proje derlenebilir:

```bash
make
```

### 2. Sunucuyu Başlatma

```bash
./server
```

Komut çalıştıktan sonra PID numarası görüntülenecektir.
Bu PID, client tarafında kullanılacaktır.

### 3. Mesaj Gönderme

```bash
./client <server_pid> "Gönderilecek mesaj"
```

Örnek:

```bash
./client 12345 "Merhaba!"
```

---

##  Kullanım Örneği (Usage Examples)

Sunucuyu başlat:

```bash
./server
```

Yeni bir terminal aç ve mesaj gönder:

```bash
./client 4218 "Hello 42!"
```

Sunucu çıktısı:

```
Hello 42!
```

---

## Kaynaklar ve Kullanılan AI (Resources)

### **Kaynaklar**

Aşağıdaki dökümanlar proje geliştirilirken rehber olarak kullanılmıştır:

* UNIX Sinyalleri: [https://man7.org/linux/man-pages/man7/signal.7.html](https://man7.org/linux/man-pages/man7/signal.7.html)
* `kill()` fonksiyonu: [https://man7.org/linux/man-pages/man2/kill.2.html](https://man7.org/linux/man-pages/man2/kill.2.html)
* `sigaction()` fonksiyonu: [https://man7.org/linux/man-pages/man2/sigaction.2.html](https://man7.org/linux/man-pages/man2/sigaction.2.html)
* `pause()` fonksiyonu: [https://man7.org/linux/man-pages/man2/pause.2.html](https://man7.org/linux/man-pages/man2/pause.2.html)
* Bit işlemleri ve ASCII temelleri ile ilgili çeşitli kaynaklar

---

### Yapay Zeka Kullanımı (AI Usage)

Bu projeyi geliştirirken yapay zeka aşağıdaki alanlarda **yardımcı araç** olarak kullanılmıştır:

* README dosyası formatı ve metin düzenlemeleri
* Hata mesajlarının yorumlanması ve teorik açıklamalar
* Norm gereksinimleri ile ilgili rehberlik
* Sinyal mekanizmasının teorik tarafının detaylandırılması
* Bit manipülasyonu tekniklerinin anlaşılması

---
