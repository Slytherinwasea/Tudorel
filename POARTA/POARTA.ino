#define STEP1 8
#define STEP2 9
#define STEP3 10
#define STEP4 11
int STATE_POARTA = 1;
char GATE_STATE_OPEN='2';
char valor ;
int b ;
int rotation = 1150;
void setpoarta(){
  if (STATE_POARTA == 1) {
      Serial.println("TEST");
      switch (GATE_STATE_OPEN) {

        case '1':
        Serial.println("OPEN");
        
          // inchidere
          b = 0;
          while (b < rotation) {
            digitalWrite(STEP1, HIGH);
            digitalWrite(STEP2, LOW);
            digitalWrite(STEP3, LOW);
            digitalWrite(STEP4, LOW);
            delay(2);

            digitalWrite(STEP1, LOW);
            digitalWrite(STEP2, HIGH);
            digitalWrite(STEP3, LOW);
            digitalWrite(STEP4, LOW);
            delay(2);

            digitalWrite(STEP1, LOW);
            digitalWrite(STEP2, LOW);
            digitalWrite(STEP3, HIGH);
            digitalWrite(STEP4, LOW);
            delay(2);

            digitalWrite(STEP1, LOW);
            digitalWrite(STEP2, LOW);
            digitalWrite(STEP3, LOW);
            digitalWrite(STEP4, HIGH);
            delay(2);
            b++;
          }
          break;

        case '2':
        //deschidere
          b = 0;
          while (b < rotation) {
            Serial.println("OPEN");
            digitalWrite(STEP1, LOW);
            digitalWrite(STEP2, LOW);
            digitalWrite(STEP3, LOW);
            digitalWrite(STEP4, HIGH);
            delay(2);

            digitalWrite(STEP1, LOW);
            digitalWrite(STEP2, LOW);
            digitalWrite(STEP3, HIGH);
            digitalWrite(STEP4, LOW);
            delay(2);

            digitalWrite(STEP1, LOW);
            digitalWrite(STEP2, HIGH);
            digitalWrite(STEP3, LOW);
            digitalWrite(STEP4, LOW);
            delay(2);

            digitalWrite(STEP1, HIGH);
            digitalWrite(STEP2, LOW);
            digitalWrite(STEP3, LOW);
            digitalWrite(STEP4, LOW);
            delay(2);
            b++;
          }
          break;
      }
  }
}
    void setup() {
      // put your setup code here, to run once:
      pinMode(STEP1, OUTPUT);
      pinMode(STEP2, OUTPUT);
      pinMode(STEP3, OUTPUT);
      pinMode(STEP4, OUTPUT);
      Serial.begin(9600);
    }

    void loop(){
      setpoarta();
    }
