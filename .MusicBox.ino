/*
Music Box 틀
Begin:
메트로늄 기호:
악보출처:
*/

#define Buzzer 3
#define LED 4
#define term 4800

const float c1 = 32.7032,   cS1 = 34.6478,   d1 = 36.7081,   dS1 = 38.8909,   e1 = 41.2034,   f1 = 43.6535,   fS1 = 46.2493,   g1 = 48.9994,   gS1 = 51.9131,   a1 = 55.0000,   aS1 = 58.2705,   b1 = 61.7354;
const float c2 = 65.4064 ,  cS2 = 69.2957,   d2 = 73.4162,   dS2 = 77.7817,   e2 = 82.4069,   f2 = 87.3071,   fS2 = 92.4986,   g2 = 97.9989,   gS2 = 103.8262,  a2 = 110.0000,  aS2 = 116.5409,  b2 = 123.4708;
const float c3 = 130.8128,  cS3 = 138.5913,  d3 = 146.8324,  dS3 = 155.5635,  e3 = 164.8138,  f3 = 174.6141,  fS3 = 184.9972,  g3 = 195.9977,  gS3 = 207.6523,  a3 = 220.0000,  aS3 = 233.0819,  b3 = 246.9417;
const float c4 = 261.6256,  cS4 = 277.1826,  d4 = 293.6648,  dS4 = 311.1270,  e4 = 329.6276,  f4 = 349.2282,  fS4 = 369.9944,  g4 = 391.9954,  gS4 = 415.3047,  a4 = 440.0000,  aS4 = 466.1638,  b4 = 493.8833;
const float c5 = 523.2511,  cS5 = 554.3653,  d5 = 587.3295,  dS5 = 622.2540,  e5 = 659.2551,  f5 = 698.4565,  fS5 = 739.9888,  g5 = 783.9909,  gS5 = 830.6094,  a5 = 880.0000,  aS5 = 932.3275,  b5 = 987.7666;
const float c6 = 1046.5023, cS6 = 1108.7305, d6 = 1174.6591, dS6 = 1244.5079, e6 = 1318.5102, f6 = 1396.9129, fS6 = 1479.9777, g6 = 1567.9817, gS6 = 1661.2188, a6 = 1760.0000, aS6 = 1864.6550, b6 = 1975.5332;
const float c7 = 2093.0045, cS7 = 2217.4610, d7 = 2349.3181, dS7 = 2489.0159, e7 = 2637.0205, f7 = 2793.8259, fS7 = 2959.9554, g7 = 3135.9635, gS7 = 3322.4376, a7 = 3520.0000, aS7 = 3729.3101, b7 = 3951.0664;
const float c8 = 4186.0090, cS8 = 4434.9221, d8 = 4698.6363, dS8 = 4978.0317, e8 = 5274.0409, f8 = 5587.6517, fS8 = 5919.9108, g8 = 6271.9270, gS8 = 6644.8752, a8 = 7040.0000, aS8 = 7458.6202, b8 = 7902.1328;

typedef struct _NOTE {
    float melody;
    float tempo;
} NOTE;

const PROGMEM NOTE NoteSong[] = {};

void setup() {
    pinMode(Buzzer, OUTPUT);
    pinMode(LED, OUTPUT);
    digitalWrite(LED,1);

    for(int i = 0; i < sizeof(NoteSong)/sizeof(NoteSong[0]); i++) {
        float pitch = pgm_read_float(&NoteSong[i].melody);
        float beat = term/pgm_read_float(&NoteSong[i].tempo);
        tone(Buzzer, pitch, beat);
        delay(beat*1.1);
    }
};

void loop() {};
