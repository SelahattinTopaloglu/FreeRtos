#include <Arduino_FreeRTOS.h>
void MyTas1( void *pvParameters );
void MyTask2( void *pvParameters );
void MyTask3( void *pvParameters );
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  
  pinMode(3, OUTPUT);
  
  pinMode(4, OUTPUT);

  xTaskCreate(MyTask1, "Task1", 100, NULL, 1, NULL);//MyTask1 fonk. ismi // 1 ise ilk yapılacak iş olduğunu belirtmek için kullandık
  xTaskCreate(MyTask2, "Task2", 100, NULL, 2, NULL);
  xTaskCreate(MyTask3, "Task3", 100, NULL, 3, NULL);
}

void loop() {
  // put your main code here, to run repeatedly:

  
  
  

}

static void MyTask1(void* pvParameters)
{
 while (true){
 digitalWrite(2, HIGH);
 vTaskDelay(1000 / portTICK_PERIOD_MS);//100 ms
 digitalWrite(2, LOW);
 vTaskDelay(2000 / portTICK_PERIOD_MS);
 Serial.println(F("Task1"));
 }
}
 
static void MyTask2(void* pvParameters)
{
 while (true) {
  vTaskDelay(1000 / portTICK_PERIOD_MS);//1000 ms
 digitalWrite(3, HIGH);
 vTaskDelay(1000 / portTICK_PERIOD_MS);//1000 ms
 digitalWrite(3, LOW);
 vTaskDelay(1000 / portTICK_PERIOD_MS);
 
 Serial.println(F("Task2"));
 }
}
 
static void MyTask3(void* pvParameters)
{
 while (true){
  
  vTaskDelay(2000 / portTICK_PERIOD_MS);//1000 ms
 digitalWrite(4, HIGH);
 vTaskDelay(1000 / portTICK_PERIOD_MS);//2000 ms
 digitalWrite(4, LOW);
 
 Serial.println(F("Task3"));
 }
}
