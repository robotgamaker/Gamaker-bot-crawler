                                                                                     /*
  Cheetah 4.0 by
  Marcos Sanchez
     http://www.3dsolid.es
      & 
  
  Mr Q
    http://www.god-i.com
 

 * 
 */

// include the servo library
#include <Servo.h>
#include <SoftwareSerial.h>// import the serial library
SoftwareSerial Genotronex(A1,A2); // RX-> A2   ;  TX -> A1
const int pinBuzzer = A3;  // pin for buzzer(zumbador), posible incorporación futura
int lightningPin = A5;  //posible arma a incorporar en el futuro
int ledpin = A4; // led on A4
int BluetoothData; // the data given from the app smartphone

Servo BL1;  // create a servo object:  Cadera trasera izda


Servo BR1;  // create a servo object:  Cadera trasera izda


Servo FL1;  // create a servo object:  Hombro delantero izdo


Servo FR1;  // create a servo object:  Hombro delantero dcho


  
int d;  // delay corto
int dMedium; // delay mediano
int dLong;   //delay largo
int dPruebas;  //delay pruebas
int i;
int first;  // variable que se usara como booleana (0 o 1) para indicar si es la primera conexion BT

//  variables que cambiaran de valor con el tiempo/delays
long previousMillis = 0;  
unsigned long currentMillis = 0;

