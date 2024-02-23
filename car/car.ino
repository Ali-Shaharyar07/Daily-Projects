#define rb 9
#define rf 8
#define lb 13
#define lf 12

#define l2 7
#define l1 6
#define m 5
#define r1 4
#define r2 3
#define en 11
#define en2 10
int l1R;
int l2R;
int mR;
int r1R;
int r2R;
int error;

void setup() {
  // put your setup code here, to run once:
pinMode (rf,OUTPUT);
pinMode (lf,OUTPUT);
pinMode (rb,OUTPUT);
pinMode (lb,OUTPUT);

pinMode (l2,INPUT);
pinMode (l1,INPUT);
pinMode (m,INPUT);
pinMode (r1,INPUT);
pinMode (r2,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

int a= 80;
reading();
if (error == 0){
  forward(a+155);
  reading();
}

while (error == -1){
  left(a+120);
  reading();
}

while (error == -2){
  leftsharp(a+120);
  reading();
}

while (error == 1){
  right(a+120);
  reading();
}
while (error == 2){
  rightsharp(a+120);
  reading();
}

while (error == -3){
  leftsharp(a+120);
  reading();
}
while (error == 3){
  rightsharp(a+120);
  reading();
}
while (error == -4){
  leftsharp(a+120);
  reading();
}
while(error == 4){
  rightsharp(a+120);
  reading();
}
while (error == -5){
  leftsharp(a+120);
  delay(500);
  reading();
}
while (error == 10){
  forward(a);
  reading();
}

}

void reading(){
  int l1R = digitalRead(l1);
  if (l1R == 0){
    error = -1;
  }
  int l2R = digitalRead(l2);
  if (l2R == 0){
    error = -2;
  }
  int r1R = digitalRead(r1);
  if (r1R == 0){
    error = 1;
  }
  int r2R = digitalRead(r2);
  if (r2R == 0){
    error = 2;
  }
  int mR = digitalRead(m);
  if (mR == 0){
    error = 0;
  }

  if (l1R == 0 && l2R == 0){
    error ==-3;
  }
  if (l1R == 0 && l2R == 0 && mR == 0){
    error ==-4;
  }
  if (r1R == 0 && r2R == 0){
    error == 3;
  }
  if (r1R == 0 && r2R == 0 && mR == 0 ){
    error == 4;
  }
  if (r1R == 0 && r2R == 0 && mR == 0 && l1R == 0 && l2R == 0){
    error = 10;
  }
  if (l1R == 1 && l2R == 0 && r1R == 0 && mR == 0 && r2R == 0){
    error = -5;
  }
}

void forward(int a)
{
digitalWrite (rf,HIGH);
digitalWrite (lf,HIGH);
digitalWrite (lb,LOW);
digitalWrite (rb,LOW);
analogWrite (en,a);
analogWrite (en2,a);


}
void backward(int a){
digitalWrite (rf,LOW);
digitalWrite (lf,LOW);
digitalWrite (lb,HIGH);
digitalWrite (rb,HIGH);
analogWrite (en,a);
analogWrite (en2,a);
}

void right(int a){
digitalWrite (rf,LOW);
digitalWrite (lf,HIGH);
digitalWrite (lb,LOW);
digitalWrite (rb,LOW);
analogWrite (en,a);
analogWrite (en2,a);}

void left (int a){
digitalWrite (rf,HIGH);
digitalWrite (lf,LOW);
digitalWrite (lb,LOW);
digitalWrite (rb,LOW);
analogWrite (en,a);
analogWrite (en2,a);
}

void leftsharp (int a){
digitalWrite (rf,HIGH);
digitalWrite (lf,LOW);
digitalWrite (lb,HIGH);
digitalWrite (rb,LOW);
analogWrite (en,a);
analogWrite (en2,a);
}
void rightsharp (int a){
digitalWrite (rf,LOW);
digitalWrite (lf,HIGH);
digitalWrite (lb,LOW);
digitalWrite (rb,HIGH);
analogWrite (en,a);
analogWrite (en2,a);}

void stop (int a){
digitalWrite (rf,LOW);
digitalWrite (lf,LOW);
digitalWrite (lb,LOW);
digitalWrite (rb,LOW);
analogWrite (en,a);
analogWrite (en2,a);
}