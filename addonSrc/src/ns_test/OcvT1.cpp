#include "OcvT1.hpp"
#include "Debute.hpp"
#include <string>
#include <vector>

using namespace cv;

namespace ns_test
{

std::string OcvT1::type2str(int type)
{
    std::string r;

    uchar depth = type & CV_MAT_DEPTH_MASK;
    uchar chans = 1 + (type >> CV_CN_SHIFT);

    switch (depth)
    {
    case CV_8U:
        r = "8U";
        break;
    case CV_8S:
        r = "8S";
        break;
    case CV_16U:
        r = "16U";
        break;
    case CV_16S:
        r = "16S";
        break;
    case CV_32S:
        r = "32S";
        break;
    case CV_32F:
        r = "32F";
        break;
    case CV_64F:
        r = "64F";
        break;
    default:
        r = "User";
        break;
    }

    r += "C";
    r += (chans + '0');

    return r;
}

OcvT1::OcvT1(char str[])
{
    _t1FilePath = str;
    _t1RawImg = imread(_t1FilePath);
    std::string ty = type2str(_t1RawImg.type());
    printf("Matrix: %s %dx%d \n", ty.c_str(), _t1RawImg.cols, _t1RawImg.rows);
    /*
      //testing pure color   
      Mat colorimg(300,300,CV_8UC3,Scalar(50,150,250));
      _t1RawImg = colorimg;
      */
    _t1ColorWindow = "ColorWindow";

    _t1MonWindow = "MonWindow";
  

    _t1RawWindow = "RawWindow";
   
}

void OcvT1::SayHello()
{
    ns_test::writeline("Hello fucker");
}



void OcvT1::Test()
{
    ns_test::writeline("Test Start:");

    char playWindow[] = "PlayWindow";
    namedWindow(playWindow,WINDOW_AUTOSIZE);
    moveWindow(playWindow,0,0);

    Mat bgImg = Mat(500,500,CV_8UC3,Scalar(255,255,255));
    imshow(playWindow,bgImg);
    
    waitKey(0);
}

void OcvT1::TestColorPick(){
    namedWindow(_t1MonWindow, WINDOW_AUTOSIZE);
    moveWindow(_t1MonWindow, 800, 0);

    namedWindow(_t1RawWindow, WINDOW_AUTOSIZE);
    moveWindow(_t1RawWindow, 0, 0);

    imshow(_t1RawWindow,_t1RawImg);
    setMouseCallback(_t1RawWindow,OnMouse,this);
}

void OcvT1::TestFaceDetect(){
    
    CascadeClassifier faceCC, eyesCC;
    faceCC.load("./cascadeXml/haarcascade_frontalface_alt.xml");
    eyesCC.load("./cascadeXml/haarcascade_eye_tree_eyeglasses.xml");

    Mat lenaImg = imread("./imgs/leana512.png");
    detectAndDraw(lenaImg, faceCC, eyesCC, 1, false);
    
}

void OcvT1::TestHistogram(){
    Mat rImg = _t1RawImg;
    std::vector<Mat> cnls;
    split(rImg,cnls);
    ns_test::writeline("size is:");
    ns_test::writeline(cnls.size());

    /*
    imshow("Blue",cnls[0]);
    imshow("Green",cnls[1]);
    imshow("Red",cnls[2]);
    */

    int dims = 1;
    int histSize = 256;
    float range[] = {0,256};
    const float* histRange = {range};
    Mat b_hist,g_hist,r_hist;
    calcHist(&cnls[0],1,0,Mat(),b_hist,dims,&histSize,&histRange);
    
    int hist_width = 512;
    int hist_height=256;
    int bin_w= cvRound((double)hist_width/histSize);

    Mat histo = Mat(hist_height,hist_width,CV_8UC3,Scalar(20,20,20));
    normalize(b_hist,b_hist,0,histo.rows,NORM_MINMAX,-1, Mat());
    for(int i=1;i<histSize;i++){
        line(histo,
            Point(i*bin_w, hist_height - cvRound(b_hist.at<float>(i))),
            Point((i-1)*bin_w,hist_height - cvRound(b_hist.at<float>(i-1))),Scalar(250,0,0),2,8,0);
    }

    imshow("Histogram",histo);
}

void OcvT1::OnMouse(int Event, int x, int y, int flags, void *param)
{
    //ns_test::writeline(flags);
    OcvT1 *inst;
    inst = (OcvT1 *)param;

    switch (Event)
    {
    case EVENT_RBUTTONDOWN:
    {
        Vec3b pixel = inst->_t1RawImg.at<Vec3b>(y, x);
        ns_test::writeline(std::to_string(x) + "," + std::to_string(y));
        ns_test::writeline(pixel[0]);
        ns_test::writeline(pixel[1]);
        ns_test::writeline(pixel[2]);

        Mat colorRect(100, 100, CV_8UC3, Scalar(pixel[0], pixel[1], pixel[2]));
        imshow(inst->_t1ColorWindow, colorRect);
    }
    break;
    case EVENT_LBUTTONDOWN:
    {
        inst->_isMouseDown = true;
        inst->_t1DownPoint = Point(x, y);
        //Rect roi(inst->_t1DownPoint.x,inst->_t1DownPoint.y,100,100);
        //Mat img = inst->_t1RawImg(roi);
        //imshow(inst->_t1MonWindow,img);
        ns_test::writeline(std::to_string(x) + "," + std::to_string(y));
    }
    break;
    case EVENT_MOUSEMOVE:
    {
        if (inst->_isMouseDown)
        {
            Point currentPt(x, y);
            Mat rawClone = inst->_t1RawImg.clone();
            rectangle(rawClone, inst->_t1DownPoint, currentPt, Scalar(188));
            imshow(inst->_t1RawWindow, rawClone);
        }
    }
    break;
    case EVENT_LBUTTONUP:
    {
        inst->_isMouseDown = false;
        inst->_t1UpPoint = Point(x, y);
        Rect roi(inst->_t1DownPoint, inst->_t1UpPoint);
        Mat imgSelected = inst->_t1RawImg(roi);
        imshow(inst->_t1MonWindow, imgSelected);

        /*
                //this is overlay testing
                Mat olay = Mat::zeros(imgSelected.rows,imgSelected.cols,CV_8UC3);
                addWeighted(imgSelected,0.1,olay,0.9,0.0,olay);
                imshow(inst->_t1MonWindow,olay);
                imshow("ttt",imgSelected);
                */
    }
    break;
    default:
        break;
    }
}

void OcvT1::detectAndDraw(Mat &img, CascadeClassifier &cascade,
                          CascadeClassifier &nestedCascade,
                          double scale, bool tryflip)
{
    double t = 0;
    std::vector<Rect> faces, faces2;
    const static Scalar colors[] =
        {
            Scalar(255, 0, 0),
            Scalar(255, 128, 0),
            Scalar(255, 255, 0),
            Scalar(0, 255, 0),
            Scalar(0, 128, 255),
            Scalar(0, 255, 255),
            Scalar(0, 0, 255),
            Scalar(255, 0, 255)};
    Mat gray, smallImg;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    double fx = 1 / scale;
    resize(gray, smallImg, Size(), fx, fx, INTER_LINEAR);
    equalizeHist(smallImg, smallImg);
    t = (double)getTickCount();
    cascade.detectMultiScale(smallImg, faces,
                             1.1, 2, 0
                                         //|CASCADE_FIND_BIGGEST_OBJECT
                                         //|CASCADE_DO_ROUGH_SEARCH
                                         | CASCADE_SCALE_IMAGE,
                             Size(30, 30));
    if (tryflip)
    {
        flip(smallImg, smallImg, 1);
        cascade.detectMultiScale(smallImg, faces2,
                                 1.1, 2, 0
                                             //|CASCADE_FIND_BIGGEST_OBJECT
                                             //|CASCADE_DO_ROUGH_SEARCH
                                             | CASCADE_SCALE_IMAGE,
                                 Size(30, 30));
        for (std::vector<Rect>::const_iterator r = faces2.begin(); r != faces2.end(); ++r)
        {
            faces.push_back(Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height));
        }
    }
    t = (double)getTickCount() - t;
    printf("detection time = %g ms\n", t * 1000 / getTickFrequency());
    for (size_t i = 0; i < faces.size(); i++)
    {
        Rect r = faces[i];
        Mat smallImgROI;
        std::vector<Rect> nestedObjects;
        Point center;
        Scalar color = colors[i % 8];
        int radius;
        double aspect_ratio = (double)r.width / r.height;
        
        if (0.75 < aspect_ratio && aspect_ratio < 1.3)
        {
            center.x = cvRound((r.x + r.width * 0.5) * scale);
            center.y = cvRound((r.y + r.height * 0.5) * scale);
            radius = cvRound((r.width + r.height) * 0.25 * scale);
            circle(img, center, radius, color, 3, 8, 0);
        }
        else
            rectangle(img, cvPoint(cvRound(r.x * scale), cvRound(r.y * scale)),
                      cvPoint(cvRound((r.x + r.width - 1) * scale), cvRound((r.y + r.height - 1) * scale)),
                      color, 3, 8, 0);
        if (nestedCascade.empty())
            continue;
        smallImgROI = smallImg(r);
        nestedCascade.detectMultiScale(smallImgROI, nestedObjects,
                                       1.1, 2, 0
                                                   //|CASCADE_FIND_BIGGEST_OBJECT
                                                   //|CASCADE_DO_ROUGH_SEARCH
                                                   //|CASCADE_DO_CANNY_PRUNING
                                                   | CASCADE_SCALE_IMAGE,
                                       Size(30, 30));
        for (size_t j = 0; j < nestedObjects.size(); j++)
        {
            Rect nr = nestedObjects[j];
            center.x = cvRound((r.x + nr.x + nr.width * 0.5) * scale);
            center.y = cvRound((r.y + nr.y + nr.height * 0.5) * scale);
            radius = cvRound((nr.width + nr.height) * 0.25 * scale);
            circle(img, center, radius, color, 3, 8, 0);
        }
    }
    imshow("result", img);
}
}