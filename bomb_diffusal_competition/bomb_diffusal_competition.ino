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
void loop(){
  int i,j;

  Serial.println("pass over");    

  for(i=2;i<12;i++)
  ipni[i-2]=digitalRead(i);
  
  for(i=0;i<10;i++){
    Serial.print(*ptrt++);
    Serial.print(tho[i]);
    Serial.print(*ptri++);
    Serial.print(ipni[i]);
    Serial.print(*ptrf++);
    Serial.println(flg[i]);
    
  }
  ptrt-=10;
  ptri-=10;
  ptrf-=10;
  
  clockin=digitalRead(A0);
  
  for(i=0;i<10;i++);{
  if(clockin==HIGH){
    Serial.println("time over");
  boom();}
 
  if(*(ptri+4)==1){      //ptr+8==1               //2,6,7,10 cheat
    flg[1]=1;     
    Serial.println("ptri+4"); }                     //flg[1]=1
  if(*(ptri+8)==1)  {                          //prti+16==1
    flg[3]=1;     
    Serial.println("ptri+8");  }                      //flg[3]=1
  if(*(ptri+0)==1)    {                         //ptri+0==1      
    flg[0]=1;         
    Serial.println("ptri+0");}                 //flg[0]=1
  if(*(ptri+5)==1)      {                      //ptri+10==1
    flg[2]=1;           
    Serial.println("ptri+5");}                  // flg[2]=1
     
  if(*(ptri+1)==1){                //ptr+2==1              
    flg[4]=1;     
    Serial.println("ptri+1");}                   //flg[1]=1
  if(*(ptri+2)==1)  {                      //prti+4==1
    flg[5]=1;  
    Serial.println("ptri+2");     }             //flg[3]=1
  if(*(ptri+3)==1)    {            //ptri+6==1      
    flg[6]=1;  
    Serial.println("ptri+3");       }             //flg[0]=1
  if(*(ptri+6)==1)      {            //ptri+12==1
    flg[7]=1;    
    Serial.println("ptri+6");       }     // flg[2]=1
  if(*(ptri+7)==1){                  //ptri+14==1
    flg[8]=1;  
    Serial.println("ptri+7");   }           // flg[2]=1
  if(*(ptri+9)==1)  {                //ptri+18==1
    flg[9]=1;   
    Serial.println("ptri+9");    }         // flg[2]=1
    //*/
//  ptri+=(i*2/i-2*tho[5]);
  
  }
  
  chk=0;
  for(i=0;i<10;i++){
    for(j=0;(i+j)<10;j++)
  if(*(ptrf+j+1)>(*ptrf)){
  Serial.println("flg down");
  boom();}
  if(*ptrt++==*ptri++)
  chk++;
  if(chk==10)
  boon();
  ptrf++;}
  ptrt-=10;
  ptri-=10;
  ptrf-=10;
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
