// C++ code
//
int RED = 13;            //LED
int PIR = 2;             //Sensor 
int state = LOW; 		//Inital State
int val = 0;			//Variable for storing state
void setup() {
  //Initalizing LED and Sensor
  pinMode(RED, OUTPUT);      
  pinMode(PIR, INPUT);    
  Serial.begin(9600);        
}

void loop(){
  
  val = digitalRead(PIR); 
  //Turning on the LED on detecting motion
  if (val == HIGH) {           
    digitalWrite(RED, HIGH);   
    delay(1000);                 
    
    if (state==LOW) {
      Serial.println("Motion has been detected!"); 
      state = HIGH;       
    }
  } 
  else {
    //Turning off the led if motion not detected
      digitalWrite(RED, LOW); 
      delay(1000);             
      
      if (state == HIGH){
        Serial.println("Motion not detected");
        state = LOW;       
    }
  }
}