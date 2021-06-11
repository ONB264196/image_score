#define _EX


#ifdef _EX
#include"libOne.h"
#include"Setting.h"
void gmain() {
    window(1920, 1080, 1);
    int img = loadImage("assets\\number.png");
    int imgs[10];
    divideImage(img, 10, 1, 150, 250, imgs);
    //初期値
    int score = m;
    int keta = 10;
    int UpFlag = 0;
    int DownFlag = 0;
    int LoopCut = 0;

    if (m > M) {
        WARNING(1, "最小値が最大値より大きい", "");
    }
    if (m < 0 || M < 0) {
        WARNING(1, "0以下は表示できない", "");
    }
    

    while (notQuit) {
        //増
        if (score < M) {
            if (isTrigger(KEY_UP)) {
                DownFlag = 0;
                UpFlag = 1;
            }
        }
        //減
        if (score > m) {
            if (isTrigger(KEY_DOWN)) {
                UpFlag = 0;
                DownFlag = 1;
            }
        }
        //ストップ
        if (isTrigger(KEY_SPACE)) {
            UpFlag = 0;
            DownFlag = 0;
        }
        //ストッパー
        if (score < m + 10 || score > M - 10) {
            if ((++LoopCut %= 10) == 0) {
                if (UpFlag == 1)score++;
                if (DownFlag == 1)score--;
            }
        }
        else {
            if (UpFlag == 1) {
                score++;
                if (isPress(KEY_W))score += 10;
            }
            if (DownFlag == 1) {
                score--;
                if (isPress(KEY_S))score += -10;
            }
        }
        if (score == m)DownFlag = 0;
        if (score == M)UpFlag = 0;
        //初期値に戻す
        if (isTrigger(KEY_ENTER))score = m;

        //描画
        clear(31, 30, 51);
        imageColor(244, 255, 204);
        int tmpScore = score;
        int kurai = pow(10,(keta-1));
        for (int i = 0; i < keta; i++) {
            int no = tmpScore / kurai;
            image(imgs[no], 100+150*i, 100);
            tmpScore %= kurai;
            kurai /= 10;
        }
    }
}
#endif

#ifdef _SAMPLE
#include"libOne.h"
void gmain() {
    window(1920, 1080, full);
    int originalImg = loadImage("assets\\number.png");
    int imgs[10];
    divideImage(originalImg, 10, 1, 150, 250, imgs);
    int score = 500;
    int keta = 3;
    while (notQuit) {
        if (score < 777)score++;
        clear();
        imageColor(20, 255, 20);
        int tmpScore = score;
        int kurai = pow(10,(keta-1));
        for (int i = 0; i < keta; i++) {
            int no = tmpScore / kurai;
            image(imgs[no], 735 + 150 * i, 150);
            tmpScore %= kurai;
            kurai /= 10;
        }
    }
}
#endif
