// 초음파 1
#define trigPin2 13                   // trigPin을 13으로 설정합니다.
#define echoPin2 12                // echoPin을 12로 설정합니다.

// 초음파 2
#define trigPin3 11                   // trigPin을 11으로 설정합니다.
#define echoPin3 10                // echoPin을 10로 설정합니다.

// 초음파 3
#define trigPin1 9                   // trigPin을 9으로 설정합니다.
#define echoPin1 8                // echoPin을 8로 설정합니다.

void setup()
{
  Serial.begin(9600);              // 시리얼 모니터를 사용하기 위해 보드레이트를 9600으로 설정합니다.
  
  pinMode(trigPin1, OUTPUT);   // trigPin 핀을 출력핀으로 설정합니다.
  pinMode(echoPin1, INPUT);    // echoPin 핀을 입력핀으로 설정합니다.
  
  pinMode(trigPin2, OUTPUT);   // trigPin 핀을 출력핀으로 설정합니다.
  pinMode(echoPin2, INPUT);    // echoPin 핀을 입력핀으로 설정합니다.
  
  pinMode(trigPin3, OUTPUT);   // trigPin 핀을 출력핀으로 설정합니다.
  pinMode(echoPin3, INPUT);    // echoPin 핀을 입력핀으로 설정합니다.
}

void loop()
{
  long duration1, distance1;                   // 각 변수를 선언합니다.
  long duration2, distance2;                   // 각 변수를 선언합니다.
  long duration3, distance3;                   // 각 변수를 선언합니다.
  
  digitalWrite(trigPin1, LOW);                 // trigPin에 LOW를 출력하고
  delayMicroseconds(2);                    // 2 마이크로초가 지나면
  digitalWrite(trigPin1, HIGH);                // trigPin에 HIGH를 출력합니다.
  delayMicroseconds(10);                  // trigPin을 10마이크로초 동안 기다렸다가
  digitalWrite(trigPin1, LOW);                // trigPin에 LOW를 출력합니다.
  duration1 = pulseIn(echoPin1, HIGH);   // echoPin핀에서 펄스값을 받아옵니다.

  
  digitalWrite(trigPin2, LOW);                 // trigPin에 LOW를 출력하고
  delayMicroseconds(2);                    // 2 마이크로초가 지나면
  digitalWrite(trigPin2, HIGH);                // trigPin에 HIGH를 출력합니다.
  delayMicroseconds(10);                  // trigPin을 10마이크로초 동안 기다렸다가
  digitalWrite(trigPin2, LOW);                // trigPin에 LOW를 출력합니다.
  duration2 = pulseIn(echoPin2, HIGH);   // echoPin핀에서 펄스값을 받아옵니다.

  
  digitalWrite(trigPin3, LOW);                 // trigPin에 LOW를 출력하고
  delayMicroseconds(2);                    // 2 마이크로초가 지나면
  digitalWrite(trigPin3, HIGH);                // trigPin에 HIGH를 출력합니다.
  delayMicroseconds(10);                  // trigPin을 10마이크로초 동안 기다렸다가
  digitalWrite(trigPin3, LOW);                // trigPin에 LOW를 출력합니다.
  duration3 = pulseIn(echoPin3, HIGH);   // echoPin핀에서 펄스값을 받아옵니다.
 
/*
      trigPin핀에서 초음파를 발사하였고 그 초음파가 다시 돌아 올 때까지 기다립니다.
      만약 벽이나 장애물에 닿아서 다시 echoPin으로 돌아왔다면 그동안의 시간을 duration에 저장합니다.
  */
 
distance1 = duration1 * 17 / 1000;          //  duration을 연산하여 센싱한 거리값을 distance에 저장합니다.
distance2 = duration2 * 17 / 1000;          //  duration을 연산하여 센싱한 거리값을 distance에 저장합니다.
distance3 = duration3 * 17 / 1000;          //  duration을 연산하여 센싱한 거리값을 distance에 저장합니다.

  /*
     거리는 시간 * 속도입니다.
     속도는 음속으로 초당 340mm이므로 시간 * 340m이고 cm단위로 바꾸기 위해 34000cm로 변환합니다.
     시간 값이 저장된 duration은 마이크로초 단위로 저장되어 있어, 변환하기 위해 1000000을 나눠줍니다.
     그럼 시간 * 34000 / 1000000이라는 값이 나오고, 정리하여 거리 * 34 / 1000이 됩니다.
     하지만 시간은 장애물에 닿기까지와 돌아오기까지 총 두 번의 시간이 걸렸으므로 2를 나누어줍니다.
     그럼 시간 * 17 / 1000이라는 공식이 나옵니다.
  */

  Serial.print("p1\t");
  Serial.println(distance1);                         // distance를 시리얼 모니터에 출력합니다.
//  Serial.println(" cm");                           // cm를 출력하고 줄을 넘깁니다.                                                           // distance가 10이면 10 cm로 출력됩니다.

  Serial.print("p2\t");
  Serial.println(distance2);                         // distance를 시리얼 모니터에 출력합니다.
//  Serial.println(" cm");                           // cm를 출력하고 줄을 넘깁니다.

  Serial.print("p3\t");
  Serial.println(distance3);                         // distance를 시리얼 모니터에 출력합니다.
//  Serial.println(" cm");                           // cm를 출력하고 줄을 넘깁니다.

  delay(600000);                                         // 1초동안 기다립니다.
}
