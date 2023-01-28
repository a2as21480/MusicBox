/*
아두이노 오르골 - 홍연(소프라노)
Begin 2022-11-30
*/

#define Buzzer 4
#define term 2000

const float f2 = 87.3071;
const float c3 = 130.8128, d3 = 146.8324, e3 = 164.8138, f3 = 174.6141, g3 = 195.9977, a3 = 220.0, b3 = 246.9417;
const float aS3 = 233.0819;
const float c4 = 261.6256, d4 = 293.6648, e4 = 329.6276, f4 = 349.2282, g4 = 391.9954, a4 = 440.0, b4 = 493.8833;
const float cS4 = 227.1826, dS4 = 312.1170, fS4 = 369.9944, aS4 = 466.1638;
const float c5 = 523.2511, d5 = 587.3295, e5 = 659.2551, f5 = 698.4565, g5 = 783.9909, a5 = 880.0, b5 = 987.7666;
const float cS5 = 553.3653, fS5 = 739.9888, gS5 = 830.6094, aS5 = 932.3275;
const float c6 = 1146.502, d6 = 1174.659, e6 = 1318.510, f6 = 1396.913, g6 = 1567.982, a6 = 1760.0;
const float cS6 = 1108.731, fS6 = 1479.978, gS6 = 1661.219, aS6 =1864.655;

typedef struct _NOTE {
    float melody;
    float tempo;
}NOTE;

