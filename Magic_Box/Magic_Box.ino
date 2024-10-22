
// Orientation: ON/OFF Rocker Switch is the bottom
// A0 -> R1 (Keypad) Orange Solid
// A1 -> C1 (Keypad) Orange Stripe
// A2 -> R2 (Keypad) Blue Solid
// A3 -> C2 (Keypad) Blue Stripe
// A4 -> R3 (Keypad) Green Solid
// A5 -> C3 (Keypad) Green Stripe
// A6 -> NC
// A7 -> Leave open for RANDOM SEED
// 2 -> LED 7
// 3 ~> LED 4
// 4 -> LED 1
// 5 ~> LED 8
// 6 ~> LED 5
// 7 -> Not Used
// 8 -> LED 9   
// 9 ~> LED 2
// 10 ~> LED 6
// 11 ~> Buzzer
// 12 -> LED 3
//
// Keep in mind the led[8] array is numbered like this because "0" is first in an array function.
// | 0 | 1 | 2 |
// | 3 | 4 | 5 |
// | 6 | 7 | 8 |

#include <Keypad.h>

char oneButton;

// Establishes the keypad...
const byte ROWS = 3;
const byte COLS = 3;
char keys[ROWS][COLS] = 
{  
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'}
};
byte rowPins[ROWS] = {A0, A2, A4};                                 //connect to the row pinouts of the keypad
byte colPins[COLS] = {A1, A3, A5};                                 //connect to the column pinouts of the keypad

Keypad nineSquare(makeKeymap(keys), rowPins, colPins, ROWS, COLS); //initialize an instance of class nineSquare

const int ledPin[9] = {4, 9, 12, 3, 6, 10, 2, 5, 8};  //Uses pins for the LED outputs
int led[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};  //Declares a variable for 9 LEDs
int buzzer = 11;

int moveCounter = 0;
unsigned long time;
unsigned long forgotten = 300000; //Amount of time of inactivity before sounding power save buzzer 1000 = 1 sec.
unsigned long buzDelay = 40;

void setup() {
  {
  
  Serial.begin(9600);
  
  for (byte i = 0; i < 9; i = i + 1)            //A 'for loop' saves time and typing to assign values to all the arrays
  {                                             //Using the same 'i' variable to assign values on all four lines
  pinMode(ledPin[i], OUTPUT);                   //Setting pins as outputs (LOW 0v / HIGH +5v)
  digitalWrite(ledPin[i], LOW);                 //Setting pins to the OFF state.
  led[i] = LOW;                                 //Setting the LED variables to the OFF state.
  }
  
  pinMode(buzzer, OUTPUT);
  randomSeed(analogRead(A6));                   //This makes 'random' much more RANDOM
  Serial.print("Waking up...");                 //Start logging the program
  
  nineSquare.setHoldTime(3000);                 //Amount of time to activate silent mode.
  
  randomPat();                                  //Starts off the game with a random pattern.
  buTone();                                     //Cool little start tone.
}

}

