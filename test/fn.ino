void forward(int a){
  digitalWrite(lf, HIGH);
  digitalWrite(rf, HIGH);
  digitalWrite(rb, LOW);
  digitalWrite(lb, LOW);
  analogWrite(en1, a+10);
  analogWrite(en2, a);
}

void backward(int a){
  digitalWrite(lf, LOW);
  digitalWrite(rf, LOW);
  digitalWrite(rb, HIGH);
  digitalWrite(lb, HIGH);
  analogWrite(en1, a);
  analogWrite(en2, a);
}



void right(int a){
digitalWrite (rf,LOW);
digitalWrite (lf,HIGH);
digitalWrite (lb,LOW);
digitalWrite (rb,LOW);
analogWrite (en1,a);
analogWrite (en2,a);}

void left (int a){
digitalWrite (rf,HIGH);
digitalWrite (lf,LOW);
digitalWrite (lb,LOW);
digitalWrite (rb,LOW);
analogWrite (en1,a);
analogWrite (en2,a);
}

void leftsharp (int a){
digitalWrite (rf,HIGH);
digitalWrite (lf,LOW);
digitalWrite (lb,HIGH);
digitalWrite (rb,LOW);
analogWrite (en1,a);
analogWrite (en2,a);
}
void rightsharp (int a){
digitalWrite (rf,LOW);
digitalWrite (lf,HIGH);
digitalWrite (lb,LOW);
digitalWrite (rb,HIGH);
analogWrite (en1,a);
analogWrite (en2,a);}

void stop (int a){
digitalWrite (rf,LOW);
digitalWrite (lf,LOW);
digitalWrite (lb,LOW);
digitalWrite (rb,LOW);
analogWrite (en1,a);
analogWrite (en2,a);
}


