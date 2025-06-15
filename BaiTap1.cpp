#include<stdio.h>
#include<math.h>
void NhapMang(int a[], int n);
void XuatMang(int a[], int n);
int TinhTongCacPTu(int a[], int n);
void LietKeCacSoChiaHetCho5(int a[], int n);
float TinhTBC(int a[], int n);
int SoNguyenTo(int n);
int TinhTongSNT(int a[], int n);
void NhapPhepTinh(int a[], int n);
void SapXepTang(int a[], int n);
void ChenPTu(int a[], int *n, int k, int x);
void XoaPTu(int a[], int *n, int k);
int main(){
	int n, m[100], k, x, luachon;
	printf("Nhap n: "); scanf("%d", &n);
	NhapMang(m, n);
	XuatMang(m, n);
	printf("==============================================\n");
	printf("|        CHUONG TRINH QUAN LY MANG SO        |\n");
	printf("==============================================\n");
	printf("| 1. Tinh tong cac phan tu                   |\n");
	printf("| 2. Liet ke cac so chia het cho 5           |\n");
	printf("| 3. Tinh trung binh cong                    |\n");
	printf("| 4. Tinh tong cac so nguyen to              |\n");
	printf("| 5. Thuc hien phep tinh (+, -, *, /)        |\n");
	printf("| 6. Sap xep mang tang dan                   |\n");
	printf("| 7. Chen phan tu vao vi tri bat ky          |\n");
	printf("| 8. Xoa phan tu tai vi tri bat ky           |\n");
	printf("| 0. Thoat                                   |\n");
	printf("==============================================\n");
	do {
		printf("\nHay chon tinh nang: ");
		scanf("%d", &luachon);
		switch(luachon){
			case 1:
				TinhTongCacPTu(m, n);
				break;
			case 2:
				LietKeCacSoChiaHetCho5(m, n);
				break;
			case 3:
				TinhTBC(m, n);
				break;
			case 4:
				TinhTongSNT(m, n);
				break;
			case 5:
				NhapPhepTinh(m, n);
				break;
			case 6:
				SapXepTang(m, n);
				break;
			case 7:
				printf("Nhap vi tri chen k: "); scanf("%d", &k);
				printf("Nhap gia tri x: "); scanf("%d", &x);
				ChenPTu(m, &n, k, x);
				break;
			case 8:
				printf("Nhap vi tri xoa k: "); scanf("%d", &k);
				XoaPTu(m, &n, k);
				break;
			case 0:
				printf("Da thoat.\n");
				break;
			default:
				printf("Lua chon khong hop le. Vui long chon lai.\n");
				break;
		}
	} while(luachon != 0);
	return 0;
}
void NhapMang(int a[], int n){
	printf("Nhap cac ptu: ");
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
}
void XuatMang(int a[], int n){
	printf("Mang: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
int TinhTongCacPTu(int a[], int n){
	int tong = 0;
	for(int i = 0; i < n; i++){
		tong += a[i];
	}
	printf("1. Tong cac ptu = %d\n", tong);
	return tong;
}
void LietKeCacSoChiaHetCho5(int a[], int n){
	printf("2. Cac so chia het cho 5 la: ");
	int co = 0;
	for(int i = 0; i < n; i++){
		if(a[i] % 5 == 0){
			printf("%d ", a[i]);
			co = 1;
		}
	}
	if (!co) printf("khong co.");
	printf("\n");
}
float TinhTBC(int a[], int n){
	float TBC = 0;
	for(int i = 0; i < n; i++){
		TBC += a[i];
	}
	TBC /= n;
	printf("3. Trung binh cong = %.2f\n", TBC);
	return TBC;
}
int SoNguyenTo(int n){
	if(n < 2) return 0;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0)
			return 0;
	}
	return 1;
}
int TinhTongSNT(int a[], int n){
	int tong = 0;
	for(int i = 0; i < n; i++){
		if(SoNguyenTo(a[i])){
			tong += a[i];
		}
	}
	printf("4. Tong cac so nguyen to = %d\n", tong);
	return tong;
}
void NhapPhepTinh(int a[], int n){
	char pheptinh;
	int ketqua;

	printf("Nhap phep tinh (+ - * /): ");
	scanf(" %c", &pheptinh);

	ketqua = a[0];

	for(int i = 1; i < n; i++){
		switch(pheptinh){
			case '+':
				ketqua += a[i]; break;
			case '-':
				ketqua -= a[i]; break;
			case '*':
				ketqua *= a[i]; break;
			case '/':
				if (a[i] != 0)
					ketqua /= a[i];
				else {
					printf("Khong the chia cho 0\n");
					return;
				}
				break;
			default:
				printf("Phep tinh khong hop le.\n");
				return;
		}
	}
	printf("5. Ket qua phep tinh: %d\n", ketqua);
}
void SapXepTang(int a[], int n){
	int temp;
	for(int i = 0; i < n-1; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] > a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("6. Mang sau khi sap xep tang: ");
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
void ChenPTu(int a[], int *n, int k, int x){
	if(k < 0 || k > *n){
		printf("Vi tri chen khong hop le.\n");
		return;
	}
	for(int i = *n; i > k; i--){
		a[i] = a[i - 1];
	}
	a[k] = x;
	(*n)++;
	printf("7. Mang sau khi chen: ");
	for(int i = 0; i < *n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
void XoaPTu(int a[], int *n, int k){
	if(k < 0 || k >= *n){
		printf("Vi tri xoa khong hop le.\n");
		return;
	}
	for(int i = k; i < *n - 1; i++){
		a[i] = a[i + 1];
	}
	(*n)--;
	printf("8. Mang sau khi xoa: ");
	for(int i = 0; i < *n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

