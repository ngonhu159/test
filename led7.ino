/*
 * A B C  D là 4 chân input vào IC 7447 - nó là chân OUTPUT của NodeMCU
 */
#define A D0  
#define B D1
#define C D2
#define D D3

int Bin[4] = {0, 0, 0, 0};  
/* 
 *  Mảng Bin[4] ngày dùng để chứa giá trị binary của 1 số. 
 *  VD: Số 10 có binary là 1010 thì Bin[0] = 0, Bin[1] = 1, Bin[2] = 0, Bin[3] = 1
 *  Mảng sẽ chứa giá trị binary ngược lại với số binary của 1 số
 */
 
void Binary(int dec); /*-------- Hàm đổi số ở dạng DEC sang dạng BIN và lưu vào mảng BIN ---------*/

void setup()
{
   Serial.begin(9600);
   pinMode(A, OUTPUT);    /* khai báo 4 chân OUTPUT trong NodeMCU để điều khiển 4 chân INPUT IC 7447. Tương ứng A là D0, B là D1, C là D2, D là D3 */
   pinMode(B, OUTPUT);
   pinMode(C, OUTPUT);
   pinMode(D, OUTPUT);
}
void loop() {  
    Dislay();   /* Gọi hàm hiển thị led */
}
/*------------------------ Hàm chuyển đổi DEC sang BIN ---------------------------*/
void Binary(int dec)  
{
  Bin[0] = 0;       /* update lại giá trị 0 để không bị sai số trong mảng đã lưu trước */
  Bin[1] = 0;
  Bin[2] = 0;
  Bin[3] = 0;

  int i = 0;
  Serial.println("BIN: ");

  /*----- bắt đầu đổi DEC sang BIN -------*/
  while (dec != 0)
  {
    
    Bin[i] = dec % 2;      /*------ chia lấy phần dư ------*/ 
    Serial.print(Bin[i]);
    Serial.print(" : ");
    dec = dec/2;           /*------ cập nhật lại giá trị nguyên của số dec được truyền vào (chia lấy phần nguyên) ----------*/
    i++;
  }
}
/*------------------------------- Hàm hiển thị ---------------------------------*/
void Dislay()
{
  int dec = 0;
  Binary(dec);        /*---------------- gọi hàm đổi số DEC sang BIN, có tham số truyền vào là dec -----------------*/
  Serial.println("so khong"); /*------- Các Serial.print() là lệnh in ra màn hình Serial Monitor (cái kính lúp gốc trên bên phải màn hình) --------------*/
  Serial.print("Bin = ");
  Serial.print(Bin[0]);
  Serial.print(Bin[1]);
  Serial.print(Bin[2]);
  Serial.println(Bin[3]);
  /*
   * Ghi giá trị  vào các chân A B C D để mặc định ở trạng thái cao hay thấp
   * VD: dec = 1 thì truyền vào hàm Binary(dec) ta được kết quả Bin[0] = 1, Bin[1] = 0, Bin[2] = 0, Bin[3] = 0
   * Nghĩa là A sẽ xuất ra tính hiệu HIGH, B, C, D xuất tính hiệu LOW -> vào làm INPUT cho 7447
   * Các hàm dưới thì tương tự
   */ 
  digitalWrite(A,Bin[0]);
  digitalWrite(B,Bin[1]);
  digitalWrite(C,Bin[2]);
  digitalWrite(D,Bin[3]);
  delay(1000);
  
  dec = 1 ;
  Binary(dec);
  Serial.println("so mot");
  Serial.print("Bin = ");
  Serial.print(Bin[0]);
  Serial.print(Bin[1]);
  Serial.print(Bin[2]);
  Serial.println(Bin[3]);
  digitalWrite(A,Bin[0]);
  digitalWrite(B,Bin[1]);
  digitalWrite(C,Bin[2]);
  digitalWrite(D,Bin[3]);
  delay(1000);
  
  dec = 2;
  Binary(dec);
  Serial.println("so hai");
  digitalWrite(A,Bin[0]);
  digitalWrite(B,Bin[1]);
  digitalWrite(C,Bin[2]);
  digitalWrite(D,Bin[3]);
  delay(1000);
  dec = 3;
  Binary(dec);
 
  Serial.println("so ba");
  digitalWrite(A,Bin[0]);
  digitalWrite(B,Bin[1]);
  digitalWrite(C,Bin[2]);
  digitalWrite(D,Bin[3]);
  delay(1000);
  
  dec = 4;
  Binary(dec);
  Serial.println("so bon");
  digitalWrite(A,Bin[0]);
  digitalWrite(B,Bin[1]);
  digitalWrite(C,Bin[2]);
  digitalWrite(D,Bin[3]);
  delay(1000);
  
  dec = 5;
  Binary(dec);
  Serial.println("so nam");
  digitalWrite(A,Bin[0]);
  digitalWrite(B,Bin[1]);
  digitalWrite(C,Bin[2]);
  digitalWrite(D,Bin[3]);
  delay(1000);
  
  dec = 6;
  Binary(dec);
  Serial.println("so sau");
  digitalWrite(A,Bin[0]);
  digitalWrite(B,Bin[1]);
  digitalWrite(C,Bin[2]);
  digitalWrite(D,Bin[3]);
  delay(1000);
  
  dec = 7;
  Binary(dec);
  Serial.println("so bay");
  digitalWrite(A,Bin[0]);
  digitalWrite(B,Bin[1]);
  digitalWrite(C,Bin[2]);
  digitalWrite(D,Bin[3]);
  delay(1000);
  
  dec = 8;
  Binary(dec);
  Serial.println("so tam");
  digitalWrite(A,Bin[0]);
  digitalWrite(B,Bin[1]);
  digitalWrite(C,Bin[2]);
  digitalWrite(D,Bin[3]);
  delay(1000);
  
  dec = 9;
  Binary(dec);
  Serial.println("so chin");
  digitalWrite(A,Bin[0]);
  digitalWrite(B,Bin[1]);
  digitalWrite(C,Bin[2]);
  digitalWrite(D,Bin[3]);
  delay(1000);
}
