const int greenLED = A0;  // Đèn xanh
const int redLED = A1;    // Đèn đỏ
const int yellowLED = A2; // Đèn vàng

void setup() {
  // Thiết lập các chân LED là đầu ra
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  
  // Khởi động giao tiếp Serial
  Serial.begin(9600);

  // Bật đèn vàng trong 2 giây
  digitalWrite(yellowLED, HIGH);
  delay(2000);
  digitalWrite(yellowLED, LOW);
  Serial.println("start");
}

void loop() {
  // Kiểm tra nếu có dữ liệu từ Serial
  if (Serial.available() > 0) {
    String input = Serial.readString();

    // Loại bỏ ký tự xuống dòng và khoảng trắng thừa
    input.trim();
    
    // Kiểm tra giá trị đọc được từ Serial
    if (input.equalsIgnoreCase("True")) {
      digitalWrite(greenLED, HIGH);  // Bật đèn xanh
      digitalWrite(redLED, LOW);     // Tắt đèn đỏ
    } else if (input.equalsIgnoreCase("False")) {
      digitalWrite(greenLED, LOW);   // Tắt đèn xanh
      digitalWrite(redLED, HIGH);    // Bật đèn đỏ
    }
    
  }
}
