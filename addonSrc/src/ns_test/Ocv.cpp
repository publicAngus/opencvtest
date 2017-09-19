#include "Debute.hpp"
#include "Ocv.hpp"
#include <iostream>


using namespace cv;

namespace ns_test{

    int Ocv::ReadPixels(){
        ns_test::writeline("readpixels");
        
        Mat rawImg = imread("./imgs/bear.jpg");
        int horiD = rawImg.cols -1 ;
        int vertD = rawImg.rows -1 ;

        Vec3b pixels = rawImg.at<Vec3b>(vertD,horiD);
        ns_test::writeline((int)pixels[0]);
        ns_test::writeline((int)pixels[1]);
        ns_test::writeline((int)pixels[2]);
        ns_test::writeline(horiD);
        ns_test::writeline(vertD);

        //show original image
        char RawImgContainer[] = "Raw-Image";
        imshow(RawImgContainer,rawImg);
        moveWindow(RawImgContainer,0,0);

        //create monitor window
        Mat monImg = Mat::zeros(400,400,CV_8UC3);
        char monitor[] = "Monitor";
        namedWindow(monitor,WINDOW_AUTOSIZE);
        imshow(monitor,monImg);
        moveWindow(monitor,900,900);

        //copy region to monitor
        Rect roi(200,200,100,100);
        Mat roiImg = rawImg(roi);
        roiImg.copyTo(monImg.rowRange(0,100).colRange(10,110));
        imshow(monitor,monImg);

        //set mouseclick event
        setMouseCallback(RawImgContainer,onMouse,NULL);

        waitKey(0);
    }

    void Ocv::onMouse(int Event,int x,int y,int flags,void* param){
        ns_test::writeline("onMouse!");
    }

    int Ocv::DrawFrameTest(){
    
     int count = 0;
     VideoCapture cap;
     cap.open("./videos/XFace.mp4");
     if(!cap.isOpened()){
         std::cout << "cannot open camera" << std::endl;
     }else{
         namedWindow("cam",1);
       
 
             while(true){
             Mat frame;
             cap >> frame;

             Scalar color(50,50,50);
             Point pt1(count++,count++);
             Point pt2(100+count,100+count);
             rectangle(frame,pt1,pt2,color,10);
             imshow("cam",frame);
             if(waitKey(10)==27) break;
             }
 
         
         cap.release();
     }
     
 
    }

    int Ocv::DrawTest(){
        Mat img = imread("./imgs/bear.jpg"); //Mat::zeros(400,400,CV_8UC3);

        //namedWindow("imgCnt",WINDOW_NORMAL);
        //namedWindow("imgCnt",WINDOW_AUTOSIZE);
        //resizeWindow("imgCnt",100,100);
        RNG rng(0xFFFFFFFF);
        //imshow("testing",img);
        Scalar color(50,50,50);
        Point pt1(0,0);
        Point pt2(400,400);
        
        rectangle(img,pt1,pt2,color,10);
        line( img, pt1, pt2,color,10,LINE_AA);

        //fillpoly
        Point pt[1][4];
        pt[0][0] = Point(100,100);
        pt[0][1] = Point(200,100);
        pt[0][2] = Point(200,200);
        pt[0][3] = Point(100,200);

        const Point* ppt[1] = {pt[0]}; 
        int npt[] = {4}; 
        polylines(img,ppt,npt,1,1,Scalar(200,200,200),1,8,0);
        fillPoly(img,ppt,npt,1,Scalar(180,180,180));
        imshow("imgCnt",img);
        waitKey(0);
        
        

        return 0;
    }

    Scalar Ocv::randomColor(RNG& rng){
        int icolor = (unsigned)rng;
        return Scalar(icolor&255, (icolor>>8)&255, (icolor>>16)&255);
    }

