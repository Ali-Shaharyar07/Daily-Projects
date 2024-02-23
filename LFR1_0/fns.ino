void forward(int a, int b)
{
digitalWrite (rf,HIGH);
digitalWrite (lf,HIGH);
digitalWrite (lb,LOW);
digitalWrite (rb,LOW);
analogWrite (enL,a);
analogWrite (enR,b);


}
void backward(int a, int b){
digitalWrite (rf,LOW);
digitalWrite (lf,LOW);
digitalWrite (lb,HIGH);
digitalWrite (rb,HIGH);
analogWrite (enL,a);
analogWrite (enR,b);
}

void right(int a, int b){
digitalWrite (rf,LOW);
digitalWrite (lf,HIGH);
digitalWrite (lb,LOW);
digitalWrite (rb,LOW);
analogWrite (enL,a);
analogWrite (enR,b);}

void left (int a, int b){
digitalWrite (rf,HIGH);
digitalWrite (lf,LOW);
digitalWrite (lb,LOW);
digitalWrite (rb,LOW);
analogWrite (enL,a);
analogWrite (enR,b);
}

void leftsharp (int a, int b){
digitalWrite (rf,HIGH);
digitalWrite (lf,LOW);
digitalWrite (lb,HIGH);
digitalWrite (rb,LOW);
analogWrite (enL,a);
analogWrite (enR,b);
}
void rightsharp (int a, int b){
digitalWrite (rf,LOW);
digitalWrite (lf,HIGH);
digitalWrite (lb,LOW);
digitalWrite (rb,HIGH);
analogWrite (enL,a);
analogWrite (enR,b);}

void stop (int a){
digitalWrite (rf,LOW);
digitalWrite (lf,LOW);
digitalWrite (lb,LOW);
digitalWrite (rb,LOW);
analogWrite (enL,a);
analogWrite (enR,a);
}