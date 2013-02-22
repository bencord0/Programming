#include <QApplication>
#include "qmlapplicationviewer.h"
#include "funcs.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/ProjectEuler/main.qml"));
    viewer.showExpanded();

    pje1();
    pje2();
    pje3(1);
    pje4();
    pje5();
    pje6();
    pje7();

    return app->exec();
}
