/*
Begin:2022-11-23
스승의 은혜 오르골
*/

#define Buzzer 3
#define term 2000

#define c4 262
#define d4 294
#define e4 330
#define f4 349
#define fS4 370
#define g4 392
#define a4 440
#define b4 494

#define c5 524
#define d5 588
#define e5 660


typedef struct _Note {
    short melody;
    char tempo;
}NOTE;

const NOTE NoteSong[] = {
    {d4,8},{d4,8},{b4,4},{b4,4},
    {c5,8},{b4,8},{a4,8},{g4,8},{e4,4},
    {d4,4},{g4,4},{fS4,8},{g4,8},
    {a4,2},{0,4},                                            //1-1
    {d4,8},{d4,8},{b4,8/3},{b4,8},
    {c5,8},{b4,8},{a4,8},{g4,8},{e4,4},
    {fS4,8},{g4,8},{a4,4},{b4,4},
    {g4,2},{0,4},                                            //1-2 
    {g4,16/3},{fS4,16},{e4,8/3},{e4,8},
    {e4,8},{g4,8},{c5,16/3},{e5,16},{d5,4},
    {c5,16/3},{e4,16},{e4,4},{fS4,8},{g4,8},
    {a4,2},{0,4},                                            //1-3
    {d4,8},{d4,8},{d5,8/3},{b4,8},
    {a4,8},{b4,8},{c5,8},{b4,16/3},{a4,16},{g4,4},
    {e4,8/3},{d4,8},{fS4,8},{a4,8},
    {g4,2},{0,4},                                            //1-4
    {b4,16/3},{c5,16},{d5,2},
    {b4,8},{c5,8},{d5,8},{g4,2},
    {a4,8/3},{d4,8},{c5,8},{b4,8},
    {a4,2},{0,4},                                            //1-5
    {b4,4},{d5,2},
    {b4,8},{b4,8},{b4,8},{e5,2},
    {d5,8},{c5,8},{b4,8},{a4,16/3},{d4,16},{a4,16/3},{b4,16},
    {g4,2},{0,4},                                            //1-6           

};

void setup() {
    pinMode(Buzzer,OUTPUT);
    pinMode(4,OUTPUT);
    digitalWrite(4,1);
    
    for(int i=0; i<(sizeof(NoteSong)/sizeof(NoteSong[0])); i++ ) {
        tone(Buzzer,NoteSong[i].melody,term/NoteSong[i].tempo);
        delay(term/NoteSong[i].tempo*1.1);
    }
    
};

void loop() {};
