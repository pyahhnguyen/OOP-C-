#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define TRUE 1
#define INVALID_CITY_CODE -1

// Khai báo kiểu cấu trúc City
struct City {
    int code;
    char name[100];
    float area;
    int population;
};
// Định nghĩa cho kiểu "struct City" 1 tên mới ngắn gọn hơn, thay vì khai báo kiểu "struct City" thì ta chỉ cần dùng "City"
typedef struct City City;
 
// Khai báo kiểu cấu trúc LinkedList
struct LinkedList{
    City city;
    struct LinkedList *next;
 };
 // Định nghĩa cho kiểu "struct LinkedList" 1 tên mới ngắn gọn hơn, thay vì khai báo kiểu "struct LinkedList" thì ta chỉ cần dùng "Node"
 typedef struct LinkedList *Node;
 
// Hàm tạo mới 1 Node trong LinkedList
 Node createNode(City city){
    Node temp; // Khai báo 1 Node
    temp = (Node)malloc(sizeof(struct LinkedList)); // Cấp phát vùng nhớ cho Node
    temp->next = NULL;// Cho next trỏ tới NULL
    temp->city = city; // Gán giá trị cho Node
    return temp;
}
 
// Thêm vào cuối
Node addTail(Node head, City value){
    Node temp,p;// Khai báo 2 Node tạm temp và p
    temp = createNode(value);//Gọi hàm createNode để khởi tạo Node temp có next trỏ tới NULL và giá trị là value
    if(head == NULL){
        head = temp;     //Nếu linked list đang trống thì Node temp là head luôn
    }
    else{
        p  = head;// Khởi tạo p trỏ tới head
        while(p->next != NULL){
            p = p->next;//Duyệt danh sách liên kết đến cuối. Node cuối là Node có next = NULL
        }
        p->next = temp;//Gán next của thằng cuối = temp. Khi đó temp sẽ là thằng cuối(temp->next = NULL mà)
    }
    return head;
}
 
 // Thêm vào đầu
Node addHead(Node head, City value){
    Node temp = createNode(value); // Khởi tạo Node temp với data = value
    if(head == NULL){
        head = temp; // //Nếu linked list đang trống thì Node temp là head luôn
    }else{
        temp->next = head; // Trỏ next của temp = head hiện tại
        head = temp; // Đổi head hiện tại = temp(Vì temp bây giờ là head mới mà)
    }
    return head;
}
 
 // Thêm vào ở "chỉ số" (bắt đầu từ 0) bất kỳ, nếu muốn thêm theo "vị trí" (bắt đầu từ 1) thì giảm position đi 1 đơn vị
Node addAt(Node head, City value, int position){
    position = position - 1; // Thêm theo vị trí
    if(position == 0 || head == NULL){
        head = addHead(head, value); // Nếu vị trí chèn là 0, tức là thêm vào đầu
    }else{
        // Bắt đầu tìm vị trí cần chèn. Ta sẽ dùng k để đếm cho vị trí
        int k = 1;
        Node p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            // Nếu duyệt hết danh sách lk rồi mà vẫn chưa đến vị trí cần chèn, ta sẽ mặc định chèn cuối
            // Nếu bạn không muốn chèn, hãy thông báo vị trí chèn không hợp lệ
            head = addTail(head, value);
            // printf("Vi tri chen vuot qua vi tri cuoi cung!\n");
        }else{
            Node temp = createNode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}
 
Node delHead(Node head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }else{
        head = head->next;
    }
    return head;
}
 
Node delTail(Node head){
    if (head == NULL || head->next == NULL){
         return delHead(head);
    }
    Node p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next; // Cho next bằng NULL
    return head;
}
 
 // Xóa Node ở "chỉ số" (bắt đầu từ 0) bất kỳ
Node delAt(Node head, int position){
    if(position == 0 || head == NULL || head->next == NULL){
        head = delHead(head); // Nếu vị trí xóa là 0, tức là thêm vào đầu
    }else{
        // Bắt đầu tìm vị trí cần xóa. Ta sẽ dùng k để đếm cho vị trí
        int k = 1;
        Node p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            // Nếu duyệt hết danh sách lk rồi mà vẫn chưa đến vị trí cần chèn, ta sẽ mặc định xóa cuối
            // Nếu bạn không muốn xóa, hãy thông báo vị trí xóa không hợp lệ
            head = delTail(head);
            // printf("Vi tri xoa vuot qua vi tri cuoi cung!\n");
        }else{
            p->next = p->next->next;
        }
    }
    return head;
}
 
