#include <opencv/highgui.h>
int main()
{
    IplImage * img = cvLoadImage("image.jpg");///�ɮ׭n��b�ୱ�{�����ؿ���
    cvShowImage("week07",img);
    cvWaitKey(0);///�e�����n�{�h,���@�U�ץ��@���~��
}