    int Ocv::DrawDemo(){
        char wndname[] = "Drawing Demo";
        const int NUMBER = 100;
        const int DELAY = 5;
        int lineType = LINE_AA; // change it to LINE_8 to see non-antialiased graphics
        int i, width = 1000, height = 700;
        int x1 = -width/2, x2 = width*3/2, y1 = -height/2, y2 = height*3/2;
        RNG rng(0xFFFFFFFF);
    
        Mat image = Mat::zeros(height, width, CV_8UC3);
        imshow(wndname, image);
        waitKey(DELAY);
    
        for (i = 0; i < NUMBER * 2; i++)
        {
            Point pt1, pt2;
            pt1.x = rng.uniform(x1, x2);
            pt1.y = rng.uniform(y1, y2);
            pt2.x = rng.uniform(x1, x2);
            pt2.y = rng.uniform(y1, y2);
    
            int arrowed = rng.uniform(0, 6);
    
            if( arrowed < 3 )
                line( image, pt1, pt2, randomColor(rng), rng.uniform(1,10), lineType );
            else
                arrowedLine(image, pt1, pt2, randomColor(rng), rng.uniform(1, 10), lineType);
    
            imshow(wndname, image);
            if(waitKey(DELAY) >= 0)
                return 0;
        }
    
        for (i = 0; i < NUMBER * 2; i++)
        {
            Point pt1, pt2;
            pt1.x = rng.uniform(x1, x2);
            pt1.y = rng.uniform(y1, y2);
            pt2.x = rng.uniform(x1, x2);
            pt2.y = rng.uniform(y1, y2);
            int thickness = rng.uniform(-3, 10);
            int marker = rng.uniform(0, 10);
            int marker_size = rng.uniform(30, 80);
    
            if (marker > 5)
                rectangle(image, pt1, pt2, randomColor(rng), MAX(thickness, -1), lineType);
            else
                drawMarker(image, pt1, randomColor(rng), marker, marker_size );
    
            imshow(wndname, image);
            if(waitKey(DELAY) >= 0)
                return 0;
        }
    
        for (i = 0; i < NUMBER; i++)
        {
            Point center;
            center.x = rng.uniform(x1, x2);
            center.y = rng.uniform(y1, y2);
            Size axes;
            axes.width = rng.uniform(0, 200);
            axes.height = rng.uniform(0, 200);
            double angle = rng.uniform(0, 180);
    
            ellipse( image, center, axes, angle, angle - 100, angle + 200,
                     randomColor(rng), rng.uniform(-1,9), lineType );
    
            imshow(wndname, image);
            if(waitKey(DELAY) >= 0)
                return 0;
        }
    
        for (i = 0; i< NUMBER; i++)
        {
            Point pt[2][3];
            pt[0][0].x = rng.uniform(x1, x2);
            pt[0][0].y = rng.uniform(y1, y2);
            pt[0][1].x = rng.uniform(x1, x2);
            pt[0][1].y = rng.uniform(y1, y2);
            pt[0][2].x = rng.uniform(x1, x2);
            pt[0][2].y = rng.uniform(y1, y2);
            pt[1][0].x = rng.uniform(x1, x2);
            pt[1][0].y = rng.uniform(y1, y2);
            pt[1][1].x = rng.uniform(x1, x2);
            pt[1][1].y = rng.uniform(y1, y2);
            pt[1][2].x = rng.uniform(x1, x2);
            pt[1][2].y = rng.uniform(y1, y2);
            const Point* ppt[2] = {pt[0], pt[1]};
            int npt[] = {3, 3};
    
            polylines(image, ppt, npt, 2, true, randomColor(rng), rng.uniform(1,10), lineType);
    
            imshow(wndname, image);
            if(waitKey(DELAY) >= 0)
                return 0;
        }
    
        for (i = 0; i< NUMBER; i++)
        {
            Point pt[2][3];
            pt[0][0].x = rng.uniform(x1, x2);
            pt[0][0].y = rng.uniform(y1, y2);
            pt[0][1].x = rng.uniform(x1, x2);
            pt[0][1].y = rng.uniform(y1, y2);
            pt[0][2].x = rng.uniform(x1, x2);
            pt[0][2].y = rng.uniform(y1, y2);
            pt[1][0].x = rng.uniform(x1, x2);
            pt[1][0].y = rng.uniform(y1, y2);
            pt[1][1].x = rng.uniform(x1, x2);
            pt[1][1].y = rng.uniform(y1, y2);
            pt[1][2].x = rng.uniform(x1, x2);
            pt[1][2].y = rng.uniform(y1, y2);
            const Point* ppt[2] = {pt[0], pt[1]};
            int npt[] = {3, 3};
    
            fillPoly(image, ppt, npt, 2, randomColor(rng), lineType);
    
            imshow(wndname, image);
            if(waitKey(DELAY) >= 0)
                return 0;
        }
    
        for (i = 0; i < NUMBER; i++)
        {
            Point center;
            center.x = rng.uniform(x1, x2);
            center.y = rng.uniform(y1, y2);
    
            circle(image, center, rng.uniform(0, 300), randomColor(rng),
                   rng.uniform(-1, 9), lineType);
    
            imshow(wndname, image);
            if(waitKey(DELAY) >= 0)
                return 0;
        }
    
        for (i = 1; i < NUMBER; i++)
        {
            Point org;
            org.x = rng.uniform(x1, x2);
            org.y = rng.uniform(y1, y2);
    
            putText(image, "Testing text rendering", org, rng.uniform(0,8),
                    rng.uniform(0,100)*0.05+0.1, randomColor(rng), rng.uniform(1, 10), lineType);
    
            imshow(wndname, image);
            if(waitKey(DELAY) >= 0)
                return 0;
        }
    
        Size textsize = getTextSize("OpenCV forever!", FONT_HERSHEY_COMPLEX, 3, 5, 0);
        Point org((width - textsize.width)/2, (height - textsize.height)/2);
    
        Mat image2;
        for( i = 0; i < 255; i += 2 )
        {
            image2 = image - Scalar::all(i);
            putText(image2, "OpenCV forever!", org, FONT_HERSHEY_COMPLEX, 3,
                    Scalar(i, i, 255), 5, lineType);
    
            imshow(wndname, image2);
            if(waitKey(DELAY) >= 0)
                return 0;
        }
    
        waitKey();
        return 0;
    }


}