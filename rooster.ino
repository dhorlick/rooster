#define HWSERIAL Serial1

void setup()
{
  /**
  Thanks to Thunderstick Studios for helping me out with the serial protocol!

  Baud rate: 115200
  Data bit:8
  Parity bit: None
  Stop bit: 1
  */

  HWSERIAL.begin(115200, SERIAL_8N1);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
}

int incoming_byte;
int speed = 1;
int delta = 0;
int previous_button_press = 0;
int previous_reset_button = 0;
int previous_select_button = 0;

void loop()
{
  delta = 0;
  
  int bytes_available = HWSERIAL.available();

  for (int i=0; i < bytes_available; i++)
  {
    // Right: FF 00 00 01
    // Left: FF 00 00 FE
    
    incoming_byte = HWSERIAL.read();

    switch (incoming_byte)
    {
      case 0x01: // Right
        delta += speed;
        // Serial.println("Right");
        break;
      case 0xFE: // Left
        delta -= speed;
        // Serial.println("Left");
        break;
    }
  }

  if (delta != 0)
  {
    Mouse.move(delta, 0);
    // Serial.print("Moving mouse: ");
    // Serial.println(delta);
  }

  int button_press = !digitalRead(6);
  if (button_press != previous_button_press)
  {
    Mouse.set_buttons(button_press, 0, 0);
    previous_button_press = button_press;
    // Serial.print("Mouse button: ");
    // Serial.println(button_press);
  }

  int reset_button = !digitalRead(7);
  if (reset_button != previous_reset_button)
  {
    if (reset_button)
    {
      Keyboard.press(KEY_F2);
    }
    else
    {
      Keyboard.release(KEY_F2);
    }
    previous_reset_button = reset_button;
  }
  
  int select_button = !digitalRead(8);
  if (select_button != previous_select_button)
  {
    if (select_button)
    {
      Keyboard.press(KEY_F1);
    }
    else
    {
      Keyboard.release(KEY_F1);
    }
    previous_select_button = select_button;
  }

  delay(12);
}