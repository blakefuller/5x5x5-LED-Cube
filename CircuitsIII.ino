int layer[5]={A7,A6,A5,A4,A3};
int column[25]={46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22};
int inputs[3]={A2,A1,A0};

void setup() 
{
  for(int i = 0; i<25; i++)   
  {
    pinMode(column[i], OUTPUT);  //setting columns to ouput
  }
  
  for(int i = 0; i<5; i++)
  {
    pinMode(layer[i], OUTPUT);  //setting layers to output
  }

  for(int i = 0; i<3; i++)
  {
    pinMode(inputs[i], INPUT);  //setting inputs to input
  }
}

void loop()
{
  //delay(75);
  int state = checkInput();
  switch(state)
  {
    case 0:
    {
      turnEverythingOff();
      break;
    }
    case 1:
    {
      left2Right();
      break;
    }
    case 2:
    {
      frontToBack();
      break;
    }
    case 3:
    {
      right2Left();
      break;
    }
    case 4:
    {
      for(int i = 0; i < 25; i++)
      {
        digitalWrite(column[i], 0);
      }
      topToBottom();
      break;
    }
    case 5:
    {
      for(int i = 0; i < 25; i++)
      {
        digitalWrite(column[i], 0);
      }
      bottomToTop();
      break;
    }
    case 6:
    {
      backToFront();
      break;
    }
    case 7:
    {
      randomflicker();
      break;
    }
    default:
    {
      turnEverythingOn();
      break;
    }
  }
}

//check input state
int checkInput()
{
  int one = digitalRead(A0);    //10kHz input
  int two = digitalRead(A1);    //17kHz input
  int three = digitalRead(A2);  //25kHz input

  if(one == LOW && two == LOW && three == LOW)
  {
    return 0;
  }
  if(one == HIGH && two == LOW && three == LOW)
  {
    return 1;
  }
  if(one == LOW && two == HIGH && three == LOW)
  {
    return 2;
  }
  if(one == LOW && two == LOW && three == HIGH)
  {
    return 3;
  }
  if(one == HIGH && two == HIGH && three == LOW)
  {
    return 4;
  }
  if(one == LOW && two == HIGH && three == HIGH)
  {
    return 5;
  }
  if(one == HIGH && two == LOW && three == HIGH)
  {
    return 6;
  }
  if(one == HIGH && two == HIGH && three == HIGH)
  {
    return 7;
  }
}

//random flicker
void randomflicker()
{
  int x = 50;
  for(int i = 0; i !=50; i+=2)
  {
  int randomLayer = random(0,5);
  int randomColumn = random(0,25);
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(layer[i],1);
  }
  for(int j = 0; j < 25; j++)
  {
    digitalWrite(column[j],0);
  }

  digitalWrite(column[randomColumn], 1);
  delay(x);

  digitalWrite(column[randomColumn], 0);
  delay(x); 
  }
}

//turn all on
void turnEverythingOn()
{
  //columns
  for(int i = 0; i < 25; i++)
  {
    digitalWrite(column[i], 0);
  }
  //layers
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(layer[i], 1);
  }
}

//turn all off
void turnEverythingOff()
{
  //turning on columns
  for(int i = 0; i < 25; i++)
  {
    digitalWrite(column[i], 1);
  }
  //turning off layers
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(layer[i], 0);
  }
}

//turn columns off
void turnColumnsOff()
{
  for(int i = 0; i < 25; i++)
  {
    digitalWrite(column[i], 1);
  }
}

//turn on layers bottom to top
void bottomToTop()
{
  int x = 50;
  digitalWrite(layer[4], 1);
  delay(x);
  digitalWrite(layer[0], 0);
  delay(x);
  digitalWrite(layer[3], 1);
  delay(x);
  digitalWrite(layer[4], 0);
  delay(x);
  digitalWrite(layer[2], 1);
  delay(x);
  digitalWrite(layer[3], 0);
  delay(x);
  digitalWrite(layer[1], 1);
  delay(x);
  digitalWrite(layer[2], 0);
  delay(x);
  digitalWrite(layer[0], 1);
  delay(x);
  digitalWrite(layer[1], 0);
  delay(x);
}

//turn on layers top to bottom
void topToBottom()
{
  int x = 50;
  digitalWrite(layer[0], 1);
  delay(x);
  digitalWrite(layer[4], 0);
  delay(x);
  digitalWrite(layer[1], 1);
  delay(x);
  digitalWrite(layer[0], 0);
  delay(x);
  digitalWrite(layer[2], 1);
  delay(x);
  digitalWrite(layer[1], 0);
  delay(x);
  digitalWrite(layer[3], 1);
  delay(x);
  digitalWrite(layer[2], 0);
  delay(x);
  digitalWrite(layer[4], 1);
  delay(x);
  digitalWrite(layer[3], 0);
  delay(x);
}

