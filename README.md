# Report
## Link Demo: https://drive.google.com/file/d/1OHyskjAcM45dtZZ0ufqao98GH_np6-rj/view?usp=drive_link

## Giới thiệu
- Dự án game này được phát triển bởi Hoàng Linh(Tôi), MSV:22024567. Mục tiêu của dự án là tạo ra một trò chơi giải trí với gameplay giải đố, mang lại trải nghiệm giải trí vui vẻ cho người chơi.

![title](https://github.com/user-attachments/assets/b904701c-75b3-4ee4-9d4a-d1ba936b0bf6)

- [0. Cách tải game](#0-cách-tải-game)
    * [a. Cách 1: Không bao gồm code.](#a-cách-1-không-bao-gồm-code)
    * [b. Cách 2: Bao gồm code và có thể biên dịch.](#b-cách-2-bao-gồm-code-và-có-thể-biên-dịch)
- [1. Bắt đầu game](#1-bắt-đầu-game)
- [2. Công nghệ sử dụng](#2-công-nghệ-sử-dụng)
- [3. Các thành phần trong game:](#3-các-thành-phần-trong-game)
- [4. Đồ họa](#4-đồ-họa)
- [5. Cách chơi và khi thất bại](#5-cách-chơi-và-khi-thất-bại)

## 0. Cách tải game
### a. Cách 1: Không bao gồm code.

- Tải game (được nén thành .zip) tại link sau: https://github.com/Krystine-825/project_game/releases/tag/pulished<br/>
- Cách này tiết kiệm bộ nhớ và thời gian tải đi rất nhiều (khoảng 205MB).<br/>
- Giải nén game vào một thư mục và bật SDL_Test.exe lên và chơi.<br/>

### b. Cách 2: Bao gồm code và có thể biên dịch.

**Bước 1:** Clone repo này về hoặc Chọn Code -> Download Zip. Giải nén code ra 1 folder.<br/> 
**Bước 2:** Mở file `SDL_Test.sln` trong Visual Studio Thiết lập C/C++ Configuration. Các thư viện SDL cần thiết đã được thêm vào project(trong thư mục deps) Đưa mode build về debug-x86.<br/> 
**Bước 3:** Bấm vào `Local Windows Debugger` để khởi động game.<br/> 

## 1. Bắt đầu game
- Nhấn bất kì nút nào trên bàn phím để bắt đầu
![title](https://github.com/user-attachments/assets/b904701c-75b3-4ee4-9d4a-d1ba936b0bf6)

## 2. Công nghệ sử dụng
- Ngôn ngữ lập trình: `C++`
- Thư viện: `SDL2.0`
- Công cụ phát triển: `Visual Studio`, `GitHub`

## 3. Các thành phần trong game:
- Nhận vật chính:
![PlayerUp](https://github.com/user-attachments/assets/546ebfd3-b676-4106-96d6-4d0f2cc0409e)
- Bẫy:
![SpikeTrapActive](https://github.com/user-attachments/assets/9e160f09-b0cb-4be1-b529-341d24d77f76)
![SpikeTrapInactive](https://github.com/user-attachments/assets/f61432df-e634-43e4-85ae-bf281cf47ab0)
- Lính canh:
![Guard](https://github.com/user-attachments/assets/39fab932-9997-49c2-a771-752cdc37c0d6)
- Chìa khóa:
![Key](https://github.com/user-attachments/assets/39cf6711-4f39-437d-a4f2-88b927ccd67d)
- Ổ khóa:
![Lock](https://github.com/user-attachments/assets/a708aaf2-6d53-4680-bec8-bc98768160a7)


## 4. Đồ họa
- Đồ họa: Sử dụng đồ họa 2D của thư viện `SDL`.
![gameplay1](https://github.com/user-attachments/assets/f22bbe26-4191-49bc-b403-6e51f4c7ac5a)


## 5. Cách chơi và khi thất bại
- **Di chuyển**: Sử dụng các phím mũi tên  `←` `→` `↑` `↓` để điều khiển nhân vật chính.
- **Mục tiêu**: Vượt chướng ngại vật để lấy chìa khóa và tới ổ khóa để qua màn
 - Từ màn 3 trở đi sẽ có bãy:
![image](https://github.com/user-attachments/assets/049d1dc8-8044-448b-9ac5-f8ee37c1d510)
 - Từ màn 6 trở đi sẽ có lính canh:
![image](https://github.com/user-attachments/assets/c2dd8e0d-370c-427f-9348-3a393775c36b)
- **Lưu ý**:
 - Game không có màn chiến thắng vì độ khó game là vô tận
 - Nếu thấy khó có thể Bấm `R` để reset màn chơi nhưng đồng nghĩa với việc mất 1 mạng
   ![image](https://github.com/user-attachments/assets/f7126afd-b85c-42b2-a8f8-2aa180f0748e)
- **Thất bại**:
![GameOver](https://github.com/user-attachments/assets/11c822d3-f444-4ca3-b02d-28f02145ff4d)


**Nguồn tham khảo**:
- Github
- Lazyfool
- Youtube
- Pacman game

