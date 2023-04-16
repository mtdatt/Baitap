#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<vector>

using namespace std;
class SinhVien
{
private:
    int id;
    char TenHocSinh[20];
    char GioiTinh[4];
    int TuoiHocSinh;
    double diemToan;
    double diemLy;
    double diemHoa;
    double diemTB;
    char  LucHoc[11] ;
public: 
    SinhVien(const char ten[20], const char gtinh[4],const int tuoi, const double toan, const double ly, const double hoa); // constructor
    void setTenHocSinh(const char ten[]);
    void setGioiTinh(const char gioi_tinh[]);
    void setTuoiHocSinh(int tuoi);
    void setdiemToan(double toan);
    void setdiemLy(double ly);
    void setdiemHoa(double hoa);

    int get_id();
    char *getTenHocSinh();
    char *getGioiTinh();
    int getTuoiHocSinh();
    double getdiemToan();
    double getdiemLy();
    double getdiemHoa();
    double getdiemTB();
    char *getHocLuc();
};
///// ----------------tạo id --------------------
SinhVien::SinhVien(const char ten[20], const char gtinh[4],const int tuoi, const double toan, const double ly, const double hoa)
{
    static int id =100;
    SinhVien::id = id;
    id ++;
    strcpy(SinhVien::TenHocSinh, ten);
    strcpy(SinhVien::GioiTinh, gtinh);
    SinhVien::TuoiHocSinh = tuoi;
    SinhVien::diemToan = toan;
    SinhVien::diemLy = ly;
    SinhVien::diemHoa = hoa;
}

int SinhVien::get_id()
{
    return id;
}
/// -----------------tên -----------
void SinhVien::setTenHocSinh(const char ten[])
{
    strcpy(TenHocSinh, ten);
}
char *SinhVien::getTenHocSinh()
{
    return TenHocSinh;
}
//---------------giới tính ----------
void SinhVien::setGioiTinh(const char gioi_tinh[])
{
    if((strcmp((char*)"Nam", gioi_tinh)!=0) && (strcmp( (char*)"Nu", gioi_tinh)!=0)&& (strcmp("nu", gioi_tinh) != 0) && (strcmp("nam", gioi_tinh) != 0))
    {
        printf("Error!! Gioi tinh khong hop le.\n");
    }
    else
    {
        strcpy(GioiTinh, gioi_tinh);
    }
}
char *SinhVien::getGioiTinh()
{
    return GioiTinh;
}
///--------------- tuổi ----------------
void SinhVien::setTuoiHocSinh(int tuoi)
{
    TuoiHocSinh = tuoi;
}
int SinhVien::getTuoiHocSinh()
{
    return TuoiHocSinh;
}
/// -------------điểm Toán---------------
void SinhVien::setdiemToan(double toan)
{
    diemToan = toan;
}
double SinhVien::getdiemToan()
{
    return diemToan;
}
/// -------------điểm lý -----------------
void SinhVien::setdiemLy(double ly)
{
    diemLy = ly;
}
double SinhVien::getdiemLy()
{
    return diemLy;
}
/// -------------điểm hóa ----------------
void SinhVien::setdiemHoa(double hoa)
{
    diemHoa= hoa;
}
double SinhVien::getdiemHoa()
{
    return diemHoa;
}
/// -----------điểm trung bình -------------

double SinhVien::getdiemTB()
{
    return SinhVien::diemTB = (diemToan + diemLy + diemHoa)/3;
}
/// --------------học lưc --------------
char *SinhVien::getHocLuc()
{
    if(getdiemTB()>=8)
    {
        strcpy(LucHoc, "Gioi");
    }
    else if (getdiemTB()>=6.5)
    {
        strcpy(LucHoc, "Kha");
    }
    else if (getdiemTB()>=5)
    {
        strcpy(LucHoc, "Trung Binh");
    }
    else
    {
        strcpy(LucHoc,"Yeu");
    }
    return LucHoc;
}

////////////////////////////////
class Menu
{
private:
   vector<SinhVien> danhsachSinhVien;
   
public: 
   void themsinhvien();
   void CapNhatTT();
   void XoaSinhVien();
   void TimKiemTheoTen();
   void SapXepTheoGPA();
   void SapXepTheoTen();
   void hienthidanhsach();

};

#define NhapThongTin(noidung, dinhdang, bien, dieukien)   \
    do{                                                   \
        printf(noidung);                                  \
        scanf(dinhdang, &bien);                           \
    }                                                     \
    while (dieukien);                                     \

