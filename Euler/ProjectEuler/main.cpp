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

    pje1(1);
    pje2(1);
    pje3(1);
    pje4(1);
    pje5(1);
    pje6(1);
    pje7(1);
    pje8(1);
    pje9(1);
    pje10(1);
    pje11(1);

    return app->exec();
}
