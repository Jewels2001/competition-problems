#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  int num;
  cin >> num;
  double control = 0;
  double ca = 0;
  double cb = 0 ;
  double cc = 0;
  double va = 0;
  double vb = 0;
  double vc = 0;
  double ansa;
  double ansb;
  double ansc;
  for(int i=0; i<num; i++){
    char group;
    cin >> group;
    if(group == 'N'){
      control++;
      char a, b, c;
      cin >> a >> b >> c;
      if(a == 'Y'){
        ca++;
      }
      if(b == 'Y'){
        cb++;
      }
      if(c == 'Y'){
        cc++;
      }
    }
    else{
      char a, b, c;
      cin >> a >> b >> c;
      if(a == 'Y'){
        va++;
      }
      if(b == 'Y'){
        vb++;
      }
      if(c == 'Y'){
        vc++;
      }
    }
  }

  double iva = 0;
  double ivb = 0;
  double ivc = 0;
  double ica = 0;
  double icb = 0;
  double icc = 0;
  ica = ca/control;
  icb = cb/control;
  icc = cc/control;
  iva = va/(num-control);
  ivb = vb/(num-control);
  ivc = vc/(num-control);

  //cout << ca << " " << control << " " << ica << endl;
  //icb << icc << iva << ivb << ivc;

  if(iva >= ica){
    cout << "Not Effective" << endl;
  }
  else{
    ansa = ((ica-iva) / ica) *100;
    cout << fixed << setprecision(6) << ansa << endl;
  }
  if(ivb >= icb){
    cout << "Not Effective" << endl;
  }
  else{
    ansb = ((icb-ivb) / icb) *100;
    cout << fixed << setprecision(6) <<ansb << endl;
  }
  if(ivc >= icc){
    cout << "Not Effective" << endl;
  }
  else{
    ansc = ((icc-ivc) / icc) *100;
    cout << fixed << setprecision(6) <<ansc << endl;
  }

  return 0;
}
