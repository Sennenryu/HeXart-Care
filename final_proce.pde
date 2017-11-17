//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;

void setup() {
  udSerial = new Serial(this, "COM3", 9600);
  output = createWriter ("Battements.csv");
}

  void draw() {
    if (udSerial.available() > 0) {
      
      String SenVal = udSerial.readStringUntil('\n');
      
      if (SenVal != null) {
        output.print(SenVal);
      }
    }
    
    if (udSerial.available() > 0) {
      
      String Val = udSerial.readStringUntil('\n');
      
      if (Val != null) {
        output.println(Val);
      }
    }
  }

  void keyPressed(){
    output.flush();
    output.close();
    exit(); 
  }