/// ---------thêm sinh viên----------------------------------/
void Menu::themsinhvien()
{
    char ten[20];
    char gt[4];
    int tuoi;
    double diemtoan;
    double diemly;
    double diemhoa;
    uint8_t key;
    do
    {
    printf("Nhap thong tin sv can them: \n");
    do{
    printf("Nhap ten: ");
    }while(scanf("%s", ten));
    
    do
    {
        printf("Nhap gioi tinh(Nam/Nu): ");
        scanf("%s", gt);
    } while ((strcmp((char*)"Nam", gt)!=0) && (strcmp( (char*)"Nu", gt)!=0)&& (strcmp("nu", gt) != 0) && (strcmp("nam", gt) != 0));

    NhapThongTin("Nhap tuoi: ",      "%d",  tuoi,      tuoi<6 || tuoi >100);
    NhapThongTin("Nhap diem Toan: ", "%lf", diemtoan,  diemtoan <0 || diemtoan >10);
    NhapThongTin("Nhap diem Ly: " ,  "%lf", diemly  ,  diemly<0 || diemly >10);
    NhapThongTin("Nhap diem Hoa: ",  "%lf", diemhoa,   diemhoa<0 || diemhoa >10);
    SinhVien sv(ten, gt, tuoi, diemtoan, diemly, diemhoa);
    danhsachSinhVien.push_back(sv);
    printf("Nhan '1' de tiep tuc them sv hoac nhan bat ky de thoat ");
    scanf("%d", &key);

    } while (key == 1);
}

//----------------Cập nhật thông tin sinh viên----------------------/
void Menu::CapNhatTT()
{
    int id;
    int i=0;
    char ten[20];
    char gt[11];
    int tuoi;
    double diemtoan;
    double diemly;
    double diemhoa;
    
    printf("Nhap id sinh vien can cap nhat thong tin: ");
    scanf("%d", &id);
    for(SinhVien sv : danhsachSinhVien)
    {
        if(sv.get_id() ==id)
        {
            printf("Nhap ten: ");
            scanf("%s", &ten);
            do
            {
              printf("Nhap gioi tinh(Nam/Nu): ");
               scanf("%s", gt);
            } while ((strcmp((char*)"Nam", gt)!=0) && (strcmp( (char*)"Nu", gt)!=0)&& (strcmp("nu", gt) != 0) && (strcmp("nam", gt) != 0));

            NhapThongTin("Nhap tuoi: ",      "%d",  tuoi,      tuoi<6 || tuoi >100);
            NhapThongTin("Nhap diem Toan: ", "%lf", diemtoan,  diemtoan <0 || diemtoan >10);
            NhapThongTin("Nhap diem Ly: " ,  "%lf", diemly  ,  diemly<0 || diemly >10);
            NhapThongTin("Nhap diem Hoa: ",  "%lf", diemhoa,   diemhoa<0 || diemhoa >10);
            

            (danhsachSinhVien.at(i)).setTenHocSinh(ten);
            (danhsachSinhVien.at(i)).setGioiTinh(gt);
            (danhsachSinhVien.at(i)).setTuoiHocSinh(tuoi);
            (danhsachSinhVien.at(i)).setdiemToan(diemtoan);
            (danhsachSinhVien.at(i)).setdiemLy(diemly);
            (danhsachSinhVien.at(i)).setdiemHoa(diemhoa);
        }
        i++;
        if(i == danhsachSinhVien.size() && sv.get_id()!=id)
        {
            printf("Khong co ID sinh vien %d.\n", id);
        }
    }

}
// ---------------Xoa sinh vien-------------------------------------/
void Menu::XoaSinhVien()
{
    int id;
    int i=0; // biến i để tính thứ tự muốn xóa
    printf("Nhap id sinh vien muon xoa: ");
    scanf("%d", &id);
    for (SinhVien sv : danhsachSinhVien)
    {
        if(sv.get_id()==id)
        {
            danhsachSinhVien.erase(danhsachSinhVien.begin()+i); // xóa sinh viên thứ 0 + i trong danh sach svien
            printf("Da xoa sinh vien co id: %d\n", id);
            return;

        }
        i++; // sau mỗi lần duyệt i tăng 1
        if(i == danhsachSinhVien.size() && sv.get_id()!=id)
        {
            printf("Khong co ID sinh vien %d ma ban muon xoa.\n", id);
        }
    }
    
}

/// ------------Tìm kiếm theo tên---------------------------------------/
void Menu::TimKiemTheoTen()
{
    char ten[20];
    int i=0;
    printf("Nhap ten sinh vien ban muon tim kiem: ");
    scanf("%s", &ten);
    for(SinhVien sv : danhsachSinhVien)
    {
       if(strcmp(sv.getTenHocSinh(), ten)==0)
       {
           printf("Thong tin sinh vien can tim:\n");
           printf("ID\t Ten\t Tuoi\t GioiTinh\tToan\t Ly\t Hoa\t GPA\t Hoc_Luc\t\n");
           printf("%d\t %s\t %d\t  %s\t\t%.2lf\t%.2lf\t%.2lf\t %.2lf\t %s\t\n",sv.get_id(), sv.getTenHocSinh(),sv.getTuoiHocSinh(), sv.getGioiTinh(), sv.getdiemToan(), sv.getdiemLy(),sv.getdiemHoa(), sv.getdiemTB(), sv.getHocLuc());
       }
        i++;
        if(i == danhsachSinhVien.size() && strcmp(sv.getTenHocSinh(), ten)!=0)
        {
            printf("Khong co sinh vien ten %s trong danh sach.\n", ten);
        }
    }
}

