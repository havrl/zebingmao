int ledPin = 13; // LED连接到数字13号引脚

//  0号 mega 
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

//A0 B21C12 L_B21C12 = 85  R_B21C12 =2.31M  0.57,
//A1 A11C12 L_A11C12 = 80  R_A11C12 =2.95M  0.84,
//A2 A11B21 L_A11B21 = 70  R_A11B21 =1.61M  0.54,

//A3 B22C12 L_B22C12 = 80  R_B22C12 =2.68M  0.71,
//A4 A21B22 L_A21B22 = 85  R_A21B22 =4.30M  4.06,
//A5 A21C12 L_A21C12 = 75  R_A21C12 =3.55M  1.13, 

//A6 A21C11 L_A21C11 = 85  R_A21C11 =0.58M  0.27,
//A7 A21B12 L_A21B12 = 85  R_A21B12 =3.22M  0.16,
//A8 B12C11 L_B12C11 = 80  R_B12C11 =4.35M  1.37
 
//A9  A22C22 L_A22C22 = 80  R_A22C22 = 3.82 M  ,0.77,
//A10 A22B22 L_A22B22 = 85  R_A22B22 = 4.44 M  1.20,
//A11 B22C22 L_B22C22 = 85  R_B22C22 = 2.85 M  1.24,

//A12 A22B12 L_A22B12 = 80  R_A22B12= 1.39 M   0.55,
//A13 A22C21 L_A22C21 = 80  R_A22C21= 3.52 M   0.97,        
//A14 B12C21 L_B12C21 = 80  R_B12C21= 1.04 M   0.31     

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
float sensor9_value = 0;
float sensor10_value = 0;
float sensor11_value = 0;
float sensor12_value = 0;
float sensor13_value = 0;
float sensor14_value = 0;
    //  float sensor15_value = 0;

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
  sensor9_value += analogRead(SENSOR9_PIN);
  sensor10_value += analogRead(SENSOR10_PIN);
  sensor11_value += analogRead(SENSOR11_PIN);
  sensor12_value += analogRead(SENSOR12_PIN);
  sensor13_value += analogRead(SENSOR13_PIN);
  sensor14_value += analogRead(SENSOR14_PIN);
//  sensor15_value += analogRead(SENSOR15_PIN);  
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
sensor9_value /= numSamaples;
sensor10_value /= numSamaples;
sensor11_value /= numSamaples;
sensor12_value /= numSamaples;
sensor13_value /= numSamaples;
sensor14_value /= numSamaples;
//sensor15_value /= numSamaples;
//A0 B21C12 L_B21C12 = 85  R_B21C12 =2.31M

  float voltage0 = sensor0_value*(5.0/1023.0); 
  float R_B21C12 = (10*voltage0)/(5.0-voltage0)/4.64+1.74;
  Serial.print(R_B21C12);Serial.print(",");

//A1 A11C12 L_A11C12 = 80  R_A11C12 =2.95M

  float voltage1 = sensor1_value*(5.0/1023.0); 
  float R_A11C12 = (10*voltage1)/(5.0-voltage1)/4.64+2.11;
  Serial.print(R_A11C12);Serial.print(",");

//A2 A11B21 L_A11B21 = 70  R_A11B21 =1.61M
  float voltage2 = sensor2_value*(5.0/1023.0); 
  float R_A11B21 = (10*voltage2)/(5.0-voltage2)/4.647+1.07; 
  Serial.print(R_A11B21); Serial.print(",");

//A3 B22C12 L_B22C12 = 80  R_B22C12 =2.68M

  float voltage3 = sensor3_value*(5.0/1023.0); 
  float R_B22C12 = (10*voltage3)/(5.0-voltage3)/4.64+1.97; 
  Serial.print(R_B22C12);Serial.print(",");
  
//A4 A21B22 L_A21B22 = 85  R_A21B22 =4.30M

  float voltage4 = sensor4_value*(5.0/1023.0); 
  float R_A21B22 = (10*voltage4)/(5.0-voltage4)/4.64+3.12; 
  Serial.print(R_A21B22);Serial.print(",");

//A5 A21C12 L_A21C12 = 75  R_A21C12 =3.55M
  float voltage5 = sensor5_value*(5.0/1023.0); 
  float R_A21C12 = (10*voltage5)/(5.0-voltage5)/4.64+2.42; 
  Serial.print(R_A21C12);Serial.print(",");

//A6 A21C11 L_A21C11 = 85  R_A21C11 =0.58M

  float voltage6 = sensor6_value*(5.0/1023.0); 
  float R_A21C11 = (10*voltage6)/(5.0-voltage6)/4.64+2.31; 
  Serial.print(R_A21C11);Serial.print(",");
  
//A7 A21B12 L_A21B12 = 85  R_A21B12 =3.22M

  float voltage7 = sensor7_value*(5.0/1023.0); 
  float R_A12B11 = (10*voltage7)/(5.0-voltage7)/4.64+3.06;
  Serial.print(R_A12B11);Serial.print(",");
    
//A8 B12C11 L_B12C11 = 80  R_B12C11 =4.35M
  float voltage8 = sensor8_value*(5.0/1023.0); 
  float R_A12B21 = (10*voltage8)/(5.0-voltage8)/4.64+2.98; 
  Serial.print(R_A12B21);Serial.print(",");

//A9  A22C22 L_A22C22 = 80  R_A22C22 = 3.82 M 

  float voltage9  = sensor9_value*(5.0/1023.0); 
  float R_A22C22 = (10*voltage9)/(5.0-voltage9)/4.64+3.05; 
  Serial.print(R_A22C22);Serial.print(",");

//A10 A22B22 L_A22B22 = 85  R_A22B22 = 4.44 M

  float voltage10 = sensor10_value*(5.0/1023.0); 
  float R_A22B22 = (10*voltage10)/(5.0-voltage10)/4.64+3.24; 
  Serial.print(R_A22B22);Serial.print(",");
   
//A11 B22C22 L_B22C22 = 85  R_B22C22 = 2.85 M
  float voltage11 = sensor11_value*(5.0/1023.0); 
  float R_B22C22 = (10*voltage11)/(5.0-voltage11)/4.64+1.61; 
  Serial.print(R_B22C22);Serial.print(",");

//A12 A22B12 L_A22B12 = 80  R_A22B12= 1.39 M      

  float voltage12 = sensor12_value*(5.0/1023.0); 
  float R_A22B12 = (10*voltage12)/(5.0-voltage12)/4.64+0.85; 
  Serial.print(R_A22B12);Serial.print(",");
    
//A13 A22C21 L_A22C21 = 80  R_A22C21= 3.52 M          

  float voltage13 = sensor13_value*(5.0/1023.0); 
  float R_A21C21  = (10*voltage13)/(5.0-voltage13)/4.64+2.56; 
  Serial.print(R_A21C21);Serial.print(",");
     
//A14 B12C21 L_B12C21 = 80  R_B12C21= 1.04 M       
  float voltage14 = sensor14_value*(5.0/1023.0); 
  float R_B12C21 = (10*voltage14)/(5.0-voltage14)/4.64+0.74; 
  Serial.println(R_B12C21);
  
 // 延时一段时间
  delay(20);

//  Serial.println(currentTime);
 
  
}
