// code from circuit digest
// Motor Driver Pin Definitions
#define enA 5  // Enable1 for Motor1  
#define in1 6  // Motor1 Input 1  
#define in2 7  // Motor1 Input 2  
#define in3 9  // Motor2 Input 3  
#define in4 10 // Motor2 Input 4  
#define enB 8  // Enable2 for Motor2  

// IR Sensor Pin Definitions
#define R_S 4  // Right IR Sensor  
#define L_S 2  // Left IR Sensor  

void setup() {  
    // Set IR sensor pins as input
    pinMode(R_S, INPUT);  
    pinMode(L_S, INPUT);  
    
    // Set motor driver pins as output
    pinMode(enA, OUTPUT);  
    pinMode(in1, OUTPUT);  
    pinMode(in2, OUTPUT);  
    pinMode(in3, OUTPUT);  
    pinMode(in4, OUTPUT);  
    pinMode(enB, OUTPUT); 

    // Enable motors
    digitalWrite(enA, HIGH);  
    digitalWrite(enB, HIGH);  
    delay(1000); 
} 

void loop() {   
    // Read IR sensor values
    int rightSensor = digitalRead(R_S);
    int leftSensor = digitalRead(L_S);
    
    // Line-following logic
    if (rightSensor == 1 && leftSensor == 1) {
        forward();  // Move forward if both sensors detect black (on line)
    }   
    else if (rightSensor == 0 && leftSensor == 1) {
        turnLeft();  // Turn left if right sensor detects white
    }   
    else if (rightSensor == 1 && leftSensor == 0) {
        turnRight();   // Turn right if left sensor detects white
    }   
    else if (rightSensor == 0 && leftSensor == 0) {
        Stop();  // Stop if both sensors detect white (off track)
    } 
} 

// Function to Move Forward
void forward() {  
    digitalWrite(in1, HIGH); // Right Motor Forward  
    digitalWrite(in2, LOW);  
    digitalWrite(in3, LOW);  
    digitalWrite(in4, HIGH); // Left Motor Forward  
} 

// Function to Turn Right
void turnRight() { 
    digitalWrite(in1, LOW);  // Stop Right Motor  
    digitalWrite(in2, LOW);  
    digitalWrite(in3, LOW);  
    digitalWrite(in4, HIGH); // Move Left Motor Forward  
} 

// Function to Turn Left
void turnLeft() { 
    digitalWrite(in1, HIGH); // Move Right Motor Forward  
    digitalWrite(in2, LOW);  
    digitalWrite(in3, HIGH); // Stop Left Motor  
    digitalWrite(in4, LOW);  
} 

// Function to Stop Robot
void Stop() {  
    digitalWrite(in1, LOW);  
    digitalWrite(in2, LOW);  
    digitalWrite(in3, LOW);  
    digitalWrite(in4, LOW);  
}

