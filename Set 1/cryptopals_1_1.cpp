#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map<char, string> HexMap;
map<string, char > base64Map;

string convertHexToBinary(string hexString) {
    string binaryString;
    for (auto character : hexString) {
        binaryString += HexMap[character];
    }
    return binaryString;
}  

string convertBinaryToBase64(string binaryString) {
    int binaryStringLength = binaryString.size(); 
    string base64String, base64Character;

    int index = 0;
    while(index + 24 <= binaryStringLength){
        for(int i = 0; i<4; i++) {
            base64Character = binaryString.substr(index, 6);
            base64String += base64Map[base64Character];
            index += 6;
        }
    }
    //Base64 theory: https://www.lifewire.com/base64-encoding-overview-1166412#:~:text=How%20Base64%20Encoding%20Works
    int remainingBits = binaryStringLength - index;
    if(remainingBits != 0) {
        string remainingString = binaryString.substr(index, remainingBits);
        int bitsToAdd = (8 - (remainingBits % 8)) % 8;
        while(bitsToAdd--){
            remainingString += '0';
            remainingBits++;
        }
        int remainingIndex = 0;

        for(int i=0; i<4; i++){
            if(remainingBits >= 6){
                base64Character = remainingString.substr(remainingIndex, 6);
                base64String += base64Map[base64Character];
                remainingIndex += 6;
                remainingBits -= 6;
            } else if (remainingBits > 0) {
                base64Character = remainingString.substr(remainingIndex, remainingBits);
                for(int j=6-remainingBits; j >0; j--) base64Character += '0';
                base64String += base64Map[base64Character];
                remainingBits = 0;
            } else {
                base64String += '=';
            }
        }
    }

    return base64String;
}

void generateHexToBinaryMap() {
    HexMap['0'] = "0000";
    HexMap['1'] = "0001";
    HexMap['2'] = "0010";
    HexMap['3'] = "0011";
    HexMap['4'] = "0100";
    HexMap['5'] = "0101";
    HexMap['6'] = "0110";
    HexMap['7'] = "0111";
    HexMap['8'] = "1000";
    HexMap['9'] = "1001";
    HexMap['a'] = "1010";
    HexMap['b'] = "1011";
    HexMap['c'] = "1100";
    HexMap['d'] = "1101";
    HexMap['e'] = "1110";
    HexMap['f'] = "1111";
}

void generateBinaryToBase64Map() {
    base64Map["000000"] = 'A';
    base64Map["000001"] = 'B';
    base64Map["000010"] = 'C';
    base64Map["000011"] = 'D';
    base64Map["000100"] = 'E';
    base64Map["000101"] = 'F';
    base64Map["000110"] = 'G';
    base64Map["000111"] = 'H';
    base64Map["001000"] = 'I';
    base64Map["001001"] = 'J';
    base64Map["001010"] = 'K';
    base64Map["001011"] = 'L';
    base64Map["001100"] = 'M';
    base64Map["001101"] = 'N';
    base64Map["001110"] = 'O';
    base64Map["001111"] = 'P';
    base64Map["010000"] = 'Q';
    base64Map["010001"] = 'R';
    base64Map["010010"] = 'S';
    base64Map["010011"] = 'T';
    base64Map["010100"] = 'U';
    base64Map["010101"] = 'V';
    base64Map["010110"] = 'W';
    base64Map["010111"] = 'X';
    base64Map["011000"] = 'Y';
    base64Map["011001"] = 'Z';
    base64Map["011010"] = 'a';
    base64Map["011011"] = 'b';
    base64Map["011100"] = 'c';
    base64Map["011101"] = 'd';
    base64Map["011110"] = 'e';
    base64Map["011111"] = 'f';
    base64Map["100000"] = 'g';
    base64Map["100001"] = 'h';
    base64Map["100010"] = 'i';
    base64Map["100011"] = 'j';
    base64Map["100100"] = 'k';
    base64Map["100101"] = 'l';
    base64Map["100110"] = 'm';
    base64Map["100111"] = 'n';
    base64Map["101000"] = 'o';
    base64Map["101001"] = 'p';
    base64Map["101010"] = 'q';
    base64Map["101011"] = 'r';
    base64Map["101100"] = 's';
    base64Map["101101"] = 't';
    base64Map["101110"] = 'u';
    base64Map["101111"] = 'v';
    base64Map["110000"] = 'w';
    base64Map["110001"] = 'x';
    base64Map["110010"] = 'y';
    base64Map["110011"] = 'z';
    base64Map["110100"] = '0';
    base64Map["110101"] = '1';
    base64Map["110110"] = '2';
    base64Map["110111"] = '3';
    base64Map["111000"] = '4';
    base64Map["111001"] = '5';
    base64Map["111010"] = '6';
    base64Map["111011"] = '7';
    base64Map["111100"] = '8';
    base64Map["111101"] = '9';
    base64Map["111110"] = '+';
    base64Map["111111"] = '/';
}

int main () {
    generateHexToBinaryMap();
    generateBinaryToBase64Map();
    string inputString;
    cin >> inputString;
    string binaryString = convertHexToBinary(inputString);
    cout << convertBinaryToBase64(binaryString);
    return 0;
}






