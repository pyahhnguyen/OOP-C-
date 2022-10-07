#include<iostream>
#include<string>
 using namespace std;
  void Time_convert(int num){
      bool Flag;
      int hr=0;
      do
      {
          Flag = false;
        if(num =60){
            hr++;
            num-=60;
            Flag=true;
        }

      } while (Flag);
      cout<<"\n H:N"<<hr<<":"<<num<<endl;
  }
      int  main(){
          Time_convert(67);
          Time_convert(60);
          Time_convert(120);
          return 0;

      }

  