#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat)
#include <opencv2/highgui/highgui.hpp>  // Video write
#include "opencv2/imgproc/imgproc.hpp"


#include <iostream>
#include <string>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

   // cv::Mat img=cv::imread(argv[1]);
    cv::Mat img(1080,7000,CV_8UC3);
    // Setup output video
    cv::VideoWriter output_cap("test.avi",
                               CV_FOURCC('M','P','4','2'),
                               15,
                               cv::Size(7000,1080));

    cv::Point pt = cv::Point( img.cols/4, img.rows/2 );
    CvFont font;
    cvInitFont( &font, CV_FONT_HERSHEY_COMPLEX,1.0, 1.0, 0, 1, CV_AA);


    if (!output_cap.isOpened())
    {
        std::cout << "!!! Output video could not be opened" << std::endl;
        return -1;
    }


    for(int i=0;i<1000;i++){
        cv::Mat text(150,1000,img.type());
        cv::Point textPt = cv::Point( 0, text.rows-10 );
        text.setTo(cv::Scalar(255,255,255));
        std::stringstream ss;
        ss << i;
        std::string str = ss.str();
        cv::putText(text, str, textPt, 2,5, cv::Scalar(0,0,0) );

        text.copyTo(img(cv::Rect(pt.x,pt.y,text.cols,text.rows)));

        output_cap.write(img);
    }


    // Release capture interfaces
///    input_cap.release();
    output_cap.release();

    return 0;
}

//    char buffer [33];
//    for(int i=0;i<100;i++){
//        std::stringstream ss;
//        ss << i;
//        string str = ss.str();
//        cv::putText(img, str, pt, 1,40, cv::Scalar(0,0,0) );
//        output_cap.write(img);
//    }

