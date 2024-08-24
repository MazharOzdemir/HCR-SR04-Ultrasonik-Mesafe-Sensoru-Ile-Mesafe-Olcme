int trigPin = 9;
int echoPin = 10;

// Cihazımızda bulunan Trig Pinini 9. çıkışa, Echo Pinini ise 10. çıkışa bağlıyoruz. Ve değer atamalarını yapıyoruz.
// VCC Pinini 5V çıkışına, GND pinin ise Gnd çıkışına bağlıyoruz,


void setup() {

 //Seri haberleşmeyi başlatıyoruz ve Trig pinine çıkış, Echo pinine ise giriş veriyoruz.

 Serial.begin(9600);
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 }
  


void loop() {
  
   digitalWrite(trigPin,LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin,HIGH);
   delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  //Trig pinin çalışmasını başlatarak ölçüme yapmaya başlıyoruz.

  int sure = pulseIn(echoPin,HIGH);
  int uzaklik = (sure/2)/29.154;

  //Echo pinine gelen sinyalin süresini hesaplayıp ikiye böldüğümüzde cisim ile aramızdaki mesafenin süresini bulmuş oluyoruz.
  //Uzaklığı bulmak için süre / 1 cm yol almak için geçen süre formulümüzü kullanıyoruz.
  //Daha sonrasında ise bu bilgileri ekrana yazdırıyoruz.

  Serial.print("Mesafe: ");
  Serial.println(uzaklik);

  delay(200);


  }
