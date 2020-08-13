void setup() {
    Serial.begin(9600);
}

void loop() {

    float mq4_sensor_volt;
    float mq9_sensor_volt;
    float mq135_sensor_volt;
    
    float mq4_RS_gas; // Get value of RS in a GAS
    float mq9_RS_gas;
    float mq135_RS_gas;
    
    float mq4_ratio; // Get ratio RS_GAS/RS_air
    float mq9_ratio;
    float mq135_ratio;

    //calcutating mq4 sensor ratio..
    
    float mq4_sensorValue=analogRead(PA5);
    /* dividing by 4096 is because stm32 has a 12 bit ADC and multiplying by 
     *  3.3 is because maximum voltage input for ADC is 3.3v
     */
    mq4_sensor_volt=((mq4_sensorValue/4096)*3.3);
    mq4_RS_gas = ((5.0-mq4_sensor_volt)/mq4_sensor_volt)*15; // omit *RL
    mq4_ratio = mq4_RS_gas/9.3;  // ratio = RS/R0
   /*-----------------------------------------------------------------------*/

    //calcutating mq9 sensor ratio..
    
    float mq9_sensorValue=analogRead(PA6);
    mq9_sensor_volt=((mq9_sensorValue/4096)*3.3);
    mq9_RS_gas = ((5.0-mq9_sensor_volt)/mq9_sensor_volt)*15; // omit *RL
    mq9_ratio = mq9_RS_gas/1.5;  // ratio = RS/R0
   /*-----------------------------------------------------------------------*/

   //calcutating mq135 sensor ratio..
    
    float mq135_sensorValue=analogRead(PA7);
    mq135_sensor_volt=((mq135_sensorValue/4096)*3.3);
    mq135_RS_gas = ((5.0-mq135_sensor_volt)/mq135_sensor_volt)*15; // omit *RL
    mq135_ratio = mq135_RS_gas/8;  // ratio = RS/R0
   /*-----------------------------------------------------------------------*/
   
    Serial.print("Mq4 Rs/R0 = ");
    Serial.println(mq4_ratio);
    Serial.print("\n\n");

    Serial.print("Mq9 Rs/R0 = ");
    Serial.println(mq9_ratio);
    Serial.print("\n\n");

    Serial.print("Mq135 Rs/R0 = ");
    Serial.println(mq135_ratio);
    Serial.print("\n\n");

    delay(5000);

}