//--------------Sắp xếp sinh viên theo GPA-----------------------------/
void Menu::SapXepTheoGPA()     // sắp xếp theo thứ tự tanwg dan
{   // danhsachSinhVien.size() là kích thước của mảng vector
    for(int i =0; i< danhsachSinhVien.size()-1; i++)//Duyệt vòng lặp bên ngoài từ vị trí đầu tiên đến vị trí trước vị trí cuối cùng của danh sách
    {
        for(int j = i+1; j < danhsachSinhVien.size(); j++)
        {
            if(danhsachSinhVien[i].getdiemTB() > danhsachSinhVien[j].getdiemTB())  //
            {
                SinhVien tg = danhsachSinhVien[i];
                danhsachSinhVien[i]=danhsachSinhVien[j];
                danhsachSinhVien[j]= tg;
            }
        }
    }
}

/// --------------Sắp xếp theo tên ------------------------------------/
void Menu::SapXepTheoTen()
{   // danhsachSinhVien.size() là kích thước của mảng vector

    for(int i =0; i< danhsachSinhVien.size()-1; i++)//Duyệt vòng lặp bên ngoài từ vị trí đầu tiên đến vị trí trước vị trí cuối cùng của danh sách
    {
        for(int j = i+1; j < danhsachSinhVien.size(); j++) // duyệt từ phần tử tiếp theo đến hết các phần tử còn lại trong mảng vector 
        {
            if(strcmp(danhsachSinhVien[i].getTenHocSinh(), danhsachSinhVien[j].getTenHocSinh()) > 0)  
            {
                SinhVien tg = danhsachSinhVien[i];
                danhsachSinhVien[i]=danhsachSinhVien[j];
                danhsachSinhVien[j]= tg;
            }
        }
    }
}
/// ------------hiển thị danh sách sinh viên---------------------------/
void Menu::hienthidanhsach()
{
    if(danhsachSinhVien.size() == 0)
    {
        printf("==> Danh sach trong!!!!\n");
    }
    else{
    printf("ID\t Ten\t Tuoi\t GioiTinh\tToan\t Ly\t Hoa\t GPA\t Hoc_Luc\t\n");
    for(SinhVien kb : danhsachSinhVien )
    {
        printf("%d\t %s\t %d\t  %s\t\t%.2lf\t%.2lf\t%.2lf\t %.2lf\t %s\t\n",kb.get_id(), kb.getTenHocSinh(),kb.getTuoiHocSinh(), kb.getGioiTinh(), kb.getdiemToan(), kb.getdiemLy(),kb.getdiemHoa(), kb.getdiemTB(), kb.getHocLuc());

    }
    }
}


int main(int argc, char const *argv[])
{
    Menu mn;
    int i=0;
    do{
        printf("---------------------------------------------------------------------\n");
        printf ("1. Them sinh vien\n");
        printf ("2. Cap nhat thong tin sinh vien\n");
        printf ("3. Xoa sinh vien\n");
        printf ("4. Tim kiem sinh vien theo ten\n");
        printf ("5. Sap Xep Theo GPA\n");
        printf ("6. Sap Xep Theo Ten\n");
        printf ("7. Hien thi danh sach sinh vien\n");
        printf ("8. Thoat\n");
        printf ("Chon mot trong cac cau tren(1-8): ");
        scanf("%d",&i);
        switch(i) {
            case 1:
                mn.themsinhvien();
                printf("Danh sach sinh vien moi: \n");
                mn.hienthidanhsach();
                break;
            case 2:
                mn.CapNhatTT();
                printf("Danh sach sinh vien sau cap nhat:\n");
                mn.hienthidanhsach();
                break;
            case 3:
                mn.XoaSinhVien();
                printf("Danh sach sinh vien moi: \n");
                mn.hienthidanhsach();
                break;
            case 4:
                mn.TimKiemTheoTen();    
                break;
            case 5:
                mn.SapXepTheoGPA();
                printf("Danh sach sinh vien sap xep theo GPA\n");
                mn.hienthidanhsach();
                break;
            case 6:
                mn.SapXepTheoTen();
                printf("Danh sach sinh vien sap xep theo ten\n");
                mn.hienthidanhsach();
                break;
            case 7:
                printf("Hien thi danh sach sinh vien: \n");
                mn.hienthidanhsach();
                break;
            case 8:
                printf ("Ket thuc chuong trinh.\n");
                return 0;
            default:
                "Vui long chon mot lua chon hop le.\n";
                break;
        }
    }while(1);
    return 0;
}
