//Digital Input and Output Game
//Push button on green light

int buzzerPin = 8;
int currentLED = 2;
int currentPitch = 1047;
int delayValue = 200;
int count = 0;
int score = 0;


#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_D6 1175
#define NOTE_E6 1319
#define NOTE_F6 1397

void setup() {
  //initialize digital pin 12 as input: 
  pinMode(12, INPUT); //button input

  //initialize digital pin 2 to 5 as output:
  pinMode(2, OUTPUT); //white LED
  pinMode(3, OUTPUT); //yellow LED
  pinMode(4, OUTPUT); //green LED
  pinMode(5, OUTPUT); //red LED
}

int checkInput(){
  if(digitalRead(12) == 0){
    return 1;
  }else{
    return 0;
  }
}

void setDefault(){
  delayValue = 200;
  count = 0;
  score = 0;
  currentLED = 2;  
}

void goodBuzzer(){
  tone(buzzerPin, NOTE_C6, 150);
  delay(60);
  tone(buzzerPin, NOTE_F6, 150);
  delay(50);
}

void badBuzzer(){
  tone(buzzerPin, NOTE_C6, 150);
  delay(60);
  tone(buzzerPin, NOTE_B5, 150);
  delay(50);
}
void scoreShow(){
  
  //Solid
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  delay(1000);
  
  //Really Fast
  for(int i=0; i<25; i++){
  digitalWrite(currentLED, HIGH);
  delay(50);
  digitalWrite(currentLED, LOW);
  delay(50);
  currentLED++;
  if(currentLED > 5)
    currentLED = 2;
  }
  
  //Blink Score        
  for(int i=0; i<score; i++){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(500);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(500);
  }
}

void loop() {
  //Check if the button is pressed at the right moment
  if(digitalRead(12) == 0) {
    if(currentLED == 4){
        //Blink the correct (green) LED
        goodBuzzer();
        digitalWrite(4, HIGH);
        delay(200);
        digitalWrite(4, LOW);
        delay(200);
        score++;
  
        //Speed up the LEDs
        if(delayValue > 20)
          delayValue = delayValue - 20;
      }
      else{
        //Blink the wrong LED
        badBuzzer();
        digitalWrite(currentLED, HIGH);
        delay(200);
        digitalWrite(currentLED, LOW);
        delay(200);
        count++;
        
        if(count == 3){
          scoreShow();
          setDefault();
        }
     }  
  }
  //Loop LED from w-y-g-r
  switch(currentLED)
        {
        case 2 : 
               tone(buzzerPin, NOTE_C6);
               break;
        case 3 : 
               tone(buzzerPin, NOTE_D6);
               break;
        case 4 : 
               tone(buzzerPin, NOTE_E6);
               break;
        case 5 : 
               tone(buzzerPin, NOTE_F6);   
               break;    
        }
  digitalWrite(currentLED, HIGH);
  delay(delayValue);
  digitalWrite(currentLED, LOW);
  delay(delayValue);
  currentLED++;
  if(currentLED > 5){
    currentLED = 2;
  }
}
