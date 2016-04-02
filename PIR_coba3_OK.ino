#define pir 4
#define led 13
#define relay1 6
#define relay2 7

int kondisi_pir_terakhir = 0;
int kondisi_pir_sekarang = 0;
int status_output = 0;

int status_led = LOW;
int status_relay1 = HIGH;
int status_relay2 = HIGH;

void setup() {
  //Serial.begin(9600);
  pinMode(pir, INPUT)  ;
  pinMode(led, OUTPUT)  ;
  pinMode(relay1, OUTPUT)  ;
  pinMode(relay2, OUTPUT)  ;

  digitalWrite (relay1, HIGH);
  digitalWrite (relay2, HIGH);


}

void loop() {
  int baca_pir = digitalRead(pir);

  if (baca_pir != kondisi_pir_terakhir) {
    status_output = 1;
    //Serial.println("on");
  }

  if (status_output  == 1) {
    if (baca_pir != kondisi_pir_sekarang) {
      kondisi_pir_sekarang = baca_pir;

      if (kondisi_pir_sekarang == HIGH) {
        status_led = !status_led;
        status_relay1 = !status_relay1;
        status_relay2 = !status_relay2;
      }
    }
    digitalWrite(led, status_led);
    digitalWrite(relay1, status_relay1);
    digitalWrite(relay2, status_relay2);
  }
}
