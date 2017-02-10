int Shift_UpIn = 2;
int Shift_DownIn = 3;
int Up_ShiftTime = 4;
int Down_ShiftTime = 5;
int Shift_UpOut = 6;
int Shift_DownOut = 7;
int time1;
int time2;
int ShiftTime;
int yoyo{};
int yoyo1{};
int prev_yoyo1 = 1;
int prev_yoyo = 1;

void setup()
{
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  shift_up_check();

  shift_down_check(); 

  auto_shifter();
  
}

void shift_up_check()
{
  //läs av upväxlingsPin 
  yoyo = digitalRead(Shift_UpIn);
  
  if (yoyo == HIGH)
  {
   prev_yoyo = yoyo;
   return;
  }
  delay(500);

  if (yoyo == LOW && prev_yoyo == HIGH)
  {
   prev_yoyo = yoyo;
   
   digitalWrite(Shift_UpOut, HIGH);
   
   time1 = millis();

   while(digitalRead(Up_ShiftTime) == HIGH)
   {
  
   }
   time2 = millis();
   //tiden då signal från knapptryck når arduino minus tiden då signal att växla ner skickades ut
   ShiftTime = time2 - time1;
   
   Serial.println(ShiftTime);
   
   delay(500);
   
   digitalWrite(Shift_UpOut, LOW);
  }
}

void shift_down_check()
{
  yoyo1 = digitalRead(Shift_DownIn);
  
  if (yoyo1 == HIGH) 
  {
    prev_yoyo1 = yoyo1;
    return;
  }

  delay(500);

  if (yoyo1 == LOW && prev_yoyo1 == HIGH) 
  {
    prev_yoyo1 = yoyo1;
    
   digitalWrite(Shift_DownOut, HIGH);
   
   time1 = millis();
    //väntar på knapptrycket
   while(digitalRead(Down_ShiftTime) == HIGH)
   { 
    
   }
   time2 = millis();
   //tiden då signal från knapptryck når arduino minus tiden då signal att växla ner skickades ut
   ShiftTime= time2 - time1;
   
   Serial.println(ShiftTime);
   
   delay(500);
   
   digitalWrite(Shift_DownOut, LOW);
  }
}

void auto_shifter(){
  
  digitalWrite(Shift_UpOut, HIGH);
  
  delay(500);
  
  digitalWrite(Shift_UpOut, LOW);
  
  delay(500);

  digitalWrite(Shift_DownOut, HIGH);
  
  delay(500);

  digitalWrite(Shift_DownOut, LOW);

  delay(500);
}

