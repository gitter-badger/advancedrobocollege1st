#include <C:/opencv249/build/include/opencv2/opencv.hpp>
//静的リンクライブラリの指定
#include <C:/opencv249/build/include/opencv2/opencv_lib.hpp>
//名前空間の指定
using namespace cv;
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
IplImage *img = cvLoadImage("C:\\Users\\syouta\\Pictures\\9[1].jpg"); /* イメージの読み込み */

cvNamedWindow("lena",1); /* ウィンドウ名の指定 */
cvShowImage("lena",img); /* イメージの表示 */

cvWaitKey(0); /* キー入力待ち */

cvDestroyWindow("lena"); /* ウィンドウの開放 */
cvReleaseImage(&img); /* イメージの開放 */

return 0;
}