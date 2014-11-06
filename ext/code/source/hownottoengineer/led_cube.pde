//////////////////
//LED CUBE CLASS//
//////////////////

//HEADER
class LED_CUBE{
  public:
    LED_CUBE();
    void clear_cube(void);
    void send_data(char data);
    void fill_layer(char data[], int layer);
    void fill_cube(char data[]);
    void latch(void);
    char flip(char input);
  private:
    int LE, SDI, CLK; 
};

//CONSTRUCTOR
LED_CUBE::LED_CUBE(){
  LE = 2;
  SDI = 3;
  CLK = 5;
  pinMode(LE, OUTPUT);
  pinMode(SDI, OUTPUT);
  pinMode(CLK, OUTPUT);
  digitalWrite(LE, LOW);
  digitalWrite(SDI, LOW);
  digitalWrite(CLK, LOW);
}


//TURN OFF ENTIRE CUBE
void LED_CUBE::clear_cube(void){
   for(int i = 0; i < 10; i++){
     send_data(0x00);  
   }
   latch();
   digitalWrite(SDI, LOW);
   digitalWrite(CLK, LOW);
}

//SEND CUBE BYTE
void LED_CUBE::send_data(char data){
  for(int i = 0; i < 8; i++){
     if(data & 0x01<<i){
       digitalWrite(SDI, HIGH);
     }
     digitalWrite(CLK, HIGH);
     digitalWrite(SDI,LOW);
     digitalWrite(CLK,LOW);  
   }  
}

//SEND 8 CUBE BYTES
void LED_CUBE::fill_layer(char data[], int layer){
  send_data(0x01<<(layer-1));
  send_data(0x00);
  for(int j = (8*layer)-1; j >= 0+8*(layer-1); j--){
    //flip every second byte, if you wired it correctly 
    //this should not be required
    if(j%2 == 0){
      send_data(data[j]);
    }else{
      send_data(flip(data[j]));
    }  
  }
  latch();
}

//FILL ENTIRE CUBE WITH 64 BYTES
void LED_CUBE::fill_cube(char data[]){
  for(int layer = 1; layer < 9; layer++){
    fill_layer(data, layer);
  }
}

//SEND LATCH COMMAND
void LED_CUBE::latch(void){
   digitalWrite(LE,HIGH);
   digitalWrite(LE,LOW);    
}

//FLIP BYTE
char LED_CUBE::flip(char input){
  char output = 0x00;
  for(int i = 7; i >= 0; i--){
    if(input & 0x01<<i){
      output = output | 0x01<<(7-i); 
    }
  }
  return output;
}

///////////////////
//     MAIN     //
//////////////////
LED_CUBE LC;

char raw_data[67] = {0x00};
int data_count = 0;
int no_op_count = 0;
  
void setup(void){
  Serial.begin(256000);
  LC.clear_cube(); 
}

void loop(void){  
  if(Serial.available()){
    no_op_count = 0;
    raw_data[data_count] = Serial.read();
    data_count++;    
  }
  
  //check to see if the "end" message has been received and send data to cube
 if(raw_data[64] == 'e' && raw_data[65] == 'n' && raw_data[66] == 'd'){
    LC.fill_cube(raw_data);
    data_count = 0;
    memset(raw_data, 0x00, 67);
 }
 
 //this resets the cube and data arrays if there is a large delay or if the received data 
 //array is full and does not include the "end" message
 if(data_count > 66 || no_op_count > 200){
   memset(raw_data, 0x00, 67);
   data_count = 0;
   LC.clear_cube();
   no_op_count = 0;  
 }
 
 no_op_count++;
}
