// Project 5: Traffic Lights

#define westButton 3
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10
#define pedWhite 9

#define yellowBlinkTime 500

boolean trafficWest = true;
int flowTime = 10000;   
int changeDelay = 2000;  


void setup() 
{
  //set button and LED pins
  pinMode(westButton, INPUT);
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed,OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);
  pinMode(pedWhite, OUTPUT);

  //set start state for each light
  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);                    // traffic West is Green
  digitalWrite(eastRed, HIGH);                      // traffic East is Red
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
  digitalWrite(pedWhite, LOW);                      // ped light is off
}


void loop() 
{
    if (digitalRead (westButton) == LOW)            // button is not pushed
     { 
      if (trafficWest) {                              // & west is green
          delay (flowTime);                        // 5sec delay traffic flow
          digitalWrite (westGreen, LOW);
          digitalWrite (westYellow, HIGH);         // west light change from green to yellow
          delay (flowTime);                        // 5sec delay

          digitalWrite (westYellow, LOW);
          digitalWrite (westRed, HIGH);            // west light change from yellow to red
          trafficWest = false; }
       
       
        else {                                      // if button is not pushed & west is red
          delay (changeDelay);
          digitalWrite (eastRed, LOW);
          digitalWrite (eastGreen, HIGH);          // east light change from red to green

          delay (flowTime);                          // 5sec delay for traffic
          digitalWrite (eastGreen, LOW);
          digitalWrite (eastYellow, HIGH);           // east light change from green to yellow
          delay (flowTime);                        // 5sec delay

          digitalWrite (eastYellow, LOW);
          digitalWrite (eastRed, HIGH);              // east light change from yellow to red
       
          delay (changeDelay);
          digitalWrite (westRed, LOW); 
          digitalWrite (westGreen, HIGH);            // west light change from red to green
          trafficWest = true; }
     }

    else {                                          // button is pushed
        if (trafficWest)                            // & west was green
       {
        //delay (changeDelay);                    // 1sec delay between button push and light change
        digitalWrite (westGreen, LOW);
        digitalWrite (westYellow, HIGH);       // light change from green to yellow
        delay (flowTime/2);                    // 2.5sec delay 

        digitalWrite (westYellow, LOW);
        digitalWrite (westRed, HIGH);          // light change from yellow to red
        delay (changeDelay);                   // 1sec delay

        digitalWrite (pedWhite, HIGH);          // turn on ped light
        delay (flowTime);                       // 5sec pedestrian walk gap
        digitalWrite (pedWhite, LOW);           // turn off ped light, resume traffic

        trafficWest = false;                        
       }


       else                                       // button is pushed & west was red
       {
        delay (changeDelay);                     // 1sec delay between button push and light change
        digitalWrite (eastGreen, LOW);
        digitalWrite (eastYellow, HIGH);        // light change from green to yellow
        delay(flowTime/2);                      // 2.5sec delay

        digitalWrite (eastYellow, LOW);
        digitalWrite (eastRed, HIGH);           // light change from yellow to red
        delay (changeDelay);                    // 1sec delay 

        digitalWrite (pedWhite, HIGH);          // turn on ped light
        delay (flowTime);                       // 5sec pedestrian walk gap
        digitalWrite (pedWhite, LOW);           // turn off ped light, resume traffic

        trafficWest = true;                     
       }
    }
  }



