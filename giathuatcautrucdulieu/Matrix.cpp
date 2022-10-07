#include<iostream>
#include <iomanip>
     using namespace std;

class Matrix {
private:
    int cols, rows;// c-->cols, r-->rows
    float **a;// luu du lieu mang 2 chieu
public:
	//thêm instructor and destructor
  Matrix(int rows =1, int cols=1) : cols(cols), rows(rows), a(NULL){
if (cols<=0||rows<=0){
    throw "Illegal argument!!";
} 
/// Cap  phat bo nho cho con tro
    a = new float*[rows]; 
   for(int i = 0; i < rows; i++){
       a[i] =  new float[cols];
       for(int j = 0; j < cols; j++){
           a[i][j] = 0;
        
       }
   }
  }
  Matrix(){
        for(int i=0; i < rows; i++){
            delete[] a[i];
        }
    delete[] a;
  }

  istream& input(istream& is = cin){
      for(int i=0; i< rows; i++){
          for(int j =0; j<cols; j++){
              is >>a[i][j];
          }
      }
      return is;
  }
   ostream& output(ostream& os= cout) const{
      for(int i=0; i<rows; i++){
          for(int j=0; j<cols; j++){
              os  << fixed<< setw(2) << a[i][j] << (j< cols - 1 ? "  " : "\n");
          }
      }
     return os; 
  }
  friend ostream& operator<<(ostream& os,const Matrix& m ){
  	return m.output(os);
  }
  friend istream& operator>>(istream& is, Matrix& m ){
  	return m.input(is);
  }
  
  friend Matrix operator + (Matrix& m1, const Matrix& m2){
  	if( m1.cols != m2.cols || m1.rows != m2.rows){
  		throw " Illegal argument !!";
	  }
	  Matrix result(m1.rows, m1.cols);
	  for( int i=0; i<m1.rows; i++){
	  	for(int j=0; j<m1.cols; j++){
	  		result.a[i][j] = m1.a[i][j] + m2.a[i][j];
		  }
	  }
	  return result;
  }
  
  friend Matrix operator - (Matrix& m1, const Matrix& m2){
  	if( m1.cols != m2.cols || m1.rows != m2.rows){
  		throw " Illegal argument";
	  }
	  Matrix result(m1.rows, m1.cols);
	  for( int i=0; i<m1.rows; i++){
	  	for(int j=0; j<m1.cols; j++){
	  		result.a[i][j] = m1.a[i][j] - m2.a[i][j];
		  }
	  }
	  return result;
  }
  
  friend Matrix operator *(Matrix m1, const Matrix& m2){
  	if( m1.cols !=  m2.rows){
  		throw " Illegal argument";
	  }
	  Matrix result(m1.rows, m2.cols);
	  for( int i=0; i<m1.rows; i++){
	  	for(int j=0; j<m2.cols; j++){
	  		for (int k=0; k< m1.cols;k++){
	  			result.a[i][j] += m1.a[i][k] + m2.a[k][j];    
			  }
	  		
		  }
	  }
	  return result;
  }
};
int main(){    
    Matrix m1(2, 2);
    cout  << "Nhap ma tran 1:\n";
    cin>>m1;
    cout<< "Xuat ma tran 1:\n";
    cout<<m1<<endl;
    
    
    Matrix m2(2, 2);
    cout  << "Nhap ma tran 2:\n";
    cin>>m2;
    cout<< "Xuat ma tran 2:\n";
    cout<<m2<<endl;
    
    cout<< "Tong:\n";
    cout<< (m1+m2)<<endl;
    cout<< "Hieu:\n";
    cout<< (m1-m2)<<endl;
    cout<< "tich:\n";
    cout<< (m1*m2)<<endl;
}
