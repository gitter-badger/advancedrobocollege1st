#include <C:/opencv249/build/include/opencv2/opencv.hpp>
//�ÓI�����N���C�u�����̎w��
#include <C:/opencv249/build/include/opencv2/opencv_lib.hpp>
//���O��Ԃ̎w��
using namespace cv;
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
IplImage *img = cvLoadImage("C:\\Users\\syouta\\Pictures\\9[1].jpg"); /* �C���[�W�̓ǂݍ��� */

cvNamedWindow("lena",1); /* �E�B���h�E���̎w�� */
cvShowImage("lena",img); /* �C���[�W�̕\�� */

cvWaitKey(0); /* �L�[���͑҂� */

cvDestroyWindow("lena"); /* �E�B���h�E�̊J�� */
cvReleaseImage(&img); /* �C���[�W�̊J�� */

return 0;
}