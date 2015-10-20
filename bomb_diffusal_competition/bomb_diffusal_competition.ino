int clockin,chk;
int ipni[10],tho[10],flg[11]={0};
boolean k[10]={1,0,1,1,0,0,1,1,1,0};
int *ptri = &ipni[0],*ptrt = &tho[0],*ptrf = &flg[0];
void setup()
{
  
  int i;
  for(i=2;i<11;i++)
    pinMode(i,INPUT_PULLUP);
    pinMode(A0,INPUT_PULLUP);
    pinMode(A1,OUTPUT);
    pinMode(A2,OUTPUT);
     Serial.begin(9600);
    for(i=0;i<10;i++)
    {*ptrt=(1<<k[i]);
     *(ptrt)=(!k[(9-i)]);
     ptrt++;
    }
    ptrt-=10;
       
    for(i=0;i<10;i++){
    Serial.println(tho[i]);}

}



void boom()
{
  for(int i=0;i<4;i++)
  {tone(A1,665,300);
  delay(100);
  tone(A1,547,300);
  delay(100);
  tone(A1,438,300);
  delay(100);
  tone(A1,620,300);
  delay(100);
  tone(A1,701,100);
  delay(100);}
  noTone(A1);
  Serial.println("BOOM");
  digitalWrite(A2,HIGH);
  while(1);
}

void boon()
{
  tone(A1,3000,150);
  delay(200);
  tone(A1,651,250);
  delay(250);
  tone(A1,2500,250);
  delay(250);
  tone(A1,651,250);
  delay(250);
  tone(A1,2200,600);
  delay(500);
  tone(A1,1321,250);
  delay(250);
  tone(A1,3000,500);
  delay(500);
  tone(A1,2200,600);
  delay(500);
  tone(A1,1300,250);
  delay(250);
  tone(A1,3000,500);
  delay(500);
  noTone(A1);
  Serial.println("BOON");
  digitalWrite(A2,HIGH);
  while(1);
}