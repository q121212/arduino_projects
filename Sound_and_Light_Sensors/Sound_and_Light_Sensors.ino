#define Mic 0
#define LightSensor 5
#define LED 13
#define Speaker 11

char state=0;
int valMic, valLight;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(Speaker, OUTPUT);

  Serial.begin(9600);
  while (!Serial) 
    {}
}

void loop() {
  // put your main code here, to run repeatedly:
  valMic = analogRead(Mic);
  valLight = analogRead(LightSensor);
  if (valMic>25){
    state=~state;
    digitalWrite(LED, state);
    Serial.print("Mic value is: ");
    Serial.println(valMic);
  }
  // threshold of darkness: the higher the value - the darker
  if (valLight>370){
    Serial.print("Light value is: ");
    Serial.println(valLight);
    if (valLight>500 && valLight<510){
      digitalWrite(Speaker, HIGH);
      delay(5);
      digitalWrite(Speaker, LOW);
    }
  }
}
