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
    load_image1();
    while(Choice != "13"){
        if(Choice == "1"){
            Black_and_White();
        }
        else if(Choice == "2"){
            Invert();
        }
        else if(Choice == "3"){
            Merge_images();
        }
        else if(Choice == "4"){
            Flip_image();
        }
        else if(Choice == "5"){
            Rotate_image();
        }
        else if(Choice == "6"){
            char Ch;
            cout<<"1-To lighten the image\n2-To darken the image";
            cin >> Ch;
            if(Ch == '1')
                Lighten();
            else
                Darken();
        }
        else if (Choice == "7"){
            Detect_Edges();
        }
        else if (Choice == "8"){
            Enlarge_image();
        }
        else if(Choice == "9"){
            Shrink_image();
        }
        else if(Choice == "10"){
            Mirror();
        }
        else if(Choice == "11"){
            Shuffle_image();
        }
        else if(Choice == "12"){
            Blur_image();
        }
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
    save_image();
    return 0;
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
void Black_and_White() {
    for (int i = 0; i < SIZE; ++i ){
        for (int j = 0; j < SIZE; ++j){
            if (image1[i][j] > 127){
                image1[i][j] = 0;
            }
            else{
                image1[i][j] = 255;
            }
        }
    }
}
void Flip_image(){
    unsigned char Flip_h[SIZE][SIZE];
    unsigned char Flip_v[SIZE][SIZE];
    char option;
    cout << "Please choose one of the two options: \n1-Flip Horizontally\n2-Flip Vertically\n";
    cin >> option;
    while(option != '1' && option != '2'){
        cout << "Please choose one of the two options: \n1-Flip Horizontally\n2-Flip Vertically\n";
        cin >> option;
    }
    if(option == '1'){
        for (int i = 0; i < SIZE; ++i ){
            for (int j = 0; j < SIZE; ++j){
                Flip_h[i][j] = image1[i][SIZE-j-1];
            }
        }
        for(int i = 0;i < SIZE; ++i){
            for(int j = 0;j < SIZE; ++j){
                image1[i][j] = Flip_h[i][j];
            }
        }
    }
    else if(option == '2'){
        for (int i = 0; i < SIZE; ++i ) {
            for (int j = 0; j < SIZE; ++j) {
                Flip_v[i][j] = image1[SIZE - i - 1][j];
            }
        }
        for(int i = 0;i < SIZE; ++i){
            for(int j = 0;j < SIZE; ++j){
                image1[i][j] = Flip_v[i][j];
            }
        }
    }
}
void Merge_images(){
    load_image2();
    unsigned char Merged[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++ ){
        for (int j = 0; j < SIZE; j++){
            Merged[i][j] = (image1[i][j]+image2[i][j])/2;
        }
    }
    for(int i = 0;i < SIZE; ++i){
        for(int j = 0;j < SIZE; ++j){
            image1[i][j] = Merged[i][j];
        }
    }
}
void Mirror(){
    unsigned char L_mirror[SIZE][SIZE];
    unsigned char R_mirror[SIZE][SIZE];
    unsigned char U_mirror[SIZE][SIZE];
    unsigned char B_mirror[SIZE][SIZE];
    string choice;
    cout << "Choose a half to Mirror it: " << '\n' << "1-Left half\n2-Right half\n3-Upper half\n4-Bottom half\n";
    cin >> choice;
    while (choice != "1" && choice != "2" && choice != "3" && choice != "4"){
        cout << "Choose a half to Mirror it: " << '\n' << "1-Left half\n2-Right half\n3-Upper half\n4-Bottom half\n";
        cin >> choice;
    }
    if(choice == "1"){
        for(int i = 0;i < SIZE;++i){
            for(int j = 0;j < SIZE/2;++j){
                L_mirror[i][j] = image1[i][j];
            }
            int x = 1;
            for(int k = SIZE/2;k < SIZE ;++k){
                L_mirror[i][k] = image1[i][k-x];
                x += 2;
            }
        }
        for(int i = 0;i < SIZE; ++i){
            for(int j = 0;j < SIZE; ++j){
                image1[i][j] = L_mirror[i][j];
            }
        }
    }
    else if(choice == "2"){
        for(int i = 0;i<SIZE;++i){
            int size = 256;
            for(int j = 0;j < SIZE/2;++j){
                R_mirror[i][j] = image1[i][size-1];
                size--;
            }
            for(int k = SIZE/2; k < SIZE;++k){
                R_mirror[i][k] = image1[i][k];
            }
        }
        for(int i = 0;i < SIZE; ++i){
            for(int j = 0;j < SIZE; ++j){
                image1[i][j] = R_mirror[i][j];
            }
        }
    }
    else if(choice == "3"){
        for(int i = 0; i < SIZE/2;++i){
            for(int j = 0;j < SIZE;++j){
                U_mirror[i][j] = image1[i][j];
            }
        }
        int x = 1;
        for(int i = SIZE/2; i < SIZE;++i){
            for(int j = 0;j < SIZE;++j){
                U_mirror[i][j] = image1[i-x][j];
            }
            x +=2;
        }
        for(int i = 0;i < SIZE; ++i){
            for(int j = 0;j < SIZE; ++j){
                image1[i][j] = U_mirror[i][j];
            }
        }
    }
    else if(choice == "4"){
        for(int i = 0;i < SIZE/2;++i){
            for(int j = 0;j < SIZE; ++j){
                B_mirror[i][j] = image1[SIZE-1-i][j];
            }
        }
        for(int i = SIZE/2;i < SIZE; ++i){
            for(int j = 0;j < SIZE; ++j){
                B_mirror[i][j] = image1[i][j];
            }
        }
        for(int i = 0;i < SIZE; ++i){
            for(int j = 0;j < SIZE; ++j){
                image1[i][j] = B_mirror[i][j];
            }
        }
    }
}
void Lighten(){
    unsigned char n_img[SIZE][SIZE];
    unsigned char lighten[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++ ) {
        for (int j = 0; j < SIZE; j++) {
            n_img[i][j] = 200;
            n_img[i][j] = (n_img[i][j] + image1[i][j]) / 2;
            lighten[i][j] = n_img[i][j];
        }
    }
    for(int i = 0;i < SIZE; ++i){
        for(int j = 0;j < SIZE; ++j){
            image1[i][j] = lighten[i][j];
        }
    }
}
void Darken(){
    unsigned char darken[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++ ){
        for (int j = 0; j < SIZE; j++){
            darken[i][j]=image1[i][j]/2;
        }
    }
    for(int i = 0;i < SIZE; ++i){
        for(int j = 0;j < SIZE; ++j){
            image1[i][j] = darken[i][j];
        }
    }
}
void Enlarge_image() {
    unsigned char image3[SIZE][SIZE];
    unsigned char part_image[SIZE][SIZE];
    int part, row, colum = 0;
    row = 0;
    cout << "Enter the part number you want to enlarge: ";
    cin >> part;
    //We take the bar from the user and then distribute it to the entire array and thus happens enlarge
    while (true) {
        if (part == 1 || part == 2 || part == 3 || part == 4) {
            break;
        }
        else {
            cout << "invalid input" << endl;
            cout << "Enter the part number you want to modify";
            cin >> part;
        }
    }
    if (part == 1) {
        for (int i = 0; i < SIZE / 2; i++) {
            colum = 0;
            for (int j = 0; j < SIZE / 2; j++) {
                part_image[row][colum] = image1[i][j];
                colum++;
            }
            row++;
        }
    }
    else if (part == 2) {
        for (int i = 0; i < SIZE / 2; i++) {
            colum = 0;
            for (int j = SIZE / 2; j < SIZE; j++) {
                part_image[row][colum] = image1[i][j];
                colum++;
            }
            row++;
        }
    }
    else if (part == 3) {
        for (int i = SIZE / 2; i < SIZE; i++) {
            colum = 0;
            for (int j = 0; j < SIZE / 2; j++) {
                part_image[row][colum] = image1[i][j];
                colum++;
            }
            row++;
        }
    }
    else {
        for (int i = SIZE / 2; i < SIZE; i++) {
            colum = 0;
            for (int j = SIZE / 2; j < SIZE; j++) {
                part_image[row][colum] = image1[i][j];
                colum++;
            }
            row++;
        }
    }
    row = 0;
    for (int i = 0;i < SIZE / 2;i++) {
        colum = 0;
        for (int j = 0;j < SIZE;j += 2) {
            image2[i][j] = part_image[row][colum];
            image2[i][j + 1] = part_image[row][colum];
            colum++;
        }
        row++;
    }
    row = 0;
    for (int i = 0;i < SIZE;i += 2) {
        colum = 0;
        for (int j = 0;j < SIZE;j++) {
            image3[i][j] = image2[row][colum];
            image3[i + 1][j] = image2[row][colum];
            colum++;
        }
        row++;
    }
    for(int i = 0; i < SIZE;++i){
        for(int j = 0; j < SIZE; ++j){
            image1[i][j] = image3[i][j];
        }
    }
}
void Detect_Edges(){
    unsigned char DE[SIZE][SIZE];
    for (int i = 0; i < SIZE; ++i ){
        for (int j = 0; j < SIZE; ++j){
            if (image1[i][j] > 127){
                image1[i][j] = 0;
            }
            else{
                image1[i][j] = 255;
            }
        }
    }
    for (int i = 0;i < SIZE;++i){
        for(int j = 0;j < SIZE-1; ++j){
            if(image1[i][j] != image1[i][j+1] || image1[i][j] != image1[i+1][j] || image1[i][j] != image1[i][j-1] || image1[i][j] != image1[i-1][j]){
                DE[i][j] = 255;
            }
        }
    }
    for (int i = 0; i < SIZE; ++i ){
        for (int j = 0; j < SIZE; ++j){
            if (DE[i][j] > 127){
                DE[i][j] = 0;
            }
            else{
                DE[i][j] = 255;
            }
        }
    }
    for(int i = 0;i < SIZE; ++i){
        for(int j = 0;j < SIZE; ++j){
            image1[i][j] = DE[i][j];
        }
    }
}
void Shrink_image(){
    unsigned char shrink[SIZE][SIZE];
    int Dividing ;
    cout <<"Enter the number you want to divide By 1/....";
    cin >> Dividing;
    for (int i = 0; i < SIZE; i++ ){
        for (int j = 0; j < SIZE; j++){
            shrink[i/Dividing][j/Dividing]=image1[i][j];
        }
    }
    for(int i = 0; i < SIZE;++i){
        for(int j = 0; j < SIZE; ++j){
            image1[i][j] = shrink[i][j];
        }
    }
}
void Rotate_image(){
    unsigned char mat[SIZE][SIZE];
    unsigned char Rotate_90[SIZE][SIZE];
    unsigned char Rotate_180[SIZE][SIZE];
    unsigned char Rotate_270[SIZE][SIZE];
    char option;
    cout << "Please choose one of three options:\n1-Rotate by 90 degree\n2-Rotate by 180 degree\n3-Rotate by 270 degree\n";
    cin >> option;
    while(option != '1' && option != '2' && option != '3'){
        cout << "Please choose one of three options:\n1-Rotate by 90 degree\n2-Rotate by 180 degree\n3-Rotate by 270 degree\n";
        cin >> option;
    }
    if(option == '1') {
        for (int i = 0; i < SIZE; ++i ){
            for (int j = 0; j < SIZE; ++j){
                mat[i][j] = image1[SIZE-i-1][j];
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                Rotate_90[j][i] = mat[i][j];
            }
        }
        for(int i = 0;i < SIZE; ++i){
            for(int j = 0;j < SIZE; ++j){
                image1[i][j] = Rotate_90[i][j];
            }
        }
    }
    else if(option == '2'){
        for (int i = 0; i < SIZE; ++i ){
            for (int j = 0; j < SIZE; ++j){
                mat[i][j] = image1[i][SIZE-j-1];
            }
        }
        for (int i = 0; i < SIZE; ++i ){
            for (int j = 0; j < SIZE; ++j){
                Rotate_180[i][j] = mat[SIZE-i-1][j];
            }
        }
        for(int i = 0;i < SIZE; ++i){
            for(int j = 0;j < SIZE; ++j){
                image1[i][j] = Rotate_180[i][j];
            }
        }
    }
    else if(option == '3'){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                mat[i][j] = image1[i][SIZE-j-1];
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                Rotate_270[j][i] = mat[i][j];
            }
        }
        for(int i = 0;i < SIZE; ++i){
            for(int j = 0;j < SIZE; ++j){
                image1[i][j] = Rotate_270[i][j];
            }
        }
    }
}
void Invert() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image1[i][j] = 255- image1[i][j];

        }
    }
}
void Shuffle_image() {
    unsigned char shuffle[SIZE][SIZE];
    int row = 0, colum = 0;
    string order, c_order;
    cout << "Please enter the order you want: ";
    cin >> order;
    c_order = order;
    sort(order.begin(), order.end());
    while (order[0] == order[1] || order[1] == order[2] || order[2] == order[3]){
        cout << "Invalid input";
        cout << "Please enter the order you want: ";
        cin >> order;
        c_order = order;
        sort(order.begin(), order.end());
    }
    if (order[0] == 1) {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                shuffle[i][j] = image1[i][j];
            }
        }
    }
    else if (order[0] == 2) {
        for (int i = 0; i < SIZE / 2; i++) {
            colum = 0;
            for (int j = SIZE / 2; j < SIZE; j++) {
                shuffle[row][colum] = image1[i][j];
                colum++;
            }
            row++;
        }
    }
    else if (order[0] == 3) {
        for (int i = SIZE / 2; i < SIZE; i++) {
            colum = 0;
            for (int j = 0; j < SIZE / 2; j++) {
                shuffle[row][colum] = image1[i][j];
                colum++;
            }
            row++;
        }
    }
    else {
        for (int i = SIZE / 2; i < SIZE; i++) {
            colum = 0;
            for (int j = SIZE / 2; j < SIZE; j++) {
                shuffle[row][colum] = image1[i][j];
                colum++;
            }
            row++;
        }
    }
    colum = SIZE / 2;
    row = 0;
    if (order[1] == 1) {
        for (int i = 0; i < SIZE / 2; i++) {
            colum = SIZE / 2;
            for (int j = 0; j < SIZE / 2; j++) {
                shuffle[row][colum] = image1[i][j];
                colum++;
            }
            row++;
        }
    }
    else if (order[1] == 2) {
        for (int i = 0; i < SIZE / 2; i++) {
            colum = SIZE / 2;
            for (int j = SIZE / 2; j < SIZE; j++) {
                shuffle[row][colum] = image1[i][j];
                colum++;
            }
            row++;
        }
    }
    else if (order[1] == 3) {
        for (int i = SIZE / 2; i < SIZE; i++) {
            colum = SIZE / 2;
            for (int j = 0; j < SIZE / 2; j++) {
                shuffle[row][colum] = image1[i][j];
                colum++;
            }
            row++;
        }
    }
    else {
        for (int i = SIZE / 2; i < SIZE; i++) {
            colum = SIZE / 2;
            for (int j = SIZE / 2; j < SIZE; j++) {
                shuffle[row][colum] = image1[i][j];
                colum++;
            }
            row++;
        }
    }
    row = SIZE / 2;
    colum = 0;
    if (order[2] == 1) {
        for (int i = 0; i < SIZE / 2; i++) {
            colum = 0;
            for (int j = 0; j < SIZE / 2; j++) {
                shuffle[row][colum] = image1[i][j];
                colum++;
            }
            row++;
        }
    }
    else if (order[2] == 2) {
        for (int i = 0; i < SIZE / 2; i++) {
            colum = 0;
            for (int j = SIZE / 2; j < SIZE; j++) {
                shuffle[row][colum] = image1[i][j];
                colum++;
            }
            row++;
        }
    }
    else if (order[2] == 3) {
        for (int i = SIZE / 2; i < SIZE; i++) {
            colum = 0;
            for (int j = 0; j < SIZE / 2; j++) {
                shuffle[row][colum] = image1[i][j];
                colum++;
            }row++;
        }
    }
    else {
        for (int i = SIZE / 2; i < SIZE; i++) {
            colum = 0;
            for (int j = SIZE / 2; j < SIZE; j++) {
                shuffle[row][colum] = image1[i][j];
                colum++;
            }row++;
        }
    }
    row = SIZE / 2;
    colum = SIZE / 2;
    if (order[3] == 1) {
        for (int i = 0; i < SIZE / 2; i++) {
            colum = SIZE / 2;
            for (int j = 0; j < SIZE / 2; j++) {
                shuffle[row][colum] = image1[i][j];
                colum++;
            }
            row++;
        }
    }
    else if (order[3] == 2) {
        for (int i = 0; i < SIZE / 2; i++) {
            colum = SIZE / 2;
            for (int j = SIZE / 2; j < SIZE; j++) {
                shuffle[row][colum] = image1[i][j];
                colum++;
            }row++;
        }
    }
    else if (order[3] == 3) {
        for (int i = SIZE / 2; i < SIZE; i++) {
            colum = SIZE / 2;
            for (int j = 0; j < SIZE / 2; j++) {
                shuffle[row][colum] = image1[i][j];
                colum++;
            }
            row++;
        }
    }
    else {
        for (int i = SIZE / 2; i < SIZE; i++) {
            colum = SIZE / 2;
            for (int j = SIZE / 2; j < SIZE; j++) {
                shuffle[row][colum] = image1[i][j];
                colum++;
            }
            row++;
        }
    }
    for(int i = 0; i < SIZE;++i){
        for(int j = 0; j < SIZE; ++j){
            image1[i][j] = shuffle[i][j];
        }
    }
}
void Blur_image(){
    unsigned char blur[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++ ){
        for (int j = 0; j < SIZE; j++){
            int avr=image1[i-1][j-1] +image1[i-1][j] +image1[i-1][j+1] +image1[i-1][j+2] +image1[i-1][j+3] +image1[i][j-1]
                    +image1[i][j] +image1[i][j+1] +image1[i][j+2] +image1[i][j+3] +image1[i+1][j-1] +image1[i+1][j] +image1[i+1][j+1] +image1[i+1][j+2] + image1[i+1][j+3] +image1[i+2][j-1] +
                    image1[i+2][j] +image1[i+2][j+1] +image1[i+2][j+2] +image1[i+2][j+3] +image1[i+3][j-1] +image1[i+3][j] +image1[i+3][j+1] +image1[i+3][j+2] +image1[i+3][j+3] ;
            int x=avr/25;
            blur[i][j]=x;
        }
    }
    for(int i = 0; i < SIZE;++i){
        for(int j = 0; j < SIZE; ++j){
            image1[i][j] = blur[i][j];
        }
    }
}
