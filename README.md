# Send a push notification with your ESP8266
Register to https://ifttt.com/ and install the app on your phone or tablet.<br />
Create a new Recipe choose from the trigger channel MAKER.<br />
Write down the Event Name and the Key from your Maker recipe.<br /><br />
Configure your Maker Recipe in the script.<br />
--const char* Key = "Maker-Key"; // Your Maker Channel Key<br />
--const char* Event = "Maker-Event-name"; // Your Maker Channel Event Name<br /><br />
Configure your wifi network here:<br />
-const char* ssid     = "Your-ssid"; // Your ssid<br />
-const char* password = "Your-Password"; // Your Password<br /><br />
Connecting the ESP8266 see below.<br />
Pin 1 GND to GROUND.<br />
Pin 2 GPIO2 to push button other side of the button to the ground.(internal pull_up used).<br />
Pin 3 GPIO0 program mode connect to GND in program mode.<br />
Pin 4 RXD program mode connect to TXD FTDI USB.<br />
Pin 5 TXD program mode connect to RXD FTDI USB.<br />
Pin 6 CH_PD connect to 3.3volt MAX!!.<br />
Pin 7 Reset not used in this project.<br />
Pin 8 VCC 3.3volt MAX!!.<br /><br />
<img src="http://dblayer.nl/github/images/ESP-IFTTT-button-1.png" alt="ESP8266"><br />
