void setup() {
    // Initializing the serial output
    Serial.begin(9600);
    
    // Config interruptions
    cli();
    
    // Initiate counters
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;
    
    // Config max value to comparation
    OCR1A = 15624; // = (16*10^6) / (1*1024) - 1 (deve ser <65536)
    // Activate the CTC mode
    TCCR1B |= (1 << WGM12);
    // Defina os bits CS10 e CS12 para o pré-escalador de 1024
    TCCR1B |= (1 << CS12) | (1 << CS10);  
    // Habilitar interrupção de comparação de temporizador
    TIMSK1 |= (1 << OCIE1A);
    
    // Allow that interruptions
    sei();
    
    
    // Delcaring outputs
    const int PINLEDS = [ [1, 2, 3], [4, 5, 6], [7, 8, 9]];
    for(int ledLines = 0; ledLines < 3; ledLines++) {
    
        for (int ledColumns = 0; ledColums < 3; ledColumns++){
            pinMode(PINLEDS[ledLines][ledColumns], OUTPUT);
        }
    }
    
    
    treeLevel = 0;
    return;
}


void loop() {
    switch(treeLevel){
    case (0):
        attachInterrupt(digitalPinToInterrupt(PINLEDS[0][0]), digitalWrite(PINLEDS[0][0], HIGH), CHANGE);
        break;
    }
}





