#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTabWidget>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    QWidget window;
    QVBoxLayout *mainLayout = new QVBoxLayout(&window);


    QTabWidget *tabs = new QTabWidget(&window);

    // 隊長頁面
    QWidget captainPage;
    QVBoxLayout *captainLayout = new QVBoxLayout(&captainPage);
    QLabel *captainLabel = new QLabel("隊長\n組員1\n組員2\n組員3", &captainPage);
    captainLayout->addWidget(captainLabel);

    // 組員1頁面（更改文字顏色）
    QWidget member1Page;
    QVBoxLayout *member1Layout = new QVBoxLayout(&member1Page);
    QPushButton *colorButton = new QPushButton("Color Select", &member1Page);
    member1Layout->addWidget(colorButton);

    QObject::connect(colorButton, &QPushButton::clicked, [&]() {
        QColor color = QColorDialog::getColor(Qt::white, &member1Page, "Select Color");
        if (color.isValid()) {
            QString style = QString("color: %1;").arg(color.name());
            captainLabel->setStyleSheet(style);
        }
    });

    // 組員2頁面（更改文字樣式）
    QWidget member2Page;
    QVBoxLayout *member2Layout = new QVBoxLayout(&member2Page);
    QPushButton *styleButton = new QPushButton("Font Select", &member2Page);
    member2Layout->addWidget(styleButton);

    QObject::connect(styleButton, &QPushButton::clicked, [&]() {
        bool ok;
        QFont font = QFontDialog::getFont(&ok, captainLabel->font(), &member2Page, "Select Font");
        if (ok) {
            captainLabel->setFont(font);
        }
    });

    // 組員3頁面（選擇檔案路徑）
    QWidget member3Page;
    QVBoxLayout *member3Layout = new QVBoxLayout(&member3Page);
    QPushButton *fileButton = new QPushButton("File Select", &member3Page);
    member3Layout->addWidget(fileButton);

    QObject::connect(fileButton, &QPushButton::clicked, [&]() {
        QString filePath = QFileDialog::getOpenFileName(&member3Page, "Select File");
        if (!filePath.isEmpty()) {
            captainLabel->setText(QString("選擇的檔案路徑：\n%1").arg(filePath));
        }
    });


    tabs->addTab(&captainPage, "隊長");
    tabs->addTab(&member1Page, "組員1");
    tabs->addTab(&member2Page, "組員2");
    tabs->addTab(&member3Page, "組員3");


    mainLayout->addWidget(tabs);


    window.setWindowTitle("Widget小組作業");
    window.resize(400, 300);
    window.show();

    return app.exec();
}
