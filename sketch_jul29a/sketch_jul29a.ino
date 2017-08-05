/*
 * MaxR, Jul 29, 2017
 */

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int d;
  for (d=0; d<1023; d+=1){
    digitalWrite(13, 1);
    delay(d);
    digitalWrite(13, 0);
    delay(d);
  }
 }
