void setup() {
    Serial.begin(9600);
}

void loop() {
    float sensor_volt;
    float RS_air; //  Get the value of RS via in a clear air
    float R0;  // Get the value of R0 via in LPG
    float sensorValue;

    /*--- Get a average data by testing 100 times ---*/
    for(int x = 0 ; x < 100 ; x++)
    {
        sensorValue = sensorValue + analogRead(PA5);
    }
    sensorValue = sensorValue/100.0;
    /*-----------------------------------------------*/
    Serial.println(sensorValue);
    sensor_volt = (sensorValue/4096)*3.3;
    RS_air = ((5.0-sensor_volt)/sensor_volt)*15; // omit *RL
    R0 = RS_air/4.35; // The ratio of RS/R0 is 9.9 in LPG gas from Graph (Found using WebPlotDigitizer)

    Serial.print("sensor_volt = ");
    Serial.print(sensor_volt);
    Serial.println("V");

    Serial.print("R0 = ");
    Serial.println(R0);
    delay(1000);

}
