#define DB_PIN  19

#define FOG_T 4000
#define SKUL_T 000
#define SKEL_T 25000
#define REEP_T 17000
#define SAM_T  25000
#define BAR_T  23000
#define MAID_T 19000
#define EDDY_T 20000
#define MARS_T 25000


#include <DMXSerial2.h>
bool DB_state=false;
int ta[32];

void trigger(int pin, int time=50){
  digitalWrite(pin, HIGH);
  delay(time);
  digitalWrite(pin,LOW);
}

void atrigger(int* pin,int len,int time = 50){
  for(int p=0; p< len; p++){
    digitalWrite(pin[p], HIGH);
  }
  delay(time);
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


void show(){
  ta[0] = 45;
  ta[1] = 44;
  trigger(22,150);
  atrigger(ta,2, FOG_T);
  delay(SKUL_T);
  ta[0] = 23;
  ta[1] = 24;
  atrigger(ta,2);
  delay(SKEL_T);
  trigger(25);
  delay(REEP_T);
  trigger(26);
  delay(SAM_T);
  trigger(27);
  delay(BAR_T);
  trigger(28);
  delay(MAID_T);
  trigger(29);
  delay(EDDY_T);
  trigger(30);
  delay(MARS_T);
  trigger(31);
  /*delay(300);
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
  trigger(53);*/
}


void setup() {
  pinMode(DB_PIN, INPUT_PULLUP);
  for(int p = 22;p<=53; p++){
     pinMode(p,OUTPUT);
     ta[p-22]=p;
  }
  //DMXSerial2.init(&rdmInit, processCommand);
  /*
  for(int p = 22;p<=53; p++){
     trigger(p);
  }
  */
  //atrigger(ta,32);
  noInterrupts();
  attachInterrupt(digitalPinToInterrupt(DB_PIN), DB,FALLING);
  interrupts();

  //show();
  DB_state = false;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(DB_state){
    show();
    DB_state = false;
  }
}
