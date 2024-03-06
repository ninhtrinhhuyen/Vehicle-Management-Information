# Vehicle Management Information

TỔNG QUAN VỀ BÀI TẬP
    Công ty X là một công ty về gia công và sản xuất phần mềm trên xe ô tô. Bạn được yêu cầu viết một chương trình cài đặt và quản lý cơ sở dữ liệu chương trình cài đặt các thông số của một số xe ô tô trước khi xuất xưởng để bán.
    Chương trình sẽ bao gồm các chức năng cơ bản như sau:
        +> Nhập thông tin cài đặt của các chức năng: Display, Sound, General
        +> Xuất thông tin cài đặt cho các chức năng: Display, Sound, General
        +> Xuất thông tin cho toàn bộ các cài đặt kèm theo phân loại theo tên chủ nhân xe. Điều này có nghĩa rằng 1 chiếc xe cần có đủ thông tin cài đặt cho cả 3 thông số Display, General và Sound
        +> Trong dự án này bạn cần phải sử dụng các kiến thức về lập trình xử lý dữ liệu với binary tree, và các thuật toán tìm kiếm để tìm kiếm giữ liệu, xử lý ngoại lệ, thao tác với file, đọc/ghi thông tin cài đặt ra file (text file) và validate dữ liệu.
        +> Thông tin cài đặt sẽ được đọc từ file (khi có cài đặt trước đó), và update vào file khi có cài đặt mới
        +> Sử dụng Binary Tree Search để lưu trữ dữ liệu
        +> Thực hiện download list timezone, language (từ file txt) và đưa lựa chọn cho người sử dụng với chức năng General

Chương trình sẽ bao gồm các chức năng cơ bản như sau:
    +> Thực hiện đọc file và đưa dữ liệu vào chương trình để thực hiện cập nhật và hiển thị dữ liệu theo các  chức năng.
    +> Kiểu tra các dữ liệu đầu vào.
    +> Sắp xếp dữ liệu timezone, language theo Anphabet hoặc theo utc/index rồi hiển thị ra màn hình
    +> Sắp xếp dữ liệu hiển thị của từng chức năng theo MSCN hoặc theo tên chủ xe
    +> Tìm kiếm kiếm cài đặt theo mã số cá nhân hoặc tên của chủ xe và xuất ra màn hình thông tin cài đặt của các chức năng Display, Sound, General tương ứng với xe có mã số đó

File Setting
    +> Cài đặt và quản lý các thông tin chung cần quản lý là Tên xe, mã số cá nhân, email người sử dụng, ODO, thông tin km cần đến để bảo dưỡng xe.
    +> Setting.txt lưu trữ thông tin cài đặt của các chức năng.
        Format: Common: [Common information] Display: [Display information] Sound: [Sound information] General: [General information]

File Display
    +> Cài đặt và quản lý các giá trị âm thanh cho: Media volume level, Call volume level, Navigation volume level, Notification volume level.

File Sound
    +> Cài đặt và quản lý liên quan đến việc hiển thị trên màn hình. Quản lý và cài đặt các giá trị về light level, screen light level, taplo light level.

File General
    +> Thực hiện cài đặt và quản lý  timezone và  languages.
    +> Thực hiện download list timezone, language (từ file txt) và đưa lựa chọn cho người sử dụng với chức năng General

File Data
    +> Thực hiện kiểm tra các dữ liệu đầu vào, sắp xếp, so sánh dữ liệu sử dụng trong chương trình.

File CommonInfo
    +> Class sử dụng để lưu trữ time zone, language đọc từ file .txt

File BinaryTreeSearch
    +> Binary tree search quản lý dữ liệu cho Display Sound và General

File main
    +> Các giao diện chương trình.
    +> Hiện thị thông tin của xe ra màn hình.

Nếu anh chị dùng windown thì vào giúp em file Data.cpp sửa hàm
void data::clearConsole()
{
    std::system("clear"); -> std::system("cls");
}

Version: C++ 20