//flow left to right
void left2Right()
{
  int x = 50;
  turnEverythingOff();
  //turn layers on
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(layer[i], 1);
  }
  //first side on
  digitalWrite(column[24], 0);
  digitalWrite(column[19], 0);
  digitalWrite(column[14], 0);
  digitalWrite(column[9], 0);
  digitalWrite(column[4], 0);
  delay(x);
  //second side on
  digitalWrite(column[23], 0);
  digitalWrite(column[18], 0);
  digitalWrite(column[13], 0);
  digitalWrite(column[8], 0);
  digitalWrite(column[3], 0);
  delay(x);
  //first side off
  digitalWrite(column[24], 1);
  digitalWrite(column[19], 1);
  digitalWrite(column[14], 1);
  digitalWrite(column[9], 1);
  digitalWrite(column[4], 1);
  delay(x);
  //third side on
  digitalWrite(column[22], 0);
  digitalWrite(column[17], 0);
  digitalWrite(column[12], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[2], 0);
  delay(x);
  //second side off
  digitalWrite(column[23], 1);
  digitalWrite(column[18], 1);
  digitalWrite(column[13], 1);
  digitalWrite(column[8], 1);
  digitalWrite(column[3], 1);
  delay(x);
  //fourth side on
  digitalWrite(column[21], 0);
  digitalWrite(column[16], 0);
  digitalWrite(column[11], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[1], 0);
  delay(x);
  //third side off
  digitalWrite(column[22], 1);
  digitalWrite(column[17], 1);
  digitalWrite(column[12], 1);
  digitalWrite(column[7], 1);
  digitalWrite(column[2], 1);
  delay(x);
  //fifth side on
  digitalWrite(column[20], 0);
  digitalWrite(column[15], 0);
  digitalWrite(column[10], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[0], 0);
  delay(x);
  //fourth side off
  digitalWrite(column[21], 1);
  digitalWrite(column[16], 1);
  digitalWrite(column[11], 1);
  digitalWrite(column[6], 1);
  digitalWrite(column[1], 1);
  delay(x);
  //first side on
  digitalWrite(column[24], 0);
  digitalWrite(column[19], 0);
  digitalWrite(column[14], 0);
  digitalWrite(column[9], 0);
  digitalWrite(column[4], 0);
  delay(x);
  //fifth side off
  digitalWrite(column[20], 1);
  digitalWrite(column[15], 1);
  digitalWrite(column[10], 1);
  digitalWrite(column[5], 1);
  digitalWrite(column[0], 1);
  delay(x);
}

//flow right to left
void right2Left()
{
  int x = 50;
  turnEverythingOff();
  //turn layers on
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(layer[i], 1);
  }
  //fifth side on
  digitalWrite(column[20], 0);
  digitalWrite(column[15], 0);
  digitalWrite(column[10], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[0], 0);
  delay(x);
  //fourth side on
  digitalWrite(column[21], 0);
  digitalWrite(column[16], 0);
  digitalWrite(column[11], 0);
  digitalWrite(column[6], 0);
  digitalWrite(column[1], 0);
  delay(x);
  //fifth side off
  digitalWrite(column[20], 1);
  digitalWrite(column[15], 1);
  digitalWrite(column[10], 1);
  digitalWrite(column[5], 1);
  digitalWrite(column[0], 1);
  delay(x);
  //third side on
  digitalWrite(column[22], 0);
  digitalWrite(column[17], 0);
  digitalWrite(column[12], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[2], 0);
  delay(x);
  //fourth side off
  digitalWrite(column[21], 1);
  digitalWrite(column[16], 1);
  digitalWrite(column[11], 1);
  digitalWrite(column[6], 1);
  digitalWrite(column[1], 1);
  delay(x);
  //second side on
  digitalWrite(column[23], 0);
  digitalWrite(column[18], 0);
  digitalWrite(column[13], 0);
  digitalWrite(column[8], 0);
  digitalWrite(column[3], 0);
  delay(x);
  //third side off
  digitalWrite(column[22], 1);
  digitalWrite(column[17], 1);
  digitalWrite(column[12], 1);
  digitalWrite(column[7], 1);
  digitalWrite(column[2], 1);
  delay(x);
  //first side on
  digitalWrite(column[24], 0);
  digitalWrite(column[19], 0);
  digitalWrite(column[14], 0);
  digitalWrite(column[9], 0);
  digitalWrite(column[4], 0);
  delay(x);
  //second side off
  digitalWrite(column[23], 1);
  digitalWrite(column[18], 1);
  digitalWrite(column[13], 1);
  digitalWrite(column[8], 1);
  digitalWrite(column[3], 1);
  delay(x);
  //fifth side on
  digitalWrite(column[20], 0);
  digitalWrite(column[15], 0);
  digitalWrite(column[10], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[0], 0);
  delay(x);
  //first side off
  digitalWrite(column[24], 1);
  digitalWrite(column[19], 1);
  digitalWrite(column[14], 1);
  digitalWrite(column[9], 1);
  digitalWrite(column[4], 1);
  delay(x);
}

