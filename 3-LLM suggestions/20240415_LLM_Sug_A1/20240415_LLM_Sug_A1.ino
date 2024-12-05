int ledPin = 13; // LED连接到数字13号引脚
// 第二台
#define SENSOR0_PIN A0   
#define SENSOR1_PIN A1
#define SENSOR2_PIN A2
#define SENSOR3_PIN A3
#define SENSOR4_PIN A4
#define SENSOR5_PIN A5
#define SENSOR6_PIN A6
#define SENSOR7_PIN A7
#define SENSOR8_PIN A8
#define SENSOR9_PIN A9
#define SENSOR10_PIN A10
#define SENSOR11_PIN A11
#define SENSOR12_PIN A12
#define SENSOR13_PIN A13
#define SENSOR14_PIN A14
#define SENSOR15_PIN A15

// A0 A12C21 L_A12C21 = 80  R_A12C21 =2.80M
// A1 A12B11 L_A12B11 = 80  R_A12B11 =8.44M
// A2 B11C21 L_B11C21 = 70  R_B11C21 =2.83M

// A3 A12C22 L_A12C22 = 75  R_A12C22 =2.23M
// A4 B21C22 L_B21C22 = 80  R_B21C22 =3.15M
// A5 A12B21 L_A12B21 = 80  R_A12B21 =0.60M

// A6 A11B11 L_A11B11 = 75  R_A11B11 =3.33M
// A7 A11C11 L_A11C11 = 75  R_A11C11 =1.02M
// A8 B11C11 L_B11C11 = 70  R_B11C11 =2.78M 

const int numSamaples=100;

void setup() {
  // 初始化串口通信
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
   
  float sensor0_value = 0;
  float sensor1_value = 0;
  float sensor2_value = 0;
  float sensor3_value = 0;
  float sensor4_value = 0;
  float sensor5_value = 0;
  float sensor6_value = 0;
  float sensor7_value = 0;
  float sensor8_value = 0;
  int data= Serial.read();
//  unsigned long currentTime = millis(); // 获取当前时间（毫秒）

  // 进行多次采样
  for (int i=0; i<numSamaples; i++)    { 
  sensor0_value += analogRead(SENSOR0_PIN);
  sensor1_value += analogRead(SENSOR1_PIN);
  sensor2_value += analogRead(SENSOR2_PIN);
  sensor3_value += analogRead(SENSOR3_PIN);
  sensor4_value += analogRead(SENSOR4_PIN);
  sensor5_value += analogRead(SENSOR5_PIN);
  sensor6_value += analogRead(SENSOR6_PIN);
  sensor7_value += analogRead(SENSOR7_PIN);
  sensor8_value += analogRead(SENSOR8_PIN);
  delay(10);
  }
sensor0_value /= numSamaples;
sensor1_value /= numSamaples;
sensor2_value /= numSamaples;
sensor3_value /= numSamaples;
sensor4_value /= numSamaples;
sensor5_value /= numSamaples;
sensor6_value /= numSamaples;
sensor7_value /= numSamaples;
sensor8_value /= numSamaples;

// A0 A12C21 L_A12C21 = 80  R_A12C21 =2.80M
  float voltage0 = sensor0_value*(5.0/1023.0); 
  float R_A12C21  = (10*voltage0)/(5.0-voltage0)/4.64+0.9;
  Serial.print(R_A12C21); Serial.print(",");

// A1 A12B11 L_A12B11 = 80  R_A12B11 =10.44M
  float voltage1 = sensor1_value*(5.0/1023.0); 
  float R_A12B11 = (10*voltage1)/(5.0-voltage1)-0.6;
  Serial.print(R_A12B11); Serial.print(",");
  
// A2 B11C21 L_B11C21 = 70  R_B11C21 =2.83M
  float voltage2 = sensor2_value*(5.0/1023.0); 
  float R_B11C21 = (10*voltage2)/(5.0-voltage2)/4.64+1.76;
  Serial.print(R_B11C21);Serial.print(","); 

// A3 A12C22 L_A12C22 = 75  R_A12C22 =2.23M
 float voltage3 = sensor3_value*(5.0/1023.0); 
  float R_A12C22= (10*voltage3)/(5.0-voltage3)/4.64+1.5;
  Serial.print(R_A12C22);Serial.print(","); 

// A4 B21C22 L_B21C22 = 80  R_B21C22 =3.15M
  float voltage4 = sensor4_value*(5.0/1023.0); 
  float R_B21C22 = (10*voltage4)/(5.0-voltage4)/4.64+2.2; 
  Serial.print(R_B21C22); Serial.print(","); 

// A5 A12B21 L_A12B21 = 80  R_A12B21 =0.60M
  float voltage5 = sensor5_value*(5.0/1023.0); 
  float R_A12B21 = (10*voltage5)/(5.0-voltage5)/4.64+3.35; 
  Serial.print(R_A12B21); Serial.print(",");
   
// A6 A11B11 L_A11B11 = 75  R_A11B11 =3.33M
  float voltage6 = sensor6_value*(5.0/1023.0); 
  float R_A11B11 = (10*voltage6)/(5.0-voltage6)/4.64+2.53; 
  Serial.print(R_A11B11); Serial.print(","); 

// A7 A11C11 L_A11C11 = 75  R_A11C11 =1.02M
  float voltage7 = sensor7_value*(5.0/1023.0); 
  float R_A11C11 = (10*voltage7)/(5.0-voltage7)/4.64+2.64;
  Serial.print(R_A11C11);Serial.print(","); 

// A8 B11C11 L_B11C11 = 70  R_B11C11 =2.78M 
  float voltage8 = sensor8_value*(5.0/1023.0); 
  float R_B11C11 = (10*voltage8)/(5.0-voltage8)/4.64-0.98; 
  Serial.println(R_B11C11);
  
//  Serial.println(currentTime);
   // 延时一段时间
  delay(20);
}
