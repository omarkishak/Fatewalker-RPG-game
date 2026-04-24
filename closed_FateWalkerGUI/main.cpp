#include <QApplication>
#include <QScreen>
#include <QStackedWidget>
#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QTextEdit>
#include <QGraphicsBlurEffect>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QWidget>

// Fade in from black helper
void fadeInFromBlack(QStackedWidget* stack, int duration = 800) {
    // Black overlay covering the entire stack
    QWidget* overlay = new QWidget(stack);
    overlay->setGeometry(stack->geometry());
    overlay->setStyleSheet("background-color: black;");
    overlay->raise();
    overlay->show();

    // Apply opacity effect
    QGraphicsOpacityEffect* effect = new QGraphicsOpacityEffect(overlay);
    overlay->setGraphicsEffect(effect);

    // Animate opacity from 1 -> 0
    QPropertyAnimation* anim = new QPropertyAnimation(effect, "opacity");
    anim->setDuration(duration);
    anim->setStartValue(1.0); // fully black
    anim->setEndValue(0.0);   // fully transparent
    anim->start(QAbstractAnimation::DeleteWhenStopped);

    // Remove overlay when done
    QObject::connect(anim, &QPropertyAnimation::finished, [overlay]() {
        overlay->deleteLater();
    });
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Main window + pages stack
    QMainWindow window;
    QStackedWidget *stack = new QStackedWidget(&window);
    window.setCentralWidget(stack);

    // Screen info
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();

    // ------------------
    // MAIN MENU PAGE
    //-------------------
    QWidget *menuPage = new QWidget();
    menuPage->setFixedSize(screenWidth, screenHeight);

    QLabel *menuBgLabel = new QLabel(menuPage);
    QPixmap menuPixmap(":/photos/main_menu.png");
    if (!menuPixmap.isNull()) {
        QPixmap scaledPixmap = menuPixmap.scaled(
            screenWidth,
            screenHeight,
            Qt::KeepAspectRatioByExpanding,
            Qt::SmoothTransformation
            );
        menuBgLabel->setPixmap(scaledPixmap);
        menuBgLabel->setScaledContents(true);
        menuBgLabel->setGeometry(0, 0, screenWidth, screenHeight);
    }

    int buttonWidth = 200;
    int buttonHeight = 50;
    int spacing = 20;
    int startY = screenHeight / 2 - (2 * buttonHeight + 1.5 * spacing);

    QPushButton *btnNewGame = new QPushButton("New Game", menuPage);
    QPushButton *btnLoadGame = new QPushButton("Load File", menuPage);
    QPushButton *btnHelp    = new QPushButton("Help", menuPage);
    QPushButton *btnQuit    = new QPushButton("Quit", menuPage);

    btnNewGame->setGeometry(screenWidth / 2 - buttonWidth / 2, startY, buttonWidth, buttonHeight);
    btnLoadGame->setGeometry(screenWidth / 2 - buttonWidth / 2, startY + buttonHeight + spacing, buttonWidth, buttonHeight);
    btnHelp->setGeometry(screenWidth / 2 - buttonWidth / 2, startY + 2 * (buttonHeight + spacing), buttonWidth, buttonHeight);
    btnQuit->setGeometry(screenWidth / 2 - buttonWidth / 2, startY + 3 * (buttonHeight + spacing), buttonWidth, buttonHeight);

    QString btnStyle = "background-color: rgba(0,0,0,150); color: white; font-size: 20px;";
    btnNewGame->setStyleSheet(btnStyle);
    btnLoadGame->setStyleSheet(btnStyle);
    btnHelp->setStyleSheet(btnStyle);
    btnQuit->setStyleSheet(btnStyle);

    stack->addWidget(menuPage); // index 0

    // =======================
    // HELP PAGE
    // =======================
    QWidget *helpPage = new QWidget();
    helpPage->setFixedSize(screenWidth, screenHeight);

    // Help page background (blurred)
    QLabel *helpBgLabel = new QLabel(helpPage);
    QPixmap helpPixmap(":/photos/main_menu.png");
    if (!helpPixmap.isNull()) {
        QPixmap scaledHelpPixmap = helpPixmap.scaled(
            screenWidth,
            screenHeight,
            Qt::KeepAspectRatioByExpanding,
            Qt::SmoothTransformation
            );
        helpBgLabel->setPixmap(scaledHelpPixmap);
        helpBgLabel->setScaledContents(true);
        helpBgLabel->setGeometry(0, 0, screenWidth, screenHeight);

        QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
        blur->setBlurRadius(10); // adjust blur amount
        helpBgLabel->setGraphicsEffect(blur);
    }

    // Help text
    QTextEdit *helpText = new QTextEdit(helpPage);
    helpText->setReadOnly(true);
    helpText->setGeometry(200, 150, screenWidth - 400, screenHeight - 300);
    helpText->setStyleSheet(
        "color: white;"
        "background-color: rgba(0,0,0,180);"
        "font-size: 18px;"
        );
    helpText->setText(R"(
FATEWALKER — HELP

• Choose actions using the menu
• Your decisions affect the world
• Death is permanent
• Explore carefully

Good luck, Fatewalker.
)");

    // Back button
    QPushButton *btnBack = new QPushButton("Back to Menu", helpPage);
    btnBack->setGeometry(screenWidth / 2 - 100, screenHeight - 120, 200, 50);
    btnBack->setStyleSheet(
        "background-color: rgba(255,255,255,180);"
        "font-size: 18px;"
        );

    stack->addWidget(helpPage); // index 1

    // =======================
    // CONNECTIONS
    // =======================
    QObject::connect(btnHelp, &QPushButton::clicked, [&](){
        stack->setCurrentIndex(1);      // switch to help page immediately
        fadeInFromBlack(stack, 800);    // overlay fades out slowly
    });

    QObject::connect(btnBack, &QPushButton::clicked, [&](){
        stack->setCurrentIndex(0);      // switch to menu page immediately
        fadeInFromBlack(stack, 800);    // overlay fades out slowly
    });

    QObject::connect(btnQuit, &QPushButton::clicked, [&](){
        QApplication::quit();
    });

    window.showFullScreen();
    return a.exec();
}
