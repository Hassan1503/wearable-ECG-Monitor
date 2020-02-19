/* PIN Layout
 *  OUTPUT-32
 *  Battery Level -33
 *  LO+ -34
 *  LO- -35
 *  
 *  rgb:
 *  R-15
 *  G-2
 *  B-4
 *   Data per field = 51 (total 8 fields 408 data)
 */

#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>
#include <ArduinoJson.h>

// Set these to run example.
#define FIREBASE_HOST "https://ecgproject-86945.firebaseio.com/"
#define FIREBASE_AUTH "7UtPoICz7T4kvDnjIRugh3H59CnldkQ2XaXqy6z5"
#define WIFI_SSID "Bzzzzttt"
#define WIFI_PASSWORD "firestorm"

const unsigned long READ_PERIOD = 4000;  // 4000 us: 250 Hz -> 4ms , 1000/4->250 Hz
const int red = 15;
const int green =2;
const int blue =4;

int raw_ecg[1500]; //Buffer for sending data
int counter=0;      //counter for sending

unsigned long start, finished, elapsed;

void setup() {
  Serial.begin(9600);
  
  pinMode(35, INPUT); // Setup for leads off detection LO +
  pinMode(34, INPUT); // Setup for leads off detection LO -
  pinMode(33, INPUT); // bATTERY lEVEL
  pinMode (15, OUTPUT);
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(red,HIGH);
    digitalWrite(blue,LOW);
    digitalWrite(green,LOW);
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  
}

int n;

void loop() {

  static unsigned long lastRead;
  if (micros() - lastRead >= READ_PERIOD) {
      lastRead += READ_PERIOD;
      if (digitalRead(34) == 1 || digitalRead(35) == 1){
          Serial.println('!');
          digitalWrite(red,HIGH);
          digitalWrite(blue,LOW);
          digitalWrite(green,LOW);
      }
      else{
          digitalWrite(blue,HIGH);
          digitalWrite(red,LOW);
          digitalWrite(green,LOW);
         raw_ecg[counter] = analogRead(32);
         Serial.println(raw_ecg[counter]);
          counter++;
        }
//       raw_ecg[counter] = random(0,4095);
//       counter++;

  }
  
  if(counter==1500){
     digitalWrite(green,HIGH);
     digitalWrite(red,LOW);
     digitalWrite(blue,LOW);
    Serial.print(millis());
    Serial.println("ms Passed");
    start=millis();
    Send_Data(raw_ecg);
    finished=millis();
    elapsed=finished-start;
    Serial.print(elapsed);
    Serial.println(" milliseconds elapsed to send data");
    counter=0;
    } 
    
}