void loop() {
  oneButton = nineSquare.getState();
   if (oneButton == HOLD)                        // Silent mode
  {
   buzzer = 7;
    }
        
  oneButton = nineSquare.getKey();
  if (oneButton) 
  {
    moveCounter++;
    time = millis();
  }
  
  if (oneButton == '1') // makes sure a key is actually pressed, equal to (oneButton != NO_KEY)
  {
    led[0] = !led[0];
    led[1] = !led[1];
    led[3] = !led[3];
    led[4] = !led[4];
    buTone();
    printLayout();
    }
    
  if (oneButton == '2') // makes sure a key is actually pressed, equal to (oneButton != NO_KEY)
  {
    led[0] = !led[0];
    led[1] = !led[1];
    led[2] = !led[2];
    buTone();
    printLayout();
  }
  
  if (oneButton == '3') // makes sure a key is actually pressed, equal to (oneButton != NO_KEY)
  {
    led[2] = !led[2];
    led[1] = !led[1];
    led[5] = !led[5];
    led[4] = !led[4];//Invert the state of the LED then...
    buTone();
    printLayout();
    }
      if (oneButton == '4') // makes sure a key is actually pressed, equal to (oneButton != NO_KEY)
  {
    led[0] = !led[0];
    led[3] = !led[3];
    led[6] = !led[6];
    buTone();
    printLayout();
    }
    
  if (oneButton == '5') // makes sure a key is actually pressed, equal to (oneButton != NO_KEY)
  {
    led[1] = !led[1];
    led[3] = !led[3];
    led[4] = !led[4];
    led[5] = !led[5];
    led[7] = !led[7];
    buTone();
    printLayout();
  }
  
  if (oneButton == '6') // makes sure a key is actually pressed, equal to (oneButton != NO_KEY)
  {
    led[2] = !led[2];
    led[5] = !led[5];
    led[8] = !led[8];
    buTone();
    printLayout();
    }
      if (oneButton == '7') // makes sure a key is actually pressed, equal to (oneButton != NO_KEY)
  {
    led[3] = !led[3];
    led[4] = !led[4];
    led[6] = !led[6];
    led[7] = !led[7];
    buTone();
    printLayout();
    }
    
  if (oneButton == '8') // makes sure a key is actually pressed, equal to (oneButton != NO_KEY)
  {
  led[6] = !led[6];
  led[7] = !led[7];
  led[8] = !led[8];
  buTone();
  printLayout();
  }
  
  if (oneButton == '9') // makes sure a key is actually pressed, equal to (oneButton != NO_KEY)
  {
  led[4] = !led[4];
  led[5] = !led[5];
  led[7] = !led[7];
  led[8] = !led[8];
  buTone();
  printLayout();
    }
    
for (byte i = 0; i < 9; i = i + 1)            //A 'for loop' saves time and typing to assign values to all the arrays
  {           
  digitalWrite(ledPin[i], led[i]);                  //Apply that state 
  }
  
if (led[0] && led[1] && led[2] && led[3] && led[4] && led[5] && led[6] && led[7] && led[8])
  {
    winner();
    delay(100);
    for(int x = 0; x < 2; x++)
    {
      for(int i = 0; i < 6; i++)
      {
        tone(buzzer, 100 * i); // Send .2 KHz sound signal...
        delay(100);        // ...for 0.1 sec
        noTone(buzzer);     // Stop sound...
        for(int a = 0; a < 9; a++)
        {
          led[a] = !led[a];
          digitalWrite(ledPin[a], led[a]);
          delay(1);
        }

      }

    }
    randomPat();  
    buTone();
  }
  delay(10);

  if (millis() - time > forgotten)
  {
    buTone();
  }
}

void allOFF()
{
  for(int a = 0; a < 9; a++)
  {
    led[a] = LOW;
    digitalWrite(ledPin[a], led[a]);  
   }
}

void allON()
{
  for(int a = 0; a < 9; a++)
  {
    led[a] = HIGH;
    digitalWrite(ledPin[a], led[a]);  
  }
}

void randomPat()
{
  Serial.print("Random: ");
  for(int a = 0; a < 9; a++)
  {
    int randy = random(2);
    led[a] = randy;
    if(randy == (led[0] && led[1] && led[2] && led[3] && led[4] && led[5] && led[6] && led[7] && led[8]))
    {
      led[8] = !led[8];
    }
    digitalWrite(ledPin[a], led[a]); 
    Serial.print(randy); 
  }
  Serial.println(" ");
}

void buTone()
{
    tone(buzzer, 400, 10);
    delay(10);
    tone(buzzer, 1500, 10);
    delay(10);
    tone(buzzer, 600, 30);
    delay(10);

}

void winner()
{
    tone(buzzer, 500, 10);
    delay(30);
    tone(buzzer, 700, 10);
    delay(30);
    tone(buzzer, 900, 20);
    delay(40);
    tone(buzzer, 1100, 20);
    delay(40);
    tone(buzzer, 1300, 40);
    delay(50);
    tone(buzzer, 1500, 40);
    delay(50);
    Serial.println("!!WINNER!!");
    Serial.print(moveCounter);
    Serial.println(" Moves");
    moveCounter = 0;
}

void printLayout()
{
  Serial.print("Pattern: ");
  Serial.println(oneButton);
  Serial.print(led[0]);
  Serial.print("  ");
  Serial.print(led[1]);
  Serial.print("  ");
  Serial.println(led[2]);
  Serial.print(led[3]);
  Serial.print("  ");
  Serial.print(led[4]);
  Serial.print("  ");
  Serial.println(led[5]);
  Serial.print(led[6]);
  Serial.print("  ");
  Serial.print(led[7]);
  Serial.print("  ");
  Serial.println(led[8]);
  Serial.println();

}
