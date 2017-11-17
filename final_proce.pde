//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;

void setup() {
  udSerial = new Serial(this, "COM3", 9600);//set serial port and frequency
  output = createWriter ("Battements.csv");//create a new file
}

  void draw() {
    if (udSerial.available() > 0) {//if data available
      
      String SenVal = udSerial.readStringUntil('\n');//read until end of string
      
      if (SenVal != null) {
        output.print(SenVal);//print in file
      }
    }
    
    if (udSerial.available() > 0) {
      
      String Val = udSerial.readStringUntil('\n');
      
      if (Val != null) {
        output.println(Val);//print in file, and return
      }
    }
  }

  void keyPressed(){//if keypressed
    output.flush();//clear var
    output.close();//close files
    exit(); //exit prog
  }
