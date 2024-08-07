// C++ code
//
#include <Adafruit_LiquidCrystal.h>

int flex_sensor = 0;

int flex2 = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  lcd_1.begin(16, 2);
}

void loop()
{
  flex_sensor = analogRead(A0);
  flex2 = analogRead(A1);
  Serial.println(flex_sensor);
  Serial.print(flex2);
  lcd_1.setCursor(0, 0);
  lcd_1.print("Sign Language.  ");
  if (flex_sensor < 150 && flex2 < 150) {
    if (flex_sensor < 90 && flex2 < 90) {
      lcd_1.setCursor(0, 1);
      lcd_1.print("Message 5.       ");
    } else {
      lcd_1.setCursor(0, 1);
      lcd_1.print("Message 6.           ");
    }
  } else {
    if (flex_sensor < 150 && flex2 > 150) {
      if (flex_sensor < 90) {
        lcd_1.setCursor(0, 1);
        lcd_1.print("messagwe 1                                  ");
      } else {
        lcd_1.setCursor(0, 1);
        lcd_1.print("Message 3.       ");
      }
    } else {
      if (flex_sensor > 150 && flex2 < 150) {
        if (flex2 < 90) {
          lcd_1.setCursor(0, 1);
          lcd_1.print("message 2.                                       ");
        } else {
          lcd_1.setCursor(0, 1);
          lcd_1.print("Message 4          ");
        }
      } else {
        lcd_1.setCursor(0, 1);
        lcd_1.print("no sign language.     ");
      }
    }
  }
  delay(10); // Delay a little bit to improve simulation performance
}
