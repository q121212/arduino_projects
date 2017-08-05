// Control 3 and 13 LED via Serial monitor

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial)
    {}
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.println("For LEDs: 10 is OFF, 11 is ON");
}

void loop() {
  // put your main code here, to run repeatedly:
  int data;
  if (Serial.available() > 0){
    data = Serial.parseInt();
    Serial.println(data);
  }    
  switch(data){
    case 10:
      Serial.println("LED 1 and 13 Off");
      digitalWrite(3, LOW);
      digitalWrite(13, LOW);
      digitalWrite(5, HIGH);
      delay(5);
      digitalWrite(5, LOW);
      delay(50);
      digitalWrite(5, HIGH);
      delay(5);
      digitalWrite(5, LOW);
      delay(50);

      data=0;
      break;
      
    case 11:
      Serial.println("LED 1 and 13 On");
      digitalWrite(3, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(5, HIGH);
      delay(5);
      digitalWrite(5, LOW);
      delay(100);
      digitalWrite(5, HIGH);
      delay(5);
      digitalWrite(5, LOW);
      delay(100);
      digitalWrite(5, HIGH);
      delay(5);
      digitalWrite(5, LOW);
      
      data=0;
      break;
  }
}
