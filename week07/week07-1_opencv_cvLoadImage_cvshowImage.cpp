#include <opencv/highgui.h>
int main()
{
    IplImage * img = cvLoadImage("image.jpg");///檔案要放在桌面程式的目錄裡
    cvShowImage("week07",img);
    cvWaitKey(0);///畫面不要閃退,等一下案任一鍵繼續
}