//flow front to back
void frontToBack()
{
  int x = 50;
  turnEverythingOff();
  //turn layers on
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(layer[i], 1);
  }
  //first side on
  for(int i = 24; i > 19; i--)
  {
    digitalWrite(column[i], 0);
  }
  delay(x);
  //second side on
  for(int i = 19; i > 14; i--)
  {
    digitalWrite(column[i], 0);
  }
  delay(x);
  //first side off
  for(int i = 24; i > 19; i--)
  {
    digitalWrite(column[i], 1);
  }
  delay(x);
  //third side on
  for(int i = 14; i > 9; i--)
  {
    digitalWrite(column[i], 0);
  }
  delay(x);
  //second side off
  for(int i = 19; i > 14; i--)
  {
    digitalWrite(column[i], 1);
  }
  delay(x);
  //fourth side on
  for(int i = 9; i > 4; i--)
  {
    digitalWrite(column[i], 0);
  }
  delay(x);
  //third side off
  for(int i = 14; i > 9; i--)
  {
    digitalWrite(column[i], 1);
  }
  delay(x);
  //fifth side on
  for(int i = 4; i > -1; i--)
  {
    digitalWrite(column[i], 0);
  }
  delay(x);
  //fourth side off
  for(int i = 9; i > 4; i--)
  {
    digitalWrite(column[i], 1);
  }
  delay(x);
  //first side on
  for(int i = 24; i > 19; i--)
  {
    digitalWrite(column[i], 0);
  }
  delay(x);
  //fifth side off
  for(int i = 4; i > -1; i--)
  {
    digitalWrite(column[i], 1);
  }
  delay(x);
}

//flow back to front
void backToFront()
{
  int x = 50;
  turnEverythingOff();
  //turn layers on
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(layer[i], 1);
  }
  //fifth side on
  for(int i = 4; i > -1; i--)
  {
    digitalWrite(column[i], 0);
  }
  delay(x);
  //fourth side on
  for(int i = 9; i > 4; i--)
  {
    digitalWrite(column[i], 0);
  }
  delay(x);
  //fifth side off
  for(int i = 4; i > -1; i--)
  {
    digitalWrite(column[i], 1);
  }
  delay(x);
  //third side on
  for(int i = 14; i > 9; i--)
  {
    digitalWrite(column[i], 0);
  }
  delay(x);
  //fourth side off
  for(int i = 9; i > 4; i--)
  {
    digitalWrite(column[i], 1);
  }
  delay(x);
  //second side on
  for(int i = 19; i > 14; i--)
  {
    digitalWrite(column[i], 0);
  }
  delay(x);
  //third side off
  for(int i = 14; i > 9; i--)
  {
    digitalWrite(column[i], 1);
  }
  delay(x);
  //first side on
  for(int i = 24; i > 19; i--)
  {
    digitalWrite(column[i], 0);
  }
  delay(x);
  //second side off
  for(int i = 19; i > 14; i--)
  {
    digitalWrite(column[i], 1);
  }
  delay(x);
  //fifth side on
  for(int i = 4; i > -1; i--)
  {
    digitalWrite(column[i], 0);
  }
  //first side off
  for(int i = 24; i > 19; i--)
  {
    digitalWrite(column[i], 1);
  }
  delay(x);
}

//random rain
void randomRain()
{
  int x = 25;
  turnEverythingOff();
  for(int i = 0; i!=60; i+=2)
  {
    int randomColumn = random(0,25);
    digitalWrite(column[randomColumn], 0);
    digitalWrite(layer[0], 1);
    delay(x+50);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 1);
    delay(x);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[2], 1);
    delay(x);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 1);
    delay(x);
    digitalWrite(layer[3], 0);
    digitalWrite(layer[4], 1);
    delay(x+50);
    digitalWrite(layer[4], 0);
    digitalWrite(column[randomColumn], 1);
  }
}
