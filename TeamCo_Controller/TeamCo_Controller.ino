#define DB_PIN  19

#define FOG_T  4000
#define SKUL_T 5000
#define SKEL_T 25000
#define REEP_T 17000
#define SAM_T  25000
#define BAR_T  23000
#define MAID_T 19000
#define EDDY_T 20000
#define MARS_T 25000
#define SPI_T  15000
#define BBONES_T 25000


#define FOG1_P 44
#define FOG2_P 45
#define FOG3_P 43
#define SKUL_P 22
//#define SKEL1_P 23
#define SKEL2_P 24
//#define SKEL2_P 42
#define REEP_P 25
#define SAM_P  26
#define BAR_P  27
#define MAID_P 28
#define EDDY_P 29
#define MARS_P 30
#define SPI_P  31
#define BBONES_P 23

//#include <DMXSerial2.h>
bool DB_state=false;
int ta[32];
int show_cnt = 0;
void trigger(int pin, int time=100){
  digitalWrite(pin, HIGH);
  delay(time);
  digitalWrite(pin,LOW);
}

void atrigger(int* pin,int len,int time = 100){
  for(int p=0; p< len; p++){
    digitalWrite(pin[p], HIGH);
  }
  delay(time);
  for(int p=0; p< len; p++){
    digitalWrite(pin[p], LOW);
  }
}

void DB(){
  int taf[3];
  DB_state = true;
  taf[0] = FOG1_P;
  taf[1] = FOG2_P;
  taf[2] = FOG3_P;
  trigger(SKUL_P,150);
  atrigger(taf,3, FOG_T);
}
/*
const uint16_t my_pids[] = {E120_DEVICE_HOURS, E120_LAMP_HOURS};
struct RDMINIT rdmInit = {
  "TeamCo.", // Manufacturer Label
  1, // Device Model ID
  "Teamoween", // Device Model Label
  32, // footprint
  (sizeof(my_pids)/sizeof(uint16_t)), my_pids,
  0, NULL
};
*/
void show(){
  
  //ta[0] = FOG1_P;
  //ta[1] = FOG2_P;
  //ta[2] = FOG3_P;
  //trigger(SKUL_P,150);
  //atrigger(ta,3, FOG_T);
  //Serial.println("Skull and Fog");
  //delay(SKUL_T);
  //ta[0] = SKEL1_P;
  //ta[1] = SKEL2_P;
  //atrigger(ta,2,1000);
  //Serial.println("Skeleton brothers");
  //delay(SKEL_T);
  trigger(BBONES_P);
  delay(BBONES_T);
  if(show_cnt == 0){
    trigger(REEP_P);
    delay(REEP_T);
    trigger(SPI_P);
    delay(SPI_T);
    show_cnt++;
  }else if(show_cnt == 1){
    trigger(SKEL2_P);
    delay(SKELT);
    trigger(EDDY_P);
    delay(EDDY_T);
    show_cnt++;
  }else if(show_cnt ==2){
    trigger(BAR_P);
    delay(BAR_T);
    trigger(MAID_P);
    delay(MAID_T);
    show_cnt++;
  }else{
    trigger(SAM_P);
    delay(SAM_T)
    trigger(MARS_P);
    delay(MARS_T);
    show_cnt = 0;
  }
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
//trigger(34);
  //show();
  DB_state = false;
  Serial.begin(9600); 
  Serial.println("Waiting for Button press");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(DB_state){
    show();
    DB_state = false;
  }
}
