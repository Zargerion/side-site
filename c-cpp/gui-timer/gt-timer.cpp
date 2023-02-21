#include <QApplication>
#include <QLabel>
#include <QTime>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel label;
    label.setAlignment(Qt::AlignCenter);
    label.setWindowTitle("Clock and Timer");
    label.resize(200, 50);
    label.show();

    // Timer to update the clock
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&label]() {
        label.setText(QTime::currentTime().toString("hh:mm:ss"));
    });
    timer.start(1000); // update every second

    return app.exec();
}