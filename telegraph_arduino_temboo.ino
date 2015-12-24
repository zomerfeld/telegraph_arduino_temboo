#include <Bridge.h>
#include <Temboo.h>
#include "TembooAccount.h" // Contains Temboo account information   

//text settings
int numRuns = 1;   // Execution count, so this doesn't run forever
int maxRuns = 10;   // Maximum number of times the Choreo should be executed
uint32_t lastChoreoRunTime = 0; // store the time of the last Choreo execution
String message;
String last_message;
int temboo_delay = 30000; //delay in milliseconds. 
//text settings

//Telegraph Settings
int relay = 2; //Relay pin
int clickLength = 100; //click length
int minDelay = 500; // wait between clicks
int pause = 2000; //wait between groups of clicks
int letterDelay = 3000; //wait between letters

//Telegraph Settings

//Dictionary
// this code works with only short click, the ABC encoded into a 3 dimensinal cube
// See the decoding page on this link - https://goo.gl/vLjSI7

int A[] = {1, 1, 1};
int B[] = {1, 1, 2};
int C[] = {1, 1, 3};
int D[] = {1, 2, 1};
int E[] = {1, 2, 2};
int F[] = {1, 2, 3};
int G[] = {1, 3, 1};
int H[] = {1, 3, 2};
int I[] = {1, 3, 3};

int J[] = {2, 1, 1};
int K[] = {2, 1, 2};
int L[] = {2, 1, 3};
int M[] = {2, 2, 1};
int N[] = {2, 2, 2};
int O[] = {2, 2, 3};
int P[] = {2, 3, 1};
int R[] = {2, 3, 2};
int S[] = {2, 3, 3};

int T[] = {3, 1, 1};
int U[] = {3, 1, 2};
int V[] = {3, 1, 3};
int W[] = {3, 2, 1};
int X[] = {3, 2, 2};
int Y[] = {3, 2, 3};
int Z[] = {3, 3, 1};
int dot[] = {3, 3, 2};
int smiley[] = {3, 3, 3};
//Dictionary

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);

  // For debugging, wait until the serial console is connected
  //delay(4000);
  //  while (!Serial);
  Bridge.begin();
}

void loop() {
  if (numRuns <= maxRuns) {
    Serial.println("Running GetMessagesThatContain - Run #" + String(numRuns++));

    TembooChoreo GetMessagesThatContainChoreo; 
    //configure this at the Temboo.com site at https://temboo.com/library/Library/Twilio/SMSMessages/GetLastMessageThatContains/

    // Invoke the Temboo client
    GetMessagesThatContainChoreo.begin();  

    // Set Temboo account credentials
    GetMessagesThatContainChoreo.setAccountName(TEMBOO_ACCOUNT);
    GetMessagesThatContainChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
    GetMessagesThatContainChoreo.setAppKey(TEMBOO_APP_KEY);
    //defined on TembooAccount.h

    // Set profile to use for execution
    GetMessagesThatContainChoreo.setProfile("TwilioAccount");

    // Set Choreo inputs
    GetMessagesThatContainChoreo.addInput("Filter", "elegraph");
    GetMessagesThatContainChoreo.addInput("Page", "0");
    GetMessagesThatContainChoreo.addInput("PageSize", "1");


    // Identify the Choreo to run
    GetMessagesThatContainChoreo.setChoreo("/Library/Twilio/SMSMessages/GetMessagesThatContain");

    // Run the Choreo; when results are available, print them to serial
    GetMessagesThatContainChoreo.run();

    while (GetMessagesThatContainChoreo.available()) {
      // read the name of the next output item
      String name = GetMessagesThatContainChoreo.readStringUntil('\x1F');
      name.trim(); // use “trim” to get rid of newlines


      // read the value of the next output item
      String data = GetMessagesThatContainChoreo.readStringUntil('\x22\x5d');
      data.trim(); // use “trim” to get rid of newlines
      data.remove(0, 12); 
      //Ignores the first character, sanitizes and looking for the filter I have set up "elegraph"
      data.remove(data.length() - 1, 1); 
      if (name == "Response") {
        Serial.println("The response is " + data);
        message = data;
        message.toLowerCase();

      }
      /*Print the full response *
           char c = GetMessagesThatContainChoreo.read();
           Serial.print(c);
           */
    }
    GetMessagesThatContainChoreo.close();
  }


  if (message == last_message) { //do nothing if the message is exactly the same as before
    Serial.println("messages are the same");
  } else {
    Serial.println("new message");
    last_message = message; //save the last message
    telegraph('*'); //trigger the handshake signal 
    for (int i = 0; i < message.length(); i++) { //run through the characters in the message
      telegraph(message[i]);
    }
    telegraph('*'); // trigger the handshake signal



  }
    Serial.println("Waiting...");
    delay(temboo_delay); // wait X seconds between GetMessagesThatContain calls
}

void telegraph(char incomingByte) {
  Serial.println(incomingByte);
  switch (incomingByte) {
    case 'a':
      letter(A);
      break;
    case 'b':
      letter(B);
      break;
    case 'c':
      letter(C);
      break;
    case 'd':
      letter(D);
      break;
    case 'e':
      letter(E);
      break;
    case 'f':
      letter(F);
      break;
    case 'g':
      letter(G);
      break;
    case 'h':
      letter(H);
      break;
    case 'i':
      letter(I);
      break;
    case 'j':
      letter(J);
      break;
    case 'k':
      letter(K);
      break;
    case 'l':
      letter(L);
      break;
    case 'm':
      letter(M);
      break;
    case 'n':
      letter(N);
      break;
    case 'o':
      letter(O);
      break;
    case 'p':
      letter(P);
      break;
    case 'q':
      letter(K);
      break;
    case 'r':
      letter(R);
      break;
    case 's':
      letter(S);
      break;
    case 't':
      letter(T);
      break;
    case 'u':
      letter(U);
      break;
    case 'v':
      letter(V);
      break;
    case 'w':
      letter(W);
      break;
    case 'x':
      letter(X);
      break;
    case 'y':
      letter(Y);
      break;
    case 'z':
      letter(Z);
      break;
    case '.':
      letter(dot);
      break;
    case '*':
      //Secret Handshake
      digitalWrite(relay, HIGH);
      delay(200);
      digitalWrite(relay, LOW);
      delay(100);

      digitalWrite(relay, HIGH);
      delay(clickLength);
      digitalWrite(relay, LOW);
      delay(50);

      digitalWrite(relay, HIGH);
      delay(clickLength);
      digitalWrite(relay, LOW);
      delay(50);

      digitalWrite(relay, HIGH);
      delay(200);
      digitalWrite(relay, LOW);
      delay(100);

      digitalWrite(relay, HIGH);
      delay(200);
      digitalWrite(relay, LOW);
      delay(300);

      digitalWrite(relay, HIGH);
      delay(200);
      digitalWrite(relay, LOW);
      delay(100);

      digitalWrite(relay, HIGH);
      delay(300);
      digitalWrite(relay, LOW);
      delay(50);
    default:
      delay(letterDelay);
      break;
  }
}

void letter(int letX[]) {
  for (int p = 0 ; p < 3; p++) {
    for (int i = 0; i < letX[p];  i++) {
      digitalWrite(relay, HIGH);
      delay(clickLength);
      digitalWrite(relay, LOW);
      delay(minDelay);
    }
    delay(pause);

  }

}