//쉼표 대신 알토 성부 음 넣기
const PROGMEM NOTE NoteSong[] = {
    {d5, 16/3},{d5, 16},{d5, 8},{d5, 4},{cS5,8},
    {d5, 16/3},{d5, 16},{d5, 8},{d5, 4},{cS5,8},
    {d5, 16/3},{d5, 16},{d5, 8},{d5, 4},{cS5,8},
    {d5,4},{d5,8},{a3,24},{b3,24},{c4,24},{d4,24},{e4,24},{f4,24},{g4,24},{b4,24},{cS5,16}, //1-1

    {d5,16},{d5,16},{cS5,16},{d5,16},{cS5,16},{a4,16},{d5,16},{d5,16},{cS5,16},{d5,16},{cS5,16},{a4,16},
    {d5,16},{d5,16},{cS5,16},{d5,16},{cS5,16},{a4,16},{d5,16},{d5,16},{cS5,16},{d5,16},{cS5,16},{a4,16},
    {d5,16},{d5,16},{cS5,16},{d5,16},{cS5,16},{a4,16},{d5,16},{d5,16},{cS5,16},{d5,16},{cS5,16},{a4,16},
    {d5,16},{d5,16},{cS5,16},{d5,16},{cS5,16},{a4,16},{d5,4},{a4,16},{c5,16}, //1-2 세상

    {d5,4},{d5,8},{d5,4},{cS5,8}, //에 처음 날
    {d5,4},{d4,8},{c4,8},{e4,8},{a4,16},{c5,16}, //때 인연
    {d5,4},{d5,8},{d5,4},{cS5,8}, //인 사람 들
    {d5,4},{d4,8},{c4,8},{e4,8},{a5,8}, //1-3 은 손

    {d5,4},{a5,8},{g5,4},{g5,8}, //과 손에 붉
    {c5,4},{g5,8},{f5,4},{a4,16},{c5,16}, //은 실이 이어
    {d5,8},{d5,8},{d5,8},{d5,4},{cS5,8}, //진채 왔다 했
    {d5,4},{d4,8},{a4,8},{a4,8},{c5,16},{d5,16}, //1-4 죠  당신이

    {d5,4},{d5,8},{d5,4},{cS5,8}, //-이 어디 있
    {d5,4},{d3,8},{d3,8},{f3,8},{a4,16},{c5,16}, //든 내가
    {c5,8},{d5,8},{d5,8},{d5,8},{cS5,8}, //-가 찾을 수 있
    {d5,4},{d3,8},{d4,8},{d4,8},{a5,8}, //1-5 게 손

    {d5,4},{a5,8},{g5,4},{g5,8}, //과 손에 붉
    {c5,4},{g5,8},{f5,4},{a4,16},{c5,16}, //은 실이 이어
    {d5,8},{d5,8},{d5,8},{d5,4},{cS5,8}, //진채 왔다 했
    {d5,4},{d3,8},{d4,4},{a3,16},{c4,16}, //2-1 죠 

    {d4,16/3},{cS4,16},{a3,16},{cS4,16},{d4,16/3},{cS4,16},{a3,16},{cS4,16},
    {d4,4},{f3,8},{d4,4},{a3,16},{cS4,16},
    {d4,16/3},{cS4,16},{a3,16},{cS4,16},{d3,16/3},{cS4,16},{a3,16},{cS4,16},
    {f4,4},{e4,8},{f4,8},{g4,8},{a4,8}, //2-2

    {a4,8/3},{g4,4},{e4,8},
    {f4,8},{g4,8},{a4,8},{f4,8},{e4,8},{d4,8},
    {d4,8/3},{d4,4},{cS4,8},
    {d4,8/3},{f3,8},{a3,8},{g3,8}, //2-3

    {f5,8/3},{f5,8},{e5,8},{d5,8}, //눈 물진
    {e5,4},{f5,8},{c5,8,},{c4,8},{a4,8}, //나 의 뺨을 
    {aS4,8},{c5,8},{d5,8},{cS5,8},{d5,8},{e5,8}, //쓰담아주면서
    {f5,4},{d4,8},{fS5,8},{g5,8},{a5,8}, //2-4 도 다른손

    {a5,8/3},{a5,8},{f5,8},{f5,8}, //은 칼을
    {f5,8},{f3,8},{c5,8},{c5,4},{f5,8}, //거 두지 않
    {d5,16},{d3,16},{e5,8},{f5,8},{f5,8},{g5,8},{a5,8}, //네 또다시 사라
    {a5,4},{e4,16},{f4,16},{d5,8},{f5,8},{a5,8}, //2-5 져 산산히

    {g5,8/3},{g5,8},{d5,8},{cS5,16},{d5,16}, //부서지는
    {d5,16},{d4,8},{d5,8},{f5,8},{c6,8}, //-는 누부신
    {g5,8/3},{g5,8},{a5,16},{g5,16},{f5,16},{g5,16}, //우-리의 날들
    {a5,4},{d4,8},{d5,8},{f5,8},{a5,8}, //3-1 이 다시는

    {g5,8/3},{g5,8},{d5,8},{cS5,8}, //오 지못
    {d5,4},{d4,8},{d5,8},{f5,8},{a5,8}, //할 어둠으
    {g5,8/3},{g5,8/3}, //로-
    {d5,16},{d5,16},{d5,4},{d5,4},{d5,8}, //3-2 가네 아-

    {d6,8/3},{d6,8/3},
    {d6,8/3},{f4,8},{cS6,8},{d6,8},{cS6,8},{d6,8},
    {cS6,8},{d6,8/3},{d6,8},{cS6,8},{d6,8},{c6,8},{d6,8},
    {cS6,8/3},{a3,8},{a3,8},{c4,8}, //3-3

    {d5,4},{a5,8},{a5,4},{c6,8}, //고운그대
    {f5,4},{g5,8},{a5,4},{f3,16},{d5,16}, //얼굴에 피
    {d5,4},{d5,16},{d5,16},{d5,16},{d5,16},{d5,8},{cS5,8}, //를 닦아주
    {d5,8/3},{d5,8},{cS5,8},{d5,8},{cS5,8},{d5,8}, //3-4 오

    {cS5,8},{d5,8/3},{d4,8},{a4,16/3},{a4,16},{c5,16},
    {a4,8/3},{g4,4},{c5,8},
    {g4,8/3},{g4,8},{g4,8},{d5,8},
    {a4,8/3},{a3,8},{a4,8},{c5,8}, //3-5

    {d5,16},{a4,16},{d5,16},{f5,16},{e5,16},{f5,16},{f5,16},{d5,16},{f5,16},{g5,16},{e5,16},{g5,16},
    {a5,16},{f5,16},{d5,16},{a5,16},{g5,16},{a5,16},{a5,16},{g5,16},{f5,16},{a5,16},{d6,32},{e6,32/3},
    {g6,4},{g6,16},{f6,32},{e6,32},{d6,4},{d6,16},{f6,32},{g6,32}, //4-1

    {a6,8/3},{a6,4},{a4,16},{c5,16}, // 나의
    {d5,4},{d5,8},{d5,4},{cS5,8}, //모든것 들
    {d5,4},{a3,8},{c4,8},{a4,8},{c5,16},{d5,16}, //이 손대면
    {d5,4},{d5,8},{d5,4},{cS5,8}, //4-2 -면 사라질

    {d5,4},{g3,8},{d4,8},{a5,8}, //듯 끝
    {d5,4},{a5,8},{g5,4},{g5,8}, //도 없이 겁
    {c5,4},{g5,8},{f5,4},{a4,16},{c5,16}, //이 나서 무엇
    {c5,16},{d5,16},{d5,8},{d5,8},{d5,16},{d5,16},{d5,8},{cS5,8}, //4-3 -도 할수 없었다 했

    {d5,4},{d4,8},{f3,8},{aS3,8},{g3,8}, //죠
    {f5,8/3},{f5,8},{e5,8},{d5,8}, //아- 픈내 
    {e5,4},{f5,8},{c5,8,},{0,8},{a4,8}, //목소리에
    {aS4,8},{c5,8},{d5,8},{cS5,8},{d5,8},{e5,8}, //4-4 입맞춰 주면서

    {f5,4},{d4,8},{fS5,8},{g5,8},{a5,8}, //도 시선끝
    {a5,8/3},{a5,8},{f5,8},{f5,8}, //엔 내가
    {f5,8},{f3,8},{c5,8},{c5,4},{f5,8},  //있지를 않
    {d5,16},{d3,16},{e5,8},{f5,8},{f5,8},{g5,8},{a5,8}, //4-5 네 또다시 사라

    {a5,4},{e4,16},{f4,16},{d5,8},{f5,8},{a5,8}, //져 아득히
    {g5,8/3},{g5,8},{d5,8},{cS5,16},{d5,16}, //멀어지는
    {d5,16},{d4,8},{d5,8},{f5,8},{c6,8}, //-는 찬란한
    {g5,8/3},{g5,8},{a5,16},{g5,16},{f5,16},{g5,16}, //5-1 우리의 날들

    {a5,4},{d4,8},{d5,8},{f5,8},{a5,8}, // 이 다시는
    {g5,8/3},{g5,8},{d5,8},{cS5,8}, //오 지못
    {d5,4},{d4,8},{d5,8},{f5,8},{a5,8}, //할 어둠으
    {g5,8/3},{g5,4},{g5,16},{gS5,16}, //5-2 로-

    {d5,16},{d5,16},{d5,4},{d5,4},{a4,8}, //가네 아-
    {g5,8/3},{g5,8},{f5,8},{d5,16},{c5,16},
    {d5,8/3},{d5,8},{f5,8},{c6,8},
    {g5,8/3},{g5,8},{f5,8},{g5,8}, //5-3

    {g5,8},{a5,8/3},{d5,8},{f5,8},{a5,8},
    {g5,8/3},{g5,8},{f5,8},{d5,16},{c5,16},
    {d5,8/3},{d5,8},{c5,8},{a4,8},
    {f4,8/3},{d4,16},{f4,16},{e4,16},{g4,16},{f4,16},{aS4,16}, //5-4

    {a4,4},{a4,8},{d5,8},{f5,8},{a5,8}, //산산히
    {g5,8/3},{g5,8},{d5,8},{cS5,16},{d5,16}, //부서지는
    {d5,16},{d4,8},{d5,8},{f5,8},{c6,8}, //-는 누부신
    {g5,8/3},{g5,8},{a5,16},{g5,16},{f5,16},{g5,16}, //5-5 우-리의 날들

    {a5,4},{d4,8},{d5,8},{f5,8},{a5,8}, //이 다시는
    {g5,8/3},{g5,8},{d5,8},{cS5,8}, //오 지못
    {d5,4},{d4,8},{d5,8},{f5,8},{a5,8}, //할 어둠으
    {g5,8/3},{g5,4},{g5,16},{gS5,16}, //6-1 로-

    {a5,8/3},{d5,8},{f5,8},{a5,8}, //로- 당신은 
    {g5,8},{g5,8},{g5,8},{g5,4},{c5,8}, //세상에게 죽
    {d4,4},{c4,8},{d4,8},{f4,8},{c6,8}, //고 나는 너
    {g5,8/3},{g5,8},{g5,8},{f5,8}, //6-2 를- 잃었

    {a5,4},{f3,8},{d5,8},{f5,8},{a5,8}, //어 돌아올
    {g5,8/3},{g5,8},{g5,8},{c5,8}, //수-가 없
    {d5,4},{d4,8},{d5,8},{f5,8},{a5,8}, //네 다시돌
    {g5,4},{g5,8},{g5,8},{g5,8},{c5,8}, //6-3 아올수가 없

    {d5,8/3},{d4,8},{d4,8},{d5,4}, //네 아-
    {d6,8/3},{d6,8/3},
    {d6,8/3},{f4,8},{cS6,8},{d6,8},{cS6,8},{d6,8},
    {cS6,8},{d6,8/3},{d6,8},{cS6,8},{d6,8},{c6,8},{d6,8}, //6-4

    {cS6,8/3},{a3,8},{a3,8},{c4,8},
    {d5,4},{a5,8},{a5,4},{c6,8}, //고운그대
    {f5,4},{g5,8},{a5,4},{f3,16},{d5,16}, //얼굴에 피
    {d5,4},{d5,16},{d5,16},{d5,16},{d5,16},{d5,8},{cS5,8}, //6-5 를 닦아주

    {d5,8/3},{d5,8},{cS5,8},{d5,8},{cS5,8},{d5,8}, //오
    {cS5,8},{d5,8/3},{d4,8},{a4,16/3},{a4,16},{c5,16},
    {a4,8/3},{g4,4},{c5,8},
    {g4,8/3},{g4,8},{g4,8},{d5,8}, //7-1

    {a4,8/3},{a3,8},{a4,8},{c5,8},
    {d5,16},{a4,16},{d5,16},{f5,16},{e5,16},{f5,16},{f5,16},{d5,16},{f5,16},{g5,16},{e5,16},{g5,16},
    {a5,16},{f5,16},{d5,16},{a5,16},{g5,16},{a5,16},{a5,16},{g5,16},{f5,16},{a5,16},{d6,32},{e6,32/3},
    {g6,8/3},{g6,8/3}, //7-2

    {a4,8/3},{a4,4}, //7-3
};

void setup() {
    pinMode(Buzzer,OUTPUT);
    
    for(int i=0; i<(sizeof(NoteSong)/sizeof(NoteSong[0])); i++ ) {
      float _melody = pgm_read_float(&NoteSong[i].melody);
      float _tempo = pgm_read_float(&NoteSong[i].tempo);
        tone(Buzzer,_melody,term/_tempo);
        delay(term/_tempo*1.1);
    }
    
};

void loop() {};
