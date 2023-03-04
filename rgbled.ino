int red=8;
int green=9;
int blue=10;
int tim(300);
String ledch;
String chi;
String ledcolor;
String msg="What color Do you want";

void rgb(){
    //red led
digitalWrite(red,HIGH);
delay(tim);
digitalWrite(red,LOW);
delay(tim);

//green led
digitalWrite(green,HIGH);
delay(tim);
digitalWrite(green,LOW);
delay(tim);

//blue led
digitalWrite(blue,HIGH);
delay(tim);
digitalWrite(blue,LOW);
delay(tim);

//white led ON
digitalWrite(red,HIGH);
digitalWrite(green,HIGH);
digitalWrite(blue,HIGH);
delay(tim);

//white led OFF
digitalWrite(red,LOW);
digitalWrite(green,LOW);
digitalWrite(blue,LOW);
delay(tim);
}


void setup(){
Serial.begin(9600);
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
pinMode(blue,OUTPUT);

}

void loop(){

Serial.println(msg);
while (Serial.available()==0){
}
ledcolor=Serial.readString();
ledcolor.trim();

if (ledcolor=="red" || ledcolor=="Red") {
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
}

if (ledcolor=="green"|| ledcolor=="Green") {
  digitalWrite(green,HIGH);
  digitalWrite(red,LOW);
  digitalWrite(blue,LOW);
}

if (ledcolor=="blue" || ledcolor=="Blue") {
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,HIGH);
}

if (ledcolor=="off" || ledcolor=="Off") {
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
}

if (ledcolor=="all" || ledcolor=="All" || ledcolor=="rgb" || ledcolor=="Rgb"  ) {
  while (ledcolor != "off"){
    rgb();
    ledcolor=Serial.readString();
    ledcolor.trim();

  }

}

}

