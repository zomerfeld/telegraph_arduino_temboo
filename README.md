###### telegraph_arduino_temboo
#Arduino Telegraph - Code System project from Systems class @CCA
![alt tag](https://s3-us-west-1.amazonaws.com/systems-noam/images/systems/IMG_0020.JPG)

###YouTube Videos
[Final Demo 1](https://youtu.be/Q5agbIDerKQ)

[Final Demo 2](https://youtu.be/oKgJvz0VeJY)

[Early Prototype](https://youtu.be/BHRiO0pCflk) (no SMS, just serial control)


###The Project
In our Systems design class at California College of the Arts (taught by Hugh Dubberly) we were trying to understand communication systems by building one of our own. We were abstracting each of the processes and layers, diagramming and visualizing.
The first step in learning this was to build a communication device - a basic telegraph made out of a wooden board, a nail, wire and two batteries. 

![alt tag](https://s3-us-west-1.amazonaws.com/systems-noam/images/systems/IMG_8545.jpg)

The second step was the creation of a code (which isn't Morse code) to which we'll encode our messages to send them to each other. The code I used was built as a sort of three-dimensional cube created together with my classmate Danielle Forward. 


###Key
![alt tag](https://s3-us-west-1.amazonaws.com/systems-noam/images/systems/Revised_Code_Danielle_Noam.png)

After testing the codes we made, we were asked to improve the input or the output of this basic telegraph to allow for easier & faster communication.
I wanted to remove knowing the code we dev of the code as a prerequisite to sending a message so I connected the circuit through an Arduino controlled relay and created a code that encodes strings to the series of clicks representing the message in the code system created earlier.
That worked ok for the class but for our yearly show I wanted it to be wireless, accessible to visitors and also opaque - de-emphasize the technology enabling it as it wasn't the emphasis for the show.

Hence the Text-to-Telegraph integration:
######SMS -> twilio -> Temboo -> Arduino Yun ->  Telegraph.

![alt tag](https://s3-us-west-1.amazonaws.com/systems-noam/images/systems/IMG_0020.JPG)


One visitor texts a message to a twilio number, the Arduino runs a Temboo call every 10 seconds to check the message queue for a message that begins with the word "telegraph" and if it's different than the last message it transcodes each letter to its corresponding series of clicks in the code we devised, bookended with an initialization sound (Shave and a Haircut).


![alt tag](https://s3-us-west-1.amazonaws.com/systems-noam/images/systems/IMG_0187.JPG)
![alt tag](https://s3-us-west-1.amazonaws.com/systems-noam/images/systems/vlcsnap-00002.jpg)

The second visitor listens to the clicks and transcribes the message back to English.
![alt tag](https://s3-us-west-1.amazonaws.com/systems-noam/images/systems/IMG_0167.JPG)