void setup() {

  pinMode(ledpin, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(lightningPin, OUTPUT);
  
  FR1.attach(2); // HOMBRO DCHO , se conecta al pin D2 del Arduino
  delay(dMedium);
  
  FL1.attach(3); // HOMBRO IZDO, se conecta al pin D3 del Arduino
  delay(dMedium);
   
  BR1.attach(4); // CADERA DCHA, se conecta al pin D4 del Arduino
  delay(dMedium);

  BL1.attach(5);  //CADERA IZDA, se conecta al pin D5 del Arduino
  delay(dMedium);   



 d=20;      ////delay corto
 dMedium = 100;
 dLong = 300;
 
 first=0;   // variable para recoger la primera conexion BlueTooth

dPruebas=300;    ///////////////////////////////////////////delay PRUEBAS

previousMillis = 0;  //  las variables de tiempo/retraso se inicializan a 0
currentMillis = 0;   //  las variables de tiempo/retraso se inicializan a 0

 
Genotronex.begin(9600);
Genotronex.flush();
 delay(100);

////   Wait in SETUP for first BT transmission    /////

while(!Genotronex.available())

{/*do nothing*/   }
  BluetoothData = Genotronex.read();
  delay(50);
//  full_Stop();
//delay(100);

   
}   ///// END SETUP



                              ////////////////////////////////////////////////////////////////////            ///////////////////////////////////////////////////////////////////
void loop() {                             //////////////////////////////// LOOP   ///////////////////  LOOP   ////////////////// LOOP ///////////////////////////////////////


     //  Pruebas iniciales antes de usar el control BT
     //full_Stop ();   //parada de todas las ruedas
     //delay(20);
     //wheelsForward () ;
    // delay(20);
    // wheelsRight ();
     //delay(20);
    // wheelsBack () ;
     //delay(20);


       //////////////////////////////////////////////////CODIGO DE CONTROL DE BLUETOOTH   ///////////////////////////////////////////////////////////////
while(Genotronex.available())
{
  //delay(30);
  
    if ((BluetoothData=='F')&&(first==1)){  // ADELANTE , a partir de la segunda lectura BT/// CON MARCHA DE ruedas  (en la primera lectura BT first pasa a ser 1; Se inicia a 0)
      //Genotronex.println(BluetoothData);
      //Genotronex.println("Bluetooth ON ! ");
        full_Stop();
        delay(d);
        wheelsForward () ;
        delay(200);
  }  // cierre if


  if ((BluetoothData=='f')&&(first==1)){                     // ADELANTE  ;  se filtra la primera orden BT que suele ser erronea
      //Serial.print(BluetoothData);
      //Genotronex.println("Bluetooth ON ! ");
      full_Stop();
      delay(d);
      wheelsForward () ;
      delay(100);     
     }


    if ((BluetoothData=='b')&&(first==1)){   //MARCHA ATRAS  300 ms
      full_Stop();
      delay(d);
      wheelsBack() ;
      delay(200);
  }  // cierre if

    if (((BluetoothData=='B'))&&(first==1)){    //MARCHA ATRAS durante 300 ms= 1segundo
      full_Stop();
      delay(d);
      wheelsBack () ;
      delay(300);
     }
   
    if (BluetoothData=='S'){    //  (señal de triangulo en app )  // Parada en posicion Base, posición felina
      full_Stop();
      delay(d);
     }

    if (BluetoothData=='X'){    //  (señal de triangulo en app )
      full_Stop();
      delay(d);
     }


    if ((BluetoothData=='i')&&(first==1)){    // adelante y a la derecha , primera flecha diagonal
        full_Stop();
        delay(d);
       wheelsRightSlow();
       delay(20);
       wheelsForward () ;
       delay(100); 
    }

    if ((BluetoothData=='I')&&(first==1)){    // adelante y a la dcha, segunda flecha diagonal
        full_Stop();
        delay(d);
       wheelsRight();
       delay(100);
       wheelsForward () ;
       delay(100); 
     }



    if((BluetoothData=='l')&&(first==1)){      ////// , GIRO LENTO IZDA
        full_Stop();
        delay(d);
       wheelsLeftSlow();
       //delay(20);   
     }


     if ((BluetoothData=='L')&&(first==1)){    //  (señal de triangulo en app )  giro a la izda
        full_Stop();
        delay(d);
       wheelsLeft();
       //delay(20);
       wheelsForward () ;
        //delay(200);
     }

      if ((BluetoothData=='r')&&(first==1)){        /////Giro a la DCHA
        full_Stop();
        delay(d);
       wheelsRightSlow();
       //delay(20);
     }


       if ((BluetoothData=='R')&&(first==1)){    //  (señal de triangulo en app ) //giro a la DCHA
        full_Stop();
        delay(d);
       wheelsRight();
       //delay(100);

     }
 

    if (((BluetoothData=='G')&&(first==1))){    //adelante y a la izda;  se filtra la primera orden BT que suele ser erronea
        full_Stop();
        delay(d);
       wheelsLeft();
       delay(20);
       wheelsForward () ;
       delay(100); 
     }

    if ((BluetoothData=='g')&&(first==1)){    //adelante y a la izda, girando en el sitio sobre sí mismo;  se filtra la primera orden BT que suele ser erronea
        full_Stop();
        delay(d);
       wheelsLeftSlow();
       delay(20);
       wheelsForward () ;
       delay(100); 
     }



   if (((BluetoothData=='J')&&(first==1))){
      //right_Back(30); 
      delay(300);       
   
     }

   if (((BluetoothData=='j')&&(first==1))){     
      //full_backRightTurn(20); 
      delay(300);     
     }


     
     
   if ((BluetoothData=='H')&&(first==1)){  
      //left_Back(30); 
      delay(300);     
  
     }

   if ((BluetoothData=='h')&&(first==1)){      
      //full_backLeftTurn(20); 
      delay(dLong);  
     }

     
    if ((BluetoothData=='W')||(BluetoothData=='w')){     //Front lights ON 
      wheelsForward () ;
      delay(300);
     // horizontal(70);    //  marcha tumbado con ruedas
      //delay(500);
     }



       if (BluetoothData=='v'){    ////HORN ON  claxon   vuelta a posicion estndar Boston
      full_Stop();
      delay(d);
     }


     if ((BluetoothData=='F')&&(first==0)){                     // primera señal de Bluetooth: `F` ADELANTE--->>> ignorarlo! 


     full_Stop();
      delay(d);
     }    
     
      first =1;    // Inicializa la variable first para empezar a recoger órdenes
      //delay(100);  

BluetoothData= Genotronex.read();   //al final recoge/lee de nuevo el mensaje Bluetooth
delay(100);


     
  } //cierre del:     while(Genotronex.available());   


    


 
}  ////////////////////////////////////////////// cierre del LOOP   ////////////////////////////////////////////////////////////////////


     ////////////////////////END LOOP////////////////////////////////////END  LOOP //////////////////////////////////////////////////////






//////////Funcion parar todas las ruedas del robot Crawl
void full_Stop()
{
  FR1.write(90);     // STOP wheel
    FL1.write(90);     // STOP wheel
      BR1.write(90);     // STOP wheel
        BL1.write(90);     // STOP wheel
}



     

int retraso(int r)       //////////////////////////////////////   FUNCION RETRASO para sustituir a la llamada a delay(r)     /////////////////////////////////////////////////////////////
{
  currentMillis = millis();    // Se toma el tiempo actual
  if (currentMillis - previousMillis > r){

// Si se cumple la condicion se guarda el nuevo tiempo
previousMillis = currentMillis;
return 1;
  }
  else return 0;
}





 void zumbido1()
 {
  //generar tono de 440Hz durante 1000 ms
  tone(pinBuzzer, 440);
  delay(1000);
 
  //detener tono durante 500ms  
  noTone(pinBuzzer);
  delay(500);
 
  //generar tono de 523Hz durante 500ms, y detenerlo durante 500ms.
  tone(pinBuzzer, 523, 300);
  delay(500);
}



 void zumbido2()
 {
  //detener tono durante 500ms  
  noTone(pinBuzzer);
  delay(500);
 
  //generar tono de 523Hz durante 500ms, y detenerlo durante 500ms.
  tone(pinBuzzer, 523, 300);
  delay(500);
}



 

void wheelsForward ()      ///////
{
int pos1 = 10;    // variable to store the servo position    HOMBRO DCHO   FR1
int pos2 = 170;    // variable to store the servo position   HOMBRO IZDO    FL1
int pos3 = 10;    // variable to store the servo position    CADERA DCHA    BR1
int pos4 = 170;    // variable to store the servo position   CADERA IZDA    BL1
  
 FR1.write(pos1); 
 BR1.write(pos3); 
  while((currentMillis - previousMillis) < dPruebas)    //  dPruebas=interval=delay=retraso     ////    OJO  :: este While equivale a delay(dPruebas);
  { 
     currentMillis = millis();    // Se toma el tiempo actual
     
    //check sensors and respond if necessary 
  }
FL1.write(pos2);
BL1.write(pos4);

  previousMillis = currentMillis;
  currentMillis = millis();    // Se toma el tiempo actual


     while((currentMillis - previousMillis) < dPruebas)    //  dPruebas=interval=delay=retraso      ////    OJO  :: este While equivale a delay(dPruebas);
    { 
        currentMillis = millis();    // Se toma el tiempo actual
        
        //check sensors and respond if necessary 
    }
  previousMillis = currentMillis;
  currentMillis = millis();    // Se toma el tiempo actual 
}



void wheelsLeft ()      ///////
{
int pos1 = 70;    // variable to store the servo position    HOMBRO DCHO   FR1
int pos2 = 150;    // variable to store the servo position   HOMBRO IZDO    FL1
int pos3 = 42;    // variable to store the servo position    CADERA DCHA    BR1
int pos4 = 155;    // variable to store the servo position   CADERA IZDA    BL1
  
 FR1.write(pos1); 
 BR1.write(pos3); 
  while((currentMillis - previousMillis) < dPruebas)    //  dPruebas=interval=delay=retraso     ////    OJO  :: este While equivale a delay(dPruebas);
  { 
     currentMillis = millis();    // Se toma el tiempo actual
     
    //check sensors and respond if necessary 
  }

  previousMillis = currentMillis;
  currentMillis = millis();    // Se toma el tiempo actual 
}


void wheelsLeftSlow ()      ///////
{
int pos1 = 35;    // variable to store the servo position    HOMBRO DCHO   FR1
int pos2 = 130;    // variable to store the servo position   HOMBRO IZDO    FL1
int pos3 = 32;    // variable to store the servo position    CADERA DCHA    BR1
int pos4 = 130;    // variable to store the servo position   CADERA IZDA    BL1
  
 FR1.write(pos1); 
 BR1.write(pos3); 

  while((currentMillis - previousMillis) < dPruebas)    //  dPruebas=interval=delay=retraso     ////    OJO  :: este While equivale a delay(dPruebas);
  { 
     currentMillis = millis();    // Se toma el tiempo actual
     
    //check sensors and respond if necessary 
  }

  previousMillis = currentMillis;
  currentMillis = millis();    // Se toma el tiempo actual 
  FL1.write(pos2); 
  BL1.write(pos4); 

     while((currentMillis - previousMillis) < dPruebas)    //  dPruebas=interval=delay=retraso      ////    OJO  :: este While equivale a delay(dPruebas);
    { 
        currentMillis = millis();    // Se toma el tiempo actual
        
        //check sensors and respond if necessary 
    }
  previousMillis = currentMillis;
  currentMillis = millis();    // Se toma el tiempo actual 
}



void wheelsRight ()      ///////
{
int pos1 = 65;    // variable to store the servo position    HOMBRO DCHO   FR1
int pos2 = 160;    // variable to store the servo position   HOMBRO IZDO    FL1
int pos3 = 65;    // variable to store the servo position    CADERA DCHA    BR1
int pos4 = 165;    // variable to store the servo position   CADERA IZDA    BL1
  
 FL1.write(pos2); 
 BL1.write(pos4); 

  while((currentMillis - previousMillis) < dPruebas)    //  dPruebas=interval=delay=retraso     ////    OJO  :: este While equivale a delay(dPruebas);
  { 
     currentMillis = millis();    // Se toma el tiempo actual
     
    //check sensors and respond if necessary 
  }

  previousMillis = currentMillis;
  currentMillis = millis();    // Se toma el tiempo actual 
   FR1.write(pos1); 
   BR1.write(pos3); 

     while((currentMillis - previousMillis) < dPruebas)    //  dPruebas=interval=delay=retraso      ////    OJO  :: este While equivale a delay(dPruebas);
    { 
        currentMillis = millis();    // Se toma el tiempo actual
        
        //check sensors and respond if necessary 
    }
  previousMillis = currentMillis;
  currentMillis = millis();    // Se toma el tiempo actual 
}



void wheelsRightSlow ()      ///////
{
int pos1 = 60;    // variable to store the servo position    HOMBRO DCHO   FR1
int pos2 = 150;    // variable to store the servo position   HOMBRO IZDO    FL1
int pos3 = 58;    // variable to store the servo position    CADERA DCHA    BR1
int pos4 = 155;    // variable to store the servo position   CADERA IZDA    BL1
  
 FL1.write(pos2); 
 BL1.write(pos4); 

  while((currentMillis - previousMillis) < dPruebas)    //  dPruebas=interval=delay=retraso     ////    OJO  :: este While equivale a delay(dPruebas);
  { 
     currentMillis = millis();    // Se toma el tiempo actual
     
    //check sensors and respond if necessary 
  }

  previousMillis = currentMillis;
  currentMillis = millis();    // Se toma el tiempo actual 
   FR1.write(pos1); 
   BR1.write(pos3); 

     while((currentMillis - previousMillis) < dPruebas)    //  dPruebas=interval=delay=retraso      ////    OJO  :: este While equivale a delay(dPruebas);
    { 
        currentMillis = millis();    // Se toma el tiempo actual
        
        //check sensors and respond if necessary 
    }
  previousMillis = currentMillis;
  currentMillis = millis();    // Se toma el tiempo actual 
}


void wheelsBack ()      ///////FUNCION PARA QUE DE 1 PASO GIRANDO HACIA DELANTE solo con caderas
{
int pos1 = 140;    // variable to store the servo position    HOMBRO DCHO   FR1
int pos2 = 50;    // variable to store the servo position   HOMBRO IZDO    FL1
int pos3 = 140;    // variable to store the servo position    CADERA DCHA    BR1
int pos4 = 50;    // variable to store the servo position   CADERA IZDA    BL1
  
 FR1.write(pos1); 
 BR1.write(pos3); 
  while((currentMillis - previousMillis) < dPruebas)    //  dPruebas=interval=delay=retraso     ////    OJO  :: este While equivale a delay(dPruebas);
  { 
     currentMillis = millis();    // Se toma el tiempo actual
     
    //check sensors and respond if necessary 
  }
FL1.write(pos2);
BL1.write(pos4);

  previousMillis = currentMillis;
  currentMillis = millis();    // Se toma el tiempo actual
    previousMillis = currentMillis;
  currentMillis = millis();    // Se toma el tiempo actual

     while((currentMillis - previousMillis) < dPruebas)    //  dPruebas=interval=delay=retraso      ////    OJO  :: este While equivale a delay(dPruebas);
    { 
        currentMillis = millis();    // Se toma el tiempo actual
        
        //check sensors and respond if necessary 
    }
  previousMillis = currentMillis;
  currentMillis = millis();    // Se toma el tiempo actual 
}


void setSpeedMotors(int pos1, int pos2, int pos3, int pos4)      /////// pos1: hombro dcho FR1 ;  pos2: hombro izdo FL1 ;   pos3: cadera dcha BR1;  pos4:c adera izda BL1 
{
                                                               // Referencia adelante: int pos1 = 50; HOMBRO DCHO   FR1   int pos2 = 130;//    HOMBRO IZDO    FL1   // int pos3 = 50;   CADERA DCHA BR1 //  int pos4 = 130; CADERA IZDA    BL1

                                                                                          
 FR1.write(pos1); 
 BR1.write(pos3); 
  while((currentMillis - previousMillis) < dPruebas)    //  dPruebas=interval=delay=retraso     ////    OJO  :: este While equivale a delay(dPruebas);
  { 
     currentMillis = millis();    // Se toma el tiempo actual
     
    //check sensors and respond if necessary 
  }
FL1.write(pos2);
BL1.write(pos4);

  previousMillis = currentMillis;
  currentMillis = millis();    // Se toma el tiempo actual
    previousMillis = currentMillis;
  currentMillis = millis();    // Se toma el tiempo actual

     while((currentMillis - previousMillis) < dPruebas)    //  dPruebas=interval=delay=retraso      ////    OJO  :: este While equivale a delay(dPruebas);
    { 
        currentMillis = millis();    // Se toma el tiempo actual
        
        //check sensors and respond if necessary 
    }
  previousMillis = currentMillis;
  currentMillis = millis();    // Se toma el tiempo actual 
}
