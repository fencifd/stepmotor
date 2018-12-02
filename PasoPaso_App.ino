//******************************************************************************
//------------------------- www.electroingenio.com -----------------------------
//******************************************************************************
//***************************    PROGRAMED BY   ********************************
//**************************** MAURICIO HIDALGO ********************************
//******************************************************************************


#define pin1  8//these are the Arduino pins that we use to activate coils 1-4 of the stepper motor
#define pin2  9
#define pin3  10
#define pin4  11
#define delaytime 2   //delay time in ms to control the stepper motor delaytime.
                      //Our tests showed that 8 is about the fastest that can yield reliable operation w/o missing steps

char unChar;
String readString; //Asignamos la palabra readString a una variable tipo cadena
float numberOfSteps = 0;
int datoserial = 0;

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT); 
  pinMode(pin3, OUTPUT); 
  pinMode(pin4, OUTPUT);
  Serial.begin(9600); //initialize serial comunication
}

void loop() {
  while (Serial.available()) { //Se verifica la disponibilidad del puero serial 
    delay(3);                  // a traves de un loop
    char c = Serial.read();  // Se leen los caracteres que ingresan por el puerto
    readString += c;         //se acumulan cada uno de los caracteres en readString
  }
 
  if (readString.length() >0) { //Se verifica que la variable contenga informacion
  
   Serial.println(readString.toInt());  //se envia lo que tenga la variable
    datoserial = readString.toInt();
    
  }
  while(datoserial>numberOfSteps){
             
         backward();
         delayMicroseconds(40);
         numberOfSteps = numberOfSteps + 1;
    
  }
 while(datoserial<numberOfSteps){
         
          forward();
          delayMicroseconds(40);
          numberOfSteps = numberOfSteps - 1;
    
  }
  
  if (readString == "SET"){
    numberOfSteps = 0;
    datoserial = 0;
    }
 
  readString=""; // Se limpia la variable
}




