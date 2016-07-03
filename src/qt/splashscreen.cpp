#include "splashscreen.h"
#include "clientversion.h"
#include "util.h"

#include <QApplication>

#include <QDesktopWidget>

SplashScreen::SplashScreen(QWidget *parent) :
    QWidget(parent)
{

    QRect rec = QApplication::desktop()->screenGeometry();

    int screenWidth = rec.width();
    int screenHeight = rec.height();

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setGeometry(0,screenHeight/2-331,screenWidth,663);


    QPixmap bgPixmap(screenWidth,670);

    QLinearGradient bgGradient(QPointF(0, 0), QPointF(screenWidth, 0));
    bgGradient.setColorAt(0, QColor("#000000"));
    //bgGradient.setColorAt(1, QColor("#7d0001"));
	bgGradient.setColorAt(1, QColor("#000000"));
    //#3c3c3b

    QRect rect_linear(0,0,screenWidth,663);

    QPainter *painter = new QPainter(&bgPixmap);
    painter->fillRect(rect_linear, bgGradient);

    painter->end();

    bg = new QLabel(this);
    bg->setPixmap(bgPixmap);


    bg->setGeometry(0,0,screenWidth,663);

    splashImage = new QLabel(this);
    splashImage->setStyleSheet("QLabel { background: transparent; }");
    QPixmap newPixmap;
    if(GetBoolArg("-testnet")) {
        newPixmap.load(":/images/splash_testnet");
    }
    else {
        newPixmap.load(":/images/splash");
    }


    splashImage->setPixmap(newPixmap);
    splashImage->move((screenWidth/2)-480,50);



    QFont smallFont; smallFont.setPixelSize(10);

    versionLabel = new QLabel(this);
    versionLabel->setStyleSheet("QLabel { background: transparent; color: #000000; }");
    versionLabel->setFont(smallFont);
    versionLabel->setText(QString::fromStdString(FormatFullVersion()).split("-")[0]);
    versionLabel->setFixedSize(1000,30);
    versionLabel->move(screenWidth/2-10,630);


    QFont largeFont; largeFont.setPixelSize(16);

    label = new QLabel(this);
    label->setStyleSheet("QLabel { background: transparent; color: #FFFFFF; }");
    label->setFont(largeFont);
    label->setText("...");
    label->setFixedSize(1000,30);
    label->move(screenWidth/2-108,630);

}

SplashScreen::~SplashScreen()
{
}