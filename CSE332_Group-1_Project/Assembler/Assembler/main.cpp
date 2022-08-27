#include <bits/stdc++.h>
using namespace std;

#define nl "\n"

string toBinary(int num, int noOfBits){
  string s="";
  for(int i=0;i<noOfBits;i++){
    if ((num & (1<<i))!=0){
      s+="1";
    }
    else {
      s+="0";
    }
  }

  reverse(s.begin(),s.end());

  return s;
}

map<string,string> mr;
void prepare_registers(){
  mr["$r0"]=toBinary(0, 3);
  mr["$r1"]=toBinary(1, 3);
  mr["$r2"]=toBinary(2, 3);
  mr["$r3"]=toBinary(3, 3);
  mr["$r4"]=toBinary(4, 3);
  mr["$r5"]=toBinary(5, 3);
  mr["$r6"]=toBinary(6, 3);
  mr["$r7"]=toBinary(7, 3);

}

map<string,string> mo;
void prepare_opcode(){
  mo["add"]=toBinary(0, 3);
  mo["sub"]=toBinary(1, 3);
  mo["addi"]=toBinary(2, 3);
  mo["lw"]=toBinary(3, 3);
  mo["sw"]=toBinary(4, 3);
  mo["and"]=toBinary(5, 3);
  mo["xor"]=toBinary(6, 3);
  mo["j"]=toBinary(7, 3);

}

map<string,string> mbh;
void prepare_binaryToHex(){
  mbh["0000"]="0";
  mbh["0001"]="1";
  mbh["0010"]="2";
  mbh["0011"]="3";
  mbh["0100"]="4";
  mbh["0101"]="5";
  mbh["0110"]="6";
  mbh["0111"]="7";
  mbh["1000"]="8";
  mbh["1001"]="9";
  mbh["1010"]="a";
  mbh["1011"]="b";
  mbh["1100"]="c";
  mbh["1101"]="d";
  mbh["1110"]="e";
  mbh["1111"]="f";

}

int main() {
  prepare_opcode();
  prepare_registers();
  prepare_binaryToHex();

#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  freopen("error.txt","w",stderr);
#endif

  vector<string> machineCode;

  string s;

  while (getline(cin,s)){
    stringstream ss(s);

    string temS;
    ss >> temS;

    int temI;

    if(temS == "add" || temS == "sub" || temS == "and" || temS == "xor"){
      string instBinary;

      instBinary+=mo[temS];

      ss>>temS;
      instBinary+=mr[temS];

      ss>>temS;
      instBinary+=mr[temS];

      ss>>temS;
      instBinary+=mr[temS];

      machineCode.push_back(mbh[instBinary.substr(0,4)] + mbh[instBinary.substr(4,4)] + mbh[instBinary.substr(8,4)]);

    }else if(temS == "addi" || temS == "lw" || temS == "sw"){

      string instBinary;

      instBinary+=mo[temS];

      ss>>temS;
      instBinary+=mr[temS];

      ss>>temS;
      instBinary+=mr[temS];

      ss>>temI;
      temS= toBinary(temI,3);
      instBinary+=temS;

      machineCode.push_back(mbh[instBinary.substr(0,4)] + mbh[instBinary.substr(4,4)] + mbh[instBinary.substr(8,4)]);

    }else if(temS == "j"){
      string instBinary;

      instBinary+=mo[temS];

      ss>>temI;
      temS= toBinary(temI,9);
      instBinary+=temS;

      machineCode.push_back(mbh[instBinary.substr(0,4)] + mbh[instBinary.substr(4,4)] + mbh[instBinary.substr(8,4)]);

    }
  }

  for(const auto& oto:machineCode){
    cout<<oto<<nl;

  }

  return 0;
}
