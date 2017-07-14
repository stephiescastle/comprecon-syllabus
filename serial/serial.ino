
int x = 3;
int y = 2;
int z;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  z = x + y;
  Serial.println(z);
  delay(500);
  z++;
  Serial.println(z);
}
