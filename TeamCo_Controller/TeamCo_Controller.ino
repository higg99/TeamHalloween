#define DB_PIN  19

#include <DMXSerial2.h>
bool DB_state=false;


void trigger(int pin){
  digitalWrite(pin, HIGH);
  delay(100);
  digitalWrite(pin,LOW);
}

void atrigger(int* pin,int len){
  for(int p=0; p< len; p++){
    digitalWrite(pin[p], HIGH);
  }
  delay(100);
  for(int p=0; p< sizeof(pin); p++){
    digitalWrite(pin[p], LOW);
  }
}

void DB(){
  DB_state = true;
}
const uint16_t my_pids[] = {E120_DEVICE_HOURS, E120_LAMP_HOURS};
struct RDMINIT rdmInit = {
  "TeamCo.", // Manufacturer Label
  1, // Device Model ID
  "Teamoween", // Device Model Label
  32, // footprint
  (sizeof(my_pids)/sizeof(uint16_t)), my_pids,
  0, NULL
};
int ta[32];
void setup() {
  pinMode(DB_PIN, INPUT_PULLUP);
  for(int p = 22;p<=53; p++){
     pinMode(p,OUTPUT);
     ta[p-22]=p;
  }
  //DMXSerial2.init(&rdmInit, processCommand);
  for(int p = 22;p<=53; p++){
     trigger(p);
  }
  //atrigger(ta,32);
  noInterrupts();
  attachInterrupt(digitalPinToInterrupt(DB_PIN), DB,FALLING);
  interrupts();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(DB_state){
    ta[0] = 22;
    ta[1] = 23;
    atrigger(ta,2);
    delay(0);
    //trigger(23);
    delay(100);
    trigger(24);
    delay(200);
    trigger(25);
    delay(500);
    trigger(26);
    delay(100);
    trigger(27);
    delay(200);
    trigger(28);
    delay(300);
    trigger(29);
    delay(100);
    trigger(30);
    delay(200);
    trigger(31);
    delay(300);
    trigger(32);
    delay(500);
    trigger(33);
    delay(100);
    trigger(34);
    delay(200);
    trigger(35);
    delay(300);
    trigger(36);
    delay(100);
    trigger(37);
    delay(200);
    trigger(38);
    delay(300);
    trigger(39);
    delay(100);
    trigger(40);
    delay(200);
    trigger(41);
    delay(300);
    trigger(42);
    delay(100);
    trigger(43);
    delay(200);
    trigger(44);
    delay(500);
    trigger(45);
    delay(100);
    trigger(46);
    delay(200);
    trigger(47);
    delay(500);
    trigger(48);
    delay(100);
    trigger(49);
    delay(200);
    trigger(50);
    delay(300);
    trigger(51);
    delay(100);
    trigger(52);
    delay(200);
    trigger(53);
    DB_state= false;
  }
}
