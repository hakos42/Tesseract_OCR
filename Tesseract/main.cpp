//
//  main.cpp
//  Tesseract
//
//  Created by hakim djelili on 17/05/2017.
//  Copyright © 2017 hakim djelili. All rights reserved.
//

#include <iostream>

#include <tesseract/baseapi.h>
#include <tesseract/strngs.h>

#include <leptonica/allheaders.h>
using namespace std ;
int main(int argc, const char * argv[]) {
    // insert code here...
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    char *outText;

    std::cout << api->Version()<<endl ;
    cout << getLeptonicaVersion() << endl;
    
    // Initialize tesseract-ocr with French, without specifying tessdata path
    if (api->Init(NULL, "fra+equ")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }
    
    //Open input image with leptonica library
    Pix *image = pixRead("/Users/hakos42/Documents/PROG_OSX/C++/Tesseract/Tesseract/lettre.gif");
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);
    
    // Destroy used object and release memory
    api->End();
    delete [] outText;
    pixDestroy(&image);

    return 0;
}