void Send_Data(int raw_data[]){

  unsigned long s1,l1,e1;
  s1 = millis();
  
  String field1 = "";
  String field2 = "";
  String field3 = "";
  String field4 = "";
  String field5 = "";
  String field6 = "";
  String field7 = "";
  String field8 = "";
  String field9 = "";
  String field10 = "";
  String field11 = "";
  String field12 = "";
  String field13 = "";
  String field14 = "";
  String field15 = "";
  String field16 = "";
  String field17 = "";
  String field18 = "";
  String field19 = "";
  String field20 = "";
  String field21 = "";
  String field22 = "";
  String field23 = "";
  String field24 = "";
  String field25 = "";
  String field26 = "";
  String field27 = "";
  String field28 = "";
  String field29 = "";
  String field30 = "";

  for(int i =0;i<=1500;i++){
              if(i<50){
                field1 += raw_data[i];
                field1 += ",";
              }
              else if(i>50 && i<100 ){
                field2 += raw_data[i];
                field2 += ",";
              }
              else if(i>100 && i<150 ){
                field3 += raw_data[i];
                field3 += ",";
              }
              else if(i>150 && i<200 ){
                field4 += raw_data[i];
                field4 += ",";
              }
              else if(i>200 && i<250 ){
                field5 += raw_data[i];
                field5 += ",";
              }
               else if(i>250 && i<300 ){
                field6 += raw_data[i];
                field6 += ",";
              }
              else if(i>300 && i<350 ){
                field7 += raw_data[i];
                field7 += ",";
              }
              else if(i>350 && i<400 ){
                field8 += raw_data[i];
                field8 += ",";
              }
              else if(i>400 && i<450 ){
                field9 += raw_data[i];
                field9 += ",";
              }
              else if(i>450 && i<500 ){
                field10 += raw_data[i];
                field10 += ",";
              }
              else if(i>500 && i<550){
                field11 += raw_data[i];
                field11 += ",";
              }
              else if(i>550 && i<600 ){
                field12 += raw_data[i];
                field12 += ",";
              }
              else if(i>600 && i<650 ){
                field13 += raw_data[i];
                field13 += ",";
              }
              else if(i>650 && i<700 ){
                field14 += raw_data[i];
                field14 += ",";
              }
              else if(i>700 && i<750 ){
                field15 += raw_data[i];
                field15 += ",";
              }
              else if(i>750 && i<800 ){
                field16 += raw_data[i];
                field16 += ",";
              }
               else if(i>800 && i<850 ){
                field17 += raw_data[i];
                field17 += ",";
              }
              else if(i>850 && i<900 ){
                field18 += raw_data[i];
                field18 += ",";
              }
              else if(i>900 && i<950 ){
                field19 += raw_data[i];
                field19 += ",";
              }
              else if(i>950 && i<1000 ){
                field20 += raw_data[i];
                field20 += ",";
              }
               else if(i>1000 && i<1050){
                field21 += raw_data[i];
                field21 += ",";
              }
              else if(i>1050 && i<1100 ){
                field22 += raw_data[i];
                field22 += ",";
              }
              else if(i>1100 && i<1150 ){
                field23 += raw_data[i];
                field23 += ",";
              }
              else if(i>1150 && i<1200 ){
                field24 += raw_data[i];
                field24 += ",";
              }
              else if(i>1200 && i<1250 ){
                field25 += raw_data[i];
                field25 += ",";
              }
              else if(i>1250 && i<1300 ){
                field26 += raw_data[i];
                field26 += ",";
              }
               else if(i>1300 && i<1350 ){
                field27 += raw_data[i];
                field27 += ",";
              }
              else if(i>1350 && i<1400 ){
                field28 += raw_data[i];
                field28 += ",";
              }
              else if(i>1400 && i<1450 ){
                field29 += raw_data[i];
                field29 += ",";
              }
              else if(i>1450 && i<1500 ){
                field30 += raw_data[i];
                field30 += ",";
              }
          }
         field1 += raw_data[50];
         field2 += raw_data[100];
         field3 += raw_data[150];
         field4 += raw_data[200];
         field5 += raw_data[250];
         field6 += raw_data[300];
         field7 += raw_data[350];
         field8 += raw_data[400];
         field9 += raw_data[450];
         field10 += raw_data[500];
         field11 += raw_data[550];
         field12 += raw_data[600];
         field13 += raw_data[650];
         field14 += raw_data[700];
         field15 += raw_data[750];
         field16 += raw_data[800];
         field17 += raw_data[850];
         field18 += raw_data[900];
         field19 += raw_data[950];
         field20 += raw_data[1000];
         field21 += raw_data[1050];
         field22 += raw_data[1100];
         field23 += raw_data[1150];
         field24 += raw_data[1200];
         field25 += raw_data[1250];
         field26 += raw_data[1300];
         field27 += raw_data[1350];
         field28 += raw_data[1400];
         field29 += raw_data[1450];
         field30 += raw_data[1500];
          
  
  DynamicJsonBuffer jsonBuffer;
  JsonArray& array = jsonBuffer.createArray();
  array.add(field1);
  array.add(field2);
  array.add(field3);
  array.add(field4);
  array.add(field5);
  array.add(field6);
  array.add(field7);
  array.add(field8);
  array.add(field9);
  array.add(field10);
  array.add(field11);
  array.add(field12);
  array.add(field13);
  array.add(field14);
  array.add(field15);
  array.add(field16);
  array.add(field17);
  array.add(field18);
  array.add(field19);
  array.add(field20);
  array.add(field21);
  array.add(field22);
  array.add(field23);
  array.add(field24);
  array.add(field25);
  array.add(field26);
  array.add(field27);
  array.add(field28);
  array.add(field29);
  array.add(field30);
 
  //array.printTo(Serial);
  l1 = millis();
  e1 = l1-s1;
  Serial.print("Processing Time:");
  Serial.println(e1);


  /*Gettting Last entry and updating*/
  int last_entry=Firebase.getInt("Channel1/last_entry_id");
  Serial.println(last_entry);
  int entry_id = last_entry+1;
  String feed_path = "feeds";
  feed_path.concat("/");
  feed_path = feed_path+ entry_id;
  
  const int capacity = JSON_OBJECT_SIZE(3);
  StaticJsonBuffer<capacity> jb;
  // Create a JsonObject
  JsonObject& obj = jb.createObject();
  
  //Entry ID values
  obj["created_at"] = millis();
  obj["field"] = array;
  obj["entry_id"] = entry_id;



//   // Declare a buffer to hold the result
//  char output[1000];
//  // Produce a minified JSON document
//  obj.printTo(output);
//  Serial.println(output);

  
  
  Firebase.set(feed_path, obj);
  Serial.println(feed_path);
  Firebase.set("Channel1/last_entry_id",entry_id);
  
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }

  
  delay(1);
  
  }

































void setup_channel(){

  StaticJsonBuffer<200> jsonBuffer;
  JsonArray& array = jsonBuffer.createArray();
  array.add("hello");
  array.add(3.14156);
  array.printTo(Serial);
  
  const int capacity = JSON_OBJECT_SIZE(3);
  StaticJsonBuffer<capacity> jb;
  // Create a JsonObject
  JsonObject& obj = jb.createObject();
  int a[10] = {1,2,3};
  //obj["value"] = array;
  obj["id"] = 01;
  obj["name"] = "ecg_raw_data";
  obj["last_entry_id"] = 00;



    // Declare a buffer to hold the result
  char output[128];
  // Produce a minified JSON document
  obj.printTo(output);
  Serial.println(output);

  // set value
  String s = String(millis());
  Firebase.set("Channel1", obj);
  n++;
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  }