void traverser(Node head){
    printf("Danh sach hien tai:\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("%10s%50s%20s%20s\n", "Ma Tinh/TP", "Tinh thanh", "Dien tich", "Dan so");
    for(Node p = head; p != NULL; p = p->next){
        printf("%10d%50s%20f%20d\n", p->city.code, p->city.name, p->city.area, p->city.population);
    }
    printf("------------------------------------------------------------------------------------------------------------\n");
}
 
// Hàm khởi tạo Node đầu tiên của LinkedList
Node initHead(){
    Node head;
    head = NULL;
    return head;
}
 
// Hàm tách các thành phần của 1 dòng trong file
City handleLineData(char *line){
    City city;
    city.code = INVALID_CITY_CODE; // Khởi tạo giá trị không hợp lệ. Về sau ta có thể kiểm tra.
    const char delimiter[] = "\t";
    char *tmp;
    tmp = strtok(line, delimiter);
    if (tmp == NULL) {
        printf("Du lieu khong dung dinh dang: %s", line);
        exit(EXIT_FAILURE);
    }
   city.code = atoi(tmp);
    int index = 0;
    for (;;index++) {
        tmp = strtok(NULL, delimiter);
        if (tmp == NULL)
            break;
        if (index == 0){
            strcpy(city.name, tmp);
        }else if (index == 1){
           city.area = (float)atof(tmp);
        }else if (index == 2){
            city.population = atoi(tmp);
        }else {
            printf("Du lieu khong dung dinh dang: %s", line);
            exit(EXIT_FAILURE);
        }
    }
    return city;
}
 
// Hàm đọc dữ liệu từ tập tin
Node readData(Node head, const char* fileName){
    FILE* file = fopen(fileName, "r");
    if(!file){
        printf("Co loi khi mo file : %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    char line[500];
    while (fgets(line, sizeof(line), file)) {
        City city = handleLineData(line);
        if (city.code != INVALID_CITY_CODE) {
            head = addTail(head, city);
        }
    }
    fclose(file);
    return head;
}
 
City createCity(){
    City newCity;
    char *p;
    printf("Nhap code: ");
    scanf("%d", &newCity.code);
    printf("Nhap ten: ");
    getchar();
    fgets(newCity.name, 100, stdin);
    // Xóa \n ở cuối chuỗi vừa nhập nếu có
    if ((p=strchr(newCity.name, '\n')) != NULL){
        *p = '\0';
    }
    printf("Nhap dien tich: ");
    scanf("%f", &newCity.area);
    printf("Nhap dan so: ");
    scanf("%d", &newCity.population);
    return newCity;
}
 
Node addNode(Node head){
    City newCity;
    char option;
    int position;
    while (TRUE) {
        printf("========== Nhap du lieu can them ===============\n");
        printf("Nhap vi tri muon them: ");
        scanf("%d", &position);
        newCity = createCity();
        head = addAt(head, newCity, position);
        printf("Them thanh cong? Them tiep (Y/n)? ");
        getchar(); // Bỏ qua '\n' trong bộ đệm
        scanf("%c", &option);
        if (option == 'N' || option == 'n'){
            break;
        }
    }
    return head;
}
 
// Hàm tìm chỉ số của Node có dữ liệu thành phố mà mã code của nó trùng với giá trị cần tìm
int findIndexByCode(Node head, int code){
    int index = -1;
    for(Node p = head; p != NULL; p = p->next){
        index++;
        if (p->city.code == code){
            return index;
        }
    }
    return -1; // Không tìm thấy
}
 
void editNode(Node head){
    int code;
    char option;
    City newCity;
    while (TRUE) {
        printf("========== Chon Node muon sua ===============\n");
        printf("Nhap ma tinh/thanh pho can sua: ");
        scanf("%d", &code);
        int found = 0;
        for(Node p = head; p != NULL; p = p->next){
            if (p->city.code == code){
                found = 1;
                newCity = createCity();
                p->city = newCity;
                break;
            }
        }
        if (found) {
            printf("Sua thanh cong! Sua tiep (Y/n)? ");
        }else {
            printf("Khong tim thay du lieu! Sua tiep (Y/n)? ");
        }
        getchar(); // Bỏ qua '\n' trong bộ đệm
        scanf("%c", &option);
        if (option == 'N' || option == 'n'){
            break;
        }
    }
}
 
Node removeNode(Node head){
    int code;
    char option;
    while (TRUE) {
        printf("========== Chon Node muon xoa ===============\n");
        printf("Nhap ma tinh/thanh pho can xoa: ");
        scanf("%d", &code);
        int position = findIndexByCode(head, code);
        if (position < 0){
            printf("Khong tim thay du lieu can xoa! Xoa tiep (Y/n)? ");
        }else {
            head = delAt(head, position);
            printf("Xoa thanh cong? Xoa tiep (Y/n)? ");
        }
        getchar(); // Bỏ qua '\n' trong bộ đệm
        scanf("%c", &option);
        if (option == 'N' || option == 'n'){
            break;
        }
    }
    return head;
}
 
// Hàm tính tổng diện tích các thành phố trong DSLK
float sumArea(Node head){
    float sum = 0;
    for(Node p = head; p != NULL; p = p->next){
        sum += p->city.area;
    }
    return sum;
}
 
 
// Hàm tìm chỉ số của Node có diện tích lớn nhất (giả sử chỉ có 1)
// Nếu dữ liệu có nhiều hơn 1, chúng ta tìm max rồi duyệt lại 1 lần nữa để tìm ra các Node có giá trị = max đó
int indexOfMaxArea(Node head){
    int maxIndex = 0, index = 0;
    int maxArea = head->city.area;
    for(Node p = head; p != NULL; p = p->next){
        if (p->city.area > maxArea){
            maxArea = p->city.area;
            maxIndex = index;
        }
        index++;
    }
    return maxIndex;
}
 
// Hàm tìm Node có dân số lớn nhất
City maxByPopulation(Node head){
    City city = head->city;
    for(Node p = head; p != NULL; p = p->next){
        if (p->city.population > city.population){
            city = p->city;
        }
    }
    return city;
}
 
void swapCityData(City *a, City *b){
    City tmp = *a;
    *a = *b;
    *b = tmp;
}
 
// Hàm sắp xếp 
// Nếu sort theo code, thì byCode = 1, byArea = 0
// Nếu sort theo area, thì byCode = 0, byArea = 1
// Nếu sắp xếp tăng dần thì desc = 0, giảm dần thì desc = 1
void sortCities(Node head, int byCode, int byArea, int desc){
    for(Node p = head; p != NULL; p = p->next){
        for(Node q = p->next; q != NULL; q = q->next){
            if (desc){
                if (byCode && p->city.code < q->city.code){
                    swapCityData(&p->city, &q->city);
                }else if (byArea && p->city.area < q->city.area){
                    swapCityData(&p->city, &q->city);
                }
            }else {
                if (byCode && p->city.code > q->city.code){
                swapCityData(&p->city, &q->city);
                }else if (byArea && p->city.area > q->city.area){
                    swapCityData(&p->city, &q->city);
                }
            }
        }
    }
}
 
void printMenu(){
    printf("================== MENU ====================\n");
    printf("1. Duyet danh sach\n");
    printf("2. Them du lieu (them Node)\n");
    printf("3. Sua du lieu (sua Node)\n");
    printf("4. Xoa du lieu (xoa Node)\n");
    printf("5. Tinh tong dien tich\n");
    printf("6. Tim dia chi cua Node co dien tich lon nhat\n");
    printf("7. Tim tinh co dan so lon nhat\n");
    printf("8. Sap xep danh sach theo ma tinh\n");
    printf("9. Sap xep danh sach theo dien tich\n");
    printf("10. Thoat chuong trinh\n");
    printf("============================================\n");
}
 
int main(){
   /* FILE *fptr;
    
   fptr = fopen("DS_CAC_TINH.txt", "w+");*/
    
    Node head = initHead();
   
    traverser(head);
     head = readData(head, "DS_CAC_TINH.txt");
    int option;
    City result;
    while (TRUE) {
        printMenu();
        printf("Nhap lua chon cua ban (1-10): ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                traverser(head);
                break;
            case 2:
                head = addNode(head);
                break;
            case 3:
                editNode(head);
                break;
            case 4:
                head = removeNode(head);
                break;
            case 5:
                printf("Tong dien tich: %f\n", sumArea(head));
                break;
            case 6:
                printf("Tinh co dien tich lon nhat o vi tri: %d\n", indexOfMaxArea(head) + 1); // vị trí = chỉ số + 1
                break;
            case 7:
                result = maxByPopulation(head);
                printf("%s la noi co dien tich lon nhat voi %d nguoi!\n", result.name, result.population);
                break;
            case 8:
                sortCities(head, 1, 0, 0);
                traverser(head);
                break;
            case 9:
                sortCities(head, 0, 1, 0);
                traverser(head);
                break;
            case 10:
                printf("Ket thuc chuong trinh!...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Lua chon khong dung, vui long nhap lai!\n");
                break;
        }
    }
}