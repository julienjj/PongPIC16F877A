    volatile  char  ball_pb;
      volatile char  ball_pd;
      volatile char  pad_pb;
      volatile char  pad_pd;
      volatile char  pad_pb_temp;
      int j=0;
      int i;
      int direcao_top;
      int direcao_butt;
      int direcao_right;
      int direcao_left;
      volatile int flag_mov;
      int colision_flag;
      bit aux;
      bit aux1;
      bit result;
      int k;

void timer(){

  PORTB=ball_pb;
  PORTD=ball_pd;
  Delay_ms(50);
  PORTB=pad_pb;
  PORTD=pad_pd;
  Delay_ms(50);

}

// Rotina colisao escolhe movimentos -----------
// so chama rotina quando detecta colisao

void col_ball_butt(){

  direcao_top = rand() % 2;

  switch(direcao_top){

     case 0:     // direçao reta p cima
     flag_mov=1;
     break;

     case 1:     // direçao incl esq
     flag_mov=2;
     break;

     case 2:     // direçao incl dir
     flag_mov=3;
     break;

  }
  colision_flag=0;

  game_over=0;
}
// fim -------------------------------------

// Rotina colisao escolhe movimentos -----------
// so chama rotina quando detecta colisao

void col_ball_top(){

  direcao_butt = rand() % 2;

  switch (direcao_butt){

     case 0:     // direçao reta
     flag_mov=5;
     break;

     case 1:     // direçao incl esq
     flag_mov=4;
     break;

     case 2:     // direçao incl dir
     flag_mov=6;
     break;

  }
  colision_flag=0;
}
// fim -------------------------------------

// Rotina colisao escolhe movimentos -----------
// so chama rotina quando detecta colisao

void col_ball_left(){

  direcao_right = rand() % 2;

  switch (direcao_right){

     case 0:     // direçao reta
     flag_mov=7;
     break;

     case 1:     // direçao incl esq
     flag_mov=8;
     break;

     case 2:     // direçao incl dir
     flag_mov=9;
     break;

  }
  colision_flag=0;
}
// fim -------------------------------------

// Rotina colisao escolhe movimentos -----------
// so chama rotina quando detecta colisao

void col_ball_right(){

  direcao_left = rand() % 2;

  switch (direcao_left){

     case 0:     // direçao reta
     flag_mov=10;
     break;

     case 1:     // direçao incl esq
     flag_mov=11;
     break;

     case 2:     // direçao incl dir
     flag_mov=12;
     break;

  }
  colision_flag=0;
}
// fim -------------------------------------





// Rotina movimento ----------------------

 void mov(){


    if(colision_flag==0){

    // de baixo p cima
    if(flag_mov==1){

    ball_pd=ball_pd>>1;}

    if(flag_mov==2){

    ball_pd=ball_pd>>1;
    ball_pb=ball_pb>>1;}
    //fim

    if(flag_mov==3){

    ball_pd=ball_pd>>1;
    ball_pb=ball_pb<<1;}

    // de cima p baixo
    if(flag_mov==4 && PORTB.RB0!=1){

    ball_pd=ball_pd<<1;}

    if(flag_mov==5 && PORTB.RB0!=1){

    ball_pd=ball_pd<<1;
    ball_pb=ball_pb<<1;}


    if(flag_mov==6 && PORTB.RB0!=1){

    ball_pd=ball_pd<<1;
    ball_pb=ball_pb>>1;}
    //fim    -ok

    // da esq p dir
    if(flag_mov==7){

    ball_pb=ball_pb<<1;}

    if(flag_mov==8){

    ball_pd=ball_pd>>1;
    ball_pb=ball_pb<<1;}


    if(flag_mov==9){

    ball_pd=ball_pd>>1;
    ball_pb=ball_pb<<1;}
    //fim

    // da dir p esq
    if(flag_mov==10){

    ball_pb=ball_pb>>1;}

    if(flag_mov==11){

    ball_pd=ball_pd>>1;
    ball_pb=ball_pb>>1;}


    if(flag_mov==12){

    ball_pd=ball_pd>>1;
    ball_pb=ball_pb>>1;}
    //fim
    Delay_ms(100);
    }

 }

// fim movimento -----------------


// colisões ---------------------

void colisoes(){
 

// colisao pad------------
  if(ball_pd==64){

        if(ball_pb=0b10000000 && pad_pb=0b11000000){
        colision_flag=1;
        col_ball_butt();
        game_over=0;
        }
        else
        if((ball_pb=0b01000000 && pad_pb=0b11000000) || (ball_pb=0b01000000 && pad_pb=0b01100000)){
        colision_flag=1;
        col_ball_butt();
        game_over=0;
        }
        else
        if((ball_pb=0b00100000 && pad_pb=0b01100000) || (ball_pb=0b00100000 && pad_pb=0b00110000)){
        colision_flag=1;
        col_ball_butt();
        game_over=0;
        }
        else
        if((ball_pb=0b00010000 && pad_pb=0b00110000) || (ball_pb=0b00010000 && pad_pb=0b00011000)){
        colision_flag=1;
        col_ball_butt();
        game_over=0;
        }
        else
        if((ball_pb=0b00001000 && pad_pb=0b00011000) || (ball_pb=0b000010000 && pad_pb=0b00001100)){
        colision_flag=1;
        col_ball_butt();
        game_over=0;
        }
        else
        if((ball_pb=0b00000100 && pad_pb=0b00001100) || (ball_pb=0b000001000 && pad_pb=0b00000110)){
        colision_flag=1;
        col_ball_butt();
        game_over=0;
        }
        else
        if((ball_pb=0b00000010 && pad_pb=0b00000110) || (ball_pb=0b000000100 && pad_pb=0b00000011)){
        colision_flag=1;
        col_ball_butt();
        game_over=0;
        }
        else
        if(ball_pb=0b00000001 && pad_pb=0b00000011){
        colision_flag=1;
        col_ball_butt();
        game_over=0;
        }
        else  game_over++;

}
// fim pad---------------



    // colisao top
    if(ball_pd==1){
     colision_flag=1;
     col_ball_top();
    }

   // colisao esq
    if(ball_pb==1){
     colision_flag=1;
     col_ball_left();
    }
   // fim

   // colisao dir
    if(ball_pb==128){
     colision_flag=1;
     col_ball_right();
    }
   // fim

}

void pad(){

     if(pad_pb <=0x64) {
     pad_pb_temp= pad_pb;
    if(PORTC.RB5!=1){
    pad_pb_temp=pad_pb_temp<<1;
                  }
     pad_pb=pad_pb_temp;
     }

         if(pad_pb >=0x04) {
     pad_pb_temp= pad_pb;
     if(PORTC.RB4!=1){
    pad_pb_temp=pad_pb_temp>>1;
                  }
    pad_pb=pad_pb_temp;

           }

}




 

 // reinicia o jogo -----
void rein(){
    
    ball_pb=0b00010000;
    ball_pd=0b00000001;
    pad_pb=0b00011000;
    pad_pd=0b10000000;
    i=0;
    game_over=0;
    //inicializa:
    col_ball_top();
}
-----------------------


void main(){
CMCON =7;
TRISD = 0b00000000;
TRISB = 0b00000000;
TRISC=0xFF;
    ball_pb=0b00010000;
    ball_pd=0b00000001;
    pad_pb=0b00011000;
    pad_pd=0b10000000;
    i=0;

    //inicializa:
    col_ball_top();


   while(1){

   if(game_over<=1){
   colisoes();
   pad();
   timer();
   mov();          }
   else
   rein();

            }
}
 

