/*
FCI – Programming 1 – 2022 - Assignment 3
Program Name: Filters.cpp
Last Modification Date: 7/4/2022
Author1 and ID and Group: Mariam Ayman Taha 20210380
Author2 and ID and Group: Amira Bassam Dabbak 20210799
Author3 and ID and Group: Mohammed Sayed Abdelhakim 20210341
Teaching Assistant: Eng.Yousra Ayman
Purpose: Edit Photos By Adding Filters
*/

#include <bits/stdc++.h>
#include "bmplib.cpp"
#include <fstream>
#include <cstring>
using namespace std;
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];


void load_image1();
void load_image2();
void save_image();
void Black_and_White();
void Flip_image();
void Rotate_image();
void Merge_images();
void Lighten();
void Darken();
void Invert();
void Mirror();
void Detect_Edges();
void Shrink_image();
void Blur_image();
void Shuffle_image();
void Enlarge_image();

int main() {
    string Choice;
    cout << "_____Welcome to Photoshop Program_____\n";
    cout << "Please choose one of the following: \n";
    cout << "1-Black & White Filter\n2-Invert Filter\n3-Merge Filter\n4-Flip Filter\n5-Rotate Filter\n6-Darken or Lighten Filter\n"
            "7-Detect image edges Filter\n8-Enlarge Filter\n9-Shrink Filter\n10-Mirror Filter\n11-Shuffle Filter\n12-Blur Filter\n13-Save and Exit\n\n";
    cout << "Your Choice is: ";
    cin >> Choice;
    cout << '\n';
    while(Choice != "1" && Choice != "2" && Choice != "3" && Choice != "4" && Choice != "5" && Choice != "6" && Choice != "7" && Choice != "8" && Choice != "9" && Choice != "10" &&Choice != "11" &&Choice != "12" &&Choice != "13") {
        cout << "Your Choice is: ";
        cin >> Choice;
        cout << '\n';
    }
}
void load_image1(){
    char file_name[100];
    cout << "Enter The Source Image: ";
    cin >> file_name;
    cout << '\n';
    strcat(file_name, ".bmp");
    readGSBMP(file_name,image1);
}
void load_image2(){
    char file_name[100];
    cout << "Enter The Source Image 2:  ";
    cin >> file_name;
    cout << '\n';
    strcat(file_name, ".bmp");
    readGSBMP(file_name,image2);
}
void save_image(){
    char ImageName[100];
    cout << "Enter the target image name: ";
    cin >> ImageName;
    strcat(ImageName, ".bmp");
    writeGSBMP(ImageName, image1);

}